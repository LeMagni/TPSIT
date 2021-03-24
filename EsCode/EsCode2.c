#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(Nodo** head, Nodo** tail, Nodo* element){
    if(is_empty(*head)) *head = element;
    else (*tail)->next = element; 
    *tail = element;
    element->next = NULL;
}

Nodo* dequeue(Nodo** head, Nodo** tail){
    Nodo* ret = *head;
    if(is_empty(*head)) return NULL;
    else *head = ret->next;
    if(*head == NULL) *tail = NULL;
    return ret;
}

void push (Nodo **head, Nodo *element){
    if (is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if (is_empty(*head)) return NULL;
    else *head = ret->next;
    return ret;
}

void stampaCoda(Nodo **head, Nodo **tail){
    Nodo* valore = (Nodo*) malloc(sizeof(Nodo));
    valore = dequeue(head, tail);
    while (valore != NULL) {
        printf("%d\n",valore->n);
        valore = dequeue(head, tail);
    }
    free(valore);
}

void main(){
    Nodo *head = NULL;
    Nodo *tail = NULL;
    Nodo* stack = NULL;
    Nodo* element = NULL;
    int risposta;

    do{
        element = (Nodo*) malloc(sizeof(Nodo));
        printf("Inserisci un valore: ");
        scanf("%d", &element->n);
        enqueue(&head, &tail, element);
        printf("Inserisci 0 se vuoi uscire. || Inserisci 1 per continuare: ");
        fflush(stdin);
        scanf("%d", &risposta);

    }while(risposta != 0);

    element = NULL;

    while (!is_empty(head)){
        element = dequeue(&head, &tail);
        push(&stack, element);
    }

    while (!is_empty(stack)){
        element = pop(&stack);
        enqueue(&head, &tail, element);
    }
    stampaCoda(&head, &tail);
}