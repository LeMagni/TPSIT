#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

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
            if (lista == NULL) //controlla se la lista è vuota
            {
                //se lista non punta ancora a una cella viene caricata con l'indirizzo di una cella

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else //se lista punta già a una cella
            {
                //assegno a l la cella successiva

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  //assegno al valore di l n
            l->next = NULL; // assegno a next di l null 
        }
    } while (n >= 0);

    l = lista; //assegno a l lista per portare l a inzio di lista
    printf("numeri inseriti: ");
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //assegno a next di l l
    }
    printf("\n");
    return 0;
}