#include <iostream>
using namespace std;
#define max 100

bool isClique(int graph[max][max],int subset[max],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        if(subset[i]){
            count++;
        }
    }
    if(count!=k){
        return false;
    }
    for(int i=0;i<n;i++){
        if(subset[i]){
            for(int j=i+1;j<n;j++){
                if(subset[j] && !graph[i][j]){
                    return false;
                }
            }
        }
    }
    return false;
}
int main(){
    int n,k;
    cin>>n;
    int graph[max][max];
    int subset[max];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>subset[i];
    }
    if(isClique(graph,subset,n,n)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}