
#include <stdio.h>
#include <conio.h>


//Stack Operation

struct sNode{
 int data;
struct sNode* next;
}*top=NULL;

void push(int x){
struct sNode * t = (struct sNode*)malloc(sizeof(struct sNode));
t->data=x;
t->next=NULL;

t->next=top;
top = t;

}

int pop(){

if(top==NULL){
    printf("Stack is empty");
}
else{
        struct Node*p = top;
    int x=top->data;
    top=top->next;
    free(p);
    return x;

}

}

int isEmptyS(){
if(top==NULL){
    return 1;
}
else return 0;
}

void displayS(struct sNode* p){

while(p){
    printf("%d \n",p->data);
    p=p->next;
}

}


//Queue
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


//Creating a Tree
struct tNode{
struct tNode* lchild;
int Data;
struct tNode* rchild;

};


void preorder_itr(struct tNode *t){

while(t!=0 || !isEmptyS()){
if(t!=0){
printf("%d ",t->Data);
push(t);
 //printf("\n pushed value in stack = %d --",t);
t=t->lchild;
}
else{
    t=pop();
    //printf("\n popped value in t = %d --",t);
    t=t->rchild;
}

}

}

void inorder_itr(struct tNode* t){
    while(t!=0 || !isEmptyS()){
    if(t!=0){
    push(t);
    t=t->lchild;

    }
    else{
        t=pop();
        printf("%d ",t->Data);
        t=t->rchild;
    }
    }

}

void postorder_itr(struct tNode* t){
 long int temp;
while(t!=0 || !isEmptyS()){
   long int temp;

    if(t!=0){

        push(t);
        t=t->lchild;

    }
    else{
        temp = pop();

        if(temp>0){
          push(-temp);
          t=((struct tNode*)temp)->rchild;
        }
        else{
            temp=temp*-1;
        printf("%d ", ((struct tNode*)temp)->Data);
        t=NULL;
        }
    }

}
}


int main(){


int x;
struct tNode* root = (struct tNode*)malloc(sizeof(struct tNode));
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
        t=(struct tNode*)malloc(sizeof(struct tNode));
        t->Data=x;
        t->lchild=0;
        t->rchild=0;
        p->lchild=t;
        enqueue(t);
    }

    printf("Enter value of Right Child: ");  //input -1 if you don't have right child
    scanf("%d",&x);
    if(x!=-1){
        t = (struct tNode*)malloc(sizeof(struct tNode));
        t->Data=x;
        t->lchild=0;
        t->rchild=0;
        p->rchild=t;
        enqueue(t);
    }


}

printf("\n Preorder Traversal : ");
preorder_itr(root);
printf("\n Inorder Traversal: ");
inorder_itr(root);
printf("\n Postorder Traversal: ");
postorder_itr(root);





}
