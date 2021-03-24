#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct El{
    char segno;
    int valore;
    struct El* next;
}El;

int is_empty(struct El* head){ //controlla se la struttura è vuota 
    if (head == NULL) return 1;
    else return 0;
}

void push(struct El** pila, struct El* element){ //inserisce una carta in cima al mazzo 
	if (&pila==NULL){
		*pila = element;
		element->next = NULL;
	}else{
		element->next = *pila;
		*pila = element;
	}
}

struct El* pop(struct El** pila){ //estrae la prima carta del mazzo
	struct El *ret = *pila;
	if(&pila==NULL){
		return NULL;
	}else{
		*pila = ret->next;
	}
	return ret;
}

void stampaPila(struct El* l){ //stampa le carte di un mazzo
    struct El *ret = pop(&l);
    while(!is_empty(l)){
        struct El *ret = pop(&l);
        printf("%d",l->valore);
        printf("%c\n",l->segno);
    }
}

int main(){

    struct El* mazzo; //mazzo completo di carte
    struct El* carta; //carta che andrà a inserirsi nel mazzo
    struct El* alice; //mazzo di alice
    struct El* bob; //mazzo di bob
    int aChiTocca=0; //variabile di supporto per sapere di chi


    for(int k = 1; k<14; k++){ //crea le carte di cuori e le mette nel mazzo
        carta = (struct El*) malloc(sizeof(struct El));
        carta->valore = k;
        carta->segno = 'C';
        push(&mazzo,carta);
    }

    
    for(int k = 1; k<14; k++){ //crea le carte di picche e le mette nel mazzo
        carta = (struct El*) malloc(sizeof(struct El));
        carta->valore = k;
        carta->segno = 'P';
        push(&mazzo,carta);
    }

    for(int k = 1; k<14; k++){ //crea le denari di cuori e le mette nel mazzo
        carta = (struct El*) malloc(sizeof(struct El));
        carta->valore = k;
        carta->segno = 'D';
        push(&mazzo,carta);
    }

    for(int k = 1; k<14; k++){ //crea le carte di fiori e le mette nel mazzo
        carta = (struct El*) malloc(sizeof(struct El));
        carta->valore = k;
        carta->segno = 'F';
        push(&mazzo,carta);
    }
    

    //stampaPila(mazzo);

    for(int k = 1; k<53; k++){ 
        struct El *ret = pop(&mazzo); //assegno a una struttura di supporto la pop del mazzo in modo da estrarre la prima carta
        struct El *ret2 = pop(&mazzo); //assegno a una struttura di supporto la pop del mazzo in modo da estrarre la seconda carta
        aChiTocca=1+rand()%2; //numeri casuali tra 1 e 2
        //printf("%d\n", aChiTocca);
        printf("Turno numero %d\n", k);
        if(aChiTocca==1){ // decite a chi tocca la prima carta
            printf("tocca a Alice:"); // metto nel mazzo di alice la carta estratta
            push(&alice, ret); 
            printf("%d",ret->valore);
            printf("%c\n",ret->segno);
            printf("tocca a Bob:"); // metto nel mazzo di Bob la carta estratta
            push(&bob, ret2);
            printf("%d",ret2->valore);
            printf("%c\n",ret2->segno);
        }else{
            printf("tocca a Bob:"); // metto nel mazzo di Bob la carta estratta
            push(&bob, ret);
            printf("%d",ret->valore);
            printf("%c\n",ret->segno);
            printf("tocca a Alice:"); // metto nel mazzo di Alice la carta estratta
            push(&alice, ret2); 
            printf("%d",ret2->valore);
            printf("%c\n",ret2->segno);
        }
    }

    printf("Carte di Alice:\n");
    stampaPila(alice); //stampo il mazzo di carte 
    
    return 0;
 }