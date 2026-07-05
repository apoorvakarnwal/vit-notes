#include <iostream>
#include<algorithm>
using namespace std;

void knapsack(int n, int capacity, int w[], int p[]) {
    int dp[n+1][capacity+1];
    int x[n];
    for(int i=0;i<n;i++){
        x[i]=0;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(j-w[i-1] >=0){
                dp[i][j]=max(dp[i-1][j] , p[i-1]+ dp[i-1][j-w[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int i=n,j=capacity;
    while(i>0 && j>0){
        if(dp[i][j] != dp[i-1][j]){
            x[i-1]=1;
            j=j-w[i-1];
        }
        i--;
    }
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
}
int main() {
    int n, capacity;
    cin >> n >> capacity;
    int w[n];
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    knapsack(n, capacity, w, p);
    return 0;
}