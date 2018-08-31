#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int digito;
	struct Numero * siguiente;
	struct Numero * anterior;
}Numero;
Numero *inicio1=NULL;
Numero *ultimo1=NULL;
Numero *inicio2=NULL;
Numero *ultimo2=NULL;

void creareinsertar1(int dato);
void creareinsertar2(int dato);
Numero *creareinsertarresultado(int dato);
void suma();
void resta();
int main(int argc, char *argv[]) {
	
	return 0;
}
void creareinsertar1(int dato){
	Numero *Nuevodigito = malloc(sizeof(Numero));
	Nuevodigito->digito = dato;
	Nuevodigito->anterior=NULL;
	Nuevodigito->siguiente=NULL;
	Numero *de;
	Numero *at;
	Numero *aux;
	if (inicio1==NULL){
		inicio1=Nuevodigito;
		ultimo1=Nuevodigito;
		de=inicio1;
		at=inicio1;
		aux=inicio1;
	}
	else{
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
			de=aux;
			ultimo1=de;
		}
		de->siguiente=Nuevodigito;
		Nuevodigito->anterior=at;
		de=Nuevodigito;
		ultimo1=de;
		aux=ultimo1;
		at=aux;
	}
}
void creareinsertar2(int dato){
	Numero *Nuevodigito = malloc(sizeof(Numero));
	Nuevodigito->digito = dato;
	Nuevodigito->anterior=NULL;
	Nuevodigito->siguiente=NULL;
	Numero *de;
	Numero *at;
	Numero *aux;
	if (inicio2==NULL){
		inicio2=Nuevodigito;
		ultimo2=Nuevodigito;
		de=inicio2;
		at=inicio2;
		aux=inicio2;
	}
	else{
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
			de=aux;
			ultimo2=de;
		}
		de->siguiente=Nuevodigito;
		Nuevodigito->anterior=at;
		de=Nuevodigito;
		ultimo2=de;
		aux=ultimo2;
		at=aux;
	}
}
void suma(){
	Numero * aux1=ultimo1;
	Numero * aux2=ultimo2;
	if(aux1==NULL || aux2==NULL){
		printf("Una de las dos listas estan vacias\n");
	}
	else{
		int sumadigito, acarreo=0, sumadigito1;
		while(aux1!=NULL || aux2!=NULL){
			sumadigito=(aux1->digito)+(aux2->digito)+acarreo;
			sumadigito1=sumadigito%10;
			
		}
	}
}

