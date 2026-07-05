// #include <iostream>
// #include <cmath>
// using namespace std;
// long karatsuba(long x, long y) {
//     if (x < 10 || y < 10)
//         return x * y;

//     int n = 0;
//     long temp = x > y ? x : y;
//     while (temp > 0) {
//         temp /= 10;
//         n++;
//     }
//     int n2 = n / 2;

//     long a = x / (long)pow(10, n2);
//     long b = x % (long)pow(10, n2);
//     long c = y / (long)pow(10, n2);
//     long d = y % (long)pow(10, n2);

//     long c2 = karatsuba(a, c);
//     long c1 = karatsuba(a + b, c + d);
//     long c0 = karatsuba(b, d);

//     return (long)pow(10, 2 * n2) * c2 + (long)pow(10, n2) * (c1 - c2 - c0) + c0;
// }

// int main() {
//     long x, y;
//     cout << "Enter two numbers: ";
//     cin >> x >> y;
//     cout << "Result of multiplication: " << karatsuba(x, y) << std::endl;
//     return 0;
// }

#include<iostream>
#include<math.h>
using namespace std;

long karatsuba(long x,long y){
    if(x<10||y<10){
        return x*y;
    }
    int n = max(to_string(x).length(),to_string(y).length());
    int n2=n/2;

    long a = (long)x/(long)pow(10,n2);
    long b = (long)x%(long)pow(10,n2);
    long c = (long)y/(long)pow(10,n2);
    long d = (long)y%(long)pow(10,n2);

    long c2=karatsuba(a,c);
    long c1=karatsuba(a+b,c+d);
    long c0=karatsuba(b,d);
    long res= c2*(pow(10,2*n2)) + (c1-c2-c0)*(pow(10,n2)) +c0 ;
    return res;
}
int main(){
    int x,y;
    cin>>x;
    cin>>y;
    cout<<karatsuba(x,y);
}