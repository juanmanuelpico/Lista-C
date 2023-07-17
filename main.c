#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "Lista.h"
int main()
{
    PtrLista lista = crearLista();
    Animal animal1 = crearAnimal("Ave", "Caniche", "Samanta", 22.3, 2, 'm');
    Animal animal2 = crearAnimal("Perro", "Dogo", "Ishikame", 31.1, 5, 'm');
    Animal animal3 = crearAnimal("Gato", "Siames", "Robertina", 8.3, 3, 'f');
    Animal animalInicio = crearAnimal("GatoInicio", "Inicio", "KevinInicio", 8.3, 3, 'f');
    Animal animalFinal = crearAnimal("GatoFinal", "Final", "CrisFinal", 8.3, 3, 'f');

    insertarInicio(lista,animal1);
    insertarInicio(lista,animal2);
    insertarInicio(lista,animal3);
    insertarFinal(lista, animalFinal);
    insertarInicio(lista,animalInicio);

    imprimirListaAnimal(lista);

    printf("\nEliminando dato inicial\nLista con dato eliminado\n");
    eliminarInicio(lista);
    eliminarFinal(lista);
    imprimirListaAnimal(lista);
    printf("\nordenando Lista de animales por edad\n\n");
    ordenamientoPorEdad(lista);
    imprimirListaAnimal(lista);

    PtrLista listaNum = crearLista();

    insertarInicio(listaNum,3);
    insertarInicio(listaNum,4);
    insertarInicio(listaNum,5);
    insertarInicio(listaNum,6);
    insertarInicio(listaNum,7);

    insertarOrdenado(listaNum, 2);
    insertarOrdenado(listaNum, 10);
    insertarOrdenado(listaNum, 1);
    eliminarNodoOrdenado(listaNum, 5);

    imprimirNumeros(listaNum);
    vaciarLista(lista);
    imprimirListaAnimal(lista);

    PtrLista listaNueva = crearLista();
    duplicarLista(listaNum, listaNueva);
    printf("buscando el 10 esta en la posicion ---> %d ", busquedaSecuencial(listaNueva, 10));
    imprimirNumeros(listaNueva);

    return 0;
}





