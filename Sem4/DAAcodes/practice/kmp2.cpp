#include <iostream>
#include <string>
using namespace std;

void lpsArray(string pat,int m,int lps[]){
    int k=0;
    int i=1;
    lps[0]=0;
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
void kmp(string pat,string txt,int n,int m){
    int i=0;
    int j=0;
    int lps[m];
    lpsArray(pat,m,lps);
    int count =0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"pattern at index"<< i-j<<endl;
            j=lps[j-1];
        }
        else if (i<n && pat[j] != txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    string text;
    cin >> text;
    cin >> m;
    string pattern;
    cin >> pattern;
    kmp(pattern,text,n,m);
    return 0;
}
