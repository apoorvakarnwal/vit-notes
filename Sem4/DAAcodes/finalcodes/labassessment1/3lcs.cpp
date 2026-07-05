#include <iostream>
#include <string>
using namespace std;

int c[100][100];
char b[101][101];

void printlcs(string X,int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(b[i][j]=='D'){
        printlcs(X,i-1,j-1);
        cout<<X[i-1];
    }
    else if(b[i][j]=='U'){
        printlcs(X,i-1,j);
    }
    else if(b[i][j]=='L'){
        printlcs(X,i,j-1);
    }
} 
void lcs(string X,string Y, int m,int n){
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1] == Y[j-1]){
                c[i][j]= c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else if(c[i - 1][j] >= c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            }
            else{
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }
    printlcs(X,m,n);
}


int main(){
    int m,n;
    cin>>m>>n;
    string X,Y;
    cin>>X;
    cin>>Y;

    lcs(X,Y,m,n);
    return 0;
}