#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

/*
 * Define size of the board and cells quantity
 */
#define SIZE 4
#define CELL_MAX (SIZE * SIZE - 1)

/*
 * Print the format for the cells
 * \t is used to print a tab.
 */
void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

/*
 * Print the board content
 * First print separations
 * Then print the content of the board SIZExSIZE starting by the columns
 * Lastly, print separations
 */
void print_board(char board[SIZE][SIZE])
{
    int cell = 0;

    print_sep(SIZE);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}

/*
 * Obtains a winner between 2 players
 * Iterates checking a for any win conditions
 * Rows: down ↓
 * Columns: right →
    [0][0] [0][1] [0][2]
    [1][0] [1][1] [1][2]
    [2][0] [2][1] [2][2]
 * Win conditions:
   by column:
   X X X X    - - - -    - - - -    - - - -
   - - - -    X X X X    - - - -    - - - -
   - - - -    - - - -    X X X X    - - - -
   - - - -    - - - -    - - - -    X X X X
   board[0][0] == X && board[0][1] == X && board[0][2] == X && board[0][3] == X
   board[1][0] == X && board[1][1] == X && board[1][2] == X && board[1][3] == X
   board[2][0] == X && board[2][1] == X && board[2][2] == X && board[2][3] == X
   board[3][0] == X && board[3][1] == X && board[3][2] == X && board[3][3] == X

   by row:
   X - - -    - X - -    - - X -    - - - X
   X - - -    - X - -    - - X -    - - - X
   X - - -    - X - -    - - X -    - - - X
   X - - -    - X - -    - - X -    - - - X
   board[0][0] == X && board[1][0] == X && board[2][0] == X && board[3][0] == X
   board[0][1] == X && board[1][1] == X && board[2][1] == X && board[3][1] == X
   board[0][2] == X && board[1][2] == X && board[2][2] == X && board[3][2] == X
   board[0][3] == X && board[1][3] == X && board[2][3] == X && board[3][3] == X

   by diagonal:
   X - - -    - - - X
   - X - -    - - X -
   - - X -    - X - -
   - - - X    X - - -
   board[0][0] == X && board[1][1] == X && board[2][2] == X && board[3][3] == X
   board[0][3] == X && board[1][2] == X && board[2][1] == X && board[3][0] == X

   by diagonal 5x5 2:
        - - - - X
        - - - X -
        - - X - -
        - X - - -
        X - - - -
    board[0][3] && board[1][2] && board[2][1] && board[3][0]
    board[0][4] && board[1][3] && board[2][2] && board[3][1] && board[4][0]
    => board[i][j] where i++; j--
 */
char get_winner(char board[SIZE][SIZE])
{
    char winner = '-';

    /*
     * Get winner by column
     * Iterates comparing all elements the column(right) on the same row(down).
     * Compares the first element of the column with the other ones
     * If any is not equal then flag=false
     * After comparing one column check if we get a winner
     *      (Winner is determined by the status of flag
     *          and if board with the column value is different than '-')
     *      (We use 0 because all column is supposed to be equal if it's winner)
     * If the column has not a winner then check the next one until the last one
    */
    for (int row = 0; row < SIZE && winner == '-'; ++row) {
        bool aux = true;
        for (int column = 1; column < SIZE && winner == '-'; ++column) {
            if (board[row][0] != board[row][column])
                aux = false;
        }
        if (aux && board[row][0] != '-') {
            winner = board[row][0];
        }
    }

    /*
     * Get winner by row
     * First iterate by column, then by rows
     * Note the need to change the [][]
     * The rest IDEM than the last one.
     */
    for (int column = 0; column < SIZE && winner == '-'; ++column) {
        bool aux = true;
        for (int row = 1; row < SIZE && winner == '-'; ++row) {
            if (board[0][column] != board[row][column])
                aux = false;
        }
        if (aux && board[0][column] != '-') {
            winner = board[0][column];
        }
    }

    /*
     * Get winner by diagonal 1
     * Diagonal starting from the left
     * Note that array positions are equal.
     * Also note that k cicle is only to ensure the context,
     * avoiding call if(aux && board[0][0]) with values of other context.
     */
    for (int k = 0; k < SIZE && winner == '-'; ++k) {
        bool aux = true;
        for (int i = 1; i < SIZE && winner == '-'; ++i) {
            if (board[0][0] != board[i][i])
                aux = false;
        }
        if (aux && board[0][0] != '-')
            winner = board[0][0];
    }

    /*
     * Get winner by diagonal 2
     * Diagonal starting from the right
     * Note that we start from top right= [0][SIZE-1] to bottom left [SIZE-1][0]
     * In the middle it does [i][j] with i++ and j-- until hit the bound values
     * So we compere [0][SIZE-1] with the next one which is [1][SIZE-1]
     * iterating with that last values using variables i and j.
     * Also note that k cicle is only to ensure the context,
     * avoiding call if(aux && board) with values of other context.
     */
    for (int k = 0; k < SIZE && winner == '-'; ++k) {
        bool aux = true;
        int j = SIZE - 2;
        for (int i = 1; i < SIZE && winner == '-'; ++i) {
            if (board[0][SIZE-1] != board[i][j])
                aux = false;
            j--;
        }
        if (aux && board[0][SIZE-1] != '-')
            winner = board[0][SIZE-1];
    }

    return winner;
}

/*
 * Check for a free cell
 * Iterates checking for a '-'
 * Used to end the game if there are no more free cells
 */
bool has_free_cell(char board[SIZE][SIZE])
{
    bool free_cell=false;
    
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            if ((board[row][column]) == '-')
                free_cell = true;
        }
    }
    return free_cell;
}

/*
 * Main function
 * Does a lot of things
 * Call a function to print the content of the board
 * Check if the game is not over and ask to another entry and does it's checks
 * get_winner is called eveytime we made an entry.
 */

int main(void)
{
    printf("TicTacToe:\n");

    char board[SIZE][SIZE];
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            board[row][column] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / SIZE;
            int colum = cell % SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
