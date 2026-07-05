#include <iostream>
#include <string>
using namespace std;

#define d 256

int mod(int a, int b) {
    return (a % b + b) % b;
}
void search(string p1, string t1, int q){
    int m = p1.length();
    int n = t1.length();
    int i, j;
    int p = 0, t = 0;

    // Calculate h = d^(m-1) % q
    int h = mod(pow(d,m-1) , q);

    for (i = 0; i < m; i++) {
        p = mod(  (d * p + p1[i])   , q);
        t = mod(  (d * t + t1[i])    , q);
    }

    int count=0;
    for (int s = 0; s <= n - m; s++) {
        if (p == t) { // patern found
            for (j = 0; j < m; j++) {
                if (t1[s + j] != p1[j]) { // manually checking patterns
                    break;
                }
            }
            if (j == m){
                count++;
                cout << "Pattern found at index " << s+1 << endl;
            }
        }
        if (s < n - m) {
            t = mod((d* (t - t1[s] * h) + t1[s + m]), q);
        }
    }
    if(count==0){
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