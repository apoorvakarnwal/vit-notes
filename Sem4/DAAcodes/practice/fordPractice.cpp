#include <iostream>
#include <queue>
#include<climits>
#include <cstring>
# define V 6
using namespace std;

bool bfs(int graph[V][V],int s,int t,int parent[]){
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    queue <int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v]){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }

    return visited[t];
}
int fordfulkerson(int graph[V][V],int s,int t,int parent[]){
    int maxflow=0;
    while (bfs(graph,s,t,parent)){
        int path_flow=INT_MAX;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            path_flow=min(path_flow,graph[u][v]);
        }
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            graph[u][v]-=path_flow;
            graph[v][u]+=path_flow;
        }
        maxflow+=path_flow;
    }
    return maxflow;
}
int main(){
    int graph[V][V];
    int parent[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>> graph[i][j];
        }
    }
    int max_flow=fordfulkerson(graph,0,5,parent);
    cout<<"Maxflow: "<<max_flow;
    return 0;
}