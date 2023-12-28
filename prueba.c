#include "listas/lista.h"
#include <stdio.h>
void main(){

    Lista l, l0;

    creaVacia(&l);
    printf("\ncreaVacia:");
    printf("\n");imprime(&l);printf("\n");


    anula(&l);
    printf("\nanula:");
    printf("\n");imprime(&l);printf("\n");


    printf("\n¿Vacia?: %d\n", vacia(&l));

    inserta(1, primero(&l), &l);
    printf("\ninserta 1:");
    printf("\n");imprime(&l);printf("\n");

    suprime(primero(&l), &l);
    printf("\nsuprime 1:");
    printf("\n");imprime(&l);printf("\n");

    inserta(1, primero(&l), &l);
    inserta(2, primero(&l), &l);
    inserta(3, primero(&l), &l);
    inserta(4, primero(&l), &l);
    printf("\ninserta 4 3 2 1:");
    printf("\n");imprime(&l);printf("\n");


    printf("\n localiza el 3, recupera el %d\n", recupera(localiza(3, &l), &l));

    printf("\nEl primero es %d\n", recupera(primero(&l), &l));
    printf("\nEl ultimo es %d\n", recupera(anterior(fin(&l), &l), &l));
    printf("\nEl ultimo es %d\n", recuperaUltimo(&l));
    printf("\nEl anterior al ultimo es %d\n", recupera(anterior(anterior(fin(&l), &l), &l), &l));
    printf("\nEl siguiente al primero es %d\n", recupera(siguiente(primero(&l), &l), &l));

    printf("\ndestruye de una lista no vacia: %i", destruye(&l));
    printf("\n");imprime(&l);printf("\n");
    
    anula(&l);
    printf("\nVaciando...\n¿Vacia?: %d\n", vacia(&l));
    printf("\ndestruye de una lista vacia: %i", destruye(&l));
    printf("\n");imprime(&l);printf("\n");

    // Creamos dos listas para probar las siguientes funciones
    creaVacia(&l);
    creaVacia(&l0);
    inserta(1, primero(&l), &l);inserta(2, primero(&l), &l);inserta(3, primero(&l), &l);inserta(4, primero(&l), &l);
    inserta(10, primero(&l0), &l0);inserta(20, primero(&l0), &l0);inserta(30, primero(&l0), &l0);inserta(40, primero(&l0), &l0);

    printf("\nl: ");imprime(&l);printf("\n");
    printf("\nl0: ");imprime(&l0);printf("\n");

    traspasarNodo(primero(&l), &l, primero(&l0), &l0);
    printf("\ntraspasarNodo primero a primero...\n");
    printf("\nl: ");imprime(&l);printf("\n");
    printf("\nl0: ");imprime(&l0);printf("\n");

    anula(&l0);
    printf("\nanula l0...\n");
    printf("\n ¿Vacia l0?: %d\n", vacia(&l0));

    dividirLista(&l, localiza(3, &l), &l0);
    printf("\ndividir l en l0 a partrir del elemento 2\n");
    printf("\nl: ");imprime(&l);printf("\n");
    printf("\nl0: ");imprime(&l0);printf("\n");

}