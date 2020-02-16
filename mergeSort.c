#include <stdio.h>
void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    int i, j, k;
    for(i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }
    i = 0;
    j = 0;
    k = p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int main(){
    int dizi[10]= {3, 81, 11, 16, 43, 6, 4, 26, 8, 1};
    mergeSort(dizi, 0, 9);
    printf("Merge Sort ile siralanmis dizi: ");
    for(int m = 0; m < 10; m++){
        printf("%d ", dizi[m]);
    }
    return 0;
}

