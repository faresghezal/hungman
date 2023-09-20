#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "fonc.h"
int main()
{   //variable
    int length ;
    int x,d,y;
    char dashes[18]="";
    char word[18];
    FILE *fp=fopen("words.txt","r");
    //setting difficulty
    d=difficulty();
    //choice of length of word
    length=length_of_word();
    //creating the dashes
    dashes_creation(dashes,length);
    //choice  of word
    wordf(length,word,fp);

    //initialization of counters
    x=0;
    y=length;
    head=NULL;
    //main game
    do{
        playing(&x,&y,d,word,dashes);
    }
    while((x<d)&&(y!=0));
    //result of game
    if (y==0)
        printf("congratulations,you have won the game");
    else {
            printf("game over");
            printf("\n the word was  %s",word);
    }
    //realizing memories
    deleteliste (head);
    //offer the possibility of replaying
    printf("\n would you like to play again\n 1:yes,i would like     0:no,next time\n");
    do
    {
        scanf("%d" ,&x);
    }
    while((x!=1)&&(x!=0));
    if (x==1)
        return main();
    else return 0;
}
