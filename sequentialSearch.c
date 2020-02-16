#include <stdio.h>

int sequentialSearch(int A[], int n){
    int enKucuk =A[0];
    for(int j =1; j <n; j++){
        if(enKucuk >A[j]){
            enKucuk =A[j];
        }
    }
    return enKucuk;
}

void main(){
    int dizi[10000];
    for(int j =0; j <10000; j++){
        dizi[j] =j;
    }
    printf("%d\n", sequentialSearch(dizi, 10000));
}

