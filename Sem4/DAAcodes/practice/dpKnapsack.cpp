#include <iostream>
using namespace std;

void knapsack(int n, int capacity, int w[], int p[]) {
    int pq[n + 1][capacity + 1];
    int items[n];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                pq[i][j] = 0;
            }
            else if (j- w[i-1] >=0) {
                pq[i][j] = max(pq[i - 1][j], p[i - 1] + pq[i - 1][j - w[i - 1]]);
            } else {
                pq[i][j] = pq[i - 1][j];
            }
        }
    }
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (pq[i][j] != pq[i - 1][j]) {
            items[i - 1] = 1;
            j -= w[i - 1];
        }
        i--;
    }
    for (int k = 0; k < n; k++) {
        cout << items[k] << " ";
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
