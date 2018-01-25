/*
	Funciones utilizadas en el Programa
	
	Autor: Carlos Calero de la Fuente
	Fecha: 29/01/2014
*/
#include "prototipo.h"
/*
	Funcion que pide el tamanio de la matriz, filas y columnas.
	El bucle es para asegurarnos de que la matriz introducida es Cuadrada
	Devuelve la matriz introducida
*/
struct matriz pedirTamanio(){
	struct matriz tamCuadrante;
	do{
		printf("RECUERDA QUE EL TAMANIO DEL CUADRANTE TIENE QUE SER CUADRARO (maximo 100x100)\n");

		printf("De que cuantas filas quieres que sea el cuadrante? ");
		scanf("%d", &tamCuadrante.filas);

		printf("De cuantas columnas quieres que sea el cuadrante? ");
		scanf("%d", &tamCuadrante.columnas);	

	}while(tamCuadrante.columnas!=tamCuadrante.filas);
	return tamCuadrante;
}

/*
	Funcion que imprime la cabecera del programa
*/
void imprimirCabecera(){
	printf("\n");
	printf("###################################\n");
	printf("###\t Cuadrado Magico \t###\n");
	printf("###################################\n");
	printf("\n");
}

/*
	Funcion que pide valores de la matriz para llenarla.
*/
void pedirValores(int cuadrante[NFIL][NCOL], int filas, int columnas){
	int i,j;	
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("Valor <%d,%d>: ",i,j);
			scanf("%d", &cuadrante[i][j]); 
		}
	}
}

/*
	Funcion que recorre el vector de las sumas y pregunta si cada valor es igual
	a la constante magica, en el momento que una suma no se igual.
	Devuelve 0 si no es magica y 1 si es magica.
*/
int esCuadradoMagico(int vSumas[NFIL], int tamanioSumas, int constanteMagica){
	int i,esMagico=1;	
	for(i=0;i<tamanioSumas;i++){
		if(vSumas[i]!=constanteMagica){
			esMagico = 0;
		}
	}
	return esMagico;
}
/*
	Funcion que suma la diagonal Invertida de la matriz. Con la variable auxiliar
	que va del tamanio de las columnas a 0 restandose cada fila para solo imprimir
	las columnas que nos interesan.
	Devuelve la suma total de dicha diagonal.
*/
int sumarDiagonalInvertida(int cuadrante[NFIL][NCOL], int filas, int columnas){
	int i,j,suma=0,aux=columnas-1;
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			if(aux==j){			
				suma+=cuadrante[i][j];
			}
		}
		aux--;
	}
	return suma;
}

/*
	Funcion que imprime la diagonal principal, recorriendo la matriz con una sola 
	variable contador para sumar los valores que nos interesan
	Devuelve la suma total de dicha diagonal.
*/
int sumarDiagonalPrincipal(int cuadrante[NFIL][NCOL], int filas, int columnas){
	int i,suma=0;
	for(i=0;i<filas;i++){
		suma+=cuadrante[i][i];
	}
	return suma;
}

/*
	Funcion que suma la columna indicada en la variable que se le pasa
	Devuelve la suma total de dicha columna.
*/
int sumarColumna(int cuadrante[NFIL][NCOL], int filas, int columnas, int columna){
	int i,j,suma=0;
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			if(j==columna){
				suma+=cuadrante[i][j];
			}
		}
	}
	return suma;
}
/*
	Funcion que suma la fila indicada en la variable que se le pasa
	Devuelve la suma total de dicha fila.
*/
int sumarFila(int cuadrante[NFIL][NCOL], int filas, int columnas, int fila){
	int i,j,suma=0;
	for(i=0;i<filas;i++){
		if(i==fila){
			for(j=0;j<columnas;j++){
				suma+=cuadrante[i][j];
			}
		}
	}
	return suma;
}
