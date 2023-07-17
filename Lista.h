#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

///Estructura y tipo de dato de la Lista
struct ListaE;
typedef struct ListaE * PtrLista;
///Puntero a tipo de dato void
typedef void * PtrDato;
///Estructura y tipo de dato del Nodo
struct NodoE;
typedef struct NodoE * PtrNodo;

PtrLista crearLista();
PtrNodo crearNodo(PtrDato dato);

PtrDato getDatoLista(PtrLista lista, int posicion);
int longitudLista(PtrLista lista);

//insertar
void insertarInicio(PtrLista lista, PtrDato dato); //insertar al inicio
void insertarFinal(PtrLista lista, PtrDato dato); //inserta al final
void insertarOrdenado(PtrLista lista, PtrDato dato);

//eliminar
void eliminarInicio(PtrLista lista);
void eliminarFinal(PtrLista lista);
void eliminarNodoOrdenado(PtrLista lista, PtrDato dato);

void vaciarLista(PtrLista lista);

void imprimirListaAnimal(PtrLista lista);
void imprimirNumeros(PtrLista lista);

void duplicarLista(PtrLista listaOriginal, PtrLista listaDuplicada);
void ordenamiento(PtrLista lista);
void ordenamientoPorEdad(PtrLista lista);
int busquedaSecuencial(PtrLista lista, int dato);


#endif // LISTA_H_INCLUDED
