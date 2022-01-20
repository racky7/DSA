#include<stdio.h>
#include<conio.h>


struct queue{

int front;
int rear;
int *A;
int size;

}q;

int isEmpty(struct queue *q){
    if(q->rear==-1){
        return 1;
    }
    else return 0;
}

void enqueue(struct queue *q, int x){

    if(q->rear!=q->size-1){
    q->rear++;
    q->A[q->rear]=x;

    }


}

int dequeue(struct queue *q){
int x = q->A[q->front];

if(!isEmpty(q)){
    q->front++;
    return x;
}

}

void display(struct queue *q){

if(!isEmpty(q)){
int ptr = q->front;
while(ptr<=q->rear){
    printf("%d ",q->A[ptr]);
    ptr++;


}
}

}

void DFS(int A[][7], int i, int n){
int u=i;
int visited[7] = {0};

printf("%d ",i);
visited[i]=1;
enqueue(&q, i);


while(!isEmpty(&q)){

    u = dequeue(&q);

    for(int v=1;v<n;v++){
        if(A[u][v]==1 && visited[v]==0){
            printf("%d ", v);
            visited[v]=1;
            enqueue(&q, v);

        }
    }
}



}


void main(){


    q.size = 7;
    q.front=0;
    q.rear =-1;
    q.A = malloc(sizeof(int)*q.size);
//    enqueue(&q, 5);
//    enqueue(&q, 10);
//    enqueue(&q, 15);
//    dequeue(&q);
//    display(&q);

    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

    DFS(G,4,7);
}
