#include <stdio.h>
int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    int key;
    for(int j = p; j <= r - 1; j++){
        if(A[j] <= x){
            i++;
            key = A[i];
            A[i] = A[j];
            A[j] = key;
        }
    }
    key = A[i + 1];
    A[i + 1] = A[r];
    A[r] = key;
    return i + 1;
}
void quickSort(int A[], int p, int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
int main(){
    int dizi[8]= {3, 5, 7, 9, 1, 2, 4, 6};
    quickSort(dizi, 0, 7);
    printf("Quick Sort ile siralanmis dizi: ");
    for(int m = 0; m < 8; m++){
        printf("%d ", dizi[m]);
    }
    return 0;
}

