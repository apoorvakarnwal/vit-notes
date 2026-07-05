#include<iostream>
#include <algorithm>
using namespace std;

void printActivities(int start[],int finish[],int n,int k){
    int i=0;
    cout<<i<<" ";
    for(int j=1;j<n;j++){
        if(start[j]>=finish[i]){
            i=j;
            cout<<j<<" ";
            k--;
        }
        if(k==0){
            break;
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int start[n],finish[n];
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>finish[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(finish[j]>finish[j+1]){
                swap(finish[j],finish[j+1]);
                swap(start[j],start[j+1]);
            }
        }
    }
    printActivities(start,finish,n,k);

    return 0;
}