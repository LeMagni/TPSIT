#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL){
        return 1;
    }else{
        return 0;
    } 
}

void enqueue(Nodo** head, Nodo** tail, Nodo* element){
    
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;

    return;
}

Nodo* dequeue(Nodo** head, Nodo** tail){
    
    Nodo* ret = *head;

    if(is_empty(*head)) return NULL;
    else *head = ret->next;
    if(*head == NULL) *tail = NULL;

    return ret;
}

void push (Nodo *head, Nodo* tail, Nodo *element){
    Nodo* supportHead = NULL;
    Nodo* supportTail = NULL;
    Nodo* element2;

    while (!is_empty(*head)){
        element2 = dequeue(head,tail);
        enqueue(&supportHead, &supportTail, element2);
    }

    enqueue(head, tail, element);

    while (!is_empty(supportHead)){
        enqueue(head, tail, dequeue(&supportHead, &supportTail));
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;

    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

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
    Nodo* element = NULL;

    for (int i = 0; i < 10; i++){
        element = (Nodo*) malloc(sizeof(Nodo));
        element->n = i;
        push(&head, &tail, element);
    }
    
    stampaCoda(&head, &tail);

}