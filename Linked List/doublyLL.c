#include <stdio.h>
#include <conio.h>

struct Node{
struct Node *prev;
int data;
struct Node *next;

}*first=NULL;

void create(int A[], int n){

struct Node *t, *last;
first =(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->prev=NULL;
first->next=NULL;
last = first;
int i;
for(i=1;i<n;i++){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->prev=last;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
}

}

void display(struct Node *p){

while(p!=0){
    printf("%d ",p->data);
    p=p->next;

}

}

int count(struct Node *p){
int count=0;
while(p){
        count++;
    p=p->next;
}
return count;
}

void insert(int pos, int x){
struct Node *p = first;
struct Node *t = (struct Node*)malloc(sizeof(struct Node));
t->data=x;

if(pos==0){
    t->next=first;
    t->prev=NULL;
    first->prev=t;
    first=t;
}


else{
int i;
for(i=0;i<pos-1;i++){
    p=p->next;
}
t->prev=p;
t->next=p->next;
if(p->next!=0)
    p->next->prev=t;
p->next=t;
}


}

int Delete(int pos){
struct Node *p=first;
if(pos==1){
    first=first->next;
    int x=p->data;
    if(first!=0)
    first->prev=NULL;
    free(p);
}

else{

int i;
for(i=0;i<pos-1;i++){
    p=p->next;
}
p->prev->next=p->next;
if(p->next!=0){
    p->next->prev=p->prev;
}
int x = p->data;
free(p);
}


}

void reverse(struct Node *p){

struct Node *t;
while(p!=0){
    t=p->next;
    p->next=p->prev;
    p->prev=t;
    p=p->prev;
    if(p!=NULL && p->next==NULL)
        first=p;
}

}

int main(){

struct Node *t = (struct Node *)malloc(sizeof(struct Node));
int A[6] = {3,5,7,9,11,15};
create(A, 6);
//display(first);
//printf("\n %d",count(first));

//insert(6,99);  // (position, value)
//Delete(1);
reverse(first);

display(first);


}
