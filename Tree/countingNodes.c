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
        printf("%d ",p->Data);
        preOrder(p->lchild);
        preOrder(p->rchild);

    }

}

int countNodes(struct tNode *p){
int x,y;
if(p!=0){
    x=countNodes(p->lchild);
    y=countNodes(p->rchild);
    return x+y+1;
}
return 0;
}

int countNodesWithTwoChildren(struct tNode *p){
int x,y;
if(p!=0){
    x=countNodes(p->lchild);
    y=countNodes(p->rchild);
    if(p->lchild && p->rchild){
    return x+y+1;
    }
    else return x+y;
}
return 0;
}

int countLeafNodes(struct tNode *p){
int x,y;
if(p!=0){
    x=countNodes(p->lchild);
    y=countNodes(p->rchild);
    if(p->lchild==-1 && p->rchild==-1){
    return x+y+1;
    }
    else return x+y;
}
return 0;
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

printf("\n Total number of nodes = %d",countNodes(root));
printf("\n Total number of nodes with 2 children = %d",countNodesWithTwoChildren(root));
printf("\n Total number of leaf nodes = %d",countLeafNodes(root));


}
