#include <iostream>
#include <iomanip>
using namespace std;

void fracKnap(float w[], float p[], float x[],float m,float n){
    for (int i=0;i<n;i++){
        x[i]=0;
    }
    int i=0;
    int remCapacity=m;
    for(int j=0;j<n;j++){
        if(w[j]>remCapacity){
            break;
        }
        i++;
        remCapacity-=w[j];
        x[j]=1;
    }
    if(i<n){
        x[i]=remCapacity/w[i];
    }
    for(int k = 0; k < n;k++){
        cout << fixed << setprecision(1)<< x[k] << " ";
    }
}

int main() {
    int capacity, n;
    cin >> capacity >> n;
    float w[n], p[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    float x[n];
    fracKnap(w,p,x,capacity,n);
}