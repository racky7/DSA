
#include<stdio.h>
#include<conio.h>


void selectionSort(int *arr, int n){
    int temp, i, j, k;
   for(i=0;i<n-1;i++){
    for(j=k=i;j<n;j++){
        if(arr[j]<arr[k]){
            k=j;
        }
    }
    temp=arr[i];
    arr[i]=arr[k];
    arr[k]=temp;
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

selectionSort(&arr, n);

 for(int j=0;j<n;j++){
    printf("%d ",arr[j]);
}




}
