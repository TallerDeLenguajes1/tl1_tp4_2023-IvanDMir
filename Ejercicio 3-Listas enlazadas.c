#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------ESTRUCTURAS------------//
typedef struct Labor{
    int TareaID;
    char *Descripcion;
    int duracion;
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
    node* nodoNuevo=(node*)malloc(sizeof(nodoNuevo));
    nodoNuevo->Tareas=Pendiente;
    nodoNuevo->siguiente=NULL;
    return nodoNuevo;
}

void agregarNodo(node** cabecera,tarea Pendiente){
    node* nodoNuevo=(node*)malloc(sizeof(nodoNuevo));
    nodoNuevo->siguiente = *cabecera;
    *cabecera = nodoNuevo;
}

void eliminarNodo (node** cabecera, tarea Pendiente) {
    node* actual = *cabecera;
    node* previo = *cabecera;
    while(actual !=NULL &&
            actual->Tareas.TareaID != Pendiente.TareaID &&
            actual->Tareas.duracion != Pendiente.duracion &&
            strcmp(actual->Tareas.Descripcion,Pendiente.Descripcion)){
            previo = actual;
            actual= actual->siguiente;
            }
        if (actual != NULL){
            previo=actual->siguiente;
           *cabecera = previo;
        }
        else {
            previo->siguiente = actual ->siguiente;
        }
        free(actual);

}

void CargarTareas(node** cabecera){
    char* buffer =malloc(100*sizeof(*buffer));
    tarea actual;
    int opciones=1;
    for (int i=0;opciones;i++){
        fflush(stdin);
        printf("---------Tarea n %d------\n",i+1);
        actual.TareaID=i+1;
        puts("Ingrese la descripcion de la Tarea");
        gets(buffer);
        fflush(stdin);
        actual.Descripcion=malloc(strlen(buffer)+1);
        strcpy(actual.Descripcion,buffer);
        puts("Ingrese la duracion de la tarea");
        scanf("%d",&actual.duracion);
        fflush(stdin);
        agregarNodo(cabecera,actual);
        puts("Ingrese 1 si quiere volver a agregar una tarea, si no 0");
        scanf("%d",&opciones);
    }
    free(buffer);
}

void MostrarTareasPendientes(node* cabecera){
    if(cabecera !=NULL){
        puts ("Tareas A realizar");
        node*  actual =cabecera;
        for (int i=0;actual;i++){
                printf("---------Tarea n %d------\n",i+1);
                printf("ID: %d \n",actual->Tareas.TareaID);
                printf("Descripcion : %s \n",actual->Tareas.Descripcion);
                printf("Duracion: %d \n",actual->Tareas.duracion);
                actual=actual->siguiente;
            }
        }
    } 
void MostrarTareasRealizadas(node* cabecera){
    if(cabecera !=NULL){
        puts ("Tareas Realizadas");
        node*  actual =cabecera;
        for (int i=0;actual;i++){
                printf("---------Tarea n %d------\n",i+1);
                printf("ID: %d \n",actual->Tareas.TareaID);
                printf("Descripcion : %s \n",actual->Tareas.Descripcion);
                printf("Duracion: %d \n",actual->Tareas.duracion);
                actual=actual->siguiente;
            }
        }
    } 

void terminarTareas(node** pendientes, node** completadas){
    int terminado;
    node* actual = *pendientes;
    while( actual != NULL){
        puts("Si se realizo la tarea poner 1, si no 0");
        if(terminado=1){
            agregarNodo(completadas,actual->Tareas);
            eliminarNodo(pendientes,actual->Tareas);
        }
        actual=actual->siguiente;
    }
}

void ID(node** todas){
    int id;
    node* actual = *todas;
    puts("-------Ingrese la ID a buscar-----");
    scanf("%d",&id);
    while(actual != NULL){
        if(actual->Tareas.TareaID == id){
            printf("ID: %d \n",actual->Tareas.TareaID);
            printf("Descripcion : %s \n",actual->Tareas.Descripcion);
            printf("Duracion: %d \n",actual->Tareas.duracion);
        }
        actual=actual->siguiente;
    }
}

void palabra(node** todas){
    char* palabra = malloc(20*sizeof(char));
    puts("Ingrese la palabra clave");
    gets(palabra);
    node* actual = *todas;
    while(actual !=NULL){
        if(strstr(actual->Tareas.Descripcion,palabra)){
            printf("ID: %d \n",actual->Tareas.TareaID);
            printf("Descripcion : %s \n",actual->Tareas.Descripcion);
            printf("Duracion: %d \n",actual->Tareas.duracion);
        }
        actual=actual->siguiente;
    }
    free(palabra);
}

int LiberarMemoria(node** cabecera){
    node* actual= *cabecera;
    node* borrado= *cabecera;
    while(actual != NULL){
        borrado=actual;
        actual=actual->siguiente;
        free(borrado);

    }
    free(cabecera);
}