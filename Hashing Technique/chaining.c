#include<stdio.h>
#include<conio.h>


struct node{
int data;
struct node * next;
}*first=NULL;

void sortedInsert(struct node **H, int x){
struct node *p = *H;
struct node *q = NULL;
struct node *t = (struct node*) malloc(sizeof(struct node));
t->data=x;
t->next=NULL;
if(*H==NULL){
    t->next=*H;
    *H = t;
}

else if(p->data>x){
    t->next=*H;
    *H = t;
}
else {

    while(p && p->data<x){

            q=p;
            p=p->next;
    }

    q->next=t;
    t->next=p;

}


}


int hash(int x){
    return x%10;
}

void Insert(struct node* H[], int key){
    int index = hash(key);
    sortedInsert(&H[index], key);
}

void Search(struct node *H, int key){

while(H){
    if(H->data==key){
        printf("%d is found! \n", key);
        return;
    }
    H = H->next;
}
printf("%d is not found! \n", key);
};

void displayHash(struct node *p){
while(p){
    printf("%d ",p->data);
    p=p->next;
}
}

void main(){

struct Node *HT[10];
int i;
for(i=0;i<10;i++)
    HT[i]=NULL;

Insert(HT,12);
Insert(HT,87);
Insert(HT,3);
Insert(HT,32);
Insert(HT,781);
Insert(HT,62);

Search(HT[hash(62)], 62);
Search(HT[hash(78)], 78);
Search(HT[hash(3)], 3);
Search(HT[hash(22)], 22);


//displayHash(HT[2]);


}
