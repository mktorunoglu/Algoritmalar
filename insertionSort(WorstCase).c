#include <stdio.h>

void insertionSort(int A[], int n){
    for(int j = 1; j < n; j++){
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void main(){
    int A[20000];
    int j = 0;
    for(int i = 19999; i >= 0; i--){
        A[j] = i;
        j++;
    }
    insertionSort(A, 20000);
    for(int i = 0; i < 20000; i++){
        printf("%d, ", A[i]);
    }  
}

