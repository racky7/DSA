#include <stdio.h>
#include <conio.h>

struct Queue{

int Size;
int front;
int rear;
int *Q;

}q1;

void create(struct Queue *q1, int size)
{
q1->Size=size;
q1->front=q1->rear=-1;
q1->Q=(int *)malloc(q1->Size*sizeof(int));
}

void enqueue(struct Queue *q1, int x){
if(q1->rear==q1->Size-1){
    printf("Queue is full! ");
}
else {
    q1->rear++;
    q1->Q[q1->rear]=x;
}
}

int dequeue(struct Queue *q1){
int x;

if(q1->front==q1->rear){
    printf("Queue is empty");
}
else {
    q1->front++;
    x=q1->Q[q1->front];
    return x;
}
}

void display(struct Queue q1){
    if(q1.rear==-1){
        printf("Queue is empty");
    }
    while(q1.front<q1.rear){
        printf("%d ",q1.Q[q1.front+1]);
        q1.front++;
    }
}


int main(){

create(&q1,5);

enqueue(&q1,5);
enqueue(&q1,9);
enqueue(&q1,12);
enqueue(&q1,18);
enqueue(&q1,25);
enqueue(&q1,35);
dequeue(&q1);

display(q1);

}
