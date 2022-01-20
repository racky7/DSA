#include <stdio.h>
#include <conio.h>

struct Node{
struct Node* lchild;
int data;
struct Node* rchild;
}*root=NULL;

void Insert(int key){

struct Node *t=root;
struct Node *p, *r;

if(root==NULL){
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    root = p;
    return;
}

while(t!=NULL){
    r=t;
    if(key<t->data){
        t=t->lchild;
    }
    else if(key>t->data){
        t=t->rchild;
    }
    else return;
}

    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data){
        r->lchild=p;
    }
    else if(key>r->data){
        r->rchild=p;
    }

}

void Inorder(struct Node *p){
if(p){
Inorder(p->lchild);
printf("%d ", p->data);
Inorder(p->rchild);
}
}

struct Node* Search(int key){

struct Node* t = root;
while(t!=NULL){
    if(t->data==key){
        return t;
    }
    else if(key<t->data){
        t=t->lchild;
    }
    else if(key>t->data){
        t=t->rchild;
    }
}

return;

};

int main(){

Insert(9);
Insert(15);
Insert(5);
Insert(20);
Insert(16);
Insert(8);
Insert(12);
Insert(3);
Insert(6);

Inorder(root);

printf("\n");
struct Node *temp;
temp=Search(6);

if(temp!=NULL){
    printf("Element %d is found!",temp->data);
}
else{
    printf("Element not found!");
}


}
