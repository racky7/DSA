#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{

int data;
struct Node *next;
}*first=NULL, *second=NULL, *third=NULL, *last=NULL;


void create(int A[], int n){

struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;

int i;
for(i=1;i<n;i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
}

}

void create2(int B[], int n){
struct Node *t, *last;
second = (struct Node *)malloc(sizeof(struct Node));
second->data=B[0];
second->next=NULL;
last = second;

int i;
for(i=1;i<n;i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=B[i];
    t->next=NULL;
    last->next=t;
    last=t;

}

}

void display(struct Node *p){

    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }

}

void RDisplay(struct Node *p){

if(p!=NULL){
    RDisplay(p->next);
    printf("%d ",p->data);

}

}


int count(struct Node *p){
//Normal Approach

/*
int count=0;
while(p!=0){
     count++;
     p=p->next;
}

return count;
*/

//Via Recursion

if(p!=0){
    return 1+count(p->next);
}
else return 0;

}

int sum(struct Node *p){

//Normal Approach
/*
int sum=0;
while(p!=0){
    sum+=p->data;
    p=p->next;
}
return sum;

*/

//Recursive Approach

if(p!=0){
    return  sum(p->next) + p->data;

}
else return 0;
}

int max(struct Node *p){
//Normal Approach
/*
int x= p->data;
p=p->next;

while(p!=0){
    if(p->data>x){
        x=p->data;
    }
    p=p->next;
}
return x;
*/

//Recursive Approach

//Note minimum integer is -32768
int x=0;
if(p==0) return -32768;
else
{
     x=max(p->next);
     if(x>p->data) return x;
     else return p->data;
}


}

struct Node* search(struct Node *p, int key){

//Normal Approach
/*
while(p!=0){
    if(p->data==key){
        return p;
        break;
    }
    p = p->next;
}

return NULL;
*/

// Recursive Approach

if (p->data==0)
    return 0;
if (p->data==key)
    return p;
return search(p->next, key);



}

int proSearch(struct Node* p, int key){

struct Node *q = NULL;

while(p!=0){
if(key==p->data){
    q->next=p->next;
    p->next=first;
    first=p;
    break;
}

    q=p;
    p=p->next;


}

return p->data;

}

void insertN(int pos, int x){
struct Node *t, *p;
if(pos==0){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=first;
    first=t;

}

else if(pos>0){
    p=first;
    for(int i=0;i<pos-1 && p!=0; i++){ //I did not understand why it is p!=0 here, without this it is also workin
        p=p->next;
    }
    if(p!=0){   //Same here I do not get any point of writing p!=0
    t = (struct Node *)malloc(sizeof(struct Node));
    t->next=p->next;
    p->next=t;
    t->data=x;
    }
}




}

SortedInsert(struct Node* p, int x){

struct Node *t = (struct Node *)malloc(sizeof(struct Node));
t->data=x;
if(p->data>x){

    t->next=first;
    first=t;
}
else{
    while((p->next)->data < (t->data)){
    p=p->next;
    }
    t->next=p->next;
    p->next=t;

}
}

int Delete(struct Node *p, int index){

int x;
//Deleting first node
if(index==1){

    first=first->next;
    x = p->data;
    free(p);
    return x;
}

//Deleting node at a given position
else {

    struct Node *q = NULL;
    for(int i=0;i<index-1 && p!=0;i++){
        q=p;
        p=p->next;
    }

    if(p!=0){
        q->next=p->next;
        x=p->data;
        free(p);
    }
    return x;

}

}

void checkSorted(struct Node *p){
int x=-32778;
int count=0;
while(p!=0){
    if(p->data<x){
        printf("It is not sorted!");
        count++;
    }
    x=p->data;
    p=p->next;
}
if(count==0)
 printf("It is sorted!");
}

void removeDublicate(struct Node *p){

struct Node *q = p->next;

while(q!=0){

    if(p->data!=q->data){
        p=q;
        q=q->next;

    }
    else{
        p->next=q->next;
        free(q);
        q=p->next;

    }


}

}

void reverseLL(struct Node *p){

// Reversing elements (not good method, it takes space)
/*
int x = count(first);
int A[x];
int i=0;
while(p!=0){
    A[i++]=p->data;
    p=p->next;

}
p=first; i--;
while(p!=0){
    p->data=A[i--];
    p=p->next;
}
*/

struct Node *q, *r;
q=NULL;
r=NULL;
while(p!=0){
    r=q;
    q=p;
    p=p->next;

    q->next=r;   //this is reversing the linnk

}

first=q;

}

void RreverseLL(struct Node *p, struct Node *q){
if(p!=0){
    RreverseLL(p->next,p);
    p->next=q;
}
else first=q;
}

void Merge(struct Node *first, struct Node *second){

    //which node should be the starting pointer (named as third)
    if(first->data<second->data){
            third=last=first;
            first=first->next;
            last->next=NULL;

    }
    else {
        third=last=second;
        second=second->next;
        last->next=NULL;
    }

    while(first!=0 && second!=0){

        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }

    }
    if(first!=NULL){
        last->next=first;
    }
    else{
        last->next=second;
    }

}

int main(){

int A[]={3,7,9,15,20,25};

create(A,6);

int B[]={4,8,12,14,16,21};
create2(B,6);
//display(first);


//printf("%d",count(first));

//printf("%d",sum(first));

//printf("%d",max(first));

//printf("%d is found!",search(first, 13)->data);

//printf("%d is found!",proSearch(first, 13));

//insertN(6,44);
// SortedInsert(first, 14);

//printf("%d is deleted! \n",Delete(first,3));

//checkSorted(first);

//removeDublicate(first);

//reverseLL(first);
//RreverseLL(first, NULL);

Merge(first, second);

display(third);

}
