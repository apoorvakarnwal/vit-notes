#include<iostream>
using namespace std;
#define max 5
bool isVertexCover(int graph[max][max],int subset[max],int V){
    for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            if(graph[i][j]==1){
                if(!subset[i] && !subset[j]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int V=5;
    int graph[max][max];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    int subset[V];
    for(int i=0;i<V;i++){
        cin>>subset[i];
    }
    if(isVertexCover(graph,subset,V)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}