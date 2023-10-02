#include <stdlib.h>
#include <stdio.h>

void insertionSort(int[], int);
void printArray(int[], int);

int main(){
    int array[]={12,11,13,5,6};
    int n = sizeof(array) / sizeof(array[0]);

    insertionSort(array, n);
    printArray(array, n);
    return 0;
}

void insertionSort(int array[], int n){
    int i, key, j;

    for(i=1;i<n;i++){
        key=array[i];
        j=i-1;

        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=key;
    }
}

void printArray(int array[], int n){
    for(int i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}