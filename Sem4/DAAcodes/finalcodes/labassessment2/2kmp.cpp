#include<iostream>
using namespace std;

void lpsArray(string pat, int m, int lps[]) {
    int k = 0; // value that keeps on changing
    lps[0] = 0;
    int i = 1; // iterator of pattern
    while (i < m){
        //if matches
        if (pat[i] == pat[k]) {
            k++;
            lps[i] = k;
            i++;
        }
        //if doesnt matches
        else {
            if (k != 0) {
                k = lps[k - 1];
            }
            else {
                lps[i] = k;
                i++;
            }
        }
    }
}

void kmp(string txt, string pat, int n, int m) {
    int lps[m];
    lpsArray(pat, m, lps); // Pass the lps array and its size
    int i = 0, j = 0;
    int count = 0;
    while (i < n) {
        // if pattern matches
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        // if entire entire string matches
        if (j == m) {
            count++;
            cout << "Pattern found at index " << i - j +1<< endl;
            j=lps[j - 1];
        }
        // if string doesnt matches
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    if (count == 0) {
        cout << "String not found" << endl;
    }
}
int main() {
    int n,m;
    string txt;
    string pat;
    cin >> n;
    cin >> txt;
    cin >> m;
    cin >> pat;
    kmp(txt, pat, n,m);
    return 0;
}