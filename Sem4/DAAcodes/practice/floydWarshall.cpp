#include <iostream>
#include<vector>
#include <climits>

using namespace std;
#define INF 10000

void floyd(vector <vector<int> >&adj , int n){
    vector <vector<int> > result = adj;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(result[i][k]+result[k][j] < result[i][j]){
                    result[i][j]=result[i][k]+result[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(result[i][j]== INF){
                cout<<"INF ";
            }
            else{
                cout<<result[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n=4;
    vector <vector<int> > adj(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    floyd(adj,n);
    return 0;
}