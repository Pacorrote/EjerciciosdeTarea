//
//  main.c
//  Shuting-yard
//
//  Created by Usuario on 04/09/18.
//  Copyright © 2018 Usuario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Nodo Nodo;

struct Nodo{
    char dato;
    Nodo* siguiente;
    Nodo* anterior;
};
Nodo* inicio1 = NULL;
Nodo* anterior1 = NULL;
Nodo* inicio2 = NULL;
Nodo* anterior2 = NULL;
Nodo* inicio3 = NULL;
Nodo* anterior3 = NULL;
Nodo* inicio4 = NULL;
Nodo* anterior4 = NULL;
Nodo* crearNodo(char dato){
    Nodo* Nuevonodo=NULL;
    Nuevonodo=(Nodo*)malloc(sizeof(Nodo));
    if(Nuevonodo!=NULL){
        Nuevonodo->dato=dato;
        Nuevonodo->siguiente= NULL;
        Nuevonodo->anterior=NULL;
    }
    return Nuevonodo;
}

void insertarCola1(char dato){
    Nodo* nuevo = crearNodo(dato);
    if(inicio1==NULL){
        inicio1=nuevo;
        anterior1=nuevo;
    }else{
        nuevo->anterior=anterior1;
        anterior1->siguiente=nuevo;
        anterior1=nuevo;
    }
}

void insertarPila1(char dato){
    Nodo* nuevo = crearNodo(dato);
    if(inicio2==NULL){
        inicio2=nuevo;
        anterior2=nuevo;
    }else{
        nuevo->anterior=inicio2;
        inicio2->siguiente=nuevo;
        inicio2=nuevo;
    }
}
void insertarCola2(char dato){
    Nodo* nuevo = crearNodo(dato);
    if(inicio3==NULL){
        inicio3=nuevo;
        anterior3=nuevo;
    }else{
        nuevo->anterior=anterior3;
        anterior3->siguiente=nuevo;
        anterior3=nuevo;
    }
}

void insertarPila2(float dato){
    Nodo* nuevo = crearNodo(dato);
    if(inicio4==NULL){
        inicio4=nuevo;
        anterior4=nuevo;
    }else{
        nuevo->anterior=inicio4;
        inicio4->siguiente=nuevo;
        inicio4=nuevo;
    }
}

void ShutPolaca(){
    Nodo *aux1 = inicio1;
    while(aux1->siguiente!=NULL){
        char ca=aux1->dato;
        Nodo *aux2=inicio2;
        switch(ca){
            case '(':
                insertarPila(ca);
                break;
            case '+':
            case '-':
                if(aux2==NULL){
                    insertarPila(ca);
                }
                else{
                    while(aux2->dato=='*'||aux2->dato=='/'||aux2->dato=='^'){
                        insertarCola2(aux2->dato);
                        inicio2=inicio2->anterior;
                        aux2->anterior=NULL;
                        aux2->siguiente=NULL;
                        inicio2->siguiente=NULL;
                        free(aux2);
                        aux2=inicio2;
                    }
                    insertarPila(ca);
                }
                break;
            case '*':
            case '/':
                if(aux2==NULL){
                    insertarPila(ca);
                }
                else{
                    while(aux2->dato=='^'){
                        insertarCola2(aux2->dato);
                        inicio2=inicio2->anterior;
                        aux2->anterior=NULL;
                        aux2->siguiente=NULL;
                        inicio2->siguiente=NULL;
                        free(aux2);
                        aux2=inicio2;
                    }
                    insertarPila(ca);
                }
                break;
            case '^':
                insertarPila(ca);
                break;
            case ')':
                while((aux2->dato)!='('){
                    insertarCola2(aux2->dato);
                    inicio2=inicio2->anterior;
                    aux2->anterior=NULL;
                    aux2->siguiente=NULL;
                    inicio2->siguiente=NULL;
                    free(aux2);
                    aux2=inicio2;
                }
                break;
            default:
                insertarCola2(ca);
        }
        aux1=aux1->siguiente;
    }
    Nodo *aux2=inicio2;
    while(aux2!=NULL){
        if(aux2->dato!='('){
            insertarCola2(aux2->dato);
        }
        aux2=aux2->anterior;
    }
}

