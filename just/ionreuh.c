#include <stdio.h>

void multiplyPolynomials(const int polyA[], const int polyB[], int res[],
                         int lenA, int lenB) {
    for (int i = 0; i < lenA + lenB - 1; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < lenA; i++) {
        for (int j = 0; j < lenB; j++) {
            res[i + j] += polyA[i] * polyB[j];
        }
    }
}

int main() {
    int dgA, dgB;

    printf("Enter highest degree of fst and sec polynomial: ");
    scanf("%d %d", &dgA, &dgB);

    int szA = dgA + 1;
    int szB = dgB + 1;
    int szR = dgA + dgB + 1;

    int fst[szA], sec[szB], prod[szR];

    printf("Enter coefficients of fst polynomial (lowest to highest degree):\n");
    for (int i = 0; i < szA; i++) {
        scanf("%d", &fst[i]);
    }

    printf("Enter coefficients of sec polynomial (lowest to highest degree):\n");
    for (int i = 0; i < szB; i++) {
        scanf("%d", &sec[i]);
    }

    mulpoly(fst, sec, prod, szA, szB);

    printf("Resultant polynomial coefficients:\n");
    for (int i = 0; i < szR; i++) {
        printf("%d ", prod[i]);
    }
    printf("\n");

    return 0;
}
/*
Input:
Enter highest degree of first and second polynomial: 3 2
Enter coefficients of first polynomial (lowest to highest degree):
1 2 3 4
Enter coefficients of second polynomial (lowest to highest degree):
5 6 7

Expected Output:
Resultant polynomial coefficients:
5 16 34 52 45 28
Input:
Enter highest degree of first and second polynomial: 0 3
Enter coefficients of first polynomial (lowest to highest degree):
3
Enter coefficients of second polynomial (lowest to highest degree):
1 0 2 4

Expected Output:
Resultant polynomial coefficients:
3 0 6 12
Input:
Enter highest degree of first and second polynomial: 0 0
Enter coefficients of first polynomial (lowest to highest degree):
9
Enter coefficients of second polynomial (lowest to highest degree):
5

Expected Output:
Resultant polynomial coefficients:
45
Input:
Enter highest degree of first and second polynomial: 2 2
Enter coefficients of first polynomial (lowest to highest degree):
0 0 0
Enter coefficients of second polynomial (lowest to highest degree):
1 2 3

Expected Output:
Resultant polynomial coefficients:
0 0 0 0 0
*/