#include <stdio.h>
#include <stdlib.h>
typedef struct Numero Numero;
struct Numero{
    int digito;
    struct Numero * siguiente;
    struct Numero * anterior;
};
Numero *inicio1=NULL;
Numero *ultimo1=NULL;
Numero *inicio2=NULL;
Numero *ultimo2=NULL;
Numero *inicios=NULL;
Numero *ultimos=NULL;
Numero *inicior=NULL;
Numero *ultimor=NULL;
Numero *iniciom=NULL;
Numero *ultimom=NULL;
void creareinsertar1(int dato);
void creareinsertar2(int dato);
void imprimirresultado1();
void imprimirresultado2();
void imprimirresultado3();
void suma();
void resta();
void multiplicacion();
int main(int argc, const char * argv[]){
    long numero1, numero2;
    int digito, filas=0, columnas=0;
    printf("Inserte numero 1: ");
    scanf("%ld", &numero1);
    printf("Inserte numero 2: ");
    scanf("%ld", &numero2);
    while(numero1>=1){
        digito=numero1%10;
        numero1/=10;
        creareinsertar1(digito);
        columnas++;
        //printf("%i", digito);
    }
    printf(" \n");
    while(numero2>=1){
        digito=numero2%10;
        numero2/=10;
        creareinsertar2(digito);
        filas++;
       // printf("%i ", digito);
    }
    suma();
    imprimirresultado1();
    resta();
    imprimirresultado2();
    multiplicacion();
    imprimirresultado3();
return 0;
}
void creareinsertar1(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    if (inicio1==NULL){
        inicio1=Nuevodigito;
        ultimo1=Nuevodigito;
        aux=inicio1;
    }
    else{
        if(ultimo1->anterior!=NULL){
            aux=ultimo1->anterior;
            while (aux->anterior!=NULL) {
                aux=aux->anterior;
            }
            Nuevodigito->siguiente=aux;
            aux->anterior=Nuevodigito;
            inicio1=Nuevodigito;
        }
        else{
            inicio1=Nuevodigito;
            inicio1->siguiente=ultimo1;
            ultimo1->anterior=Nuevodigito;
        }
    }
}
void creareinsertar2(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    if (inicio2==NULL){
        inicio2=Nuevodigito;
        ultimo2=Nuevodigito;
    }
    else{
        if(ultimo2->anterior!=NULL){
            aux=ultimo2->anterior;
            while (aux->anterior!=NULL) {
                aux=aux->anterior;
            }
            Nuevodigito->siguiente=aux;
            aux->anterior=Nuevodigito;
            inicio2=Nuevodigito;
        }
        else{
            inicio2=Nuevodigito;
            inicio2->siguiente=ultimo1;
            ultimo2->anterior=Nuevodigito;
        }
    }
}
void imprimirresultado2(){
    
    Numero *aux=inicior->anterior;
    while (aux!=NULL) {
        printf("%d", aux->digito);
        aux=aux->siguiente;
    }
    
}
void suma(){
    Numero * aux1=ultimo1;
    Numero * aux2=ultimo2;
    Numero *sumalist;
    if(aux1==NULL || aux2==NULL){
        printf("Una de las dos listas estan vacias\n");
    }
    else{
        int sumadigito, acarreo=0, sumadigito1;
        while(aux1!=NULL || aux2!=NULL){
            sumadigito=(aux1->digito)+(aux2->digito)+acarreo;
            sumadigito1=sumadigito%10;
            acarreo/=10;
            sumalist=malloc(sizeof(Numero));
            sumalist->digito=sumadigito1;
            sumalist->anterior=NULL;
            sumalist->siguiente=NULL;
            if(inicios==NULL){
                inicios=sumalist;
                ultimos=inicios;
            }
            else{
                if(ultimos->anterior!=NULL){
                    inicios=ultimos->anterior;
                    while (inicios->anterior!=NULL) {
                        inicios=inicios->anterior;
                    }
                    sumalist->siguiente=inicios;
                    inicios->anterior=sumalist;
                }
                else{
                    inicios=sumalist;
                    inicios->siguiente=ultimos;
                    ultimos->anterior=sumalist;
                }
            }
            aux1=aux1->anterior;
            aux2=aux2->anterior;
        }
    }
}
void imprimirresultado1(){
    
    Numero *aux=inicios->anterior;
    while (aux!=NULL) {
        printf("%d", aux->digito);
        aux=aux->siguiente;
    }
}
void resta(){
    Numero * aux1=ultimo1;
    Numero * aux2=ultimo2;
    Numero *restalist;
    if(aux1==NULL || aux2==NULL){
        printf("Una de las dos listas estan vacias\n");
    }
    else{
        int restadigito;
        while(aux1!=NULL || aux2!=NULL){
            if((inicio1->digito)>(inicio2->digito)){
                if((aux1->digito)>(aux2->digito)){
                    restadigito=(aux1->digito)-(aux2->digito);
                }
                else{
                    restadigito=((aux1->digito+10))-(aux2->digito);
                    aux1->anterior->digito+=-1;
                }
            }
            else{
                if(aux1==inicio1 || aux2==inicio2){
                    restadigito=(aux2->digito)-(aux1->digito);
                    restadigito=restadigito*1;
                }
                else{
                    if((aux2->digito)>(aux1->digito)){
                        restadigito=(aux2->digito)-(aux1->digito);
                    }
                    else{
                        restadigito=((aux2->digito+10))-(aux1->digito);
                        aux2->anterior->digito+=-1;
                    }
                }
            }
            restalist=malloc(sizeof(Numero));
            restalist->digito=restadigito;
            restalist->anterior=NULL;
            restalist->siguiente=NULL;
            if(inicios==NULL){
                inicios=restalist;
                ultimos=inicios;
            }
            else{
                if(ultimos->anterior!=NULL){
                    inicios=ultimos->anterior;
                    while (inicios->anterior!=NULL) {
                        inicios=inicios->anterior;
                    }
                    restalist->siguiente=inicios;
                    inicios->anterior=restalist;
                }
                else{
                    inicios=restalist;
                    inicios->siguiente=ultimos;
                    ultimos->anterior=restalist;
                }
            }
            aux1=aux1->anterior;
            aux2=aux2->anterior;
        }
    }
}
void multip(int dato){
    for(int i=0;i<dato;i++){
        Numero *Nuevodigito = malloc(sizeof(Numero));
        Nuevodigito->digito = 10;
        Nuevodigito->anterior=NULL;
        Nuevodigito->siguiente=NULL;
        Numero *aux;
        if (iniciom==NULL){
            iniciom=Nuevodigito;
            ultimom=Nuevodigito;
        }
        else{
            if(ultimom->anterior!=NULL){
                aux=ultimom->anterior;
                while (aux->anterior!=NULL) {
                    aux=aux->anterior;
                }
                Nuevodigito->siguiente=aux;
                aux->anterior=Nuevodigito;
                iniciom=Nuevodigito;
            }
            else{
                iniciom=Nuevodigito;
                iniciom->siguiente=ultimom;
                ultimom->anterior=Nuevodigito;
            }
        }
    }
}
void multiplicacion(){
    int acarreo=0,acarreos=0,digito,multi;
    Numero *aux2=ultimo2;
    int a2=0;
    while(aux2!=NULL){
        Numero *aux1=ultimo1;
        Numero *aux3=ultimom;
        acarreo=0;
        acarreos=0;
        for(int ac=0;ac<a2;ac++){
            aux3=aux3->anterior;
        }
        while(aux1!=NULL){
            multi=((aux1->digito)*(aux2->digito))+acarreo;
            acarreo = multi/10;
            digito = multi%10;
            if(aux3->digito==10){
                aux3->digito=((aux3->digito)-10)+digito;
            }
            else{
                aux3->digito=(aux3->digito)+digito+acarreos;
                acarreos=(aux3->digito)/10;
                (aux3->digito)=(aux3->digito)%10;
            }
            aux3=aux3->anterior;
            aux1 = aux1->anterior;
        }
        if(acarreo>0){
            aux3->digito=((aux3->digito)-10)+acarreo;
        }
        aux2=aux2->anterior;
        a2+=1;
    }
}
void imprimirresultado3(){
    Numero *aux=iniciom->anterior;
    while (aux!=NULL) {
        printf("%d", aux->digito);
        aux=aux->siguiente;
    }
}
