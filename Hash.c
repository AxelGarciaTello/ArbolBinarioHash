/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: De la Cruz Sierra Diana Paola
 * 		   García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Funciones hash
 * 
 * Fecha: 29 de marzo de 2019
*/

#include "Hash.h"

//Crea la tabla hash
void CrearTabla(TABLADISPERSION *T){
	int i;
	for(i=0; i<TAM; i++){
		T->Tabla[i]=NULL;
	}
	T->elementos=0;
}

//Crea el código de identificación de los datos a guardar
long funcionHash(char *clave){
	long p=0;
	int i;
	for(i=0; i<strlen(clave); i++){
		p=p*31+clave[i];
	}
	p=abs(p);
	return p;
}

//Relaciona el código de identificación con la tabla hash
int direccion(TABLADISPERSION *T, char *clave){
	long p=funcionHash(clave);
	int i=1;
	p=p%TAM;
	while(T->Tabla[i]!=NULL && strcmp(T->Tabla[i]->nombre, clave)){
		p=p+i*i;
		p=p%TAM;
		i++;
	}
	return (int) p;
}

//Guardar el registro en la tabla hash
void insertarReg(TABLADISPERSION *T, ALUMNO A){
	int dir=direccion(T, A.nombre);
	ALUMNO *B=(ALUMNO *)malloc(sizeof(ALUMNO));
	strcpy(B->nombre, A.nombre);
	strcpy(B->direccion, A.direccion);
	strcpy(B->correo, A.correo);
	strcpy(B->telefono, A.telefono);
	B->edad=A.edad;
	B->alta=1;
	T->Tabla[dir]=B;
	T->elementos++;
}

//Elimina el registro de la tabla hash
void eliminarReg(TABLADISPERSION *T, char *clave){
	int dir=direccion(T, clave);
	if(T->Tabla[dir]!=NULL && T->Tabla[dir]->alta==1){
		T->Tabla[dir]->alta=0;
		T->elementos--;
	}
}

//Imprime la estructura de los datos guardados
void mostrarAlumno(ALUMNO a){
	printf("Nombre: %s\nDireccion: %s\nCorreo: %s\nTelefono: %s\nEdad: %d\n", a.nombre, a.direccion, a.correo, a.telefono, a.edad);
}

//Busca los datos guardados dentro de la tabla hash
void buscar(TABLADISPERSION *T, char *clave){
	int dir=direccion(T, clave);
	if(T->Tabla[dir]!=NULL && T->Tabla[dir]->alta==1){
		mostrarAlumno(*(T->Tabla[dir]));
	}
}

//Muestra toda la tabla hash
void mostrarTabla(TABLADISPERSION *T){
	int i;
	for(i=0; i<TAM; i++){
		if(T->Tabla[i]!=NULL && T->Tabla[i]->alta==1){
			mostrarAlumno(*(T->Tabla[i]));
		}
	}
}
