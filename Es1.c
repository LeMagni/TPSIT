#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 100

void insString(char s[]){
    printf("\nInserire una stringa:\n");
    fflush(stdin);
    scanf("%s", s);
}

void encoding(char s[]){
    int k=0, cnt=1;
    do{
        if(s[k]==s[k+1]){
            cnt++;
        }else{
            if(cnt==1){
                printf("%c", s[k]);
            }else{
                printf("%d", cnt);
                printf("%c", s[k-1]);
                cnt=0;
            }
        }
        k++;
    }while(s[k]!='\0');
    printf("\n");
}

void decoding(char s[]){
    int t=0,k=0;
    do{
        t=s[k]-48;
        printf("%d", t);
        if(t<=9 && t-48>=0){
            for(int j=0; j<t; j++){
                printf("%c", s[k]);
            }
        }
        k++;
    }while(s[k]!='\0');
    printf("\n");
}

int menu(int c){
    char stringa[LUNG];
    int x;

    printf("DECODING AND ENCODING\n");
    printf("Menu : \n");
    printf("1 = Decoding \n");
    printf("2 = Encoding \n");
    printf("3 = Esci \n");
    printf("Inserisci un numero: ");
    scanf("%d",&x);
    switch(x){
        case 1:
            insString(stringa);
            decoding(stringa);
            c=1;
            break;
        case 2:
            insString(stringa);
            encoding(stringa);
            c=1; 
            break;
        case 3:
            c=0; 
            break;
        }
    return c;
}

void main(){
    int uscita=1;
    while(uscita==1){
    uscita=menu(uscita);
    }
    printf("\n>>Premi un tasto per terminare<<\n");
}