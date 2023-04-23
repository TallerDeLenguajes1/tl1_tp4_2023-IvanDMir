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
    int total;
    if(cabecera !=NULL){
        puts ("Tareas A realizar");
        node*  actual =cabecera;
        for (int i=0;actual;i++){
                printf("---------Tarea n %d------\n",i+1);
                printf("ID: %d \n",actual->Tareas.TareaID);
                printf("Descripcion : %s \n",actual->Tareas.Descripcion);
                printf("Duracion: %d \n",actual->Tareas.duracion);
                actual=actual->siguiente;
                total=total + actual->Tareas.duracion;
            }
            printf("La duracion total de las tareas pendientes es %d",total);
        }
    } 
void MostrarTareasRealizadas(node* cabecera){
    int total;
    if(cabecera !=NULL){
        puts ("Tareas Realizadas");
        node*  actual =cabecera;
        for (int i=0;actual;i++){
                printf("---------Tarea n %d------\n",i+1);
                printf("ID: %d \n",actual->Tareas.TareaID);
                printf("Descripcion : %s \n",actual->Tareas.Descripcion);
                printf("Duracion: %d \n",actual->Tareas.duracion);
                actual=actual->siguiente;
                total=total+actual->Tareas.duracion;
            }
          printf("La duracion total de las tareas Realizadas es %d",total);  
        }
    } 
void MostrarTareasEnProceso(node* cabecera){
    int total;
    if(cabecera !=NULL){
        puts ("Tareas En proceso");
        node*  actual =cabecera;
        for (int i=0;actual;i++){
                printf("---------Tarea n %d------\n",i+1);
                printf("ID: %d \n",actual->Tareas.TareaID);
                printf("Descripcion : %s \n",actual->Tareas.Descripcion);
                printf("Duracion: %d \n",actual->Tareas.duracion);
                actual=actual->siguiente;
                total=total+actual->Tareas.duracion;
            }
          printf("La duracion total de las tareas en proceso es %d",total);  
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
tarea* IDevolver(node** t,int id){
    node * actual = *t;
    while(actual){
        if (actual->Tareas.TareaID == id){
            return &actual->Tareas;
        }
    }
    return NULL;
}
void moverTarea(node** origin, node** destino, tarea* modificado){
    

}

void interfazMover(node** realizadas, node** pendientes, node** en_proceso){
    int id,ubicacion=4,opcion;
    tarea  *Modificando;
    MostrarTareasPendientes(*pendientes);
    MostrarTareasRealizadas(*realizadas);
    MostrarTareasEnProceso(*en_proceso);
    puts("Ingrese la ID de la tarea a modificar");
    scanf("%d",&id);
    Modificando=IDevolver(pendientes,id);
    if (!Modificando){
        ubicacion=5;
        Modificando=IDevolver(realizadas,id);
         } else {
            Modificando=IDevolver(en_proceso,id);
            ubicacion=6;
             }
    if (!Modificando) {
        puts("Id no encontrado");
    }
    printf("Ingrese que quiere realizar (1 para eliminar,2 para mover,3 para no hacer nada )");
    scanf("%d",&opcion);
    switch (opcion){ 

    case 1 :
            switch(ubicacion){
                case 4:
                eliminarNodo(pendientes,*Modificando);
                break;
                case 5:
                eliminarNodo(realizadas,*Modificando);
                break;
                case 6:
                eliminarNodo(en_proceso,*Modificando);
                break;
            break;
            }
    case 2 :
            switch(ubicacion){
                case 4 :
                    puts("Desea comenzar(1) o finalizar la tarea(2)");
                    scanf("%d",&opcion);
                    if(opcion==1){
                        agregarNodo(en_proceso,*Modificando);
                        eliminarNodo(pendientes,*Modificando);

                    }else {
                        agregarNodo(realizadas,*Modificando);
                        eliminarNodo(pendientes,*Modificando);
                    }
                    break;
                case 5 :
                    puts("Desea deshacer(1) o corregir la tarea(2)");
                    scanf("%d",&opcion);
                    if(opcion==1){
                        agregarNodo(pendientes,*Modificando);
                        eliminarNodo(realizadas,*Modificando);

                    }else {
                        agregarNodo(en_proceso,*Modificando);
                        eliminarNodo(realizadas,*Modificando);
                    }
                    break;
                case 6 :
                    puts("Desea deshacer(1) o terminar la tarea(2)");
                    scanf("%d",&opcion);
                    if(opcion==1){
                        agregarNodo(pendientes,*Modificando);
                        eliminarNodo(en_proceso,*Modificando);

                    }else {
                        agregarNodo(realizadas,*Modificando);
                        eliminarNodo(en_proceso,*Modificando);
                    }
                    break;
            }
        default : 
                    break;
    }

}


int main () {
    node  *pendientes, *en_proceso,*realizadas;
    int opcion;
    pendientes=crearLista();
    en_proceso=crearLista();
    realizadas=crearLista();
    CargarTareas(&pendientes);
    interfazMover(&realizadas,&pendientes,&en_proceso);
    puts("Desea Modificar otra tarea?\n 1-Si \n 2-No\n");
    if (opcion == 1){
        interfazMover(&realizadas,&pendientes,&en_proceso);
    }
    return 0;
}