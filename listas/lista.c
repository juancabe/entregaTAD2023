#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}



int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf(" %d ",aImprimir->elemento);
            // "Las funciones a implementar no mostrarán ningún mensaje por pantalla, en ningún caso."
            aImprimir = aImprimir->sig;
        }
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return NULL;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}

tipoPosicion
primero(Lista *l)
{
 if (l == NULL) {
        return NULL;
    }
    else
        return l->raiz;
    
}



tipoPosicion
fin(Lista *l)
{
    if (l == NULL) {
        return NULL;
    }
    else if (l->ultimo == NULL){
        return NULL;
    }
    else
        return l->ultimo;
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
    tipoCelda *nuevo;
    
    if (l == NULL) {
        return -1;
    }
    else if (l->raiz == NULL) {
        return -2;
    }
    else if (p == NULL){
        return -3;
    }
    else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
        return -4;
    }
    else {
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo)
            l->ultimo = nuevo;
        return 0;
    }
}


int
suprime (tipoPosicion p, Lista *l)
{
    
    if (l == NULL || l->raiz == NULL || p == NULL || p->sig == NULL) {
        return 0;
    }
    else {
        
        tipoPosicion aux = p->sig;
        
        p->sig = p->sig->sig;

        free(aux);

        return 1;

    }
    
}



tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    
    if (l == NULL || l->raiz == NULL || p == NULL || p->sig == NULL) {
        return NULL;
    }
    else {
        return p->sig;
    }
   
    
}




tipoPosicion
localiza (tipoElemento x, Lista *l)
{

    tipoCelda *aux;
    
    if (l == NULL || l->raiz == NULL) {
        return NULL;
    }
    else {

        aux = l->raiz;

        while (aux->sig != l->ultimo && aux->sig->elemento != x)
            aux = aux->sig;

        if(aux->sig->elemento == x)
            return aux;

        return NULL;
    }
	
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    tipoCelda *aux;
    
    if (l == NULL || l->raiz == NULL || p == NULL || p->sig == NULL) {
        if(l->raiz == NULL)
            return -1;
        else if(p == NULL)
            return -2;
        else if(p->sig == NULL)
            return -3;
        else
            return -4;
        return 0;
    }
    else {
        
        return p->sig->elemento;

    }
    
}


int
anula(Lista *l)
{
    tipoPosicion aux = primero(l)->sig;

    while(aux != NULL){
        aux = aux->sig;
        free(aux);
    }

    l->raiz;
    l->ultimo = l->raiz;
    
}

tipoElemento recuperaUltimo(Lista *l){

    if(l == NULL || l->ultimo == NULL)
        return -1;

    return l->ultimo->elemento;

}


int traspasarNodo(tipoPosicion p, Lista *la, tipoPosicion q, Lista *lb){

    /*
    if(la == NULL || la->raiz == NULL || la->ultimo == NULL){
        return -1;
    }
    if(lb == NULL || lb->raiz == NULL || lb->ultimo == NULL){
        return -2;
    }
    */

    if(p == NULL || p->sig == NULL || q == NULL || q->sig == NULL){
            return -3;
        }

    tipoPosicion aux = p->sig;
    p->sig = p->sig->sig;

    aux->sig = q->sig;
    q->sig = aux;
    

}


int dividirLista(Lista *lOrigen, tipoPosicion p, Lista *lNueva){

    if(lOrigen == NULL || lOrigen->raiz == NULL || lOrigen->ultimo == NULL){
        return -1;
    }
    if(lNueva == NULL || lNueva->raiz == NULL || lNueva->ultimo == NULL){
        return -2;
    }
    if(p == NULL || p->sig == NULL){
        return -3;
    }

    lNueva->raiz->sig = p->sig->sig;

    p->sig->sig == NULL;

}

