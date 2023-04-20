#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Tareasporhacer{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
};

typedef struct Tareasporhacer Tarea;

void interfaz(Tarea** tareas,int numero);
void TRealizadas(Tarea** pendientes,Tarea** Realizadas,int num);
void MostrarR(Tarea** realizadas,int num);


int main(){
    int cant=0;
    puts("Ingrese la cantidad las tareas a realizar ");
    scanf("%d",&cant);
    Tarea** tareas = malloc(cant * sizeof(Tarea*));
    Tarea** Realizadas = malloc(cant * sizeof(Tarea*));
     for (int i=0; i < cant ;i++) { 
        tareas[i]=NULL;
     }
    for (int i=0; i<cant;i++) {
        Realizadas[i]=NULL;
    }
    interfaz(tareas,cant);
    TRealizadas(tareas,Realizadas,cant);
    MostrarR(Realizadas,cant);
    return 0;
    for(int i=0;i<cant;i++){
        free(Realizadas[i]);
        free(tareas[i]);
    }
}

void interfaz(Tarea** tareas,int numero){
	int i;
    char* buffer =malloc(100*sizeof(*buffer));
    for(i = 0;i<numero;i++){  
        fflush(stdin);
        getchar();
        tareas[i]=malloc(sizeof(*(tareas[i])));
        printf("---- Tarea n %d ----- \n",i+1);
        puts("Ingrese la descripcion");
        gets(buffer);
        tareas[i]->TareaID=i+1;
        tareas[i]->Descripcion=malloc(strlen(buffer) +1);
        strcpy(tareas[i]->Descripcion,buffer);
        
        puts("Ingrese la duracion de la tarea");
        scanf("%d",&tareas[i]->Duracion);
    }
    free(buffer);
}

void TRealizadas(Tarea** pendientes,Tarea** Realizadas,int num){
	int i;
    int* buffer = malloc(3*sizeof(*buffer));
     for ( i=0; i <num; i++){
        if (pendientes != NULL ){ 
            puts("¿La tarea ha sido realizada?");
            fflush(stdin);
            scanf("%d",buffer);
            if(*buffer== 1){
                Realizadas[i]=pendientes[i];
                pendientes[i]=NULL;

            }
        }
    }
}
void MostrarR(Tarea** realizadas,int num){
    int i;
    puts("Tareas Realizadas");
    for (i=0;i<num;i++){
        if (realizadas != NULL ){ 
          printf("----Tarea n° %d----\n",i+1);
          printf("%s",realizadas[i]->Descripcion);
          printf(" Duracion : %d \n",realizadas[i]->Duracion);
    }
 }
}

