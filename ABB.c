/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: De la Cruz Sierra Diana Paola
 * 		   García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Funciones de árboles y árboles binarios
 * 
 * Fecha: 29 de marzo de 2019
*/

#include "ABB.h"

//Creación de un nodo
ARBOLBINARIO CrearNodoA(TipoDatoA x){
	ARBOLBINARIO nuevo=(ARBOLBINARIO) malloc(sizeof(ELEMENTODEARBOLBINARIO));
	nuevo->dato=x;
	nuevo->der=nuevo->izq=NULL;
	return nuevo;
}

//Creación de un árbol
void nuevoArbol(ARBOLBINARIO *raiz, ARBOLBINARIO ramaizq, ARBOLBINARIO ramader, TipoDatoA x){
	*raiz=CrearNodoA(x);
	(*raiz)->izq=ramaizq;
	(*raiz)->der=ramader;
}

//Calculo de la profundidad de un árbol
int profundidad(ARBOLBINARIO raiz){
	if(!raiz){
		return 0;
	}
	else{
		int profI=profundidad(raiz->izq);
		int profD=profundidad(raiz->der);
		if(profI>profD){
			return profI+1;
		}
		else{
			return profD+1;
		}
	}
}

//Calculo de las hojas de un árbol
void hojas(ARBOLBINARIO raiz, int *ct){
	if(raiz){
		hojas(raiz->izq, ct);
		hojas(raiz->der, ct);
		if(!(raiz->izq) && !(raiz->der)){
			(*ct)++;
		}
	}
}

//Eliminación de un árbol
void liberar(ARBOLBINARIO *raiz){
	if(*raiz){
		liberar(&(*raiz)->izq);
		liberar(&(*raiz)->der);
		free(*raiz);
	}
}

//Insertar datos en un árbol binario
void insertarABB(ARBOLBINARIO *raiz, TipoDatoA x){
	if(!(*raiz)){
		*raiz=CrearNodoA(x);
	}
	else if(((*raiz)->dato)>x){
		insertarABB(&((*raiz)->izq),x);
	}
	else{
		insertarABB(&((*raiz)->der),x);
	}
}

//Buscar un datos en un árbol binario
ARBOLBINARIO buscarABB(ARBOLBINARIO raiz, TipoDatoA x){
	if(raiz->dato==x){
		return raiz;
	}
	else if(raiz==NULL){
		return raiz;
	}
	else if((raiz->dato)>x){
		return buscarABB(raiz->izq,x);
	}
	else{
		return buscarABB(raiz->der,x);
	}
}

//Eliminar un dato en un árbol binario
void eliminarABB(ARBOLBINARIO *raiz, TipoDatoA x){
	if(!(*raiz)){
		printf("No se encontro el elemento\n");
	}
	else if((*raiz)->dato>x){
		eliminarABB(&((*raiz)->izq),x);
	}
	else if((*raiz)->dato<x){
		eliminarABB(&((*raiz)->der),x);
	}
	else{
		ARBOLBINARIO q=(*raiz);
		if(q->der==NULL){
			*raiz=q->izq;
		}
		else if(q->izq==NULL){
			*raiz=q->der;
		}
		else{
			reemplazar(&q);
		}
		free(q);
	}
}

//3er caso de eliminación de un nodo en un árbol binario
void reemplazar(ARBOLBINARIO *actual){
	ARBOLBINARIO p=(*actual), a=p->izq;
	while(a->der){
		p=a;
		a=a->der;
	}
	(*actual)->dato==a->dato;
	if(a->der==NULL){
		p->izq=a->izq;
	}
	else{
		p->der=a->izq;
	}
	*actual=a;
}

//Copiar un árbol binario
void copiarABB(ARBOLBINARIO A, ARBOLBINARIO *B){
	if(A!=NULL){
		*B=CrearNodoA(A->dato);
		copiarABB(A->izq, (&(*B)->izq));
		copiarABB(A->der, (&(*B)->der));
	}
}
