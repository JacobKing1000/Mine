#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], c[3][3], i, j, k;

    // Reading matrix a
    printf("Enter the first matrix (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Reading matrix b
    printf("Enter the second matrix (3x3):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initializing matrix c to 0
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Printing the resultant matrix
    printf("\nResultant matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("\t%d", c[i][j]);
        }
        printf("\n");
    }

    printf("By Chander Kant (DS) M-24\n");
    return 0;
}
