/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: De la Cruz Sierra Diana Paola
 * 		   García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Cabeceras de las funciones hash
 * 
 * Fecha: 29 de marzo de 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1009

//Estructura de los datos a guardar
typedef struct alumno{
	char nombre[25], direccion[40], correo[20], telefono[10];
	int edad, alta;
} ALUMNO;

//Tipo de datos a guardar
typedef ALUMNO* TipoDato;

//Estructura de la tabla hash
typedef struct tabla{
	TipoDato Tabla[TAM];
	int elementos;
} TABLADISPERSION;

//Funciones de la tabla hash
void CrearTabla(TABLADISPERSION *);
long funcionHash(char *);
int direccion(TABLADISPERSION *, char *);
void insertarReg(TABLADISPERSION *, ALUMNO);
void eliminarReg(TABLADISPERSION *, char *);
void mostrarAlumno(ALUMNO);
void buscar(TABLADISPERSION *, char *);
void mostrarTabla(TABLADISPERSION *);
