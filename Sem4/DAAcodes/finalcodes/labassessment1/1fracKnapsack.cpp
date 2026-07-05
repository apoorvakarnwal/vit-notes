#include <iostream>
#include <iomanip>
using namespace std;

void knapsack2(float p[], float w[],float capacity, int n){
    float x[n];
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    int remcap=capacity;
    int count=0;
    for(int i=0;i<n;i++){
        if(remcap>=w[i]){
            x[i]=1;
            remcap-=w[i];
            count++;
        }
        else{
            break;
        }
    }
    if(count<n){
        x[count]=remcap/w[count];
    }
    for(int i=0;i<n;i++){
        cout<<x[i]<<fixed<<setprecision(1)<<" ";
    }
}

int main(){
    int n;
    int W;
    cin>>W>>n;
    float p[n], w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    fknapsack(p,w,W,n);
    return 0;
}