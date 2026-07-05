#include <iostream>
#include <cstring> // Include for strlen function
using namespace std;

void computeLPSArray(char* pat, int m, int* lps); // Change M to m

void KMPSearch(char* pat, char* txt, int m, int n) { // Include m and n parameters
    int lps[m];
    computeLPSArray(pat, m, lps);
    int i = 0;
    int j = 0;
    while (i < n) { // Change N to n
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Found pattern at index %d ", i - j + 1);
            j = lps[j - 1];
        }

        else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(char* pat, int m, int* lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    int textLength, patternLength;
    cin >> textLength;
    char txt[textLength];
    cin >> txt;
    cin >> patternLength;
    char pat[patternLength];
    cin >> pat;

    KMPSearch(pat, txt, patternLength, textLength); // Pass patternLength and textLength
    return 0;
}
