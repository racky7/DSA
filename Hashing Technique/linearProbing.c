#include <stdio.h>
#include <conio.h>

#define SIZE 10

int hash(int x){
return x%SIZE;

}

int prob(int HT[], int key)
{

    int i=0;

    int index = hash(key);
    while(HT[(index+i)%SIZE]!=0){
        i++;

    }

    return (index+i)%SIZE;

}
void insert(int HT[], int key){

int index = hash(key);

if(HT[index]!=0){
    index = prob(HT, key);
}
HT[index]=key;
}

int search(int HT[], int key){

int index = hash(key);
int i=0;
while(HT[(index+i)%SIZE]!=key){
    if(i>9) return -1;
    i++;
}
index = (index+i)%SIZE;
return index;

}



void main(){

int HT[10] = {0};
insert(HT, 12);
insert(HT, 32);
insert(HT, 35);
insert(HT, 39);
insert(HT, 49);
insert(HT,21);
insert(HT,31);
insert(HT,41);
insert(HT,67);
insert(HT,98);

printf("%d is found at index %d \n", 12, search(HT, 12));
printf("%d is found at index %d \n", 32, search(HT, 32));
printf("%d is found at index %d \n", 35, search(HT, 35));
printf("%d is found at index %d \n", 39, search(HT, 39));
printf("%d is found at index %d \n", 49, search(HT, 49));
printf("%d is found at index %d \n", 21, search(HT, 21));
printf("%d is found at index %d \n", 31, search(HT, 31));
printf("%d is found at index %d \n", 41, search(HT, 41));
printf("%d is found at index %d \n", 67, search(HT, 67));
printf("%d is found at index %d \n", 98, search(HT, 98));
printf("%d is found at index %d \n", 89, search(HT, 89));



}
