#include <iostream>
#include <string> // Include the string header for std::string
using namespace std;

void printLCS(const string& X, const string& Y, int m, int n, int c[][101]) {
    if (m == 0 || n == 0) {
        return;
    }
    if (X[m - 1] == Y[n - 1]) {
        printLCS(X, Y, m - 1, n - 1, c);
        cout << X[m - 1];
    } else if (c[m - 1][n] >= c[m][n - 1]) {
        printLCS(X, Y, m - 1, n, c);
    } else {
        printLCS(X, Y, m, n - 1, c);
    }
}

void longestCommonSubsequence(const string& X, const string& Y, int m, int n) {
    int c[101][101];
    for (int i = 0; i <= m; ++i) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    cout << "\nLongest Common Subsequence: ";
    printLCS(X, Y, m, n, c);
    cout << "\n";
}

int main() {
    string X, Y; // Change the arrays to string objects
    int m, n;
    cin >> m >> n;
    cin >> X;
    cin >> Y;
    longestCommonSubsequence(X, Y, m, n);

    return 0;
}
