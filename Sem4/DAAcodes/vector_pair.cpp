#include <iostream>
#include<vector>
using namespace std;
bool mycompare(pair<int,int> p1, pair<int,int > p2){
    return p1.first<p2.first;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    vector<int> v2 (3,50);
    swap(v,v2);
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }



    int arr[]={10,16,7,14,5,3,2,9};

    vector < pair<int,int> > vp;

    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        pair <int,int> p;
        p.first=arr[i];
        p.second=i;
        vp.push_back(p);
    }

    sort(vp.begin(),vp.end(),mycompare);

    for(int i=0;i<vp.size();i++){
        arr[vp[i].second]=i;
    }
    for(int i=0;i<vp.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}