#include <iostream>
#include <string> // Include the string header for std::string
using namespace std;

#define MAX_SIZE 100

int c[100][100];
char b[101][101];
void printLCS(string X, int m, int n) {
    if (m == 0 || n == 0) {
        return;
    }
    if (b[m][n] == 'D') {
        printLCS(X, m - 1, n - 1);
        cout << X[m - 1];
    } 
    else if (b[m][n] == 'U') {
        printLCS(X, m - 1, n);
    } 
    else {
        printLCS(X, m, n - 1);
    }
}

void longestCommonSubsequence(string X, string Y, int m, int n) {
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
                b[i][j] = 'D';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    cout << "\nLongest Common Subsequence: ";
    printLCS(X, m, n);
    cout << "\n";
}

int main() {
    string X, Y; // Change the arrays to string objects
    int m, n;
    cout << "Enter lengths: ";
    cin >> m >> n;
    cout << "Enter the first sequence: ";
    cin >> X;
    cout << "Enter the second sequence: ";
    cin >> Y;

    longestCommonSubsequence(X, Y,m,n);

    return 0;
}
