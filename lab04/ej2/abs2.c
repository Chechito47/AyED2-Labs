#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    /*if (x >= 0)
        *y = x;
    else
        *y = -x;
    */
   *y = (x >= 0)? x : -x; 
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a=-10;

    absolute(a, &res);
    printf("%d\n", res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
    b)
    Now the return value is 10.
    With pointers just pass the memory direction of res as argument to absolute,
        so in absolute *y is the memory address of res. Then if x is pos or neg,
        using *y we changes the value of that memory address.



    c)
    *y is an out parameter beacause is only used on the left side of the
        assignations. Also note that we don't read the value inside, just use
        it memory address.

    C has all the parameters mentioned:
        in: values that we read, example: y = x where x is IN
        out: values where we write, example: y = x where y is OUT
        in/out: only possible with pointers, example: *y = &y
*/