#include <iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

long karatsuba(long x,long y){
    if(x<10||y<10){
        return x*y;
    }
    int n=max(to_string(x).length(), to_string(y).length());
    int n2=n/2;
    long a= x/ (long)(pow(10,n2));
    long b= x% (long)(pow(10,n2));
    long c= y/ (long)(pow(10,n2));
    long d= y% (long)(pow(10,n2));

    long c2=karatsuba(a,c);
    long c1=karatsuba(a+b,c+d);
    long c0=karatsuba(b,d);

    return (c2*(pow(10,2*n2)))+((c1-c2-c0)*pow(10,n2))+c0;

}

int main(){
    long x,y;
    cin>>x>>y;
    cout<<karatsuba2(x,y);
    return 0;
}