/*
 * Instituto Politécnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: De la Cruz Sierra Diana Paola
 * 		   García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Programa de registro de estudiantes de un ABB
 * 
 * Fecha: 29 de marzo de 2019
*/

#include "ABB.h"

//Función para imprimir el árbol en preorden
void preorden(ARBOLBINARIO raiz, TABLADISPERSION *registros){
	if(raiz!=NULL){
		mostrarAlumno(*(registros->Tabla[raiz->dato]));
		printf("\n");
		preorden(raiz->izq, registros);
		preorden(raiz->der, registros);
	}
}

//Función para imprimir el árbol en orden
void orden(ARBOLBINARIO raiz, TABLADISPERSION *registros){
	if(raiz!=NULL){
		orden(raiz->izq, registros);
		mostrarAlumno(*(registros->Tabla[raiz->dato]));
		printf("\n");
		orden(raiz->der, registros);
	}
}

//Función para imprimir el árbol en postorden
void postorden(ARBOLBINARIO raiz, TABLADISPERSION *registros){
	if(raiz!=NULL){
		postorden(raiz->izq, registros);
		postorden(raiz->der, registros);
		mostrarAlumno(*(registros->Tabla[raiz->dato]));
		printf("\n");
	}
}

//Menu del programa principal
void menu(void){
	int opcion=0, i, codigo;
	TABLADISPERSION hash;
	CrearTabla(&hash);
	ARBOLBINARIO arbol=NULL;
	ALUMNO persona;
	do{
		printf("Seleccione una opción\n");
		printf("\t1. Dar de alta un registro\n");
		printf("\t2. Dar de baja un registro\n");
		printf("\t3. Modificar un registro\n");
		printf("\t4. Buscar un registro\n");
		printf("\t5. Imprimir el arbol\n");
		printf("\t6. Salir\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: //Dar de alta un registro
					printf("Nombre:\n");
					scanf("%s",persona.nombre);
					printf("Direccion: \n");
					scanf("%s",persona.direccion);
					printf("Telefono: \n");
					scanf("%s",persona.telefono);
					printf("Correo: \n");
					scanf("%s",persona.correo);
					printf("Edad: \n");
					scanf("%d",&(persona.edad));
					//Guardar en la tabla hash
					insertarReg(&hash, persona);
					//Obtener el código de la tabla
					codigo=direccion(&hash, persona.nombre); 
					//Insertar en el árbol
					insertarABB(&arbol, codigo);
			break;
			case 2: //Dar de baja un registro
					printf("Ingrese el nombre del registro:\n");
					scanf("%s",persona.nombre);
					//Obtener el código de la tabla
					codigo=direccion(&hash, persona.nombre);
					//Eliminar de la tabla hash
					eliminarReg(&hash,persona.nombre);
					//Eliminar del árbol
					eliminarABB(&arbol, codigo);
			break;
			case 3: //Editar los datos
					printf("Ingrese el nombre del registro:\n");
					scanf("%s",persona.nombre);
					printf("Ingrese la nueva direccion: \n");
					scanf("%s",persona.direccion);
					printf("Ingrese el nuevo telefono: \n");
					scanf("%s",persona.telefono);
					printf("Ingrese el nuevo correo: \n");
					scanf("%s",persona.correo);
					printf("Ingrese la nueva edad: \n");
					scanf("%d",&(persona.edad));
					//Elimina los viejos datos
					eliminarReg(&hash,persona.nombre);
					//Ingresa los nuevos
					insertarReg(&hash, persona);
			break;
			case 4: //Buscar un registro
					printf("Ingrese el nombre del registro:\n");
					scanf("%s",persona.nombre);
					buscar(&hash, persona.nombre);
			break;
			case 5: //Imprimir el árbol en preorden, orden y postorden
					printf("\tPreorden:\n\n");
					preorden(arbol, &hash);
					printf("\tEn orden:\n\n");
					orden(arbol, &hash);
					printf("\tPostorden:\n\n");
					postorden(arbol, &hash);
			break;
			case 6: 
			break;
			default: printf("Opcion incorrecta\n");
			break;
		}
	} while(opcion!=6);
}

//Función principal main
int main(void){
	menu();
	return 0;
}
