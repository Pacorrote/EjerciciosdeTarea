//
//  main.c
//  POLINOMIOS
//
//  Created by Usuario on 28/08/18.
//  Copyright © 2018 Usuario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodou Nodou;
struct Nodou{
    int coeficiente;
    int potencia;
    struct Nodou * siguiente;
};
Nodou * inicio1 = NULL;
Nodou * ultimo1 = NULL;
Nodou * inicio2 = NULL;
Nodou * ultimo2 = NULL;
Nodou * inicio = NULL;
Nodou * ultimo = NULL;
Nodou * inicior = NULL;
Nodou * ultimor = NULL;

void creareinsertar1(int coeficiente, int potencia);
void creareinsertar2(int coeficiente, int potencia);
Nodou * creareinsertarresultado(int coeficiente, int potencia, int opcion);
void ordenarpolinomio1();
void simplificarpolinimio1();
void ordenarpolinomio2();
void simplificarpolinimio2();
void suma();
void resta();
void imprimirresultado1();
void imprimirresultado2();
void imprimirresultado3();
void imprimirresultado4();
int main(int argc, const char * argv[]) {
    int coeficiente1, coeficiente2, potencia1, potencia2;
    int polinomios1, polinomios2;
    printf("Inserte el numero de terminos a ingresar: ");
    scanf("%d", &polinomios1);
    for(int i=0; i<polinomios1; i++){
        printf("Inserte coefinciente y potencia: ");
        scanf("%d %d", &coeficiente1, &potencia1);
        creareinsertar1(coeficiente1, potencia1);
    }
    printf("Inserte el numero de terminos a ingresar: ");
    scanf("%d", &polinomios2);
    for(int i=0; i<polinomios2; i++){
        printf("Inserte coefinciente y potencia: ");
        scanf("%d %d", &coeficiente2, &potencia2);
        creareinsertar2(coeficiente2, potencia2);
    }
    imprimirresultado1();
    printf("\n\n");
    imprimirresultado2();
    printf("\n\n");
    ordenarpolinomio1();
    imprimirresultado3();
    printf("\n\n");
    ordenarpolinomio2();
    imprimirresultado4();
    //printf("\n\n");
    //simplificarpolinimio1();
    //imprimirresultado3();
    /*printf("\n\n");
    simplificarpolinimio2();
    imprimirresultado4();*/
    return 0;
}
void creareinsertar1(int coeficiente, int potencia){
    Nodou *Nuevonodo=malloc(sizeof(Nodou));
    Nuevonodo->coeficiente=coeficiente;
    Nuevonodo->potencia=potencia;
    Nuevonodo->siguiente=NULL;
    Nodou *aux;
    if (inicio1==NULL){
        inicio1=Nuevonodo;
        ultimo1=Nuevonodo;
        aux=inicio1;
    }
    else{
        aux=inicio1;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
            ultimo1=aux;
        }
        aux->siguiente=Nuevonodo;
        ultimo1->siguiente=aux->siguiente;
        aux=Nuevonodo;
        ultimo1=aux;
    }
}
void creareinsertar2(int coeficiente, int potencia){
    Nodou *Nuevonodo=malloc(sizeof(Nodou));
    Nuevonodo->coeficiente=coeficiente;
    Nuevonodo->potencia=potencia;
    Nuevonodo->siguiente=NULL;
    Nodou *aux;
    if (inicio2==NULL){
        inicio2=Nuevonodo;
        ultimo2=Nuevonodo;
        aux=inicio2;
    }
    else{
        aux=inicio2;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
            ultimo2=aux;
        }
        aux->siguiente=Nuevonodo;
        ultimo2->siguiente=aux->siguiente;
        aux=Nuevonodo;
        ultimo2=aux;
    }
}
void imprimirresultado1(){
    
    Nodou *aux=inicio1;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void imprimirresultado2(){
    
    Nodou *aux=inicio2;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void ordenarpolinomio1(){
    if(inicio1!=NULL){
        Nodou *PIVOTE=inicio1;
        Nodou *aux=PIVOTE;
        if (PIVOTE->siguiente==NULL){
            printf("La lista solo contiene un monomio\n");
        }
        else{
            int auxpotencia, auxcoeficiente;
            while(PIVOTE->siguiente!=NULL){
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    if((PIVOTE->potencia) < (aux->potencia)){
                        auxpotencia=PIVOTE->potencia;
                        auxcoeficiente=PIVOTE->coeficiente;
                        PIVOTE->potencia=aux->potencia;
                        PIVOTE->coeficiente=aux->coeficiente;
                        aux->potencia=auxpotencia;
                        aux->coeficiente=auxcoeficiente;
                    }
                }
                PIVOTE=PIVOTE->siguiente;
                aux=PIVOTE;
            }
        }
    }
    else{
        printf("Lista vacia\n");
    }
}
void ordenarpolinomio2(){
    if(inicio2!=NULL){
        Nodou *PIVOTE=inicio2;
        Nodou *aux=PIVOTE;
        if (PIVOTE->siguiente==NULL){
            printf("La lista solo contiene un monomio\n");
        }
        else{
            int auxpotencia, auxcoeficiente;
            while(PIVOTE->siguiente!=NULL){
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    if((PIVOTE->potencia) < (aux->potencia)){
                        auxpotencia=PIVOTE->potencia;
                        auxcoeficiente=PIVOTE->coeficiente;
                        PIVOTE->potencia=aux->potencia;
                        PIVOTE->coeficiente=aux->coeficiente;
                        aux->potencia=auxpotencia;
                        aux->coeficiente=auxcoeficiente;
                    }
                }
                PIVOTE=PIVOTE->siguiente;
                aux=PIVOTE;
            }
            
        }
    }
    else{
        printf("Lista vacia\n");
    }
}
void imprimirresultado3(){
    Nodou *aux=inicio1;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void imprimirresultado4(){
    Nodou *aux=inicio2;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void simplificarpolinimio1(){
    Nodou *PIVOTE=inicio1;
    if(PIVOTE!=NULL){
        Nodou *aux=PIVOTE;
        while (PIVOTE->siguiente!=NULL) {
            aux=aux->siguiente;
            if(PIVOTE->potencia==aux->potencia && aux!=NULL){
                while(PIVOTE->potencia==aux->potencia && aux!=NULL && PIVOTE->siguiente!=NULL){
                    PIVOTE->coeficiente=PIVOTE->coeficiente+aux->coeficiente;
                    PIVOTE->siguiente=aux->siguiente;
                    aux->siguiente=NULL;
                    free(aux);
                    aux=PIVOTE->siguiente;
                }
            }
            PIVOTE=PIVOTE->siguiente;
            aux=PIVOTE;
        }
    }
    else
        printf("Lista vacia");
}
void simplificarpolinimio2(){
    Nodou *PIVOTE=inicio2;
    Nodou *aux=PIVOTE;
    while(PIVOTE->siguiente!=NULL){
        aux=aux->siguiente;
        if(PIVOTE->potencia==aux->potencia && PIVOTE!=NULL && aux!=NULL){
            do{
                PIVOTE->coeficiente+=aux->coeficiente;
                PIVOTE->siguiente=aux->siguiente;
                aux->siguiente=NULL;
                free(aux);
                if(PIVOTE->siguiente!=NULL)
                    aux=PIVOTE->siguiente;
                else
                    aux=PIVOTE;
            }while(PIVOTE->potencia==aux->potencia && PIVOTE!=NULL && aux!=NULL);
        }
        PIVOTE=PIVOTE->siguiente;
        aux=PIVOTE;
    }
}



