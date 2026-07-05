#include<iostream>
#include<cstring>

using namespace std;
void lpsArray(char* pat, int m, int*lps);

void kmp(char* txt,char* pat,int n,int m){
    int lps[m];
    lpsArray(pat,m,lps);
    int i=0,j=0;
    int count=0;
    while (i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m){
            count++;
            printf("Pattern found at index %d ", i - j + 1);
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(count==0){
        cout << "String not found" << endl;
    }
}
void lpsArray(char* pat, int m, int*lps){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void lps(char* pat,int m,int*lps){
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=len;
                i++;
            }
        }
    }
}
int main(){
    int textLength,patternLength;
    cin>> textLength;
    char txt[textLength];
    cin>>txt;
    cin>>patternLength;
    char pat[patternLength];
    cin>>pat;
    kmp(txt,pat,textLength,patternLength);
    return 0;
}