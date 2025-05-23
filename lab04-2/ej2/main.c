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
    int i = 3; //Nodes quantity
    //Create my_list
    Node *my_list = malloc(sizeof(Node));
    if (!my_list) {
        fprintf(stderr, "malloc error");
        exit(EXIT_FAILURE);
    }

    //Create first node
    Node *a_node = my_list;
    i = i - 1;

    //Create intermediate nodes
    while (i > 0) {
        a_node->data = i * 10;
        a_node->next = malloc(sizeof(Node));
        if (!a_node->next) {
            fprintf(stderr, "malloc error");
            exit(EXIT_FAILURE);
        }

        a_node = a_node->next;
        i--;
    }

    //Last node
    a_node->data = 0;
    a_node->next = NULL;

    return my_list;
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

    show_list(my_list);

    return 0;
}
