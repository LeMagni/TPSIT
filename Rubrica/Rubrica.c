#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_NUM_CONTATTI 1024

typedef struct contatto{
    int id;
    char nome[64];
    char numero[16];
}Contatto;

typedef struct rubrica{
    int num_inseriti;
    struct contatto db[MAX_NUM_CONTATTI];
}Rubrica;

int inserisci(Rubrica *r,char *nome,char *numero){
    Contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI){
        printf("Rubrica Piena");
        return -1;  //errore
    }
    p = &r->db[r->num_inseriti];    //punta la prima area di memoria disponibile

    strcpy(p->nome,nome);   //copia nome
    strcpy(p->numero, numero); //copia il numero
    p->id = r->num_inseriti; //assegno il numero
    r->num_inseriti++; //aumenta numero contatti
    return 0;   //tutto ok
}

char *trova_numero_da_nome(Rubrica *r,char *nome){
    int i;
    Contatto *p;
    for(i=0;i<MAX_NUM_CONTATTI;i++){
        if(i==r->num_inseriti){
            break;  //STOP se abbiamo raggiunto l'ultimo
        }
        p = &r->db[i];  //punto l'i-esimo contatto

        if(strcmp(p->nome,nome)==0){
            return p->numero;   //ritorno il num se i nomi coincidono
        }
    }
    return NULL;
}

void stampa_rubrica(Rubrica *r){
    int i;
    Contatto *p;
    printf("\nStampa rubrica: %d contatti\n", r->num_inseriti);

    for(i=0;i<MAX_NUM_CONTATTI;i++){
        if(i==r->num_inseriti){
            break;  //STOP se abbiamo raggiunto l'ultimo
        }
        p=&r->db[i];    //punto l'i-esimo contatto

        printf("%s, %s\n",p->nome,p->numero);
    }
}