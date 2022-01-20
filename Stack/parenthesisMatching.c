#include<stdio.h>
#include<conio.h>
#include <string.h>

struct Stack{
int Size;
int Top;
int *s;

}st;

int isEmpty(struct Stack st){

    if(st.Top==-1) return 1;
    else return 0;

}

int isFull(struct Stack st){

    if(st.Top==(st.Size-1)) return 1;
    else return 0;

}

int push(struct Stack *st, char x){

    if(st->Top==(st->Size-1)) return 0;
    else{
        st->Top++;
        st->s[st->Top] = x;
    }

}

int pop(struct Stack *st){
    if(st->Top==-1) return 0;
    else{
        st->Top--;
    }

}

char stackTop(struct Stack st){
return st.s[st.Top];
}

int main(){

//char exp[] = "((a+b)*(c-d))";

/*
ASCII Codes
( - 40
) - 41
{ - 91
} - 93
[ - 123
] - 125

*/
char exp[] = "{([a+b]*[c-d])/e}";
st.Size = strlen(exp);
st.Top=-1;
st.s = (char *)malloc(sizeof(char)*st.Size);

for(int i=0;exp[i]!='\0';i++){

    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
        push(&st,exp[i]);
    }
    else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){

       // printf("%c %c\n",stackTop(st),exp[i]-2);

        if(isEmpty(st)) return printf("Parenthesis are NOT Okay.");

        else if(stackTop(st)==(exp[i]-2) || stackTop(st)==(exp[i]-1))
        pop(&st);

        else return printf("Parenthesis are N O T Okay.");



    }

}

return isEmpty(st)?printf("Parenthesis are Okay."):printf("Parenthesis are NOT Okay.");

}
