#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 10 // Adjust this according to your needs

int n;
int col[MAX_N];

bool promising(int i) {
    for (int k = 1; k < i; ++k) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
            return false;
    }
    return true;
}

void printSolution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (col[i] == j) {
                cout << "1 ";
            }
			else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printSol(){
	for(int i=1;i<=n;i++){
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
}


void queens(int i) {
    if (promising(i)) {
        if (i == n){
            printSolution();
        }
		else {
            for (int j = 1; j <= n; ++j) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}
void queens(int i){
	if(promising(i)){
		if(i==n){
			printSol();
		}
		else{
			for(int j=1;j<=n;j++){
				col[i+1]=j;
				queens(i+1);
			}
		}
	}
}
int main() {
    cout << "Enter the value of n: ";
    cin >> n;
    queens(0);
    return 0;
}