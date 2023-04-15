#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ESTRUCTURAS--------------------------//
typedef struct Treas {
    int TareaID;
    char *Descripcion;
    int duracion;
}Tareas;
//-------------------DECLARACION DEFUNCIONES -------------------//

void InicilizararTareas (Tareas** Pendientes, Tareas** Realizadas, int cant);
void CargarTareas(Tareas** Pendientes,int cant);
void MostrarTareasPendientes(Tareas** Pendientes, int cant);
void TerminarTareas(Tareas** Pendientes,Tareas** Completadas,int cant);
void MostrarTareasRealizadas(Tareas** Realizadas, int cant);
void TerminarTareas(Tareas** Pendientes,Tareas** Completadas,int cant);
void ID(Tareas** todas, int cant);
void PalabraClave(Tareas** todas, int cant);
void Liberar(Tareas** Todas,int cant);
//-------------------MAIN------------------------//
int main(int argc, char** argv){
    int Cantidad;
    puts("Ingrese la cantidad de Tareas a realizar");
    scanf("%d",&Cantidad);
    Tareas** Pendientes = malloc(Cantidad*sizeof(*Pendientes));
    Tareas** Realizadas = malloc(Cantidad*sizeof(*Pendientes));
    InicilizararTareas(Pendientes,Realizadas,Cantidad);
    CargarTareas(Pendientes,Cantidad);
    TerminarTareas(Pendientes,Realizadas,Cantidad); 
    MostrarTareasRealizadas(Realizadas,Cantidad);
    MostrarTareasPendientes(Pendientes,Cantidad);
    ID(Pendientes,Cantidad);
    ID(Realizadas,Cantidad);
    PalabraClave(Pendientes,Cantidad);
    PalabraClave(Realizadas,Cantidad);
    Liberar(Pendientes,Cantidad);
    Liberar(Realizadas,Cantidad);
    
    return 0;
}

//-----------------------FUNCIONES---------------------//
void InicilizararTareas (Tareas** Pendientes, Tareas** Realizadas, int cant){
    for(int i=0;i<cant;i++){
        Pendientes[i]=NULL;
    }
    for(int j=0;j<cant;j++){
        Realizadas[j]=NULL;
    }
}
void CargarTareas(Tareas** Pendientes,int cant){
    char* buffer =malloc(100*sizeof(*buffer));
    for (int i=0;i<cant;i++){
        fflush(stdin);
        Pendientes[i]=malloc(sizeof(*(Pendientes[i])));
        printf("---------Tarea n %d------\n",i+1);
        Pendientes[i]->TareaID=i+1;
        puts("Ingrese la descripcion de la Tarea");
        gets(buffer);
        fflush(stdin);
        Pendientes[i]->Descripcion=malloc(strlen(buffer)+1);
        strcpy(Pendientes[i]->Descripcion,buffer);
        puts("Ingrese la duracion de la tarea");
        scanf("%d",&Pendientes[i]->duracion);
        fflush(stdin);
    }
}

void MostrarTareasPendientes(Tareas** Pendientes, int cant){
    puts ("Tareas A realizar");
    for (int i=0;i<cant;i++){
        if (Pendientes[i] != NULL){
            printf("---------Tarea n %d------\n",i+1);
            printf("ID: %d \n",Pendientes[i]->TareaID);
            printf("Descripcion : %s \n",Pendientes[i]->Descripcion);
            printf("Duracion: %d \n",Pendientes[i]->duracion);
        }
    }
}

void TerminarTareas(Tareas** Pendientes,Tareas** Completadas,int cant){
    int si;
    for (int i=0;i<cant;i++){
        puts("¿La tarea fue realizada? \n 1=Si \n 2=NO");
        scanf("%d",&si);
        if(si==1){
            Completadas[i]=malloc(sizeof(*(Completadas)));
            Completadas[i]=Pendientes[i];
            Pendientes[i]=NULL;
        }
    }
}

void MostrarTareasRealizadas(Tareas** Realizadas, int cant){
    puts ("Tareas Realizadas");
    for (int i=0;i<cant;i++){
        if (Realizadas[i] != NULL){
            printf("---------Tarea n %d------\n",i+1);
            printf("ID: %d \n",Realizadas[i]->TareaID);
            printf("Descripcion : %s \n",Realizadas[i]->Descripcion);
            printf("Duracion: %d \n",Realizadas[i]->duracion);
        }
    }
}

void ID(Tareas** todas, int cant){
    int id;
    puts("-----Ingrese la ID a buscar-----");+
    scanf("%d",&id);
    for(int i=0;i<cant;i++){
        if(todas[i]->TareaID == id){
            printf("ID: %d \n",todas[i]->TareaID);
            printf("Descripcion : %s \n",todas[i]->Descripcion);
            printf("Duracion: %d \n",todas[i]->duracion);
        }
    }


}

void PalabraClave(Tareas** todas, int cant){
    char* Palabra = malloc(20*sizeof(char));
    puts("INGRESE LA PALABRA CLAVE");
    gets(Palabra);
    for(int i=0;i<cant;i++){
        if(strstr(todas[i]->Descripcion,Palabra)){
            printf("ID: %d \n",todas[i]->TareaID);
            printf("Descripcion : %s \n",todas[i]->Descripcion);
            printf("Duracion: %d \n",todas[i]->duracion);
        }
    }
    free(Palabra);
}

void Liberar(Tareas** Todas,int cant){
    for(int i=0;i<cant;i++){
        free(Todas[i]);
    }
    free(Todas);
}