#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{ //Estructura NODO.
    int dato;
    struct nodo* siguiente;
}Nodo;

void Agregar_dato_pila(Nodo**,const int);
void Mostrar_Ultimo_Nodo(Nodo*);

int main(){
    Nodo* Pila =NULL;
    //Creacion de la Pila.
    Pila=(Nodo*)malloc(sizeof(Nodo));
    if(Pila==NULL){
      printf("Error en la asignacion de memoria.");
      return EXIT_FAILURE;
    }
    int nuevo_dato;
    int opcion=1;
    do{
        fflush(stdin);
        printf("Ingrese el valor a agregar: ");
        scanf("%i",&nuevo_dato);
        Agregar_dato_pila(&Pila,nuevo_dato); //Traspaso por referencia la pila.
        printf("Desea continuar [1/0]: ");
        fflush(stdin);
        scanf("%i",&opcion);
        if(opcion==0||opcion==0){
            break;
        }
    }while(1);
    printf("Proceso finalizado!\n");
    Mostrar_Ultimo_Nodo(Pila);
    return EXIT_SUCCESS;
}

void Agregar_dato_pila(Nodo** Pila,const int dato){
  Nodo* nuevo_nodo = NULL;
  nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
  if(nuevo_nodo==NULL){
    printf("Error en la asignacion de memoria.");
    exit(EXIT_FAILURE);
  }
  nuevo_nodo->dato=dato;
  nuevo_nodo->siguiente=*Pila;
  *Pila=nuevo_nodo;
  printf("Elemento agregado con exito a la Pila!\n");
}

void Mostrar_Ultimo_Nodo(Nodo* Pila){
    printf("Ultimo Dato ingresado: %i\n",Pila->dato);
}
