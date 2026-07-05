#include<iostream>
#include<climits>
#include <vector>
using namespace std;

void bellman(vector <vector<int> >&adj, int n,int start){
    int distance[n];
    // all distance infinity
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
    }
    // start vertex 0
    distance[start-1]=0;
    for (int k = 0; k < n - 1; k++){
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && distance[u] != INT_MAX && distance[u] + adj[u][v] < distance[v]) {
                    distance[v] = distance[u] + adj[u][v];
                }
            }
        }
    }

    cout<<"From source vertex: "<<start<<endl;
    for(int i=0;i<n;i++){
        cout << "Distance of vertex " << (i + 1) << ":" << distance[i] << endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector <vector<int> > adj(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int start = 5;
    bellman(adj, n, start);
    return 0;
}