void desarser(){
    float resultado;
    Nodo *aux=inicio3;
    while(aux!=NULL){
        Nodo *aux2=inicio4;
        switch(aux->dato){
            case '+':
                resultado=(inicio4->anterior->dato)+(inicio4->dato);
                if(aux2->anterior->anterior!=NULL){
                    inicio4=aux2->anterior->anterior;
                    inicio4->siguiente=NULL;
                    inicio4->anterior=aux2->anterior->anterior->anterior;
                    free(aux2);
                    free(aux2->anterior);
                    //printf("suma %i",inicio4->dato);
                }
                else{
                    inicio4=NULL;
                }
                insertarPila2(resultado);
                break;
            case '-':
                resultado=(inicio4->anterior->dato)-(inicio4->dato);
                if(aux2->anterior->anterior!=NULL){
                    inicio4=aux2->anterior->anterior;
                    inicio4->siguiente=NULL;
                    inicio4->anterior=aux2->anterior->anterior->anterior;
                    free(aux2);
                    free(aux2->anterior);
                }
                else{
                    inicio4=NULL;
                }
                insertarPila2(resultado);
                break;
            case '*':
                resultado=((inicio4->anterior->dato)*(inicio4->dato));
                if(aux2->anterior->anterior!=NULL){
                    inicio4=aux2->anterior->anterior;
                    inicio4->siguiente=NULL;
                    inicio4->anterior=aux2->anterior->anterior->anterior;
                    free(aux2);
                    free(aux2->anterior);
                }
                else{
                    inicio4=NULL;
                }
                insertarPila2(resultado);
                break;
            case '/':
                resultado=((inicio4->anterior->dato)/(inicio4->dato));
                if(aux2->anterior->anterior!=NULL){
                    inicio4=aux2->anterior->anterior;
                    inicio4->siguiente=NULL;
                    inicio4->anterior=aux2->anterior->anterior->anterior;
                    free(aux2);
                    free(aux2->anterior);
                }
                else{
                    inicio4=NULL;
                }
                insertarPila2(resultado);
                break;
            case '^':
                resultado=pow((inicio4->anterior->dato),(inicio4->dato));
                if(aux2->anterior->anterior!=NULL){
                    inicio4=aux2->anterior->anterior;
                    inicio4->siguiente=NULL;
                    inicio4->anterior=aux2->anterior->anterior->anterior;
                    free(aux2);
                    free(aux2->anterior);
                }
                else{
                    inicio4=NULL;
                }
                insertarPila2(resultado);
                break;
            default:
                resultado=(aux->dato)-48;
                insertarPila2(resultado);
        }
        aux=aux->siguiente;
    }
    printf("El resultado es: %.2f",resultado);
}

void leerCola(){
    Nodo *aux = inicio1;
    while(aux!=NULL){
        printf("%c", aux->dato);
        aux = aux->siguiente;
    }
}

void leerCola2(){
    Nodo *aux = inicio3;
    while(aux!=NULL){
        printf("%c", aux->dato);
        aux = aux->siguiente;
    }
}


int main(){
    char p[20];
    int ca=0;
    for(int i=0;i<20;i++){
        p[i]='.';
    }
    printf("Ingresa una ecuacion\n");
    scanf("%s",&p[0]);
    while(p[ca]!='.'){
        char pa=p[ca];
        insertarCola(pa);
        ca+=1;
    }
    leerCola();
    printf("\nNotacion Polaca:\t");
    ShutPolaca();
    leerCola2();
    printf("\n\t");
    desarser();
    return 0;
}
