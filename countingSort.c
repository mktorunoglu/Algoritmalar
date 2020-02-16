#include <stdio.h>
void countingSort(int A[], int B[], int k){
    int C[k], j;
    for(j = 0; j < k; j++){
        C[j] = 0;
    }
    for(j = 0; j < 8; j++){
        C[A[j]]++;
    }
    for(j = 1; j < k; j++){
        C[j] += C[j - 1];
    }
    for(j = 7; j >= 0; j--){
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}
void main(){
    int dizi1[8] = {3, 5, 7, 9, 3, 5, 7, 8};
    int dizi2[8];
    countingSort(dizi1, dizi2, 10);
    printf("Counting Sort ile siralanmis dizi: ");
    for(int m = 0; m < 8; m++){
        printf("%d ", dizi2[m]);
    }
}

