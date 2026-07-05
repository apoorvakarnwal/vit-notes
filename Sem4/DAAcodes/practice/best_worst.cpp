#include <iostream>
#include<vector>
using namespace std;

pair <int,int> findPlayer(vector<int> &score, int left, int right){
    if(left==right){
        return make_pair(left, left);
        // return make_pair(score[left], score[left]);
    }
    int mid=(left+right) / 2;
    pair<int,int> leftHalf=findPlayer(score,left,mid);
    pair<int,int> rightHalf=findPlayer(score,mid+1,right);

    int best= score[leftHalf.first]>score[rightHalf.first] ? leftHalf.first:rightHalf.first;
    int worst= score[leftHalf.second]>score[rightHalf.second] ? rightHalf.second:leftHalf.second;

    // int best = max(leftHalf.first, rightHalf.first);
    // int worst = min(leftHalf.second, rightHalf.second);
    return make_pair(best,worst);
}

int main(){
    int numPlayers;
    cin>> numPlayers;
    vector <int> score(numPlayers);
    for(int i=0;i<numPlayers;i++){
        cin>>score[i];
    }
    pair<int,int>result= findPlayer(score,0,numPlayers-1);
    cout<<result.first<<endl;
    cout<<result.second<<endl;
    return 0;
}