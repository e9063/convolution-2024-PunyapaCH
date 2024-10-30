#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <omp.h>

int main(){

    omp_set_num_threads(8);

    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *FF = malloc(sizeof(int) * NF);

    int NR = NA - NF + 1;
    int *R = malloc(sizeof(int) * NR);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }

    for (int i = 0 ; i < NF ; i++) {
        FF[i] = F[NF-i-1];
    }

    // ---- end input and malloc----

    // implement here

    clock_t start = clock();

    #pragma omp parallel for
    for (int k = 0; k < NR; k++) {
        int sum = 0;
        for (int i = 0; i < NF; i++) {
            sum += A[k + i] * FF[i];
        }
        R[k] = sum;
    }

    clock_t end = clock();

    // Compute elapsed time in seconds
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // ---- Output the result ----
    for (int i = 0; i < NR; i++) {
        printf("%d\n", R[i]);
    }

    // ---- Output the timing info to stderr ----
    // fprintf(stderr, "Parallel Time (seconds): %f\n", elapsed_time);

    // ---- End output ----

    // ---- free memory ----
    free(FF);
    free(F);
    free(A);
    free(R);
    // ---- end free ----
    return 0;
}
