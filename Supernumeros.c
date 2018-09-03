#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
Numero *creareinsertarresultado(int dato, int opcion);
void suma();
void resta();
void multiplicacion(int filas, int columnas);
void imprimirresultado(Numero *i);
int main(int argc, char *argv[]) {
    long numero1, numero2;
    int digito, filas=0, columnas=0;
    printf("Inserte numero 1: ");
    scanf("%ld", &numero1);
    printf("Inserte numero 2: ");
    scanf("%ld", &numero2);
    while(numero1>1){
        digito=numero1%10;
        numero1/=10;
        creareinsertar1(digito);
        columnas++;
    }
    while(numero2>1){
        digito=numero2%10;
        numero2/=10;
        creareinsertar1(digito);
        filas++;
    }
    suma();
    imprimirresultado(inicios);
    resta();
    imprimirresultado(inicior);
    multiplicacion(filas,columnas);
    imprimirresultado(iniciom);
    return 0;
}
void creareinsertar1(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    Numero *at;
    if (inicio1==NULL){
        inicio1=Nuevodigito;
        ultimo1=Nuevodigito;
        aux=ultimo1;
    }
    else{
        at=aux->anterior;
        while(at->anterior!=NULL){
            at=at->anterior;
            inicio1=at;
            aux=aux->anterior;
        }
        at->anterior=Nuevodigito;
        at=Nuevodigito;
        inicio1=at;
        at->siguiente=aux;
    }
}
void creareinsertar2(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *at;
    Numero *aux;
    if (inicio2==NULL){
        inicio2=Nuevodigito;
        ultimo2=Nuevodigito;
        aux=ultimo2;
    }
    else{
        at=aux->anterior;
        while(at->anterior!=NULL){
            at=at->anterior;
            inicio2=at;
            aux=aux->anterior;
        }
        at->anterior=Nuevodigito;
        at=Nuevodigito;
        inicio2=at;
        at->siguiente=aux;
    }
}
Numero *creareinsertarresultado(int dato, int opcion){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Numero *at;
    Numero *aux;
    Numero *de;
    switch(opcion){
        case 1:
            
            Nuevodigito->digito = dato;
            Nuevodigito->anterior=NULL;
            Nuevodigito->siguiente=NULL;
            
            if (inicios==NULL){
                inicios=Nuevodigito;
                ultimos=Nuevodigito;
                aux=ultimos;
            }
            else{
                at=aux->anterior;
                while(at->anterior!=NULL){
                    at=at->anterior;
                    inicios=at;
                    aux=aux->anterior;
                }
                at->anterior=Nuevodigito;
                at=Nuevodigito;
                inicios=at;
                at->siguiente=aux;
            }
            break;
        case 2:
            
            Nuevodigito->digito = dato;
            Nuevodigito->anterior=NULL;
            Nuevodigito->siguiente=NULL;
            if (inicior==NULL){
                inicior=Nuevodigito;
                ultimor=Nuevodigito;
                aux=ultimos;
            }
            else{
                at=aux->anterior;
                while(at->anterior!=NULL){
                    at=at->anterior;
                    inicios=at;
                    aux=aux->anterior;
                }
                at->anterior=Nuevodigito;
                at=Nuevodigito;
                inicios=at;
                at->siguiente=aux;
            }
            break;
        case 3:
            Nuevodigito->digito = dato;
            Nuevodigito->anterior=NULL;
            Nuevodigito->siguiente=NULL;
            if (iniciom==NULL){
                iniciom=Nuevodigito;
                ultimom=Nuevodigito;
                aux=iniciom;
            }
            else{
                de=aux->siguiente;
                while(de->siguiente!=NULL){
                    de=de->siguiente;
                    ultimom=de;
                    aux=aux->siguiente;
                }
                de->siguiente=Nuevodigito;
                de=Nuevodigito;
                ultimom=de;
                de->anterior=aux;
            }
            break;
    }
    return opcion==1? inicios: opcion==2? inicior: iniciom;
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
            acarreo/=10;
            Numero *suma=creareinsertarresultado(sumadigito1, 1);
            aux1=aux1->anterior;
            aux2=aux2->anterior;
        }
    }
}
void resta(){
    Numero * aux1=ultimo1;
    Numero * aux2=ultimo2;
    Numero * prestado=aux1->anterior;
    if(aux1==NULL || aux2==NULL){
        printf("Una de las dos listas estan vacias\n");
    }
    else{
        int restadigito;
        while(aux1!=NULL || aux2!=NULL){
            if((aux1->digito)>(aux2->digito))
                restadigito=(aux1->digito)-(aux2->digito);
            else {
                restadigito=((aux1->digito)+10)-(aux2->digito);
                prestado->digito=(prestado->digito)-1;
            }
            Numero *resta=creareinsertarresultado(restadigito, 2);
            aux1=aux1->anterior;
            aux2=aux2->anterior;
            prestado=prestado->anterior;
        }
    }
}
void multiplicacion(int filas, int columnas){
    Numero * aux1=ultimo1;
    Numero * aux2=ultimo2;
    int matriz[filas][columnas];
    int i=0, j;
    if(aux1==NULL || aux2==NULL){
        printf("Una de las dos listas estan vacias\n");
    }
    else{
        int ayudante;
        while(aux2!=NULL){
            int acarreo=0, j=1;
            while(aux1->anterior!=NULL){
                ayudante=((aux1->digito)*(aux2->digito))+acarreo;
                acarreo=ayudante/10;
                matriz[i][(columnas)-j]=ayudante%10;
                aux1=aux1->anterior;
                j+=1;
            }
            aux2=aux2->anterior;
            i=i+1;
        }
        int arrayaux[(filas+columnas)-1];
        int suma=0, i1, j1, resultado, w=(filas+columnas)-3, acarreo1=0;
        for(j=columnas; j>=1; j--){
            for(i=0; i<filas; i++){
                if(i==0 && j==3)
                    arrayaux[(filas+columnas)-2]=matriz[0][columnas-1];
                else if (i==0 && j==1){
                    suma=0;
                    for (i1=0; i1<filas; i1++){
                        for (j1=0; j1<columnas; j1++){
                            if (i1==j1)
                                suma+=matriz[i1][j1];
                        }
                    }
                    resultado=suma%10;
                    arrayaux[filas-1]=resultado+acarreo1;
                    acarreo1=suma/10;
                    suma=0;
                    for(int l=1; l<filas-1; l++){
                        suma=0;
                        for(i1=l; i1<3; i1++){
                            for (j1=0; j1<3; j1++){
                                if(i1==j1+i)
                                    suma+=matriz[i1][j1+l];
                            }
                        }
                        suma-=1;
                        resultado=suma%10;
                        arrayaux[l]=resultado+acarreo1;
                        acarreo1=suma/10;
                        suma=0;
                    }
                }
                else if(i==2 && j==1)
                    arrayaux[0]=matriz[filas-1][0]+acarreo1;
                else{
                    suma=0;
                    if (i+j<4)
                        //2. aqui empezamos a poner los acarreos;
                        suma+=matriz[i][j+i];
                    resultado=suma%10;
                    arrayaux[w]=resultado+acarreo1;
                    acarreo1=suma/10;
                    w-=1;
                }
            }
        }
        Numero *m;
        int parametro;
        for(i=0; i<(filas+columnas)-1; i++){
            parametro=arrayaux[i];
            m=creareinsertarresultado(parametro, 3);
        }
    }
}
void imprimirresultado(Numero *i){
    Numero *aux=i;
    while(aux->siguiente!=NULL){
        printf("%d",aux->digito);
        aux=aux->siguiente;
    }
}
