#include<stdio.h>
#include<conio.h>

struct Node{
int data;
struct Node *next;
}*first=NULL;

void push(int x){

struct Node *t = (struct Node*)malloc(sizeof(struct Node));
t->data=x;
t->next=first;
first=t;

}
int isEmpty(){
if(first==NULL) return 1;
else return 0;
}
int pop(struct Node *p){
if(!isEmpty()){
        int x = p->data;
first=first->next;
free(p);
return x;

}
return 0;
}

void display(struct Node *p){
while(p){
    printf("%d ",p->data);
    p=p->next;
}
}

void DFS(int G[][7], int i, int n){

    int u = i;

    int visited[7] = {0};
    printf("%d ",u);
    visited[u]=1;
    push(u);
    while(!isEmpty()){
        int v;
        u = pop(first);
        for(v=1;v<=n;v++){
            if(G[u][v]==1 && visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                push(u);
                u=v;
            }
        }

    }

}

int main(){

//push(5);
//push(15);
//push(25);
//pop(first);
//display(first);

int G[7][7] = {{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

DFS(G, 3, 7);

}
