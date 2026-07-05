#include <iostream>
#include <algorithm>
using namespace std;

void  activitySelection(int start[],int finish[],int n,int k){
    int i=0;
    cout<<i;
    for(int j=1;j<n;j++){
        if(start[j]>=finish[i]){
            cout<<" "<<j;
            i=j;
            k--;
        }
        if(k==0){
            break;
        }
    }
}
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;

    int finish[n],start[n];

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
    activitySelection(start,finish,n,k);

    return 0;
}