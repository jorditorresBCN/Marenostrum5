#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 4

double h_a[N][N], h_b[N][N], h_c[N][N];
 
void cleanMatrices(int nrows, int ncols, double *M) {
    for (int i = 0; i < nrows; i ++) {
        for (int j = 0; j < ncols; j++){
            M[i*ncols+j] = 0;
    }
    }
}

void iniMatrices(int nrows, int ncols, double *M) {
    for (int i = 0; i < nrows; i ++) {
        for (int j = 0; j < ncols; j++){
            M[i*ncols+j] = 1;
    }
    }
}

void printMatrix(int nrows, int ncols, double *M) {
    printf("\n ******** PRINT MATRIX ******** \n");
    for (int i = 0; i < nrows; i ++) {
        for (int j = 0; j < ncols; j++){
            printf("| %f |", M[i*ncols+j]);
        }
    printf("\n");
    }
    printf("\n ******** END ******* \n");
}

int main() {
   
    iniMatrices(N, N, (double *) h_a);
    iniMatrices(N, N, (double *) h_b);
    cleanMatrices(N, N, (double *) h_c);
    printf("Matrix A\n");
    printMatrix(N, N, (double *) h_a);
    printf("Matrix B\n");
    printMatrix(N, N, (double *) h_b);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
                h_c[i][j] += h_a[i][k] * h_b[k][j];
            }
        }
    }

    printMatrix(N, N, (double *) h_c); 

    return 0;
}
