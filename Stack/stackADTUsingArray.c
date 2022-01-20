#include <stdio.h>
#include <conio.h>

struct Stack{

int Size;
int Top;
int *s;

};

void push(struct Stack *st, int x){

if(st->Top==(st->Size-1)){
    printf("Stack overflow");

}
else{
    st->Top++;
    st->s[st->Top]=x;
}

}

void display(struct Stack st){
if(st.Top<0){
    printf("Stack is empty!");
}
else{
    while(st.Top>=0){
        printf("\n %d ",st.s[st.Top]);
        st.Top--;
    }
}
}

void pop(struct Stack *st){

if(st->Top<0){
    printf("Stack is empty!");
}
else{
    int x=st->s[st->Top];
    st->Top--;
    printf("%d is popped! \n",x);
}

}

int peek(struct Stack st, int pos){

if(st.Top<0){
    printf("Stack is empty!");
}
else{
    int x = st.s[st.Top - pos + 1]; //index = top - pos + 1
    return x;
}

}

int main(){

struct Stack st;
printf("Enter size of Stack ");
scanf("%d",&st.Size);

st.s = (int *)malloc(sizeof(int)*st.Size);

st.Top=-1;
push(&st,5);
push(&st,9);
push(&st,3);
//push(&st,7);
//pop(&st);
//pop(&st);
//pop(&st);

display(st);
printf("\n %d ",peek(st,2));


}
