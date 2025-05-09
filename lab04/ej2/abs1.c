#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0)
        y = x;
    else
        y = -x;
}

int main(void) {
    int a=0, res=0;
    a=-10;

    absolute(a, res);
    printf("%d\n", res);

    return EXIT_SUCCESS;
}

/* This program return 0
   On the other hand, the theory algorithm return 10.
   That's because how proc works.

   In the theory algorithm we call to the proc absoulte(a, res) with -10 and y
   Then the proc absolute enter the else case and makes y = 10 (y is res), so 
   now res=10
   
   The values are not the same, because in the theory we can use proc to change
   variables value independently of their "world", in c we can't, the y=10 we
   made only lives in absolute.

   In orden to change this we can make a int instead a void function to return
   the absolute value or use a pointer *y
*/
