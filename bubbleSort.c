#include <stdio.h>

void bubbleSort(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i; j++){
            if(A[j] > A[j + 1]){
                int key = A[j];
                A[j] = A[j + 1];
                A[j + 1] = key;
            }
        }
    }
}

void main(){
    int dizi[5] = {5, 4, 3, 2, 1};
    bubbleSort(dizi, 5);
    for(int k = 0; k < 5; k++){
        printf("%d  ", dizi[k]);
    }
}

