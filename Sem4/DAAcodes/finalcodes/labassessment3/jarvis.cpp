#include <iostream>

using namespace std;

struct Point{
    int x,y;
};
int orientation(Point p,Point q, Point r){
    int val=(r.x-p.x)*(q.y-p.y) - (r.y-p.y)*(q.x-p.x);
    if(val==0){
        return 0;
    }
    return (val>0)?1:2;
}
void convexhull(Point points[],int n){
    if(n<3){
        return;
    }
    bool included[n];
    for(int i=0;i<n;i++){
        included[i]=false;
    }
    int left=0;
    for(int i=1;i<n;i++){
        if(points[i].x < points[left].x){
            left=i;
        }
    }
    int prev=left;
    int curr;

    do{
        curr=(prev+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(points[prev], points[curr],points[i])==2){
                curr=i;
            }
        }
        included[prev]=true;
        prev=curr;
    }while(prev!=left);

    for(int i=0;i<n;i++){
        if(included[i]){
            cout<<points[i].x <<" "<< points[i].y<<endl;
        }
    }
}

int main(){
    int n=10;
    Point points[n];
    for(int i=0;i<n;i++){
        cin>> points[i].x >> points[i].y;
    }
    convexhull(points,n);
    return 0;
}