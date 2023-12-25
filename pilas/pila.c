#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{

    *p = NULL;
    
}

int pilaVacia(Pila *p)
{
   if(*p == NULL)
   {
       return 1;
   }
   else
   {
       return 0;
   }
    
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    tipoCelda * new;

    if(NULL == (new = malloc(sizeof(tipoCelda)))){
        return 0;
    }
    
    new->sig = *p;
    new->elemento = elemento;

    *p = new;

    return 1;

}

tipoElemento pilaSuprime(Pila *p)
{

    if(*p == NULL){
        return 0;
    }
    else {

        tipoCelda * aux = (*p)->sig;
        tipoElemento devolver = (*p)->elemento;

        free(*p);
        *p = aux;

        return devolver;
    }

   
}
