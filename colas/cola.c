#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    
    if(NULL == (c = malloc(sizeof(Cola)))){
        c->fondo = NULL;
        c->frente = NULL;
        return 1;
    }
    else{
        return 0;
    }
    
}

int colaVacia(Cola *c)
{
    if(c->fondo = NULL && c->frente == NULL){
        return 1;
    }
    else{
        return 0;
    }          
    
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    tipoCelda * celda;
    
    if(c == NULL){
        return 0;
    }
    if(NULL == (celda = malloc(sizeof(tipoCelda)))){
        return 0;
    }

    celda->elemento = elemento;
    celda->sig = NULL;

    if(c->fondo == NULL || c->frente == NULL){
        c->fondo = elemento;
        c->frente = elemento;
        return 1;
    }
    else{
        c->fondo->sig = elemento;
        c->fondo = elemento;
        return 1;
    }
    
}

tipoElemento colaSuprime(Cola *c)
{
    if(c == NULL){
        return 0;
    }
    if(c->fondo == NULL || c->frente == NULL){
        return 0;
    }

    tipoElemento elemento = c->frente->elemento;
    tipoCelda * celdaPointAux = c->frente->sig;

    free(c->frente);

    if(c->frente == c->fondo){
        c->frente = celdaPointAux;
        c->fondo = celdaPointAux;
    }
    else{
        c->frente = celdaPointAux;
    }

    return elemento;
        
}
