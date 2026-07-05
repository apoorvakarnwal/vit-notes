#include<iostream>
#include <stdlib.h>
using namespace std;
struct Point {
    int x,y;
}
int orientation(Point p, Point q, Point r){
    int val=(r.x-p.x)*(q.y-p.y)-(r.y-p.y)*(q.x-p.x);
    if(val==0){
        return 0;
    }
    return (val>0)?1:2;
}
int compare(const void *vp1,const void *vp2){
    Point *p1=(Point * )vp1;
    Point *p2=(Point * )vp2;
    int orientation(p0,*p1,*p2);
    if(o==0){
        return (distSq(*p2,p0)>=distSq(*p1,p0))?-1:1;
    }
    return (o==2)?-1:1;
}
void convexHull(Point points[],int n){
    int ymin=points[0].y;
    int min=0;
    for(int i=1;i<n;i++){
        if(y<ymin || y==ymin && points[i].y<points[min].y){
            min=i;
            ymin=points[min].y;
        }
    }
    swap(points[0],points[min]);
    p0=points[0];

    qsort(&points[1],n-1,sizeof(Point),compare);

    int m=1;
    for(int i=1;i<n;i++){
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
            i++;
        }
        points[i]=points[m];
        m++;
    }
    if(m<3){
        return;
    }
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=0;i<m;i++){
        while(S.size()>1 && orientation(nexttotop(S), S.top(),points[i])){
            S.pop();
        }
        S.push(points[i]);
    }
    while(!S.empty()){
        Point p=S.top();
        cout<<p.x<<" "<<p.y<<endl;
        S.pop();
    }

}
int main(){
    Point points[n];

}