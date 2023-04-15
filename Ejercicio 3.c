#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------ESTRUCTURAS------------//
typedef struct Labor{
    int TareaID;
    char *Descripcion;
    int duration;
}tarea;
//--------NODO------------//
typedef struct Nodo {
    tarea Tareas;
    struct Nodo* siguiente;
}node;

//--------------FUNCIONES-----------//

node* crearLista(){
    return NULL;
}

node* crearNodo(tarea Pendiente){
    node* nodoNuevo=(node*)malloc(sizeof(nodoNuevo*));
    nodoNuevo->Tareas=Pendiente;
    nodoNuevo->siguiente=NULL;
    return nodoNuevo;
}

void agregarNodo(node** cabecera,tarea Pendiente){
    node* nodoNuevo=(node*)malloc(sizeof(nodoNuevo*));
    nodoNuevo->siguiente = *cabecera;
    *cabecera = node;
}

void eliminarNodo (node** cabecera, tarea Pendiente) {
    node* temporal = *cabecera;
    node* previo = *cabecera;
    
}