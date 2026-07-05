#include <iostream>
#include <vector>

using namespace std;

void floyd(vector<vector<int> >&adj, int n){
    vector<vector<int> >res=adj;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res[i][k]+res[k][j]<res[i][j]){
                    res[i][j]=res[i][k]+res[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        } 
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > adj(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        } 
    }
    floyd(adj,n);
    return 0;
}