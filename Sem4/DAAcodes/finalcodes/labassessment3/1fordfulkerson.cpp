#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

#define V 6

bool bfs(int graph[V][V], int s, int t, int parent[]) {
    // visited array
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    // queue: push parent visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // while queue is empty
    while (!q.empty()) {
        // get u 
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v) {
            // check for all u 
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int parent[V];
    int maxflow = 0;
    while (bfs(graph, s, t, parent)) {
        int pathflow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathflow = min(pathflow, graph[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathflow;
            graph[v][u] += pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
int main() {
    int graph[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    int source = 0;
    int sink = 5;
    cout << "Maximum flow is " << fordFulkerson(graph, source, sink) << endl;
    return 0;
}