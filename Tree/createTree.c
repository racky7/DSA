#include <stdio.h>
#include <conio.h>

struct Node{
int data;
struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x){


struct Node *t = (struct Node*)malloc(sizeof(struct Node));
t->data=x;
t->next=NULL;
if(t==NULL){
    printf("Queue is empty!");
}
else{
if(front==NULL){
    front=rear=t;
}
else
{
rear->next=t;
rear=t;

}
}


}

int dequeue(){
int x=-1;
if(front==NULL){
    return 1;
}
else{
struct Node *p=front;
front=front->next;
x=p->data;
free(p);

}

return x;

}

void displayQ(){
struct Node *p=front;
while(p!=0){
    printf("%d ",p->data);
    p=p->next;
}
}

int isEmptyQ(){
if(front==NULL){
    return 1;
}
else return 0;
}

struct tNode{
struct tNode* lchild;
int Data;
struct tNode* rchild;

};

void preOrder(struct tNode* p){
    if(p!=0){
        printf("%d",p->Data);
        preOrder(p->lchild);
        preOrder(p->rchild);

    }

}

int main(){

/* Queueu Operation
enqueue(200);
enqueue(300);
enqueue(400);
dequeue();
dequeue();
dequeue();
displayQ();

printf("\n %d",isEmptyQ());

*/
int x;
struct tNode* root = (struct Node*)malloc(sizeof(struct tNode));
struct tNode *p, *t;
printf("Enter root value : ");
scanf("%d",&x);

root->Data=x;
root->lchild=0;
root->rchild=0;

enqueue(root);

while(!isEmptyQ()){
    p=dequeue();
    printf("Enter value of Left Child: "); //input -1 if you don't have left child
    scanf("%d",&x);
    if(x!=-1){
        t=(struct Node*)malloc(sizeof(struct tNode));
        t->Data=x;
        t->lchild=0;
        t->rchild=0;
        p->lchild=t;
        enqueue(t);
    }

    printf("Enter value of Right Child: ");  //input -1 if you don't have right child
    scanf("%d",&x);
    if(x!=-1){
        t = (struct Node*)malloc(sizeof(struct tNode));
        t->Data=x;
        t->lchild=0;
        t->rchild=0;
        p->rchild=t;
        enqueue(t);
    }

}

preOrder(root);




}
