#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    int dado;
    struct sNodo* prox;
} Nodo;

typedef struct sLista
{
    struct sNodo* head;
    struct sNodo* tail;
    int size; 
} Lista;

// Prototipação
Nodo* criaNodo(int);
Lista* criaLista();
int listaVazia(Lista*);
void tratarErro(int);
void inserir(Lista*, Nodo*, int);
void remover(Lista*, Nodo*);
void escreveLista(Lista*);
Nodo* buscar(Lista*, int);

int main(){
    Lista* minhaLista;
    minhaLista = criaLista();
    
    remover(minhaLista, buscar(minhaLista, 15));
    inserir(minhaLista, NULL, 10);
    inserir(minhaLista, minhaLista->head, 15);
    inserir(minhaLista, minhaLista->tail, 25);
    inserir(minhaLista, NULL, 5);
    inserir(minhaLista, minhaLista->tail, 35);
    escreveLista(minhaLista);
    inserir(minhaLista, buscar(minhaLista, 70), 60);
    escreveLista(minhaLista);
    inserir(minhaLista, buscar(minhaLista, 70), 20);
    escreveLista(minhaLista);
}

Nodo* criaNodo(int dado){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if(novo!=NULL){
        novo->dado=dado;
        novo->prox=NULL;
    }

    return novo;
}

Lista* criaLista(){
    Lista* lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if(lista!=NULL){
        lista -> head = NULL;
        lista -> tail = NULL;
        lista -> size = 0;
    }

    return lista;
}

int listaVazia(Lista* lista){
    if(lista->size==0)
        return 1;
    return 0;
}

void tratarErro(int erro){
    if (erro == -1)
        printf("\nLista vazia!(Underflow)\n");
    else if (erro == -2)
        printf("\nFim da lista!\n");
}

void inserir(Lista* lista, Nodo* pivo, int dado){
    Nodo* novo_elemento;
    novo_elemento=criaNodo(dado);
    if(pivo==NULL){
        if(listaVazia(lista))
            lista->tail=novo_elemento;
        novo_elemento->prox=lista->head;
        lista->head=novo_elemento;
    }else{
        if(pivo->prox==NULL)
            lista->tail=novo_elemento;
        
        novo_elemento->prox=pivo->prox;
        pivo->prox=novo_elemento;
    }
    lista->size++;
}

void remover(Lista* lista, Nodo* pivo){
    
    Nodo* elemento_antigo;
    if(listaVazia){
        tratarErro(-1); // Lista Vazia
    }
    if(pivo==NULL){
        elemento_antigo=lista->head;
    
        lista->head=lista->head->prox;
        if(lista->head==NULL)
            lista->tail==NULL;
    }else{
        if(pivo->prox==NULL)
            tratarErro(-2); // Fim da lista
        
        elemento_antigo=pivo->prox;
        pivo->prox=pivo->prox->prox;
        if(pivo->prox==NULL)
            lista->tail=pivo;
    }
    free(elemento_antigo);
    lista->size--;
}

void escreveLista(Lista* lista){
    Nodo* nodo;

    if (listaVazia(lista)){
        tratarErro(-1);
    }
    else {
        printf("\nElementos da lista: \n");
        nodo = lista->head;
        while (nodo!=NULL){
            printf("%i, ", nodo->dado);
            nodo = nodo->prox;
        }
    }
}

Nodo* buscar(Lista* lista, int dado){
    Nodo* nodo;
    if(listaVazia(lista)){
        tratarErro(-1);
    }else{
        nodo=lista->head;
        while(nodo!=NULL){
            if(nodo->dado==dado){
                return nodo;
            }
            nodo=nodo->prox;
        }
        return NULL;
    }
}