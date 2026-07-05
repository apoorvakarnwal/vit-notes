#include <iostream>
#include <string>
using namespace std;

#define d 256
int mod(int a, int b) {
    return (a % b + b) % b;
}
void search(string pat, string txt, int q){
    int m = pat.length();
    int n = txt.length();
    int i, j;
    int p = 0, t = 0;
    int h = 1;

    // Calculate h = d^(m-1) % q
    h = mod(pow(d,m-1) , q);

    for (i = 0; i < m; i++) {
        p = mod((d * p + pat[i]), q);
        t = mod((d * t + txt[i]), q);
    }

    int counter=0;
    for (int s = 0; s <= n - m; s++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[s + j] != pat[j]) {
                    break;
                }
            }
            if (j == m){
                counter++;
                cout << "Pattern found at index " << s+1 << endl;
            }
        }
        if (s < n - m) {
            t = mod((d* (t - txt[s] * h) + txt[s + m]), q);
            if (t < 0){
                t = (t + q);
            }
        }
    }
    if(counter==0){
        cout<<"String not found";
    }

}

int main(){
    int textLength, patternLength;
    string text, pattern;
    cin >> textLength;
    cin >> text;
    cin >> patternLength;
    cin >> pattern;
    int q = 13;
    search(pattern, text,q);
    return 0;
}
