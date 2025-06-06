#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

/* Constructors */
/* {- crea una lista vacia -} */
list empty() {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    l->start = 0;
    return l;
}

/* {- agrega el elemento al comienzo de la lista -} */
list addl(elem e, list l) {
    if (l->size >= MAX_LENGTH)
        return l;

    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;

    l->size++;
    l->a[l->start] = e;

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

    return l->a[l->start];
}

/* {- PRE: not is_empty() -} */
/* {- elimina el primer elemento de la lista l -} */
list tail(list l) {
    assert(!is_empty(l));
    l->size--;
    l->start = (l->start + 1) % MAX_LENGTH;

    return l;
}

/* {- agrega el elemento e al final de la lista -} */
list addr(list l, elem e) {
    int index = (l->start + l->size) % MAX_LENGTH;
    l->size++;
    l->a[index] = e;

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

    for (int i = 0; i < l0->size; i++) {
        int index_l0 = (l0-> start + i) % MAX_LENGTH;    //position of l0 elems
        int index_l = (l->start + l->size) % MAX_LENGTH; //End of l

        l->size++;
        l->a[index_l] = l0->a[index_l0];
    }

    return l;
}

/* {- PRE: n < length(l) -} */
/* {- devuelve el n-esimo elemento de la lista -} */
elem index(list l, int n) {
    assert(n < length(l));
    int index = (l->start + n) % MAX_LENGTH;
    return l->a[index];
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
    if (n >= l->size)
        l->size = 0;
    else
        l->size = l->size - n;

    l->start = (l->start + n) % MAX_LENGTH;

    return l;
}

/* {- copia todos los elementos de la lista l1 en la nueva lista l2 -} */
list copy_list(list l) {
    list l2 = malloc(sizeof(struct _list));
    l2->size = l->size;
    l2->start = l->start;
    for (int i = 0; i < l->size; i++) {
        int index = (l->start + i) % MAX_LENGTH;
        l2->a[index] = l->a[index];
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

