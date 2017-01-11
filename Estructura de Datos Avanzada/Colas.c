#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_AGREGAR 15

typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
}Nodo;

void AgregarDato_Cola(Nodo**,Nodo**,int);
void EliminarDato_Cola(Nodo**,Nodo**);

int main(){
    Nodo* FrenteCola=NULL;
    Nodo* FinCola=NULL;
    int dato;
    for(int i=1;i<=CANTIDAD_AGREGAR;i++){
        printf("Ingrese el dato a agregar a la cola: ");
        scanf("%i",&dato);
        AgregarDato_Cola(&FrenteCola,&FinCola,dato);
        printf("Dato agregado con exito!\n");
    }
    for(int i=1;i<=CANTIDAD_AGREGAR;i++){
        printf("Primer elemento en la cola: %i\n",FrenteCola->dato);
        EliminarDato_Cola(&FrenteCola,&FinCola);
        printf("El elemento ha salido de la cola!\n");
    }
    return 0;
}

void AgregarDato_Cola(Nodo** FrenteCola, Nodo** FinCola, int dato){
    Nodo* nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    if(nuevo_nodo==NULL){
        printf("Error en la creacion de un nodo en memoria.");
        exit(1);
    }
    nuevo_nodo->dato=dato;
    if((*FrenteCola)==NULL){
        (*FrenteCola)=nuevo_nodo;
    }
    else{
        (*FinCola)->siguiente=nuevo_nodo;
    }
    (*FinCola)=nuevo_nodo;
}

void EliminarDato_Cola(Nodo** FrenteCola, Nodo** FinCola){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("Error en la creacion de un nodo en memoria.");
        exit(1);
    }
    aux=(*FrenteCola);
    if((*FrenteCola)==(*FinCola)){
        (*FrenteCola)=NULL;
        (*FinCola)=NULL;
    }
    else{
        (*FrenteCola)=(*FrenteCola)->siguiente;
    }
    free(aux);
}
