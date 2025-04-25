length, arreglo de entrada, resultado esperado:
        { 1, {red}, {red} },
        { 1, {white}, {white} },
        { 1, {blue}, {blue} },
        { 2, {red, red}, {red, red} },
        { 2, {red, white}, {red, white} },
        { 2, {white, red}, {red, white} },
        { 2, {red, blue}, {red, blue} },
        { 2, {blue, red}, {red, blue} },
        { 2, {white, blue}, {white, blue} },
        { 2, {blue, white}, {white, blue} },
        { 6, {blue, red, white, white, blue, red}, {red, red, white, white, blue, blue} },

1: i=0, j=0, k=0
    j<=k si
    a[0] == red si 
        swap(a, i, j) -> no cambia nada
        i=1, j=1
    1<=0 no termino => {red} bien

2: i=0, j=0, k=0
    0<=0 si
    a[0] == red no
    a[0] == white si
        swap(a, j, k) -> no cambia nada
        k=-1
    0<=-1 no => {white}

3: IDEM

4:i=0, j=0, k=1
    0 <= 1 si
        a[0] == blue si
            swap(a, i, j)
            {blue, blue} -> no cambio nada
            i=1, j=1
    1 <= 1 si
        a[1] == blue si
            swap(a, i, j)
            {blue, blue} -> no cambio nada
            i=2, j=2
    2 <= 1 no

5, 6: IDEM

7: { 2, {red, blue}, {red, blue} },
i=0, j=0, k=1
0 <= 1 si
    a[0] == red si
        swap(a, i, j)
        {red, blue} -> no cambio nada
        i=1, j=1
1 <= 1 si 
    a[1] == red no
    a[1] == white no
    a[1] == blue si
        j=2
2 <= 1 no termino
{red, blue}

8: { 2, {blue, red}, {red, blue} },
i=0, j=0, k=1
0 <= 1 si
    a[0] == red no
    a[0] == blue si
        swap(a, j, k)
        {red, blue}
        k=0
0 <= 0 si
    a[0] == red si
        swap(a, i, j)
        {red, blue} -> no cambio nada
        i=1, j=1
1 <= 0 no

9: IDEM

10: { 6, {blue, red, white, white, blue, red}, {red, red, white, white, blue, blue} },
i=0, j=0, k=5
0 <= 5 si
    a[0] == red no
    a[0] == blue si
        swap(a, j, k)
        {red, red, white, white, blue, blue}
        k=4
0 <= 4 si
    a[0] == red si
        swap(a, i, j)
        {red, red, white, white, blue, blue} -> no cambio nada
        i=1, j=1
1 <= 4 si
    a[1] == red si
        swap(a, i, j)
        {red, red, white, white, blue, blue} -> no cambio nada
        i=2, j=2
2<= 4 si
    a[2] == red no
    a[2] == blue no
    a[2] == white si
        j=3
3<=4 si
    a[3] == red no
    a[3] == blue no
    a[3] == white si
        j=4
4 <=4 si 
    a[4] == red no
    a[4] == blue si
        swap(a, j, k)
        {red, red, white, white, blue, blue} -> no cambia nada
        k=3
4 <= 3 no