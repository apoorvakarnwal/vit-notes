#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;

int findMinDistance(const vector<int> &dist, const vector<bool> &visited){
    int minDist = INF, minIndex = -1;
    for (int i = 0; i < dist.size(); i++){
        if (!visited[i] && dist[i] < minDist){
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void linkStateRouting(const vector<vector<int> > &graph, int source){
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++){
        int u = findMinDistance(dist, visited);
        if (u == -1)
            break; 
        visited[u] = true;

        // Update distances of neighboring nodes
        for (int v = 0; v < n; v++){
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Node\tDistance from Source\n";
    for (int i = 0; i < n; i++){
        cout << i << "\t" << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}

int main()
{
    vector<vector <int> > graph = {
        {0, 4, 8, INF, INF, INF, INF, INF, INF}, // a
        {4, 0, 11, 8, INF, INF, INF, INF, INF},  // b
        {8, 11, 0, INF, INF, 1, INF, INF, INF},  // c
        {INF, 8, INF, 0, 2, INF, 7, 4, INF},     // d
        {INF, INF, 7, 2, 0, 6, INF, INF, INF},   // e
        {INF, INF, 1, INF, 6, 0, INF, 2, INF},   // f
        {INF, INF, INF, 7, INF, INF, 0, 14, 9},  // g
        {INF, INF, INF, 4, INF, 2, 14, 0, 10},   // h
        {INF, INF, INF, INF, INF, INF, 9, 10, 0} // i
    };

    int source = 0; // Source node
    linkStateRouting(graph, source);

    return 0;
}