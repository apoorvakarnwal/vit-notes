#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999;

// Bellman-Ford algorithm for Distance Vector Routing
void distanceVectorRouting(vector<vector<int> >& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != INF && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    cout << "Node\tDistance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
}

int main() {
    vector<vector<int> > graph = {
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

    int source = 0;
    distanceVectorRouting(graph, source);
    return 0;
}