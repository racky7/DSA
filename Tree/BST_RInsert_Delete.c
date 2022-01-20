
#include <stdio.h>
#include <conio.h>

struct Node{
struct Node* lchild;
int data;
struct Node* rchild;
}*root=NULL;

struct Node* RInsert(struct Node* p, int key){
    struct Node *t;

    if(p==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
    }

    if(key<p->data){
        p->lchild=RInsert(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild=RInsert(p->rchild, key);
    }

    return p;

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

int Height(struct Node *p){
int x,y;
if(p==NULL) return -1;
x=Height(p->lchild);
y=Height(p->rchild);
return x>y?x+1:y+1;
}

struct Node* InPre(struct Node * p){
while(p && p->rchild!=NULL){
    p=p->rchild;
}
return p;
}

struct Node* InSucc(struct Node * p){
while(p && p->lchild!=NULL){
    p=p->lchild;
}
return p;
}

struct Node * Delete(struct Node * p, int key){

    struct Node *q;

    if(p==NULL){
        return NULL;
    }

    if(p->lchild==NULL & p->rchild==NULL){

        if(p==root)
            root=NULL;

        free(p);
        return NULL;
    }

if(key > p->data){
    p->rchild=Delete(p->rchild, key);
}
else if(key < p->data){
    p->lchild=Delete(p->lchild, key);
}
else {
    if(Height(p->lchild)>Height(p->rchild)){
        q=InPre(p->lchild);
        p->data=q->data;
        p->lchild=Delete(p->lchild,q->data);
    }
    else{
        q=InSucc(p->rchild);
        p->data=q->data;
        p->rchild=Delete(p->rchild,q->data);

    }
}

return p;

}



int main(){

root = RInsert(root,9);
RInsert(root,15);
RInsert(root,5);
RInsert(root,20);
RInsert(root,16);
RInsert(root,8);
RInsert(root,12);
RInsert(root,3);
RInsert(root,6);
Delete(root,6);
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
