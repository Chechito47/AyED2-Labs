#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

//Our struct will have a value to identify elements
//and a struct to a pointer to identify the next values
struct _list {
    elem value;
    struct _list *next;
};

/* Constructors */
/* {- crea una lista vacia -} */
list empty() {
    list l = NULL;
    return l;
}

/* {- agrega el elemento al comienzo de la lista -} */
list addl(elem e, list l) {
    list aux = malloc(sizeof(struct _list));
    aux->value = e;
    aux->next = l;
    l = aux;
    return l;
}



/* Operations */
/* {- devuelve True si l es vacia -} */
bool is_empty(list l) {
    return (l == NULL);
}

/* {- PRE: not is_empty() -} */
/* {- devuelve el primer elemento de la lista l -} */
elem head(list l) {
    assert(!is_empty(l));

    return l->value;
}

/* {- PRE: not is_empty() -} */
/* {- elimina el primer elemento de la lista l -} */
list tail(list l) {
    assert(!is_empty(l));
    list aux = l;
    l = l->next;
    free(aux);

    return l;
}

/* {- agrega el elemento e al final de la lista -} */
list addr(list l, elem e) {
    list aux = malloc(sizeof(struct _list));
    aux->value = e;
    aux->next = NULL;

    if(is_empty(l)) {
        l = aux;
    } else {
        list aux2 = l;
        while (aux2->next != NULL) {
            aux2 = aux2->next;
        }
        aux2->next = aux;
    }

    return l;
}

/* {- devuelve la cantidad de elementos de la lista l -} */
int length(list l) {
    int length = 0;
    list aux = l;

    while (aux != NULL) {
        aux = aux->next;
        length++;
    }

    return length;
}

/* {- agrega al final de l todos los elementos de IO en el mismo orden} */
//No need to use malloc because is a list with another list
list concat(list l, list l0) {
    if (is_empty(l)) {
        l = l0;
    } else {
        list aux = l;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = l0;
    }

    return l;
}

/* {- PRE: n < length(l) -} */
/* {- devuelve el n-esimo elemento de la lista -} */
elem index(list l, int n) {
    assert(n < length(l));
    list aux = l;
    int count = 0;

    while (count < n) {
        aux = aux->next;
        count++;
    }

    return aux->value;
}

/* {- deja en l solo los primeros n elementos eliminando el resto -} */
list take(list l, int n) {
    if (n == 0) {
        destroy_list(l);
        return NULL;
    } else if (n < length(l)) {
        list aux = l;
        int count = 0;
        while (count < n-1) {
            aux = aux->next;
            count++;
        }
        list aux2 = aux->next;
        aux->next = NULL;
        destroy_list(aux2);
    }

    return l;
}

/* {- elimina los primeros n elementos de la lista l -} */
list drop(list l, int n) {
    list aux = l;

   if (n >= length(l)) {
        destroy_list(l);
        return NULL;
    }

    while (n > 0 && aux != NULL) {
        list aux2 = aux->next;
        free(aux);
        aux = aux2;
        n--;
    }

    return aux;
}

/* {- copia todos los elementos de la lista l1 en la nueva lista l2 -} */
list copy_list(list l) {
    list aux = empty();
    list aux2 = l;

    while (aux2 != NULL) {
        aux = addr(aux, aux2->value);
        aux2 = aux2->next;
    }

    return aux;
}



/* Destroy */
/* {- libera memoria en caso que sea necesario -} */
void destroy_list(list l) {
    list aux;
    while (l != NULL) {
        aux = l;
        l = l->next;
        free(aux);
    }
    aux = NULL;
}