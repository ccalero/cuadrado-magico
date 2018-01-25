/*
	Definicion de las funciones, constantes y estructras del programa.
	
	Autor: Carlos Calero de la Fuente
	Fecha: 29/01/2014
*/
#include <stdio.h>
#include <math.h>

#define NCOL 100
#define NFIL 100

struct matriz pedirTamanio();
int sumarFila(int cuadrante[NFIL][NCOL], int filas, int columnas, int fila);
int sumarColumna(int cuadrante[NFIL][NCOL], int filas, int columnas, int columna);
int sumarDiagonalPrincipal(int cuadrante[NFIL][NCOL], int filas, int columnas);
int sumarDiagonalInvertida(int cuadrante[NFIL][NCOL], int filas, int columnas);
int esCuadradoMagico(int vSumas[NFIL], int tamanioSumas, int constanteMagica);
void pedirValores(int cuadrante[NFIL][NCOL], int filas, int columnas);
void imprimirCabecera();

struct matriz {
	int filas;
	int columnas;
};
