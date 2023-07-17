#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"



struct AnimalEstructura{

    char tipo[20];
    char subtipo[20];
    char nombre[20];
    float peso;
    int edad;
    char sexo;


};

Animal crearAnimal(char t[20], char s[20], char n[20], float p, int e, char se){

    Animal a = malloc(sizeof(struct AnimalEstructura));

    a->edad = e;
    strcpy(a->tipo, t);
    strcpy(a->subtipo, s);
    strcpy(a->nombre, n);
    a->peso = p;
    a->sexo = se;

    return a;
};

Animal crearAnimalTeclado(){

    char t[20]; char s[20]; char n[20]; float p; int e; char se;

    printf("-----Cargando animal----- 'n");

    printf("\nIntroducir el tipo:\n");
    fflush(stdin);
    gets(t);

    printf("\nIntroducir el subtipo:\n");
    fflush(stdin);
    gets(s);

    printf("\nIntroducir el nombre:\n");
    fflush(stdin);
    gets(n);


    printf("\nIntroducir el peso\n");
    scanf("%f", &p);

    printf("\nIntroducir la edad\n");
    scanf("%d", &e);

    printf("\nIntroducir el sexo\n");
    fflush(stdin);
    scanf("%c", &se);

    return crearAnimal(t,s,n,p,e,se);
};

void mostrarAnimal(Animal a){

    printf("\n\n---------ANIMAL-----------\n");
    printf("TIPO: %s  (subtipo: %s, sexo: %c)\n", a->tipo, a->subtipo, a->sexo);
    printf("NOMBRE: %s  (peso: %f kg, edad: %d anios)\n", a->nombre, a->peso, a->edad);



};

char * getTipo(Animal a){
return a->tipo;};

char * getSubtipo(Animal a){
return a->subtipo;};

char * getNombre(Animal a){
return a->nombre;};

float getPeso(Animal a){
return a->peso;};

float getEdad(Animal a){
return a->edad;};

char getSexo(Animal a){
return a->sexo;}


void setTipo(Animal a, char nuevo[20]){

    strcpy(a->tipo, nuevo);

};

void setSubtipo(Animal a, char nuevo[20]){

    strcpy(a->subtipo, nuevo);

};

void setNombre(Animal a, char nuevo[20]){

    strcpy(a->nombre, nuevo);

};

void setPeso(Animal a, float nuevo){

   a->peso =  nuevo;

};

void setEdad(Animal a, int nuevo){

   a->edad =  nuevo;

};

void setSexo(Animal a, char nuevo){

   a->sexo =  nuevo;

};
