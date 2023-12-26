#include "insercion.h"
#include "listas/lista.h"
#include <stdlib.h>

void ordenacionInsercion(Lista *l){

    tipoPosicion i = siguiente(primero(l), l), j;
    tipoElemento x;

    while(siguiente(i, l) != NULL){
        x = recupera(i, l);
        j = anterior(i, l);

        while(j != NULL && recupera(j, l) > x){
            suprime(siguiente(j, l), l);
            inserta(recupera(j, l), siguiente(j, l), l);
            j = anterior(j, l);
        }

        suprime(siguiente(j, l), l);
        inserta(x, siguiente(j, l), l);
        
    }

}