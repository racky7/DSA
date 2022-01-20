#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Stack{

int Size;
int Top;
int *s;

}st;

int stackTop(struct Stack st){
    return st.s[st.Top];
}

int nextTop(struct Stack st){
    return st.s[st.Top-1];
}






void push(struct Stack *st, int x){
    if(st->Top==st->Size-1){
        return 0;
    }
    else {
        st->Top++;
        st->s[st->Top]=x;
    }
}

int pop(struct Stack *st){
    if(st->Top==-1){
        return 0;
    }
    else {
        int x = st->s[st->Top];
        st->Top--;
        return x;

    }
}

int isOperand(int x){

if(x=='/' || x=='*' || x=='+' || x=='-'){
    return 0;
}
else return 1;

}

int postFixEvaluation(char *postfix){
 int i, x, y, r;

for(i=0;postfix[i]!='\0';i++){
    if(isOperand(postfix[i])){
        push(&st,abs(postfix[i]-48));

    }
    else{
        y = (pop(&st));
        x = (pop(&st));
        /*
        printf("y = %d \n ",y);
        printf("x = %d \n ",x);
        printf("postfix = %c \n ",postfix[i]);
        */
        switch(postfix[i]){
            case '+' : {r=x+y; push(&st,r); break;}
            case '-' : {r=x-y; push(&st,r); break;}
            case '*' : {r=x*y; push(&st,r); break;}
            case '/' : {r=x/y; push(&st,r); break;}

        }

        //printf("top = %d \n ",stackTop(st));


    }
    }


    return pop(&st);
}



int main(){
    st.Size = 15;
    st.Top = -1;
    st.s = (int *)malloc(sizeof(int)*st.Size);

    char *postfix = "35*62/+4-";

   int x = postFixEvaluation(postfix);

   printf("%d",x);


}
