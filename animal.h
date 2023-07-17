#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED



struct AnimalEstructura;

typedef struct AnimalEstructura * Animal;


Animal crearAnimal(char t[20], char s[20], char n[20], float p, int e, char se);

Animal crearAnimalTeclado();

void mostrarAnimal(Animal a);

char * getTipo(Animal a);

char * getSubtipo(Animal a);

char * getNombre(Animal a);

float getPeso(Animal a);

float getEdad(Animal a);

char getSexo(Animal a);


void setTipo(Animal a, char nuevo[20]);

void setSubtipo(Animal a, char nuevo[20]);

void setNombre(Animal a, char nuevo[20]);

void setPeso(Animal a, float nuevo);

void setEdad(Animal a, int nuevo);

void setSexo(Animal a, char nuevo);


#endif // ANIMAL_H_INCLUDED
