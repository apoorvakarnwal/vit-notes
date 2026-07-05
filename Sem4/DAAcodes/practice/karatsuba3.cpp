#include<iostream>
#include <cmath>
using namespace std;

long karatsuba(long x, long y){
    if(x<10||y<10){
        return x*y;
    }
    int n=max(to_string(x).length(), to_string(y).length());
    int n2=n/2;
    long a=(long)x/(long)(pow(10,n2));
    long b=(long)x%(long)(pow(10,n2));
    long c=(long)y/(long)(pow(10,n2));
    long d=(long)y%(long)(pow(10,n2));
    long c2=karatsuba(a,c);
    long c1=karatsuba(a+b,c+d);
    long c0=karatsuba(b,d);

    return(c2*pow(10,2*n2)+ (c1-c0-c2)*pow(10,n2)  +c0);
}
int main(){
    long x,y;
    cin>>x>>y;
    cout<< karatsuba(x,y);

    return 0;
}