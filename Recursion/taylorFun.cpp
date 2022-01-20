#include <iostream>

using namespace std;

//Normal method

/*

double e(int x, int n){

    static double p=1, f=1;

    if(n==0) return 1;
    else {

        double r = e(x,n-1);
        p=p*x; f=f*n;
        return r + (p/f);

    }


}

*/


//using Horner's Rule - Recursive

double e(int x, int n){

double static s =1;

if(n==0) return s;

s= 1 + x*s/n;

return e(x,n-1);

}



//using Horner's Rule (iterative)
/*
double e(int x, int n){

double s=1;

for(;n>0;n--){
    s= 1 + x*s/n;
}

return s;
}
*/





int main(){

    cout<<e(5,10);

}
