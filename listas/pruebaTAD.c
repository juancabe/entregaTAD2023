#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{   

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


    // Ahora cambiaremos el valor del elemento de la posición 5 por el 100

    p = primero(&miLista);  // Obtenemos la primera posición de la lista
    

    printf("Cambiando el valor del elemento de la posición 5 por el 100\n");
    suprime(p, &miLista);
    inserta(100, p, &miLista);

    // Imprimimos la lista

    printf("Lista: ");
    imprime(&miLista);
    printf("\n");

    return 0;


}