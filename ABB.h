/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: De la Cruz Sierra Diana Paola
 * 		   García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Cabeceras de las funciones de árboles y árboles binarios
 * 
 * Fecha: 29 de marzo de 2019
*/

#include "Hash.h"

//Tipo da dato a guardar en el árbol
typedef int TipoDatoA;

//Estructura de los nodos de un árbol
typedef struct nodoA{
	TipoDatoA dato;
	struct nodoA *izq, *der;
}ELEMENTODEARBOLBINARIO;
typedef ELEMENTODEARBOLBINARIO *ARBOLBINARIO;

//Funciones principales de los árboles y árboles binarios
ARBOLBINARIO CrearNodoA(TipoDatoA);
void nuevoArbol(ARBOLBINARIO *, ARBOLBINARIO, ARBOLBINARIO, TipoDatoA);
int profundidad(ARBOLBINARIO);
void hojas(ARBOLBINARIO, int *);
void liberar(ARBOLBINARIO *);
void insertarABB(ARBOLBINARIO *, TipoDatoA);
ARBOLBINARIO buscarABB(ARBOLBINARIO, TipoDatoA);
void eliminarABB(ARBOLBINARIO *, TipoDatoA);
void reemplazar(ARBOLBINARIO *);
void copiarABB(ARBOLBINARIO, ARBOLBINARIO *);
