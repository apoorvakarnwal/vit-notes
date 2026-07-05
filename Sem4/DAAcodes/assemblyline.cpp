#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assembly_time(int n, vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x) {
    vector<vector<int>> dp(2, vector<int>(n));

    dp[0][0] = e[0] + a[0][0];
    dp[1][0] = e[1] + a[1][0];

    for (int j = 1; j < n; ++j) {
        dp[0][j] = min(dp[0][j - 1] + a[0][j], dp[1][j - 1] + t[1][j - 1] + a[0][j]);
        dp[1][j] = min(dp[1][j - 1] + a[1][j], dp[0][j - 1] + t[0][j - 1] + a[1][j]);
    }

    return min(dp[0][n - 1] + x[0], dp[1][n - 1] + x[1]);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(2, vector<int>(n));
    vector<vector<int>> t(2, vector<int>(n - 1));
    vector<int> e(2), x(2);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> t[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        cin >> e[i];
    }

    for (int i = 0; i < 2; ++i) {
        cin >> x[i];
    }
    cout << assembly_time(n, a, t, e, x) << endl;

    return 0;
}