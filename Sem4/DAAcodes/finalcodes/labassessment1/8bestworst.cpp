#include <iostream>
using namespace std;

// void findWinnerAndWorst(int scores[], int start, int end, int& winner, int& worst) {
//     if (start == end) {
//         winner  = start;
//         worst=start;
//         return;
//     }

//     int mid  = (start + end) / 2;
//     int winner1, winner2, worst1, worst2;

//     findWinnerAndWorst(scores, start, mid, winner1, worst1);
//     findWinnerAndWorst(scores, mid+1, end, winner2, worst2);

//     if (scores[winner1] > scores[winner2]) {
//         winner = winner1;
//     } else {
//         winner = winner2;
//     }

//     if (scores[worst1] < scores[worst2]) {
//         worst = worst1;
//     } else {
//         worst = worst2;
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     int scores[n];
//     for (int i = 0; i < n; i++) {
//         cin >> scores[i];
//     }
//     int winner, worst;
//     findWinnerAndWorst(scores, 0, n-1, winner, worst);

//     cout << "Winner " << (winner + 1) << endl;
//     cout << "Worst player " << (worst + 1) << endl;

//     return 0;
// }
void findbest(int scores[],int start,int end, int& winner,int& worst){
    if(start==end){
        winner=start;
        worst=start;
        return;
    }
    int mid=(start+end)/2;

    int w1,w2,b1,b2;
    findbest(scores,start,mid,w1,b1);
    findbest(scores,mid+1,end,w2,b2);

    if(scores[w1]>scores[w2]){
        winner=w1;
    }else{
        winner=w2;
    }
    if(scores[b1]>scores[b2]){
        worst=b2;
    }else{
        worst=b1;
    }

}
int main(){
    int n;
    cin>>n;
    int scores[n];

    for(int i=0;i<n;i++){
        cin>>scores[i];
    }
    int winner,worst;

    findbest(scores,0,n-1,winner,worst);
    cout<<"winner "<<winner;
    cout<<"worst "<<worst;

    return 0;
}

