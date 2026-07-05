#include<iostream>
using namespace std;
#define max 5

void printparens(int s[][max], int i,int j){
    if(i==j){
        cout<<(char)('A'+i-1);
    }
    else{
        cout<<"(";
        printparens(s,i,s[i][j]);
        printparens(s,s[i][j]+1,j);
        cout<<")";
    }
}
void matrixchain(int p[], int n){
    int m[max][max]={0};
    int s[max][max]={0};

    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                int q=m[i][k] + m[k+1][j] +p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<m[1][n-1];
    cout<<endl;
    for(int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    printparens(s,1,n-1);
}

int main(){
    int n;
    cin>>n;
    int p[n+1];
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    matrixchain(p,n+1);
    return 0;
}

/*
int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int y;
    int temp=1;
    int p[n+1];
    cout << "Enter the dimensions of matrices: ";
    cin>>p[0];
    for (int i = 1; i <= 2*(n-1); i++) {
        cin>>y;
        if(i%2==1){
            p[temp]=y;
            temp++;
        }
    }
    cin>>p[n];
    matrixChainOrder(p, n + 1);

    return 0;
}*/