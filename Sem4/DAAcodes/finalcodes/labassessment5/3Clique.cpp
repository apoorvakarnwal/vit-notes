#include <iostream>
#include <cstring>
using namespace std;
# define max 100

bool isClique(int graph[max][max], int subset[max], int V, int k) {
    int count = 0;
    // counting the vertices of subgraph
    for (int i=0; i<V; i++) {
        if (subset[i]) {
            count++;
        }
    }
    // if number of vertices is not equal to count value return false
    if (count != k) {
        return false;
    }
    // iterate all elements to if they're in (subset[i]) then all other elements 
    for (int i = 0; i < V; i++) {
        if (subset[i]) {
            for (int j = i + 1; j < V; j++) {
                if (subset[j] && !graph[i][j]) {
                    return false;
                }
            }
        }
    }
    return true; 
}

int main() {
    int V; 
    int graph[max][max];
    int subset[max];
    int k;
    cin >> V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < V; i++) {
        cin >> subset[i];
    }
    if (isClique(graph, subset, V, k)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
