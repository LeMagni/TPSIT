#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define N_CANZONI 10
#define SIZE 100

typedef struct canzone{//si crea la struttura canzone
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

bool controllo(int vet[],int cerc,int dim){//funzione che serve per il controllo dell'ordine
    bool ok=false;
    for(int k=0;k<dim;k++){
        if(cerc==vet[k]){
            ok=true;
            k=dim;
        }
    }
    return ok;
}

void randomize(Canzone playlist[],int dim){//randomizzatore della playlist
    int vet[dim];
    srand(time(NULL));
    for(int k=0; k<dim; k++){
        do{
            vet[k]=rand()%(dim-1+1);
        }while(controllo(vet,vet[k],k));
    }
    for(int j=0;j<dim;j++){
        printf("%d - %s - %s\n",playlist[vet[j]].num,playlist[vet[j]].nome_canzone,playlist[vet[j]].artista);
    }
}

int main(){
    FILE *fp;
    Canzone playlist[N_CANZONI];
    char buffer[SIZE];
    int k=0;

    if((fp=fopen("playlist.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer,SIZE,fp)){
            playlist[k].num = atoi(strtok(buffer,","));
            strcpy(playlist[k].nome_canzone,strtok(NULL,","));
            strcpy(playlist[k].artista,strtok(NULL,"\n"));
            k++;
        }
        randomize(playlist,k);
    }
}