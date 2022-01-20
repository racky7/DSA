#include<iostream>

using namespace std;


struct Array{
int A[20];
int size;
int length;

};

void display(struct Array arr){

for(int i=0;i<arr.length;i++){
    cout<<arr.A[i]<<" ";
}
}

void append(struct Array *arr, int x){
    arr->A[arr->length]=x;
    arr->length++;

}


void insert(struct Array *arr, int index, int x){

    int i;
    for(i=arr->length; i>index;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;



}

void Delete(struct Array *arr, int index){
    int i;
    int x=arr->A[index];

    if(index>=0 && index<arr->length){

    for(i=index;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
    }
    }
    arr->length--;
    cout<<x<<" is deleted! \n";
}

void swap(int *x, int *y){

int temp;
temp = *x;
*x = *y;
*y = temp;

}


int LinearSearch(struct Array *arr, int key){


    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            //Transpotion technique
           // swap(&arr->A[i],&arr->A[i-1]);

           //Move to the Head/Front Technique
            // swap(&arr->A[i],&arr->A[0]);

            cout<<"Element found at index "<<i<<endl;
            return 0;
        }

    }

    cout<<-1<<endl;
    return 0;

}

//Iterative approach of binary Search
int BinarySearch(struct Array arr, int key){

    int l=0;
    int h=arr.length-1;

    while(l<=h){
    int mid = ((l+h)/2);

    if(arr.A[mid]==key){
            cout<<"Element found at index "<<mid<<endl;
            return 0;
    }
    else if (key>arr.A[mid]){
        l = mid + 1;
    }

    else {
        h = mid - 1;
    }
    }

    cout<<-1;
    return 0;
}

// Recursive approach of Binary search

int RBinSearch(struct Array arr, int l, int h, int key){
int mid;
if(l<=h){
    mid = (l+h)/2;

    if(arr.A[mid]==key){
         cout<<"Element found at index "<<mid<<endl;
        return 0;
    }
    else if (key<arr.A[mid]){
        return RBinSearch(arr, l, mid-1, key);
    }
    else return RBinSearch(arr, mid+1, h, key);
}

}

void Reverse(struct Array *arr){


int *arrB = new int[arr->length];

for(int i=arr->length-1, j=0; i>=0; i--, j++){
        arrB[i] = arr->A[j];
}

for(int i=0;i<arr->length;i++){
    arr->A[i] = arrB[i];
}


}

void Reverse2(struct Array *arr){

for(int i=0, j=arr->length-1; i<j; i++, j--){
    swap(arr->A[i],arr->A[j]);
}


}

insertInSorted(struct Array *arr, int num){
int i=arr->length-1;
while(arr->A[i]>num){
    arr->A[i+1]=arr->A[i];
    i--;
}
arr->A[i+1]=num;
arr->length++;


}

void checkSorted(struct Array arr){

for(int i=0;i<arr.length-1;i++){
    if(arr.A[i]>arr.A[i+1]) {
        cout<<"Not sorted!"<<endl;
        return;
    }

}

cout<<"Sorted array!"<<endl;

}

void negativeOnLeft(struct Array *arr){

int i=0, j=arr->length-1;

while(i<j){
    while(arr->A[i]<0){i++;}
    while(arr->A[j]>0){j--;}
    if(i<j)
        swap(arr->A[i],arr->A[j]);
}

}

struct Array *mergeTwoArray(struct Array *arr1, struct Array *arr2){

    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

    while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j]){
        arr3->A[k]=arr1->A[i];
        k++; i++;
    }
    else {
        arr3->A[k]=arr2->A[j];
        k++; j++;
    }

    }

    for(;i<(arr1->length);i++){
        arr3->A[k]=arr1->A[i];
        k++;
    }
    for(;j<(arr2->length);j++){
        arr3->A[k]=arr2->A[j];
        k++;
    }

    arr3->length=arr1->length+arr2->length;
arr3->size=10;
return arr3;



}


struct Array *UnionOf(struct Array *arr1, struct Array *arr2){

    int i,j,k;



    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

    /*

    int set=0;
    for(i=0;i<arr1->length;i++){
        arr3->A[i]=arr1->A[i];
    }

    for(j=0;j<arr2->length;j++){
        for(k=0;k<arr1->length;k++){
            if(arr2->A[j]!=arr3->A[k]){
                 set=1;
            }
            else if (arr2->A[j]==arr3->A[k]){
                    set=0;
                break;
            }

        }
        if(set==1){
        arr3->A[i]=arr2->A[j];
        i++;
        }


    }

    */

    //Using merge technique

    i=j=k=0;

    while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]==arr2->A[j]){
        arr3->A[k]=arr1->A[i];
        i++; j++; k++;
    }
    else if(arr1->A[i]<arr2->A[j]){
        arr3->A[k]=arr1->A[i];
        i++; k++;
    }
    else {
        arr3->A[k]=arr2->A[j];
        j++; k++;
    }

    }

    for(;i<arr1->length;i++){
        arr3->A[k]=arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        arr3->A[k]=arr2->A[j];
        k++;
    }


    arr3->length=k;
    arr3->size=10;

    return arr3;

}

struct Array *Intersection(struct Array *arr1, struct Array *arr2){

    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

    while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]==arr2->A[j]){
        arr3->A[k]=arr1->A[i];
        k++; i++; j++;
    }
    else if(arr1->A[i]<arr2->A[j]){

        i++;
    }
    else {

        j++;
    }

    }
/*
    for(;i<(arr1->length);i++){
        arr3->A[k]=arr1->A[i];
        k++;
    }
    for(;j<(arr2->length);j++){
        arr3->A[k]=arr2->A[j];
        k++;
    }
*/

    arr3->length=arr1->length+arr2->length;
arr3->size=10;
return arr3;



}

struct Array *Difference(struct Array *arr1, struct Array *arr2){

    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

    while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j])
arr3->A[k++]=arr1->A[i++];
else if(arr2->A[j]<arr1->A[i])
j++;
else
{
i++;
j++;
}
}

for(;i<arr1->length;i++)
arr3->A[k++]=arr1->A[i];
arr3->length=k;
arr3->size=10;
return arr3;
}





int main(){

    struct Array arr = {{4,-8,8,-4,10,15,-25,18,-15,21,-21,24},20,12};

    struct Array arr1={{2,9,21,28,35},10,5};
struct Array arr2={{2,3,9,18,28},10,5};
struct Array *arr3;

   // append(&arr, 14);

    // insert(&arr,4,15);

    // Delete(&arr, 3);

   // LinearSearch(&arr, 6);
   //LinearSearch(&arr, 21);

  // BinarySearch(arr,21);
   // RBinSearch(arr,0,arr.length-1,21);

  // Reverse(&arr);
   // Reverse2(&arr);

   //insertInSorted(&arr, 12);

   // checkSorted(arr);

   // negativeOnLeft(&arr);

  // arr3 = mergeTwoArray(&arr1,&arr2);

 //  arr3 = UnionOf(&arr1, &arr2);

   // arr3 = Intersection(&arr1, &arr2);

  // arr3 = Difference(&arr1, &arr2);

    display(*arr3);


}
