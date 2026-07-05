#include <stdio.h>
#define V 9
#define INF 9999
struct Node{
    int dist[V];
    int from[V];
};
void distanceVectorRouting(int cost[V][V]){
    struct Node routingTable[V];
    int i, j, k;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            routingTable[i].dist[j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
            {
                routingTable[i].from[j] = j;
            }
            else
            {
                routingTable[i].from[j] = -1;
            }
        }
    }
    int updated;
    do{
        updated = 0;
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                for (k = 0; k < V; k++){
                    if (routingTable[i].dist[j] >
                        routingTable[i].dist[k] + routingTable[k].dist[j]){
                        routingTable[i].dist[j] =
                            routingTable[i].dist[k] + routingTable[k].dist[j];
                        routingTable[i].from[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
    for (i = 0; i < V; i++){
        printf("Routing table for node %c:\n", 'A' + i);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < V; j++){
            if (routingTable[i].dist[j] == INF){
                printf("%c\t\t-\t\tINF\n", 'A' + j);
            }
            else{
                printf("%c\t\t%c\t\t%d\n", 'A' + j,routingTable[i].from[j] == -1 ? '-' : 'A' + routingTable[i].from[j], routingTable[i].dist[j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int cost[V][V] = {
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
    for (int i = 0; i < V; i++)
    {
        
        for (int j = 0; j < V; j++)
        {
            if (cost[i][j] == 0 && i != j)
            {
                cost[i][j] = INF;
            }
        }
    }
    distanceVectorRouting(cost);
    return 0;
}