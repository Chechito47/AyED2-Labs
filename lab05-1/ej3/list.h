#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int list_elem;

//This way is oppaque
typedef struct my_list *list;


/* Constructors */
list empty();
/*
	fun empty() ret l: list of T
	{- crea una lista vacia -}
*/	

list addl(list l, list_elem e);
/*
	proc addl(in e: T, in/out l: List of T)
	{- agrega el elemento al comienzo de la lista -}
*/	



/* Destroy */
list destroy(list l);
/*
	proc destroy(in/out l: List of T)
	{- libera memoria en caso que sea necesario -}
*/



/* Operations */
bool is_empty(list l);
/*
	fun is_empty(l: List of T) ret b: bool
	{- devuelve True si l es vacia -}
*/

/* {- PRE: not is_empty() -} */
list_elem head(list l);
/*
	fun head(l: List of T) ret e: T
	{- devuelve el primer elemento de la lista l -}
	{- PRE: not is_empty() -}
*/
//here is list_elem because there's no polimorf, we only use int values

/* {- PRE: not is_empty() -} */
list tail(list l);
/*
	proc tail(in/out l: List of T)
	{- elimina el primer elemento de la lista l -}
	{- PRE: not is_empty() -}
*/

list addr(list l, list_elem e);
/*
	proc addr(in/out l: List of T, in e: T)
	{- agrega el elemento e al final de la lista -}
*/

unsigned int length(list l);
/*
	fun length(l: List of T) ret n: nat
	{- devuelve la cantidad de elementos de la lista l -}
*/

list concat(list l, list IO);
/*
	proc concat(in/out l: List of T, in IO: List of T)
	{- agrega al final de l todos los elementos de IO en el mismo orden}
*/

/* {- PRE: n < length(l) -} */
list_elem index(list l, unsigned int e);
/*
	fun index(l: List of T, n: nat) ret e: T
	{- devuelve el n-esimo elemento de la lista -}
	{- PRE: length(l) < n -}
*/

list take(list l, unsigned int n);
/*
	proc take(in/out l: List of T, in n: nat)
	{- deja en l solo los primeros n elementos eliminando el resto -}
*/

list drop(list l, unsigned int n);
/*
	proc drop(in/out l: List of T, in n:nat)
	{- elimina los primeros n elementos de la lista l -}
*/

list copy_list(list l);
/*
	fun copy_list(l1: List of T) ret l2: List of T
	{- copia todos los elementos de la lista l1 en la nueva lista l2 -}
*/
#endif