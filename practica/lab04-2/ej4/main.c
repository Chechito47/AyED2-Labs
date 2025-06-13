#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    int i = 3;
    Node *mylist = NULL;
    mylist = malloc(sizeof(Node));
    if (!mylist) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    Node *a_node = mylist;
    i--;

    while (i > 0) {
        a_node->data = i*10;
        a_node->next = malloc(sizeof(a_node->next));
        if (!a_node->next) {
            perror("malloc error");
            exit(EXIT_FAILURE);
        }
        a_node = a_node->next;
        i--;
    }

    a_node->data = 0;
    a_node->next = NULL;
    a_node = NULL;

    return mylist;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    if (!xs) {
        perror("xs vacia");
        exit(EXIT_FAILURE);
    }

    Node *a_node = xs->next;
    free(xs);
    return a_node;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
