// #include <iostream>
// #include<vector>
// using namespace std;

// void floyd(vector<vector <int> >&adj, int n){
//     vector<vector <int> >res=adj;

//     for(int k=0;k<n;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(res[i][k]+res[k][j]<res[i][j]){
//                     res[i][j]=res[i][k]+res[k][j];
//                 }
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<res[i][j]<<" ";
//         }
//         cout<<endl;
//     }

// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector <int> >adj(n,vector <int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>adj[i][j];
//         } 
//     }
//     floyd(adj,n);
// }

#include<iostream>
#include <vector>
#include<climits>
using namespace std;
void bellman(vector<vector <int> >&adj, int n,int start){
    vector<vector <int> >res=adj;
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[start-1]=0;

    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]!=0 && dist[i]!=INT_MAX && res[i][j]+dist[i]<dist[j]){
                    dist[j]=res[i][j]+dist[i];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"dist of vertex "<<i<<dist[i]<<" ";
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector <int> >adj(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        } 
    }
    bellman(adj,n,5);
    return 0;
}
