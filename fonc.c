#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "fonc.h"
int difficulty(){
    int x,d=5;
       printf("welcome to the hungman game\n");
    printf("would you like to change difficulty\n 1:yes,i would like     0:no,i like to play with standard\n");
    do
    {
        scanf("%d" ,&x);

    }
    while((x!=1)&&(x!=0));
    if (x==1)
    {
        printf("how many error are accepted\n");
        do
        {
            scanf("%d" ,&d);
            if (d>20) printf("please chose a more reasonable difficulty(<20)\n");
        }
        while(d>20);
    }
    return d;

}
int length_of_word(){
    int length;
        printf("please,chose the length of the word \n");
    do
    {
        scanf("%d",&length);
        if ((length>17)||(length<3))
            printf("you cant chose a length longer than 17 or smaller than 3\n");
    }
    while((length>17)||(length<3));
    return length;
}
void dashes_creation(char *dashes,int length){
    int i;
        for(i=0;i<=length;i++){
        dashes[i]='-';
    }
    dashes[length]='\0';
    printf("%s\n", dashes);
    return;
}
//randomize a word to scan
int randomize(int length){
    int x;
    srand(time(0));
    x=1+(rand() %20);
    x=x+(length-3)*20;
    return x;
}
//scan word
void wordf(int length,char*word,FILE *fp){
    int x;
    int i;
    i=1;
    x=randomize(length);
    if (fp !=NULL){
        while(!feof(fp)){
            fgets(word,length+2,fp);
            if (i==x){
                fclose(fp);
                return;
                }
            else
                i=i+1;
}
}
}
//turn uppercase unto lowercase letter
char lowercase(char c){
    if ((c >= 65) && (c <= 90))
        c = c + 32;
    return c;
}


//check if letter in alphabet
char letter()
{char c;
printf("give a letter\n");

do
        {
            scanf(" %c" ,&c);
            if ( !((c>='a' && c<='z') || (c>='A' && c<='Z')))
                printf("please select a letter from alphabet\n");
        }
        while( !((c>='a' && c<='z') || (c>='A' && c<='Z')));
c=lowercase(c);
    return c;
}
//check if letter in word and replace dashes
int check(char *s1,char *s2,char c,int*y){
    int a =0;
    while (*s1 !='\0'){
        if (*s1==c){
            *s2=c;
            *y=*y-1;
            a=1;}
        s1++;
        s2++;
    }
    return a;
}
//check if word was used
int use (listuse *head,char c){
    listuse *p = head ;
   while (p !=NULL){
        if (p->data ==c){
                printf("this letter have been used \n");
                return 1;
                break ;}
        else
            p=p->next;
   }
   return 0 ;
}
//store used letter
void store(listuse **head ,char c ){
    listuse *p = ( listuse *) malloc ( sizeof ( listuse ));
    p -> data = c ;
    p -> next = *head ;
    *head = p ;


}

void playing(int *x,int *y,int d,char*word,char*dashes){
    char l;
        do{
            l=letter();
        }while(use(head,l) ==1);
        store(&head ,l);
        if (check(word,dashes,l,&*y)==0){
            *x=*x+1;
            printf(" wrong decision tries remaining are %d        %s\n", d-*x, dashes);
            }
        else printf("nicely done \n %s\n", dashes);
        return ;

}
//remove letter from list
listuse * deleteletter ( listuse * head )
 {
 if ( head != NULL )
 {
 listuse * p = head ;
 head = head -> next ;
 free ( p );
 }
 return head ;
 }
//remove list
void deleteliste ( listuse * head )
 {
 while ( head != NULL ){
 head = deleteletter ( head );
 }
 return;

 }

