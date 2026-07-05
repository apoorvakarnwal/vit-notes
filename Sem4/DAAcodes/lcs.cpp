#include <iostream>
#include <algorithm>

using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
string lcs(string s1,string s2, int len1,int len2){
    int m=len1;
    int n=len2;
    int c[m+1][n+1];
    for(int i=0;i<m+1;i++){
        c[i][0]=0;
    }
    for(int j=0;j<n+1;j++){
        c[0][j]=0;
    }
    for (int i = 1; i < m+1; i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1]==s2[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    int i=m,j=n;
    int lcsLen=c[m][n];
    
    return ;
}

int main(){
    int len1,len2;
    cin>>len1>>len2;
    string s1,s2;
    cin>>s1>>s2;
    string result = lcs(s1,s2,len1,len2);
    return 0;
}