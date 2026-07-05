#include <iostream>
using namespace std;



void knapsack(int n,int capacity, int p[],int w[]){
    int pq[n+1][capacity+1];
    int item[n];
    for(int i=0;i<n;i++){
        item[i]=0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0||j==0){
                pq[i][j]=0;
            }
            else if(j>=w[i-1]){
                pq[i][j]=max(pq[i-1][j], p[i-1]+pq[i-1][j-w[i-1]]);
            }
            else if(j<w[i-1]){
                pq[i][j]=pq[i-1][j];
            }
        }
    }

    int i=n,j=capacity;
    while (i>0 && j>0){
        if(pq[i][j] !=pq[i-1][j]){
            item[i-1]=1;
            j=j-w[i-1];
        }
        i--;
    }
    
    for(int i=0;i<n;i++){
        cout<<item[i]<<" ";
    }
}


int main(){
    int n,capacity;
    cin>>n>>capacity;
    int p[n],w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    knapsack(n,capacity,p,w);
    return 0;
}
// int main() {
//     int n, capacity;
//     cin >> n >> capacity;
//     int w[n];
//     int p[n];
//     for (int i = 0; i < n; i++) {
//         cin >> w[i];
//     }
//     for (int i = 0; i < n; i++) {
//         cin >> p[i];
//     }
//     knapsack(n, capacity, w, p);
//     return 0;
// }
