#include "insercion.h"
#include "listas/lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void insercion(Lista *l){

    Lista * listaOrdenada;
    tipoPosicion desordenada;
    tipoPosicion ordenada;
    tipoElemento elementoDesordenada;

    if(NULL == (listaOrdenada = malloc(sizeof(Lista)))){
        return;
    }

    if(creaVacia(listaOrdenada) < 0){
        return;
    }

    do{
        desordenada = primero(l);
        elementoDesordenada = recupera(desordenada, l);
        suprime(desordenada, l);

        if(elementoDesordenada > recuperaUltimo(listaOrdenada)){
            inserta(elementoDesordenada, fin(listaOrdenada), listaOrdenada);
        }
        else if(elementoDesordenada < recupera(primero(listaOrdenada), listaOrdenada)){
            inserta(elementoDesordenada, primero(listaOrdenada), listaOrdenada);
        }
        else{
            ordenada = primero(listaOrdenada);

            fprintf(stderr, "Se mete :))))\n");

            do{ 

                if((elementoDesordenada > recupera(ordenada, listaOrdenada) && elementoDesordenada < recupera(siguiente(ordenada, listaOrdenada), listaOrdenada)) || elementoDesordenada == recupera(ordenada, listaOrdenada)){
                    inserta(elementoDesordenada, siguiente(ordenada, listaOrdenada), listaOrdenada);
                    break;
                }                
                
                ordenada = siguiente(ordenada, listaOrdenada);
                
            }while(ordenada != fin(listaOrdenada));

        }

        fprintf(stderr, "Lista ordenada: ");
        imprime(listaOrdenada);
        fprintf(stderr, "\n\n");

        fprintf(stderr, "Lista desordenada: ");
        imprime(l);
        fprintf(stderr, "\n\n");
        char desecho;
        scanf("%s", &desecho);

    }while(desordenada != fin(l));

}