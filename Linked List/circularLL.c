#include<stdio.h>
#include<conio.h>

struct Node{
    int data;
    struct Node *next;

}*Head;

void createCLL(int A[], int n){
struct Node *last, *t;
//Creating first Node
Head = (struct Node*)malloc(sizeof(struct Node));
Head->data=A[0];
Head->next=Head;
last = Head;

//Creating other nodes and linking


int i;
for(i=1;i<n;i++){
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    last->next=t;
    last=t;
}

}

void displayCLL(struct Node *p){

//Normal approach
/*
do{
    printf("%d ", p->data);
    p=p->next;
} while(p!=Head);
*/

//Normal approach without do while
/*
static flag=0;
while(p!=Head || flag==0){
    flag=1;
    printf("%d ",p->data);
    p=p->next;

}
flag=0;
*/

//Recursive Approach

static flag =0;
if(p!=Head || flag==0){
flag=1;
printf("%d ",p->data);
displayCLL(p->next);
}
flag=0;

}

void insert(int pos, int x){

struct Node *p = Head;
struct Node *t = (struct Node*)malloc(sizeof(struct Node));

if(pos>count(Head)||pos<0){
    return printf("Position is invalid ");
}

else if(pos==0){
    t->data=x;
    t->next=Head;
    while(p->next!=Head) p=p->next;
    p->next=t;
    Head=t;
}

else{
for(int i=0;i<pos-1;i++){
    p=p->next;
}
t->data=x;
t->next=p->next;
p->next = t;


}
}

int count(struct Node *t){
int count=1;
while(t->next!=Head){
    count++;
    t=t->next;

}
return count;
}


int Delete(struct Node*p, int pos){
    int x;
    if(pos>count(Head)||pos<1){
    return printf("Position is invalid ");
    }
    else if(p->next==NULL){
        x=Head->data;
        free(Head);
        Head=NULL;

    }
    else if(pos==1){
        while(p->next!=Head) p=p->next;
        p->next=Head->next;
        x=Head->data;
        free(Head);
        Head=p->next;
        return x;
    }

    else{

    struct Node *q;
    for(int i=0;i<pos-2;i++){
        p=p->next;
    }
    q=p->next;
    x = q->data;
    p->next=q->next;
    q->next=NULL;
    free(q);
    return x;

    }


}

int main(){

    int A[6]={3,5,7,9,11,15};
    createCLL(A,6);
    //insert(0,88);
    //insert(3,25);
    //printf("%d \n",count(Head));
    //insert(9,99);
   // displayCLL(Head);
    Delete(Head,7);
    displayCLL(Head);
}
