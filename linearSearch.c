#include <stdio.h>

int linearSearch(int A[], int n, int a){
    int indis = 0;
    for(int j =0; j <n; j++){
        if(A[j] == a){
            indis = j;
        }
    }
    return indis;
}

void main(){
    int dizi[100000];
    for(int j =0; j <100000; j++){
        dizi[99999 -j] =j;
    }
    printf("%d\n", linearSearch(dizi, 100000, 0));
}

