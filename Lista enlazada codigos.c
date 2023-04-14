typedef struct Tnodo
{
    int valor; //dato
    Tnodo * Sig; //puntero al siguiente
}Tnodo;


// ------CREAR NODOS-------//

Tnodo * CrearNodo(int valor)
{
        Tnodo * NNodo = (Tnodo *) malloc (sizeof(Tnodo));
        Nnodo->Valor = valor;
        NNodo->siguiente = null;
        return NNodo;
}

//-------- CREAR UNA LISTA VACIA----//


Tnodo * head

Tnodo * crearListaVacia() {
    return null;

}

head = crearListaVacia();

//-----Insertar un nodo al comienzo -------//

void InsertarNodo(Tnodo ** head , int valor)
{
        Tnodo * NuevoNodo = CrearNodo(valor);
        NuevoNodo -> siguiente = *head;
        *head = NuevoNodo ;
}

//------ Insertar un nodo al final-----//
void InsertarAlFinal(Tnodo * head, tnodo * Nodo)
{
        Tnodo * NuevoNodo = CrearNodo(valor);
        Tnodo * Aux = head;
        while(Aux->siguiente)
        {
            Aux = Aux -> siguiente;
        }
        Aux -> siguiente = NuevoNodo;
}

//----------Buscar un elemento/nodo -------//

Tnodo * buscarNodo(Tnodo * head, int IdBuscado)
{
    Tnodo * Aux = head;
    while(Aux && aux -> id != idBuscado)
    {
        Aux = Aux -> siguiente;
        }
    return Aux;
}

//-.----- Eliminar Nodo ------- //

void EliminarNodo(Tnodo * nodo)
{
if (!nodo) free(nodo);
}

//----- Eliminar un nodo pero manteniendo la lista ordenada ------//

void EliminarNodo(Tnodo * head, int dato)
{
        int DatoBuscado = 10;
        Tnodo * Aux = head;
        Tnodo * AuxAnterior = head;
        while (Aux && Aux->dato != DatoBuscado)
        {
            AuxAnterior = Aux;
            Aux = Aux->siguiente;
        }
        if(Aux)
        {
        AuxAnterior -> siguiente = Aux -> siguiente;
        free(Aux);
        }
}
