#include <iostream>
using namespace std;

void lpsArray(string pat, int m,int lps[]){
    int k=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[k]){
            k++;
            lps[i]=k;
            i++;
        }
        else{
            if(k!=0){
                k=lps[k-1];
            }
            else{
                lps[i]=k;
                i++;
            }
        }
    }
}
void kmp(string txt,string pat,int n,int m){
    int lps[m];
    lpsArray(pat,m,lps);
    int i=0;
    int j=0;
    int count=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            count++;
            cout<<"pattern at shift "<<i-j+1;
            j=lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(count==0){
        cout<<"pattern not found";
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