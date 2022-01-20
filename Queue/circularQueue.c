#include <stdio.h>
#include <conio.h>

struct Queue{
int Size;
int front;
int rear;
int *Q;
}q1;

void enqueue(struct Queue *q1, int x){

if((q1->rear+1)%(q1->Size)==q1->front){
    printf("Queue is full!");
}
else {
    q1->rear=(q1->rear+1)%(q1->Size);
    q1->Q[q1->rear]=x;
}
}

int dequeue(struct Queue *q1){
int x=-1;
if(q1->front==q1->rear){
    printf("Queue is empty! ");
}
else{
    q1->front=(q1->front+1)%(q1->Size);
    x=q1->Q[q1->front];
    return x;
}

}

void display(struct Queue q1){
    if(q1.front==q1.rear){
        printf("Queue is empty");
    }
    while(q1.front!=q1.rear){
        printf("%d ",q1.Q[(q1.front+1)%(q1.Size)]);
        q1.front=(q1.front+1)%(q1.Size);
    }
}

int main(){

q1.Size = 7;
q1.front=q1.rear=0;
q1.Q = (int *)malloc(sizeof(int)*q1.Size);

enqueue(&q1,5);
enqueue(&q1,10);
enqueue(&q1,15);
enqueue(&q1,20);
dequeue(&q1);
enqueue(&q1,88);
enqueue(&q1,99);
enqueue(&q1,77);
dequeue(&q1);
enqueue(&q1,55);
display(q1);


}
