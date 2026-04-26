#include <stdio.h>

typedef struct{
    int PID;
    int PC;
    int estado;
    int RegistroDeEstados[8];
    
}PCB;
typedef struct{
    PCB proceso;
    char archivoPseudoCodigo[20];
    int tamanio;
}Proceso;

typedef struct {
    void* dato;
    struct Nodo* siguiente;
}Nodo;

void agregarNodo(Nodo** cabeza, void* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}




int main(int argc, char const *argv[])
{
    return 0;
}
