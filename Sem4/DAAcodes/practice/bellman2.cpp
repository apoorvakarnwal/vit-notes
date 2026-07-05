#include<iostream>
#include <vector>
#include <climits>
using namespace std;

void bellman(vector<vector <int> >&adj, int start, int n){
    vector<vector <int> >res=adj;
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[start-1]=0;

    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]!=0 && dist[i]!=INT_MAX && (dist[i]+res[i][j]<dist[j])){
                    dist[j]=dist[i]+res[i][j];
                }
            }
        }
    }
    cout<<"From vertex: "<<start<<endl;
    for(int i=0;i<n;i++){
       cout<<"Distance from vertex: "<<i<<" "<<dist[i]<<endl;
    }

}
int main(){
    int n;
    cin>>n;
    vector<vector <int> > adj(n,vector <int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> adj[i][j];
        }
    }
    int start=5;
    bellman(adj,start,n);
    return 0;
}