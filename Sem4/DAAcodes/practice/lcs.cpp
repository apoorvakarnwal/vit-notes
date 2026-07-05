#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
int count=0;

void printLCS(char b[MAX_SIZE + 1][MAX_SIZE + 1], char X[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (b[i][j] == 'D') {
        printLCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
        count++;
    } else if (b[i][j] == 'U') {
        printLCS(b, X, i - 1, j);
    } 
    else {
        printLCS(b, X, i, j - 1);
    }
}

void longestCommonSubsequence(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int c[MAX_SIZE + 1][MAX_SIZE + 1];
    char b[MAX_SIZE + 1][MAX_SIZE + 1];

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
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            } 
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    printf("\nLongest Common Subsequence: ");
    printLCS(b, X, m, n);
    printf("\n");
}

int main() {
    char X[MAX_SIZE], Y[MAX_SIZE];
    printf("Enter the first sequence: ");
    scanf("%s", X);
    printf("Enter the second sequence: ");
    scanf("%s", Y);

    longestCommonSubsequence(X, Y);
    printf("The length of the subsequence is %d",count);

    return 0;
}