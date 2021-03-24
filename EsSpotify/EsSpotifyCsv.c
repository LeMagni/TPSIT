#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define SIZE 100

typedef struct canzone{//si crea la struttura canzone
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

bool controllo(int *vet,int cerc,int dim){//funzione che serve per il controllo dell'ordine
    bool ok=false;
    int *p;
    for(p=vet;p<vet+dim;p++){
        if(cerc==*p){
            ok=true;
            p=vet+dim;
        }
    }
    return ok;
}

void randomize(Canzone* playlist,int dim){//randomizzatore della playlist
    int *p;
    srand(time(NULL));
    for(int k=0; k<dim; k++){
        do{
            *(p+k)=rand()%dim;
        }while(controllo(p,*(p+k), k));
    }
    for(int j=0;j<dim;j++){
         printf("%d - %s - %s\n",(playlist+(*(p+j)))->num,(playlist+(*(p+j)))->nome_canzone,(playlist+(*(p+j)))->artista);
    }
}

int main(){
    FILE *fp;
    Canzone *playlist;
    char *buffer;
    buffer = malloc(SIZE * sizeof(char));
    int k=0;
    if((fp=fopen("playlist.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer,SIZE,fp)){ //leggo una volta tutto il file per sapere quante canzoni ci sono all'interno
            k++;
        }
        fclose(fp);
        fp=fopen("canzoni.csv","r");
        playlist = malloc(k * sizeof(Canzone)); //allocazione dinamica della memoria
        k=0;
        while(fgets(buffer,SIZE,fp)){
            (playlist+k)->num = atoi(strtok(buffer,","));
            strcpy((playlist+k)->nome_canzone,strtok(NULL,","));
            strcpy((playlist+k)->artista,strtok(NULL,"\n"));
            k++;
        }
        randomize(playlist,k);
    }
}