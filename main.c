#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();

int cargarParalelo(int legajos[20], char nombres[20][30], int anios[20]);
void mostrarParalelo(int legajos[20], char nombres[20][30], int validos, int anios[20]);
int buscarLegajo(int legajos[], int validos, int numero, int *posicion);
int menorPosicion(char nombres[20][30], int validos, int a);
void ordenarSeleccion(int legajos[20], int anios[20], char nombres[20][30], int validos);

int main(){
    int seleccion=0;
    char seguir='s';

    do{
        puts("\t----SELECCIONE UN EJERCICIO----\n");
        printf("\nEJERCICIO 1");
        printf("\nEJERCICIO 2");
        printf("\nEJERCICIO 3");
        printf("\nEJERCICIO 4\n\n");
        scanf("%i", &seleccion);


        switch(seleccion){
        case 1:
            {
                system("cls");
                ejercicio1();
                break;
            }
        case 2:
            {
                system("cls");
                ejercicio2();
                break;
            }
        case 3:
            {
                system("cls");
                ejercicio3();
                break;
            }
        case 4:
            {
                system("cls");
                ejercicio4();
                break;
            }
        }

        system("pause");
        system("cls");

        printf("Desea ver otro ejercicio? s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');


    return 0;
}

int cargarParalelo(int legajos[20], char nombres[20][30], int anios[20]){
    char continuar='s';
    int i, validos=0;

    for(i=0; (i<20) && (continuar=='s'); i++){
        printf("\nIngrese el nombre del alumno:\t");
        fflush(stdin);
        gets(nombres[i]);

        legajos[i]=i+1;

        anios[i]=rand()%13+18;

        validos++;

        puts("\n\nDesea ingresar otro alumno? 's' o 'n'\n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return validos;
}

void mostrarParalelo(int legajos[20], char nombres[20][30], int validos, int anios[20]){
    int i;

    printf("\nNombres\t\tLegajo\t\tEdad\n");

    for(i=0; i<validos; i++){
        printf("\n%s\t\t", nombres[i]);

        printf("%d\t\t", legajos[i]);

        printf("%d\n", anios[i]);
    }
}

int buscarLegajo(int legajos[], int validos, int numero, int *posicion){
    int i, flag=0;

    for(i=0;i<validos && flag==0;i++)
    {
        if(legajos[i]==numero)
        {
            *posicion=i;
            flag=1;
        }
    }

    return flag;
}

int menorPosicion(char nombres[20][30], int validos, int a){
    char aux[1][30];
    int i=a+1;
    int posicion=a;
    strcpy(aux[0], nombres[a]);

    while(i<validos){

        if(strcmp(aux[0], nombres[i])==1){
            strcpy(aux[0],nombres[i]);
            posicion=i;
        }

        i++;
    }

    return posicion;
}

void ordenarSeleccion(int legajos[20], int anios[20], char nombres[20][30], int validos){
    char auxN[1][30];
    int auxA[1];
    int auxL[1];
    int posicion, i=0;

    while(i<validos-1){
        posicion=menorPosicion(nombres, validos, i);

        auxL[0]=legajos[posicion];
        strcpy(auxN[0],nombres[posicion]);
        auxA[0]=anios[posicion];

        legajos[posicion]=legajos[i];
        strcpy(nombres[posicion],nombres[i]);
        anios[posicion]=anios[i];

        legajos[i]=auxL[0];
        strcpy(nombres[i],auxN[0]);
        anios[i]=auxA[0];

        i++;
    }
}

void ejercicio1(){
    int legajos[20];
    int anios[20];
    char nombres[20][30];

    int validos=cargarParalelo(legajos, nombres, anios);
    mostrarParalelo(legajos, nombres, validos, anios);
}

void ejercicio2(){
    int legajos[20], posicion=0, numeroLegajo=0;
    int anios[20];
    char nombres[20][30];

    int validos=cargarParalelo(legajos, nombres, anios);
    mostrarParalelo(legajos, nombres, validos, anios);

    puts("\nIngrese el numero de legajo que desea encontrar: \n\n");
    scanf("%d", &numeroLegajo);

    int flag=buscarLegajo(legajos, validos, numeroLegajo, &posicion);

    if(flag==0){
        puts("\nNo se encontro el legajo\n");
    }else{
        printf("\nEl legajo esta en la posicion: %d\n", posicion);
    }
}

void ejercicio3(){
    int legajos[20], posicion=0, numeroLegajo=0;
    int anios[20];
    char nombres[20][30];

    int validos=cargarParalelo(legajos, nombres, anios);
    mostrarParalelo(legajos, nombres, validos, anios);

    puts("\nIngrese el numero de legajo que desea encontrar: \n\n");
    scanf("%d", &numeroLegajo);

    int flag=buscarLegajo(legajos, validos, numeroLegajo, &posicion);

    if(flag==0){
        puts("\nNo se encontro el legajo\n");
    }else{
        printf("\nEl legajo esta en la posicion: %d y pertenece a: %s\n\n", posicion, nombres[posicion]);
    }
}

void ejercicio4(){
    int legajos[20];
    int anios[20];
    char nombres[20][30];

    int validos=cargarParalelo(legajos, nombres, anios);
    mostrarParalelo(legajos, nombres, validos, anios);

    ordenarSeleccion(legajos, anios, nombres, validos);
}
