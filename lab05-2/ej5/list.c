#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

//typedef struct _list *list;


/* Constructors */
/* {- crea una lista vacia -} */
list empty() {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}

/* {- agrega el elemento al comienzo de la lista -} */
list addl(elem e, list l) {
    assert(l->size <= MAX_LENGTH-1);

    for (int i = l->size-1; i >= 0; i--) {
        l->elems[i+1] = l->elems[i];
    }

    l->size++;
    l->elems[0] = e;

    return l;
}



/* Operations */
/* {- devuelve True si l es vacia -} */
bool is_empty(list l) {
    return (l->size == 0);
}

/* {- PRE: not is_empty() -} */
/* {- devuelve el primer elemento de la lista l -} */
elem head(list l) {
    assert(!is_empty(l));

    return l->elems[0];
}

/* {- PRE: not is_empty() -} */
/* {- elimina el primer elemento de la lista l -} */
list tail(list l) {
    assert(!is_empty(l));
    for (int i = 0; i < l->size; i++) {
        //aux = l->elems[i+1];
        l->elems[i] = l->elems[i+1];
    }
    l->size--;
    return l;
}

/* {- agrega el elemento e al final de la lista -} */
list addr(list l, elem e) {
    assert(l->size <= MAX_LENGTH-1);

    l->size++;
    l->elems[l->size-1] = e;

    return l;
}

/* {- devuelve la cantidad de elementos de la lista l -} */
int length(list l) {

    return l->size;
}

/* {- agrega al final de l todos los elementos de IO en el mismo orden} */
//No need to use malloc because is a list with another list
list concat(list l, list l0) {
    assert(l->size + l0->size <= MAX_LENGTH);

    if (is_empty(l)) {
        for (int i = 0; i < l0->size; i++) {
            l->size = l0->size;
            l->elems[i] = l0->elems[i];
        }
    } else if (l->size + l0->size <= MAX_LENGTH) {
        l->size = l->size + l0->size;
        for (int i = l->size - l0->size, j = 0; i < l->size; i++, j++) {
            l->elems[i] = l0->elems[j];
        }
    }

    return l;
}

/* {- PRE: n < length(l) -} */
/* {- devuelve el n-esimo elemento de la lista -} */
elem index(list l, int n) {
    assert(n < length(l));

    return l->elems[n];
}

/* {- deja en l solo los primeros n elementos eliminando el resto -} */
list take(list l, int n) {
    if (n > length(l))
        l->size = length(l);
    else
        l->size = n;

    return l;
}

/* {- elimina los primeros n elementos de la lista l -} */
list drop(list l, int n) {
    if (n > l->size)
        l->size = 0;
    else {
        l->size = l->size - n;
    }

    if (n > 0) {
        for (int i = 0; i < l->size+n; i++) {
            l->elems[i] = l->elems[i+1];
        }
    }

    return l;
}

/* {- copia todos los elementos de la lista l1 en la nueva lista l2 -} */
list copy_list(list l) {
    list l2 = malloc(sizeof(struct _list));
    l2->size = l->size;
    for (int i = 0; i < l->size; i++) {
        l2->elems[i] = l->elems[i];
    }

    return l2;
}



/* Destroy */
/* {- libera memoria en caso que sea necesario -} */
void destroy_list(list l) {
    if (l != NULL) {
        free(l);
    }
}

