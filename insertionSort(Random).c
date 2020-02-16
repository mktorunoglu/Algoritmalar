#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argcv[]){
    int diziBoyutu = atoi(argcv[1]);
    int dizi[diziBoyutu];
    srand(time(NULL)); 

    for(int d = 0; d < diziBoyutu; d++){
        dizi[d] = rand();
    }

    for(int j = 1; j < diziBoyutu; j++){
        int key = dizi[j];
        int i = j-1;
        while(i >= 0 && dizi[i] > key){
            dizi[i+1] = dizi[i];
            i = i-1;
        }
        dizi[i+1] = key;
    }

    printf("Siralanmis dizi: ");
    for(int k = 0; k < diziBoyutu; k++){
        printf("%d ", dizi[k]);
    }
    return 0;
}

