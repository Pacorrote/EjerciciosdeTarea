//
//  main.c
//  POLINOMIOS
//
//  Created by Usuario on 28/08/18.
//  Copyright © 2018 Usuario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int coeficiente;
	int potencia;
	struct Nodou * siguiente;
}Nodou;

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
int main(int argc, const char * argv[]) {

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
Nodou * creareinsertarresultado(int coeficiente, int potencia, int opcion){
	Nodou * Nuevonodo=malloc(sizeof(Nodou));
	switch(opcion){
	case 1:	
	Nuevonodo->coeficiente=coeficiente;
	Nuevonodo->potencia=potencia;
	Nuevonodo->siguiente=NULL;
	Nodou *aux1;
	if (inicio==NULL){
		inicio=Nuevonodo;
		ultimo=Nuevonodo;
		aux1=inicio;
	}
	else{
		while(aux1->siguiente!=NULL){
			aux1=aux1->siguiente;
			ultimo=aux1;
		}
		aux1->siguiente=Nuevonodo;
		ultimo->siguiente=aux1->siguiente;
		aux1=Nuevonodo;
		ultimo=aux1;
	}
	break;
	case 2:
		Nuevonodo->coeficiente=coeficiente;
		Nuevonodo->potencia=potencia;
		Nuevonodo->siguiente=NULL;
		Nodou *aux2;
		if (inicio==NULL){
			inicior=Nuevonodo;
			ultimor=Nuevonodo;
			aux2=inicior;
		}
		else{
			while(aux2->siguiente!=NULL){
				aux2=aux2->siguiente;
				ultimor=aux2;
			}
			aux2->siguiente=Nuevonodo;
			ultimor->siguiente=aux2->siguiente;
			aux2=Nuevonodo;
			ultimor=aux2;
		}
		break;
	}
	return opcion==1? inicio: inicior;
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

void simplificarpolinimio1(){
	Nodou * PIVOTE=inicio1;
	Nodou * aux=PIVOTE;
	ordenarpolinomio1();
	while(PIVOTE!=NULL){
		aux=aux->siguiente;
		if(aux->potencia==PIVOTE->potencia){
			PIVOTE->coeficiente+=aux->coeficiente;
			PIVOTE->siguiente=aux->siguiente;
			free(aux);
		}
		PIVOTE=PIVOTE->siguiente;
		aux=PIVOTE;
	}
}
void simplificarpolinimio2(){
	Nodou * PIVOTE=inicio2;
	Nodou * aux=PIVOTE;
	ordenarpolinomio2();
	while(PIVOTE!=NULL){
		aux=aux->siguiente;
		if(aux->potencia==PIVOTE->potencia){
			PIVOTE->coeficiente+=aux->coeficiente;
			PIVOTE->siguiente=aux->siguiente;
			free(aux);
		}
		PIVOTE=PIVOTE->siguiente;
		aux=PIVOTE;
	}
}
void suma(){
	Nodou * aux1=inicio1;
	Nodou * aux2=inicio2;
	
	while(aux1!=NULL || aux2!=NULL){
		if(aux1->potencia==aux2->potencia){
			Nodou * suma = creareinsertarresultado((aux1->coeficiente) + (aux2->coeficiente),aux2->potencia, 1);
		}
		aux1=aux1->siguiente;
		aux2=aux2->siguiente;
	}
}
void resta(){
	Nodou * aux1=inicio1;
	Nodou * aux2=inicio2;
	
	while(aux1!=NULL || aux2!=NULL){
		if(aux1->potencia==aux2->potencia){
			Nodou * resta = creareinsertarresultado((aux1->coeficiente) - (aux2->coeficiente),aux2->potencia, 2);
		}
		aux1=aux1->siguiente;
		aux2=aux2->siguiente;
	}
}

