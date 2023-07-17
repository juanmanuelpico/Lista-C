#include <stdlib.h>
#include "Lista.h"
#include "animal.h"

struct ListaE{

     PtrNodo primero;
};

struct NodoE {

    PtrDato dato; // dato almacenado
    struct NodoE * sgte; // puntero al siguiente nodo que es un Nodo de la misma estructura
};

///Lista

PtrLista crearLista(){

    ///El constructor, lo de siempre :)
    PtrLista lista = malloc(sizeof(struct ListaE));
    lista->primero = NULL;

    return lista;
}

///NODO

PtrNodo crearNodo(PtrDato dato){

    PtrNodo nodo=(PtrNodo)malloc(sizeof(struct NodoE));
    nodo->dato = dato;
    nodo->sgte = NULL;

    return nodo;
}


PtrDato getDatoLista(PtrLista lista, int posicion){

    PtrNodo actual = lista->primero;
    int posicionActual = 0;

    if (actual != NULL) {

        while (posicionActual < posicion && actual->sgte != NULL) {

            posicionActual++;
            actual = actual->sgte;
        }
    }

    return actual->dato;
}


int longitudLista(PtrLista lista){
    // para obtener la longitud, debemos recorrer la lista.
    int tam = 0;
    PtrNodo actual = lista->primero;

    while(actual != NULL){

        actual = actual->sgte;
        tam++;

    }

    return tam;
}

void insertarInicio(PtrLista lista, PtrDato dato) {
    // Creamos un nuevo nodo con el dato
    PtrNodo nuevoNodo = crearNodo(dato);

    // Si la lista está vacía, el nuevo nodo será el primero
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        // Si la lista no está vacía, ajustamos los punteros
        nuevoNodo->sgte = lista->primero;
        lista->primero = nuevoNodo;
    }
}

void insertarFinal(PtrLista lista, PtrDato dato) {
    // Creamos un nuevo nodo con el dato
    PtrNodo nuevoNodo = crearNodo(dato);

    // Si la lista está vacía, el nuevo nodo será el primero
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        // Si la lista no está vacía, recorremos hasta el último nodo
        PtrNodo actual = lista->primero;
        while (actual->sgte != NULL) {
            actual = actual->sgte;
        }
        // Asignamos el nuevo nodo al siguiente del último nodo
        actual->sgte = nuevoNodo;
    }
}

void insertarOrdenado(PtrLista lista, PtrDato dato) {
    PtrNodo nuevoNodo = crearNodo(dato);

    // Si la lista está vacía o el dato es menor que el primer elemento
    if (lista->primero == NULL || dato < lista->primero->dato) {
        nuevoNodo->sgte = lista->primero;
        lista->primero = nuevoNodo;
    } else {
        PtrNodo actual = lista->primero;
        PtrNodo anterior = NULL;

        // Recorremos la lista hasta encontrar la posición adecuada para el nuevo nodo
        while (actual != NULL && dato >= actual->dato) {
            anterior = actual;
            actual = actual->sgte;
        }

        // Insertamos el nuevo nodo en la posición adecuada
        nuevoNodo->sgte = actual;
        anterior->sgte = nuevoNodo;
    }
}


void eliminarInicio(PtrLista lista) {

    if (lista->primero != NULL) {

        PtrNodo nodoAEliminar = lista->primero;
        lista->primero = lista->primero->sgte;
        free(nodoAEliminar);
    }
}

void eliminarFinal(PtrLista lista){

    if(lista->primero != NULL){
        PtrNodo actual = lista->primero;
        PtrNodo anterior = NULL;

        // Recorremos hasta el último nodo
        while(actual->sgte != NULL){
            anterior = actual;
            actual = actual->sgte;
        }

        // Si hay un nodo anterior, ajustamos su puntero al siguiente
        if(anterior != NULL){
            anterior->sgte = NULL;
        }
        // Si no hay un nodo anterior, el último nodo es el primero de la lista
        else{
            lista->primero = NULL;
        }
        // Liberamos la memoria del nodo a eliminar
        free(actual);
    }
}

void eliminarNodoOrdenado(PtrLista lista, PtrDato dato) {
    PtrNodo actual = lista->primero;
    PtrNodo anterior = NULL;

    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->sgte;
    }

    if (actual != NULL) {
        // Si el nodo a eliminar es el primero de la lista
        if (anterior == NULL) {
            lista->primero = actual->sgte;
        } else {
            // Si el nodo a eliminar está en medio o al final de la lista
            anterior->sgte = actual->sgte;
        }

        free(actual);
    }
}


void vaciarLista(PtrLista lista){

    while(lista->primero != NULL){
    eliminarInicio(lista);
    }

}

void duplicarLista(PtrLista listaOriginal, PtrLista listaDuplicada) {
    PtrNodo nodoOriginal = listaOriginal->primero;

    while (nodoOriginal != NULL) {

        insertarFinal(listaDuplicada, nodoOriginal->dato); // le pasamos por parametro el puntero del nodo de la lista original
        nodoOriginal = nodoOriginal->sgte; //luego nos movemos hacia adelante
    }
    ordenamiento(listaDuplicada); //llamamos al ordenamiento de la listaDuplicada
}


void imprimirListaAnimal(PtrLista lista){

    printf("\n\n------ Lista con %d datos: ------\n",longitudLista(lista) );

    for(int i=0;i<longitudLista(lista);i++){
        mostrarAnimal( (Animal)  getDatoLista(lista,i) );

    }

}

void imprimirNumeros(PtrLista lista){

    printf("\n\n------ Lista con %d datos: ------\n",longitudLista(lista) );

    for(int i=0;i<longitudLista(lista);i++){
        printf(" %d  ", ( (int)  getDatoLista(lista,i) ));

    }

}

int busquedaSecuencial(PtrLista lista, int dato){

    int pos=-1;
    int i=0;

        while(i<longitudLista(lista) && pos == -1){
            if(dato == getDatoLista(lista, i)){
                pos = i;
        }
        i++;
}

return pos;

};


void ordenamiento(PtrLista lista){

int aux;
PtrNodo actual;

for(int i=0; i<longitudLista(lista); i++){

    actual = lista->primero;

    for(int j=0; j<longitudLista(lista)-1;j++){
        if(actual->dato > actual->sgte->dato ){

                aux = actual->dato;
                actual->dato = actual->sgte->dato;
                actual->sgte->dato = aux;
            }
        actual = actual->sgte;
        }
    }
}

void ordenamientoPorEdad(PtrLista lista) {
    Animal aux;
    PtrNodo actual;

    for (int i = 0; i < longitudLista(lista); i++) {

        actual = lista->primero;

        for (int j = 0; j < longitudLista(lista) - 1; j++) {
            if (getEdad((Animal)actual->dato) > getEdad((Animal)actual->sgte->dato)) {
                aux = actual->dato;
                actual->dato = actual->sgte->dato;
                actual->sgte->dato = aux;
            }
        actual = actual->sgte;
        }
    }
}

