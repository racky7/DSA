#include<stdio.h>
#include<conio.h>

struct Node{
int data;
struct Node *next;
}*top=NULL;

void push(int x){

struct Node *t=(struct Node *)malloc(sizeof(struct Node));
if(t==NULL) return -1;
t->data=x;
t->next=top;
top=t;

}

void display(struct Node *p){
if(p==NULL){
    printf("Stack is empty!");
}
while(p){
    printf("%d \n",p->data);
    p=p->next;
}
}

int pop(struct Node *p){
if(p==NULL){
    return -1;
}
else{
    int x=p->data;
    top=top->next;
    free(p);
    return x;
}
}

int peek(int pos){

    struct Node *p = top;
    if(p==NULL || pos<1) return -1;

    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    if(p){
    return p->data;
    }

}

int stackTop(){
if(top){
    return top->data;
}
else return -1;
}

int isEmpty(){
return top!=0?0:1;
}

int isFull(){
struct Node *t=(struct Node *)malloc(sizeof(struct Node));
int r = t!=0?1:0;
free(t);
return r;
}


int main(){

push(5);
push(9);
push(15);
push(12);
push(18);
//pop(top);
//pop(top);
//pop(top);
//pop(top);
printf("%d \n",peek(3));
//display(top);


}
