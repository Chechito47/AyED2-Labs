/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 * 
 * @details Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.

 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    //Declarate 2 pointers, one per type
    int *aux_int = NULL;
    person_t *aux_person = NULL;

    //Point to x direction and change the value of that direction
    aux_int = &x;
    *aux_int = 9;

    //Point to a[1] direction and change the value of that direction
    aux_int = &a[1]; //aux_int = a + 1. Podrias haber hecho *(a + 1) = 42
    *aux_int = 42;

    //Point to m direction and change the value of the components of that direction
    aux_person = &m;
    aux_person->age=100;
    aux_person->name_initial='F';

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

