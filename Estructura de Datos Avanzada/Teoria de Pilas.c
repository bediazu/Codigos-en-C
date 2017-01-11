#include <stdio.h>
#include <stdlib.h> //Libreria siempre necesaria.

//Creacion del nodo.
typedef struct Nodo{
  int dato; //Lo que almacenara el nodo.
  struct Nodo* siguiente; //Apuntador hacia un siguiente nodo.
}Nodo; //En las demas funciones la llamo como nodo.

void Agregar_dato_pila(Nodo**,const int);
void Mostrar_ultimo_dato(const Nodo*);
void Mostrar_penultimo_dato(const Nodo*);
void Mostrar_n_dato(Nodo*,const int);

void Sacar_dato_pila(Nodo**,int*);

int main(){
  //Como la pila se compone de nodos. Creo que primer nodo (La base)
  Nodo* Pila = (Nodo*)malloc(sizeof(Nodo)); //Inicializaciones y dimension en una sola linea.
  if(Pila==NULL){
    printf("Error en la asignacion del nodo.");
    return 1;
  }
  Pila->dato=0; //El primer valor.
  int opcion=0;
  int dato;
  do{
    printf("Ingrese el valor a agregar al nodo: ");
    scanf("%i",&dato);
    Agregar_dato_pila(&Pila,dato);
    printf("Agregar mas valores? [1/0] ");
    scanf("%i",&opcion);
  }while(opcion==1);
  Mostrar_ultimo_dato(Pila);
  Mostrar_penultimo_dato(Pila);
  int n;
  printf("Ingrese la posicion a buscar: ");
  scanf("%i",&n);
  Mostrar_n_dato(Pila,n);
  return 0;
}

void Agregar_dato_pila(Nodo** Pila,const int dato){
  Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
  if(nuevo_nodo==NULL){
    printf("Error en la asignacion del nodo.");
    exit(1);
  }
  nuevo_nodo->dato=dato;
  nuevo_nodo->siguiente=(*Pila);
  (*Pila)=nuevo_nodo; //Por eso el traspaso es por referencia ya que altero toda la variable pila.
}

void Mostrar_ultimo_dato(const Nodo* Pila){
    printf("El valor ingresado es: %i\n",Pila->dato);
}

void Mostrar_penultimo_dato(const Nodo* Pila){
  printf("El valor ingresado es: %i\n",Pila->siguiente->dato);
}

void Mostrar_n_dato(Nodo* Pila,const int n){
    for(int i=0;i<n;i++){
      Pila=Pila->siguiente;
    }
    printf("Dato: %i\n",Pila->dato);
}

void Sacar_dato_pila(Nodo** Pila, int* n){
    Nodo* aux=(*Pila);
    (*n)=aux->dato;
    (*Pila)=aux->siguiente;
    free(aux);
}
