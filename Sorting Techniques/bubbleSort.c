#include<stdio.h>
#include<conio.h>


void bubbleSort(int *arr, int n){
    int temp, flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
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

bubbleSort(&arr, n);

 for(int j=0;j<n;j++){
    printf("%d ",arr[j]);
}




}
