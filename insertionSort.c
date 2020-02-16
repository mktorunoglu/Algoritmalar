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
    int dizi[5] = {77777, 7777, 777, 77, 7};
    insertionSort(dizi, 5);
    for(int i = 0; i < 5; i++){
        printf("%d, ", dizi[i]);
    }  
}

