#include<iostream>
#include<cmath>
using namespace std;

#define max 10

int n;
int col[max];

bool promising(int i){
    for(int k=1; k<i ; k++){
        if(col[i]==col[k] || abs(col[i]-col[k])==abs(i-k)){
            return false;
        }
    }
    return true;
}

//print the solution array of the board
void printSol(){
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(col[i]==j){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void nqueens(int i){
    if(promising(i)){
        if(i==n){
            printSol();
        }
        else{
            for(int k=1;k<=n;k++){
                col[i+1]=k;
                nqueens(i+1);
            }
        }
    }
}

int main(){
    cin>>n;
    nqueens(0);
    return 0;
}