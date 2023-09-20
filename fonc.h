typedef struct listuse {
int data ;
struct listuse * next ;
} listuse ;
//declaring list
listuse * head ;
int difficulty();
int length_of_word();
void dashes_creation(char *dashes,int length);
int randomize(int length);
void wordf(int length,char*word,FILE *fp);
char lowercase(char c);
char letter();
int check(char *s1,char *s2,char c,int*y);
int use (listuse *head,char c);
void store(listuse **head ,char c );
void playing(int *x,int *y,int d,char*word,char*dashes);
listuse * deleteletter ( listuse * head );
void deleteliste ( listuse * head );
