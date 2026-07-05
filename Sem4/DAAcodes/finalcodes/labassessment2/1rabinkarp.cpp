#include <iostream>
#include <string>
using namespace std;
# define d 256
int mod(int a,int b){
    return (a%b + b)%b;
}
void rabinkarp(string t1,string p1,int n,int m){
    int q=101;
    int p=0,t=0;
    int i,j;
    int h=mod(pow(d,m-1),q);
    for(i=0;i<m;i++){
        p= mod(d*p +p1[i] ,q);
        t= mod(d*t +t1[i] ,q);
    }
    int count=0;
    
    for(int s=0;s<=n-m;s++){
        if(p==t){
            for(j=0;j<m;j++){
                if(t1[s+j]!=p1[j]){
                    break;
                }
            }
            if(j==m){
                count++;
                cout<<"string at index "<<s+1;
            }
        }
        if(s<n-m){
            t= mod(d*(t-t1[s]*h)+t1[s+m], q);
        }
    }
    if(count==0){
        cout<<"String not found"<<endl;
    }
}
int main(){
    int m,n;
    string text,pattern;
    cin>>n;
    cin>>text;
    cin>>m;
    cin>>pattern;
    rabinkarp(text,pattern,n,m);
    return 0;
}