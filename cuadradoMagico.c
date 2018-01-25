/*
	Programa que dice si una matriz es un cuadrado magico.
	Una matriz cuadrada es un cuadrado mágico, si la suma 
	de los elementos de sus filas, de sus columnas y de su 
	diagonal son el mismo número.
	La constante mágica se calcula como: M=n*(n^2+1)/2, 
	donde n es el orden de la matriz.

	Autor: Carlos Calero de la Fuente
	Fecha: 29/01/2014
*/
#include "prototipo.h"

int main(){

	int cuadrante[NFIL][NCOL];
	int suma; //Variable donde guardo las sumas de las filas, columnas y diagonales
	int i,j;

	imprimirCabecera(); //Funcion que imprime la cabecera del programa

	//Estructura que tiene el tamaño de las filas y columnas
	//Las pido en la funcion pedirTamanio que me devuelve una estructura
	struct matriz tamCuadrante = pedirTamanio();

	int tamanioSumas = (tamCuadrante.filas*2)+2; //Tamanio del vector de las sumas
	int vSumas[tamanioSumas]; //Vector que guardo las diferentes sumas de cada columna, fila y diagonal
	int constanteMagica = (tamCuadrante.filas*(pow(tamCuadrante.filas,2)+1))/2; //El numero que tienen que sumar para ser magico

	//Pido los valores para llenar el cuadrante
	pedirValores(cuadrante, tamCuadrante.filas, tamCuadrante.columnas);
	
	//Aqui recorro el cuadrante, sumando las filas y a la vez lo voy imprimiendo por pantalla.
	for(i=0;i<tamCuadrante.filas;i++){
		suma = sumarFila(cuadrante, tamCuadrante.filas, tamCuadrante.columnas, i);
		vSumas[i]=suma; //Guardo la suma de cada fila en el vector.

		printf(" %2d = | ",suma);
		for(j=0;j<tamCuadrante.columnas;j++){
			printf("%2d   ",cuadrante[i][j]);
		}
		printf("| = %2d",sumarFila(cuadrante, tamCuadrante.filas, tamCuadrante.columnas, i));
		printf("\n");
	}	
	//Sumo la diagonal invertida y la imprimo
	suma = sumarDiagonalInvertida(cuadrante, tamCuadrante.filas, tamCuadrante.columnas);
	vSumas[i]=suma;
	//Este for es para escribir una ralla formada con guiones para separar la suma de columnas y diagonales de la matriz en pantalla
	for(i=0;i<tamCuadrante.filas*10;i++){
		printf("-");
	}	
	printf("\n");
	printf(" %2d   | ", suma);
	
	//Recorro las columnas para ir sumandolas e imprimiendolas.
	for(i=0;i<tamCuadrante.columnas;i++){
		suma = sumarColumna(cuadrante, tamCuadrante.filas, tamCuadrante.columnas, i);
		vSumas[tamCuadrante.filas+1+i]=suma;
		
		printf("%2d   ",suma);
	}
	
	//Y por ultimo sumo la diagonal principal
	suma = sumarDiagonalPrincipal(cuadrante, tamCuadrante.filas, tamCuadrante.columnas);
	vSumas[tamanioSumas-1]=suma;

	printf("|   %2d", suma);
	printf("\n");

	//Una vez que tengo el vector de las sumas compruebo si es magico o no y lo imprimo 
	if(esCuadradoMagico(vSumas, tamanioSumas, constanteMagica)){
		printf("\nEl cuadrado es Magico\n");
	} else {
		printf("\nEl cuadrado no es Magico\n");
	}
		
	return 0;
}


