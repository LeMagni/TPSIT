//Obertino Mattia 4Arob
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIZE 100
#define LUNG 25

typedef struct posizione{ //dichiaro una struttura Posizione che contenga le posizioni e il tempo in cui si salva la posizione
    int tempo;
    float lat;
    float lon;
}Posizione;

typedef struct anomalia{ //dicjiaro una struttura che contenga il tempo in cui è stata rilevata l'anomalia e il tipo dell'anomalia
    int tempo;
    char tipo[LUNG];
}Anomalia;

void calcoloAnom(Posizione *pos, Anomalia *anom, int dim1, int dim2){
    for(int k=1; k<dim1; k++){ //parto da 1 e non da 0 per saltare la prima riga dove sono presenti la descrizione dei dati
        for(int j=1; j<dim2; j++){ //parto da 1 e non da 0 per saltare la prima riga dove sono presenti la descrizione dei dati
            if((pos+k)->tempo == (anom+j)->tempo){ //confronto i tempi delle anomali con quelli della posizione e li stampo se sono uguali
                printf("\nERROR:%.3f %.3f %d %s", (pos+k)->lat, (pos+k)->lon, (anom+j)->tempo, (anom+j)->tipo);
            }
        }
    }
}

int main(){
    FILE *fvolo; 
    FILE *fanom;
    Posizione *pos;
    Anomalia *anom;
    char *buffer1;
    char *buffer2;
    buffer1 = malloc(SIZE * sizeof(char));
    int dim1=0;
    if((fvolo=fopen("Volo_drone.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer1,SIZE,fvolo)){ //leggo una volta tutto il file per sapere quante righe ci sono all'interno
            dim1++;
        }
        fclose(fvolo);
        fvolo=fopen("Volo_drone.csv","r");
        pos = malloc(dim1 * sizeof(Posizione)); //allocazione dinamica della memoria
        dim1=0;
        while(fgets(buffer1,SIZE,fvolo)){
            (pos+dim1)->tempo = atoi(strtok(buffer1,","));
            (pos+dim1)->lat = atof(strtok(NULL,","));
            (pos+dim1)->lon = atof(strtok(NULL,"\n"));
            //printf("\n%d %f %f", (pos+dim1)->tempo, (pos+dim1)->lat, (pos+dim1)->lon);
            dim1++;
        }  
    }
    buffer2 = malloc(SIZE * sizeof(char));
    int dim2=0;
    if((fanom=fopen("Anomalie_drone.csv","r"))==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer2,SIZE,fanom)){ //leggo una volta tutto il file per sapere quante righe ci sono all'interno
            dim2++;
        }
        fclose(fanom);
        fanom=fopen("Anomalie_drone.csv","r");
        anom = malloc(dim2 * sizeof(Anomalia)); //allocazione dinamica della memoria
        dim2=0;
        while(fgets(buffer2,SIZE,fanom)){
            (anom+dim2)->tempo = atoi(strtok(buffer2,","));
            strcpy((anom+dim2)->tipo,strtok(NULL,"\n"));
            //printf("\n%d %s", (anom+dim2)->tempo, (anom+dim2)->tipo);
            dim2++;
        }
        
    }

    calcoloAnom(pos, anom, dim1, dim2);

}