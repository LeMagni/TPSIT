#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define SIZE 100

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
    struct canzone *next;
}Canzone;

void push(Canzone* p,int ind,char* titolo,char* autore){
    Canzone* p_appoggio;
    p_appoggio = p;
    if(ind != 1){
        while(p_appoggio->next != NULL){
            p_appoggio = p_appoggio->next;
        }
        p_appoggio->next = malloc(sizeof(Canzone));
        p_appoggio->next->num = ind;
        strcpy(p_appoggio->next->nome_canzone,titolo);
        strcpy(p_appoggio->next->artista,autore);
        p_appoggio->next->next = NULL;
    }else{
        p_appoggio->num=ind;
        strcpy(p_appoggio->nome_canzone,titolo);
        strcpy(p_appoggio->artista,autore);
    }
}

bool check(int* vet,int cerc,int dim){ //funzione che controlla se il numero randomico inserito è già presente all'interno del vettore
    bool ok=false;
    for(int k=0;k<dim;k++){
        if(cerc==*(vet+k)){ //se è uguale return true ed esce dal ciclo
            ok=true;
            k=dim;
        }
    }
    return ok;
}

void printRand(Canzone* p,int dim){
    Canzone* p_appoggio;
    int k;
    int* vetRand = malloc(dim  * sizeof(int));
    vetRand = malloc(dim  * sizeof(int));
    srand(time(NULL));
    for(int i=0;i<dim;i++){
        do{
            *(vetRand+i)=rand()%(dim+1-1)+1;//carica il vettore con un valore randomico da 1 a dim
        }while(check(vetRand,*(vetRand+i),i));//funzione che controlla se il numero randomico inserito è già presente all'interno del vettore
    }
    for(int j=0;j<dim;j++){
        p_appoggio = p;
        k=0;
        while(k<*(vetRand+j)){
            if(k+1==*(vetRand+j)){
                printf("%d - %s di %s\n",p_appoggio->num,p_appoggio->nome_canzone,p_appoggio->artista);
            }
            p_appoggio = p_appoggio->next;
            k++;
        }
    }
}

void main(){

    FILE* fp;
    fp=fopen("canzoni.csv","r");

    char* buffer;
    buffer = malloc(SIZE * sizeof(char));

    Canzone* playlist;
    playlist = malloc(sizeof(Canzone));
    int nCanz=0;

    int ind; //indice
    char* na = malloc(SIZE * sizeof(char)); //nome artista
    char* nc = malloc(SIZE * sizeof(char)); //nome canzone

    //LETTURA FILE
    while(fgets(buffer,SIZE,fp)){
        ind = atoi(strtok(buffer,","));
        strcpy(nc,strtok(NULL,","));
        strcpy(na,strtok(NULL,"\n"));
        push(playlist,ind,nc,na);
        nCanz++;
    }
    printRand(playlist,nCanz);
}