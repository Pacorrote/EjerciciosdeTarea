#include <stdio.h>
#include <stdlib.h>

FILE *file;

typedef struct Nodo Nodo;
struct Nodo{
	char caracter;
	Nodo *siguiente;
};

Nodo *inicio=NULL;

Nodo *CrearNuevoNodo(char caracter){
	Nodo *Nuevonodo=NULL;
	Nuevonodo=(Nodo *)malloc(sizeof(Nodo));
	if(Nuevonodo!=NULL){
		Nuevonodo->caracter=caracter;
		Nuevonodo->siguiente=Nuevonodo;
	}
	return Nuevonodo;
}

void CrearArchivo(){
	
	file = fopen("mensaje.txt","wt");
	if(file==NULL){
		printf("Archivo inexistente");
	}else{
		fprintf(file, "Hola a todos, este archivo esta encriptado");
	}
	fclose(file);
}
void InsertarNodo(char caracter){
	Nodo *Nuevonodo = CrearNuevoNodo(caracter);
	if(inicio==NULL){
		inicio = Nuevonodo;
	}else{
		Nodo *aux = inicio;
		while(aux->siguiente!=inicio){
			aux = aux->siguiente;
		}
		aux->siguiente = Nuevonodo;
		Nuevonodo->siguiente = inicio;
	}
}

void Imprimir(){
	if(inicio!=NULL){
		Nodo *aux = inicio;
		do{
			printf("%c", aux->caracter);
			aux = aux->siguiente;
		}while(aux != inicio);
	}
}

void encriptado(){
	FILE *encript;
	file = fopen("mensaje.txt", "w+");
	char caracter;
	int suma=0;
	Nodo *aux = inicio;
	while(feof(file)==0){
		caracter = fgetc(file);
		if (file==NULL)
			exit(1);
		int pas = aux->caracter;
		int ff = caracter;
		int encription = ff-pas;
		fwrite(&encription, sizeof(encription), 1, file);
		aux = aux->siguiente;
	}
	fclose(file);
}

void desencriptado(){
	file = fopen("mensaje.txt", "r+");
	char c;
	int suma=0;
	Nodo *aux = inicio;
	while(feof(file)==0){
		c = fgetc(file);
		int pas = aux->caracter;
		int ff = c;
		int encript = c-pas;
		fwrite(&encript, sizeof(encript), 1, file);
		aux = aux->siguiente;
	}
	fclose(file);
}

int main(){
	int o=0;
	char contrasenna[20];
	for(int i=0;i<20;i++){
		contrasenna[i]='*';
	}
	printf("Dame una contrasenna\n");
	scanf("%s",&contrasenna[0]);
	while(contrasenna[o]!='*'){
		insertar(contrasenna[o]);
		o+=1;
	}
	Imprimir();
	
	file = fopen("mensaje.txt","wt");
	if(file==NULL){
		printf("Archivo inexistente");
	}else{
		fprintf(file, "Hola a todos, este archivo esta encriptado");
	}
	fclose(file);
	file = fopen("mensaje.txt", "rb");
	char c1;
	while(feof(file)==0){
		c1 = fgetc(file);
	}
	encriptado();
	return 0;
}
