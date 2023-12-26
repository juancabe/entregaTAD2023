#include <stdio.h>
#include <stdlib.h>
#include "listas/lista.h"
#include "insercion.h"
#include <time.h>

int main(int argc, char *argv[])
{ 
	//clock_t tiempoInicial , tiempoFinal ;
	double tiempoInicial , tiempoFinal, tiempoMinimo=1*CLOCKS_PER_SEC ;
	
	double tiempo;

	int *vector, *vectorOrdenado, rango=100000, numElementos=10000,i,repeticiones=0;
        
	FILE *f;  
 	
	if (argc != 2) {
		printf("\n Uso: ./eje1 <nombre fichero resultados>\n\n");
		return -1;
	}

	f = fopen(argv[1], "w+");
	fprintf(f,"n           ;tiempoMedio;  repeticiones\n");

	

	for (numElementos=500;numElementos<=6000;numElementos=500+numElementos*3) {
        
		Lista miLista;
		tipoPosicion p;

		repeticiones=0;
		creaVacia(&miLista);
		anula(&miLista);	
		p = primero(&miLista);
		for (int i = 0; i < numElementos; i++) { 
			inserta(rand()%100000,p,&miLista);
			p = siguiente(p,&miLista);
		}
		printf("\n Lista creada con %d elementos\n",numElementos);
		tiempoInicial = tiempoFinal= (double)clock();

		while (tiempoFinal-tiempoInicial < tiempoMinimo) 
		{ 	
			insercion(&miLista);
			repeticiones++;
		    tiempoFinal = (double) clock();
			fprintf(stderr, " %d ;%g ; %d \n", numElementos,tiempo,repeticiones);
		}

		tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
		printf( "\n Elementos: %d Tiempo :%g Repeticiones: %d \n", numElementos, tiempo, repeticiones);
		fprintf(f, " %d ;%g ; %d \n", numElementos,tiempo,repeticiones);

		anula(&miLista);
		destruye(&miLista);
	}
   	fclose(f);
return 0;
}


