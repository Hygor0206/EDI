#include <stdlib.h>
#include <stdio.h>

// Prototipação das funções
void insertionSort(int[], int);
void printArray(int[], int);

// Função main com as chamadas das funções
int main(){
    int array[]={12,11,13,5,6};
    int n = sizeof(array) / sizeof(array[0]);

    insertionSort(array, n);
    printArray(array, n);
    return 0;
}

// Função responsável para organizar o algoritmo seguindo a lógica de insertion sort
void insertionSort(int array[], int n){
    int key, j;


    for(int i=1;i<n;i++){
        key=array[i]; // Seleciona a chave para ser comparada
        j=i-1; // Definie o elemento anterior a chave

        // Move o elemento to vetor de posição i-1, que for maior que 
        // chave, para uma posição a frente da sua posição atual
        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=key;
    }
}

// Função para printar o vetor
void printArray(int array[], int n){
    for(int i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}