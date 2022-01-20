#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n, q;
    cin>>q>>n;

    int *A[n];
    int temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
        A[i] = new int[temp[i]];
        for(int j=0;j<temp[i];j++){
            cin>>A[i][j];
        }
    }

    int x[q], y[q];

    for(int k=0;k<q;k++){

        cin>>x[k]>>y[k];

    }

    for(int k=0;k<q;k++){
        cout<<A[x[k]][y[k]]<<"\n";
    }



    return 0;
}
