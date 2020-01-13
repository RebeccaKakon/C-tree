#include<stdio.h>
#include <stdlib.h>
#define NUM_LETTERS 26


typedef struct node{
    char letter;
    long unsigned int count;
    struct node* children [NUM_LETTERS];
} node;

void build (node *pass,char *data){     //data ends with \0
node **root=&pass;
printf("ffff");
    
    while(*data!='\0'){
        

         while( (*root)->children[(int)(*data)-65]!=NULL){
             struct node* n=(struct node*) malloc (sizeof(struct node));
             (*root)->children[(int)(*data)-65]=n;
             *root=(*root)->children[(int)(*data)-65];
             *data=*data+1;

         }

     
     if(*data!='\0'){
        
     // struct node* arrn=(struct node*)malloc(sizeof(node)*26);

     //node arr[]= (node*)malloc(sizeof(node)*26);
      for(int i=0;i<26;i++){
          (*root)->children[i]=(struct node*) malloc (sizeof(struct node));
      }
      
     int place=*data;
     struct node* n=(struct node*) malloc (sizeof(struct node));
    (*root)->children[place-65]=n;
     *data=*data+1;
     *root=(*root)->children[place-65];
     }
     if(*data=='\0'){
         (*root)->count=(*root)->count+1;
         printf("%c",(*root)->letter);

     }
    }

return ;


}


int main(int argc, char* argv[]){
     
    node *root=(node*)malloc(sizeof(node));
    for(int i=0;i<26;i++){
        (root)->children[i]=NULL;

    }

    node* r=root;
    
    (root)->count=0;
   
   // node tree={'^',0,NULL}; 
   // node *r=&tree;

    
char txt[64000];
       char i;
       int j=0;
       while ((i=getc(stdin))!=EOF)
       {
           txt[j]=i;
           j++;
       }
    
       printf("%s",txt);

     int place =0;
       char *move =txt;
      
       while(*move !='\0'){
           char word[30]={0};
          
           while(*move !='\t'&&*move !=' '&&*move !='\n'){
                 word[place]=*move; 
                 place=place+1;
                 move=move+1;
                 
                 
           }
           printf("%s\n",word);
           build(root,word);
           
           if(*move !='\0'){
           
           move=move+1;
           }
           
           
           place=0;


       }
       
     
     


return 0;

}