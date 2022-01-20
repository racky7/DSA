#include<stdio.h>
#include<conio.h>

struct Node{

int data;
struct Node *next;

}*first=NULL;

void insertLast(int x){

struct Node *p, *last;
p=(struct Node *)malloc(sizeof(struct Node));
p->data=x;
p->next=NULL;

if(first==NULL){
    first=last=p;
}
else{
    last->next=p;
    last=p;
}


}

void display(struct Node *p){

while(p!=0){
    printf("%d ",p->data);
    p=p->next;
}
}

void checkIsLoop(struct Node *p){

struct Node *q = first;

do{
    p=p->next;
    q=q->next;
    if(q!=0){
        q=q->next;
    }
    else q=NULL;
} while(p!=0 && q!=0 && p!=q);

if(p==q){
    printf("It is loop linked list!");
}
else printf("This is linear linked list");



}

int main(){

insertLast(3);
insertLast(5);
insertLast(7);
insertLast(9);
insertLast(12);
insertLast(15);

struct Node *p, *q;

p = q = first;
p = p->next->next;
q = q->next->next->next->next->next;
q->next=p;

checkIsLoop(first);


//display(first);



}
