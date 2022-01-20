
#include<stdio.h>
#include<conio.h>


void insertionSort(int *arr, int n){
   int x,j;
   for(int i=1;i<n;i++){
    x=arr[i];
    j=i-1;
    while(arr[j]>x&j!=-1){
        arr[j+1]=arr[j];
        arr[j]=x;
        j--;
    }
   }

}

void main(){
int n;
printf("Enter size of array : ");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

insertionSort(&arr, n);

 for(int j=0;j<n;j++){
    printf("%d ",arr[j]);
}




}
