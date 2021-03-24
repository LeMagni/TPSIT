#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

void push(struct El* lista, int valore){
    if (lista == NULL) //controlla se la lista è vuota
    {
        //se lista non punta ancora a una cella viene caricata con l'indirizzo di una cella

        lista = (struct El*)malloc(sizeof(struct El));
        lista->valore=valore;
        lista->next=NULL;
    }else //se lista punta già a una cella
    {
        while(lista->next != NULL){
            lista=lista->next;
        }
        //assegno a lista la cella successiva

        lista->next = (struct El *)malloc(sizeof(struct El));

        lista->next->valore = valore;

        lista->next->next= NULL;
    }
}

void stampaLista(struct El*){
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //assegno a next di l l
    }
};


}
int main(){
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; //imposta la lista a null in modo che lista sia vuota

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            push(lista, l);
            l->valore = n;  //assegno al valore di l n
            l->next = NULL; // assegno a next di l null 
        }
    } while (n >= 0);

    l = lista; //assegno a l lista per portare l a inzio di lista
    printf("numeri inseriti: "); 
    printf("\n");
    return 0;
}