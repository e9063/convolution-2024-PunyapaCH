#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Parallel

int main(){

    omp_set_num_threads(8);

    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    int *FF = malloc(sizeof(int) * NF);

    int NR = NA - NF + 1;
    
    int *arr = malloc(sizeof(int) * NR);
    
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

    #pragma omp parallel for
    for (int k = 0; k < NR; k++) {
        int sum = 0;
        for (int i = 0; i < NF; i++) {
            sum += A[k + i] * FF[i];
        }
        arr[k] = sum;
    }

    // Print the result 
    for (int i = 0; i < NR; i++) {
        printf("%d\n", arr[i]);
    }


    // ---- free memory ----
    free(FF);
    free(F);
    free(A);
    free(arr);

    // ---- end free ----
    return 0;
}