#include<stdio.h>
#include<conio.h>

void Merge(int A[], int l, int mid, int h){
    int i,j,k;
    i=l; j=mid+1; k=l;
    int B[h+1];

    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else B[k++]=A[j++];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(;i<=mid;i++){
        B[k++]=A[i];
    }

    for(int m=l;m<=h;m++) A[m]=B[m];


}

void MergeSort(int A[], int n){
int p, l, h, mid;
for(p=2;p<=n;p=p*2){
    for(int i=0;i+p-1<=n;i=i+p){
        l=i;
        h=i+p-1;
        mid=(l+h)/2;

        Merge(A,l,mid,h);
    }
}
if(p/2 < n) Merge(A,0,p/2-1,n-1);  //for odd number of elements which left out 'jisme 2 ki power nhi bn rhe ho'

}

void main(){

    int A[]={3,4,7,8,2,5,6,9,1};
    int n=9;
    MergeSort(A, n);

    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

}
