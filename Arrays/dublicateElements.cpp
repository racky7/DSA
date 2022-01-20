#include <iostream>

using namespace std;

int main(){

    int A[]={3,6,8,8,1,12,15,15,15,20};
    int n=10;

//Method 1

/*
    int lastDublicate = 0;


    for(int i=0;i<n;i++){
        if(A[i]==A[i+1] && A[i]!=lastDublicate){
            cout<<A[i]<<" ";
            lastDublicate=A[i];
        }
    }
    cout<<endl;
    //For counting dublicates
    int j;
    for(int i=0;i<n-1;i++){

        if(A[i]==A[i+1]){
            j=i+1;
            while(A[i]==A[j]){
                j++;
            }
             cout<<A[i]<<" appeared for "<<j-i<<" times \n";
             i = j-1;

        }

    }

    */


// Method 2 (Using hasing) - applicable to sorted and unsorted both

/*
     int B[]={15,6,8,12,1,8,15,3,15,20}; //n=10
      int low = 3, high = 20;
     int H[high]={0};

     for(int i=0;i<n;i++){
        H[B[i]]++;
     }

     for(int i=low;i<high;i++){
        if(H[i]>1){
            cout<<i<<" appeared for "<<H[i]<<" times. "<<endl;
        }
     }

*/

//Method 3 (for unsorted array)

    int C[]={15,6,8,12,1,8,15,3,15,20}; //n=10

    int count;

    for(int i=0;i<n-1;i++){
        count=1;
        if(C[i]!=-1){
        for(int j=i+1;j<n;j++){
            if(C[i]==C[j]){
                count++;
                C[j]=-1;
            }

        }
            if(count>1)
            cout<<C[i]<<" appeared for "<<count<<" times. "<<endl;

        }


    }









}
