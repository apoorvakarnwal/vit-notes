#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Vertex{
    int ht, eflow;
};

int v, e;
vector <vector<int> > cap, flow;
vector <Vertex> vert;

void preflow(int s){
    vert[s].ht = v;
    for (int i = 0; i < v; i++){
        if (cap[s][i] != 0 && i != s){
            flow[s][i] += cap[s][i];
            flow[i][s] -= cap[s][i];
            vert[i].eflow += cap[s][i];
        }
    }
}

int getActiveNode(int source, int sink){
    for (int i = 1; i < v - 1; i++){
        if (vert[i].eflow > 0){
            for (int j = 0; j < v; j++){
                if (cap[i][j] != 0 || flow[i][j] != 0){
                    if (cap[i][j] != flow[i][j])
                        return i;
                }
            }
        }
    }
    return -1;
}

bool push(int u){
    for (int j = 0; j < v; j++){
        if (cap[u][j] != 0 || flow[u][j] != 0){
            if (cap[u][j] != flow[u][j]){
                if (vert[u].ht > vert[j].ht){
                    int Flow = min(cap[u][j] - flow[u][j], vert[u].eflow);
                    vert[u].eflow -= Flow;
                    vert[j].eflow += Flow;
                    flow[u][j] += Flow;
                    flow[j][u] -= Flow;
                    return true;
                }
            }
        }
    }
    return false;
}

void relabel(int u){
    int minh = INT_MAX;
    for (int j = 0; j < v; j++){
        if ((cap[u][j] != 0 || flow[u][j] != 0) && (cap[u][j] != flow[u][j])){
            if (vert[j].ht < minh)
                minh = vert[j].ht;
        }
    }
    vert[u].ht = minh + 1;
}

int maxFlow(int source, int sink){
    preflow(source);
    int u = getActiveNode(source, sink);
    while (u != -1){
        if (!push(u))
            relabel(u);
        u = getActiveNode(source, sink);
    }
    return vert[sink].eflow;
}

int main(){
    cout << "Enter the number of vertices: ";
    cin >> v;

    cap.resize(v, vector<int>(v, 0));
    flow.resize(v, vector<int>(v, 0));
    vert.resize(v);

    cout << "Enter the capacity matrix:" << endl;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            cin >> cap[i][j];
        }
    }

    int source, sink;
    cout << "Enter source and sink: ";
    cin >> source >> sink;

    cout << "Max Flow: " << maxFlow(source, sink) << endl;

    return 0;
}
