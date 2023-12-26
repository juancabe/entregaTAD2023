// Programa para probar todas las funciones del TAD Lista

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{   
    // Probaremos todas las funciones declaradas en el header lista.h

    Lista miLista;
    tipoPosicion p;
    int numElementos = 10;

    // Primero creamos una lista vacía

    printf("Creando lista vacía: %d\n", creaVacia(&miLista));

    // Ahora insertamos 10 elementos en la lista, seran el 1 2 3 4 5 6 7 8 9 10

    printf("Se crea una lista de %d elementos\n", numElementos);
    p = primero(&miLista);  // Obtenemos la primera posición de la lista
    for (int i = 0; i < numElementos; i++) { 
        inserta(i+1,p,&miLista);    // Insertamos el elemento i+1 en la posición p
        p = siguiente(p,&miLista);  // Obtenemos la siguiente posición de la lista
    }
    

    // Imprimimos la lista

    printf("Lista: ");
    imprime(&miLista);
    printf("\n");

    // Ahora probamos la función recupera

    printf("Recuperamos el elemento en la posición 5: %d\n", recupera(p, &miLista));
    
    // Probamos la función localiza

    printf("Localizamos el elemento 5: %p\n", localiza(5, &miLista));

    // Probamos la función anterior

    printf("El elemento anterior a la posición 5 es: %d\n", recupera(anterior(p, &miLista), &miLista));

    // Probamos la función siguiente

    printf("El elemento siguiente a la posición 5 es: %d\n", recupera(siguiente(p, &miLista), &miLista));

    // Probamos la función primero

    printf("El primer elemento de la lista es: %d\n", recupera(primero(&miLista), &miLista));

    // Probamos la función fin

    printf("El último elemento de la lista es: %d\n", recupera(fin(&miLista), &miLista));

    // Probamos la función vacia

    printf("La lista está vacía: %d\n", vacia(&miLista));

    // Probamos la función suprime

    printf("Suprimimos el elemento en la posición 5: %d\n", suprime(p, &miLista));

    // Imprimimos la lista

    printf("Lista: ");
    imprime(&miLista);

    // Probamos la función destruye

    printf("\nDestruimos la lista: %d\n", destruye(&miLista));

    // Probamos la función creaVacia

    printf("Creamos una lista vacía: %d\n", creaVacia(&miLista));

    // Probamos la función vacia

    printf("La lista está vacía: %d\n", vacia(&miLista));

    // Probamos la función destruye

    printf("Destruimos la lista: %d\n", destruye(&miLista));

    return 0;


}