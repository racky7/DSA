#include <stdio.h>
#include <conio.h>

struct Node{
int data;
struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
           printf("Queue is full!");

    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
        rear->next=t;
        rear=t;
        }
    }


}

int dequeue(){

if(front==NULL){
    printf(" Queue is empty! ");
}
else{
struct Node *p = front;
int x;
x=front->data;
front=front->next;
free(p);
return x;
}

}

void display(){
struct Node *p = front;
while(p!=0){
    printf("%d ",p->data);
    p=p->next;

}
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();


}
