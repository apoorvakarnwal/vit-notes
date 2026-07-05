#include <iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

void activity(int start[],int finish[],int n,int k){
    int j=0;
    cout<<j<<" ";
    k--;
    for(int i=1;i<n;i++){
        if(start[i]>=finish[j]){
            cout<<i<<" ";
            k--;
            j=i;
        }
        if(k==0){
            break;
        }
    }
}
void activity2(int n,int k,int start[],int finish[]){
    int i=0;
    cout<<i<<" ";
    int count=1;

    for(int j=1;j<n;j++){
        if(count==k){
            break;
        }
        if(start[j]>=finish[i]){
            count++;
            i=j;
            cout<<i<<" ";
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
    activity2(n,k,start,finish);
    return 0;
}