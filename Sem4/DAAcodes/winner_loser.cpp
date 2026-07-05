#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

pair<int, int> bestWorstPlayer(const vector<int>& scores, int left,int right){
    if(left == right){
        return make_pair(left,left);
    }
    int mid=(left+right)/2;

    pair<int,int> leftResult = bestWorstPlayer(scores,left,mid);
    pair<int,int> rightResult = bestWorstPlayer(scores,mid+1,right);

    int best=((scores[leftResult.first])>(scores[rightResult.first]))?leftResult.first:rightResult.first;
    int worst=((scores[leftResult.second])<(scores[rightResult.first]))?leftResult.second:rightResult.second;
    return make_pair(best,worst);
}

int main(){
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Invalid number of players: "<<endl;
        return 1;
    }
    vector<int> playerScores(num);
    for(int i=0;i<num;i++){
        cin>>playerScores[i];
    }
    pair<int,int> result = bestWorstPlayer(playerScores,0,num-1);
    cout<<"Winner: "<<result.first;
    cout<<"Loser: "<<result.second;
    return 0;
}