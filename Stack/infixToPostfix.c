#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Stack{

int Size;
int Top;
int *s;

}st;

int isEmpty(struct Stack st){
    if(st.Top==-1){
        return 1;
    }
    else return 0;
}

void push(struct Stack *st, char x){

    if(st->Top==(st->Size-1)){
        printf("Stack is full!");
    }
    else {
        st->Top++;
        st->s[st->Top] = x;
    }

}

int pop(struct Stack *st){
int x;
if(st->Top==-1){
    return 0;
}
else {
    int x = st->s[st->Top];
    st->Top--;
    return x;
}

}

int stackTop(struct Stack st){
    return st.s[st.Top];
}
void display(struct Stack st){
int i;

for(i=0;i<=st.Top;i++){
    printf("%c \n",st.s[i]);
}


}

int isOperand(char x){

if(x=='+' || x=='-' || x=='*' || x=='/'){
    return 0;
}
else return 1;

}

int pre(char x){

if(x=='+'||x=='-'){
    return 1;
}
else if(x=='*'||x=='/'){
    return 2;
}

}

char * convertToPosfix(char *infix){

char *postfix = (char *)malloc(sizeof(char)*(strlen(infix)+1));
int i=0, j=0;

while(infix[i]!='\0'){

    if(isOperand(infix[i])){
        postfix[j++]=infix[i++];
    }
    else{
        if(pre(infix[i])>pre(st.s[st.Top])){
            push(&st,infix[i++]);
        }
        else{
            postfix[j++]=pop(&st);
        }
    }


}

while(!isEmpty(st)){
    postfix[j++]=pop(&st);
}

postfix[j]='\0';

return postfix;

}

int main(){

   st.Size=10;
   st.s = (char *)malloc(sizeof(char)*st.Size);
   st.Top = -1;

    char *infix = "a+b*c-d/e";

char *inToPo = convertToPosfix(infix);

printf("%s ",inToPo);




}
