#include <iostream>
using namespace std;
struct Point{
    int x,y;
};
int orientation(Point p,Point q, Point r){
    int val=(r.x-p.x)*(q.y-p.y)- (r.y-p.y)*(q.x-p.x);
    if(val==0){
        return 0;
    }
    return (val>0)?1:2;
}
void convexHull(Point points[],int n){
    if(n<3){
        return;
    }
    // all included are false
    bool included[n];
    for(int i=0;i<n;i++){
        included[i]=false;
    }
    // find the leftmost 
    int left=0;
    for(int i=1;i<n;i++){
        if(points[i].x<points[left].x){
            left=i;
        }
    }
    // jarvis march
    
    int prev=left;
    int curr;
    do{
        curr=(prev+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(points[prev],points[curr],points[i])==2){
                curr=i;
            }
        }
        included[prev]=true;
        prev=curr;
    }while(prev!=left);

    // output
    cout<<endl;
    for(int i=0;i<n;i++){
        if(included[i]){
            cout<<points[i].x<<" "<<points[i].y<<endl;
        }
    }
}
int main(){
    int n=10;
    Point points[n];
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    convexHull(points,n);
    return 0;
}