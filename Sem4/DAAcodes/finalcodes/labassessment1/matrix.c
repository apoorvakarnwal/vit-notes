#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

void printOptimalParens(int s[][MAX_SIZE], int i, int j);

void printMatrix(int mat[][MAX_SIZE], int n, const char* name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[MAX_SIZE][MAX_SIZE]={0};
    int s[MAX_SIZE - 1][MAX_SIZE]={0};

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printMatrix(m, n - 1, "Cost");
    printMatrix(s, n - 1, "S");

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}


void printOptimalParens(int s[][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[MAX_SIZE];
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n + 1);
    return 0;
}