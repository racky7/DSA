//Increasing size of array using DMA


#include<iostream>

using namespace std;

int main(){

int *p, *q;
int n;
cout<<"enter your size of array: ";
cin>>n;
p = new int[n];

cout<<"Enter your "<<n<<" elements: ";

for(int i=0;i<n;i++){
    cin>>p[i];
}

cout<<"Enter new size of your array: ";
int N;
cin>>N;

q = new int[N];

for(int i=0;i<n;i++){
    q[i]=p[i];
}

delete []p;
p=q;
q=NULL;

cout<<"Enter your remaining "<<N-n<<" elements : ";

for(int i=n;i<N;i++){
    cin>>p[i];
}

cout<<"Final elements are: ";

for(int i=0;i<N;i++){
    cout<<p[i]<<" ";
}


}
