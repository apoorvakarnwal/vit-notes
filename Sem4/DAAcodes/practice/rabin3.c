#include <stdio.h>
#include <string.h>
#include <math.h>

// Custom modulo function to handle negative dividends
int mod(int a, int b) {
    return (a % b + b) % b;
}

// Function to perform Rabin-Karp string matching
void rabinKarpMatcher(char *T, char *P, int d, int q) {
    int n = strlen(T);
    int m = strlen(P);
    int h = 1;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text

    // Calculate h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = mod(h * d, q);
    printf("mod: %d",h);
    // Calculate the initial hash values for pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = mod(d * p + P[i], q);
        t = mod(d * t + T[i], q);
    }

    // Slide the pattern over the text one by one
    for (int s = 0; s <= n - m; s++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            int match = 1;
            // Check if the pattern actually matches the text
            for (int i = 0; i < m; i++) {
                if (P[i] != T[s + i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Pattern occurs with genuine shift %d\n", s + 1);
            } else {
                printf("Spurious hit at index %d\n", s + 1);
            }
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if (s < n - m) {
            t = mod(d * mod(t - T[s] * h, q) + T[s + m], q);
        }
    }
}

int main() {
    char text[100];
    char pattern[100];
    int d = 256; // Number of characters in the input alphabet
    int q;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Enter the prime number (q): ");
    scanf("%d", &q);

    rabinKarpMatcher(text, pattern, d, q);
    return 0;
}
