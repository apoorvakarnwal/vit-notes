#include <iostream>
#include <cmath>
using namespace std;
# define d 256

int mod(int a,int b){
    return (a%b + b)%b;
}
void rabin(string t1,string p1,int n,int m){
    int q=101;
    int t=0,p=0;
    int h=mod(pow(d,m-1),q);
    int j;
    
    for(int i=0;i<m;i++){
        p=mod(d*p + p1[i] , q);
        t=mod(d*t + t1[i] , q);
    }
    int count=0;
    for(int s=0;s<=n-m;s++){
        if(p==t){
            for(j=0;j<m;j++){
                if(p1[j]!=t1[j+s]){
                    break;
                }
            }
            if(j==m){
                count++;
                cout<<"Shift occur"<<s+1;
            }
        }
        if(s<n-m){
            t= mod(d*(t-t1[s]*h) +t1[s+m] ,q);
        }
    }
    if(count==0){
        cout<<"no string found";
    }
}

int main(){
    int m,n;
    string text,pattern;
    cin>>n;
    cin>>text;
    cin>>m;
    cin>>pattern;
    rabin(text,pattern,n,m);
    return 0;
}