#include <iostream>

using namespace std;

int main(){

int A[]={6,7,8,9,11,12,15,16,17,18,19};


//Method 1 (for sorted array)
/*
int diff = A[0]-0;

for(int i=0;i<11;i++){
    if(A[i]-i!=diff){
        while(diff<A[i]-i){
            cout<<diff+i<<" ";
            diff++;
        }
    }
}
*/

//Method 2 using Hashing (applicable for unsorted array too)

int B[]={15,19,8,9,18,12,6,16,17,11,7};

int low = 6, high = 19;

int H[high]={0};

for(int i=0;i<11;i++){
    H[B[i]]++;  //H[A[i]] = 1

}

for(int i=low;i<high;i++){
    if(H[i]==0){
        cout<<i<<" ";
    }
}

}
