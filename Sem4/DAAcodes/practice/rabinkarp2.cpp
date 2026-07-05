#include <iostream>
#include <string>
#include <cmath>

using namespace std;
# define d 256
int mod(int a,int b){
    return (a%b +b)%b;
}
// void search(string p1, int m, string t1, int n, int q){
//     int p=0,t=0;
//     int h= mod((pow(d,m-1)),q);
//     int j;
//     int count=0;

//     for(int i=0;i<m;i++){
//         p=mod (d*p +p1[i] , q);
//         t=mod (d*t + t1[i] , q);
//     }
//     for(int s=0;s<=n-m;s++){
//         if(p==t){
//             for(j=0 ; j<m ;j++){
//                 if(p1[j]!=t1[s+j]){
//                     break;
//                 }
//             }
//             if(j==m){
//                 count++;
//                 cout<<"String found at index"<<s+1<<endl;
//             }
//         }
//         if(s<n-m){
//             t= mod( d*(t- h*t1[s])   +  t1[s+m] , q);
//             if(t<0){
//                 t=t+q;
//             }
//         }

//     }
//     if(count==0){
//         cout<<"no string found";
//     }

// }


void search(string p1, int m, string t1, int n, int q){
    int p=0,t=0;
    int h= mod( pow(d,m-1) , q);
    int j;
    int count=0;

    for(int i=0;i<m;i++){
        p= mod(d * p + p1[i] ,q);
        t= mod(d * t + t1[i], q);
    }
    for(int s=0;s<=n-m;s++){
        if(p==t){
            for(j=0;j<m;j++){
                if(t1[j+s]!=p1[j] ){
                    break;
                }
            }
            if(j==m){
                count++;
                cout<<"strinf at index"<<s+1;
            }
        }

        if(s<n-m){
            t= mod(d*(t - t1[s] * h) + t1[s+m] ,q);
            if(t<0){
                t=t+q;
            }
        }
    }
    if (count==0){
        cout<<"no string found";
    }
}
int main(){
    int n, m;
    string text, pattern;
    cin >> n;
    cin >> text;
    cin >> m;
    cin >> pattern;
    int q = 13;
    search(pattern,m, text,n,q);
    return 0;
}