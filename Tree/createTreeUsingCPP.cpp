#include <iostream>
using namespace std;


struct Node{
int data;
struct Node* next;
}*front=NULL,*rear=NULL;

struct tNode{
int Data;
struct tNode * lchild;
struct tNode * rchild;
}*root;


void enqueue(int x){

struct Node *t = new Node;
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

int dequeue(){

if(front==NULL){
    return -1;
}
else{
    int x = front->data;
    struct Node*p = front;
    front = front->next;
    free(p);
    return x;

}

}

void displayQ(){
struct Node *p = front;
while(p!=0){
    cout<<p->data<<" ";
    p=p->next;

}
}

int isEmptyQ(){
if(front==NULL){
    return 1;
}
else return 0;
}


void displayT(struct tNode* p){
    if(p){
        cout<<p->Data;
        displayT(p->lchild);
        displayT(p->rchild);
    }
}

int main(){
/* Queue operation
enqueue(5);
enqueue(10);
enqueue(10);
enqueue(20);
dequeue();
dequeue();
displayQ();

*/
int x;
cout<<"Enter value in root: ";
cin>>x;
root = new tNode;
struct tNode *t, *p;
root->Data=x;
root->lchild = root->rchild = 0;
enqueue(root);

while(!isEmptyQ){
    p=dequeue();
    cout<<"Enter value of left child: ";
    cin>>x; //input -1 if you have no left child
    if(x!=-1){
    t = new tNode;
    t->Data=x;
    t->lchild=t->rchild=0;
    p->lchild=t;
    enqueue(t);
    }
    cout<<"Enter value of right child: ";
    cin>>x; //input -1 if you have no right child
    if(x!=-1){
        t=new tNode;
        t->data=x;
        t->lchild=t->rchild=0;
        p->rchild=t;
        enqueue(t);
    }


}

displayT(root);
}
