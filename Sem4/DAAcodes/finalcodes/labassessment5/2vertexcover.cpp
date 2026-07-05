#include <iostream>

using namespace std;
# define max 5

bool isVertexCover(int graph[max][max], bool subset[max], int n) {
    // for each edge check whether both the vertices are 0 then subset is not a solution otherwise it is 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] == 1) {
                if (subset[i]==0 && subset[j]==0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    const int V = 5;  
    int graph[max][max];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    bool subset[max];
    for (int i = 0; i < V; ++i) {
        cin >> subset[i];
    }

    bool isValidCover = isVertexCover(graph, subset, V);
    if (isValidCover) {
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }
    return 0;
}