#include<iostream>
#include<stack>
#include <stdlib.h>
using namespace std;

struct Point{
    int x;
    int y;
};
Point p0;
Point nexttotop(stack<Point>&s){
    Point temp=s.top();
    s.pop();
    Point result=s.top();
    s.push(temp);
    return result;
}
void swap(Point &p1,Point &p2){
    Point temp=p1;
    p1=p2;
    p2=temp;
}
int distSq(Point p1,Point p2){
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int orientation(Point p,Point q, Point r){
    int val=((r.x-p.x)*(q.y-p.y)- (r.y-p.y)*(q.x-p.x));
    if(val==0)
        return 0;
    return (val>0)?1:2;
}
int compare(const void *vp1, const void *vp2){
    Point *p1=(Point *)vp1;
    Point *p2=(Point *)vp2;

    int o=orientation(p0,*p1,*p2);
    if(o==0){
        return (distSq(p0,*p2)>=distSq(p0,*p1))?-1:1;
    }
    return (o==2)?-1:1;
}
void convexHull(Point points[], int n){
    // finding p0
    int ymin=points[0].y;
    int min=0;
    for(int i=1;i<n;i++){
        int y=points[i].y;
        if((y<ymin) || (ymin==y && points[i].x<points[min].x) ){
            min=i;
            ymin=y;
        }
    }
    swap(points[0],points[min]);
    p0= points[0];
    qsort(&points[1],n-1,sizeof(Point),compare);

    // filtering collinear points
    int m=1;
    for(int i=1;i<n;i++){
        while (i<n-1 && orientation(p0, points[i], points[i+1])==0) {
            i++;
        }
        points[m]=points[i];
        m++;
    }
    if(m<3){
        return;
    }

    stack<Point> S;
    S.push(p0);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=3;i<m;i++){
        while (S.size()>1 && orientation(nexttotop(S),S.top(),points[i])!=2 ){
            S.pop();
        }
        S.push(points[i]);
    }
    cout<<endl;
    while (!S.empty()){
        Point p=S.top();
        cout<<p.x<<" "<<p.y<<endl;
        S.pop();
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

void convexHull(Point points[],int n){
    int ymin=points[0].y;
    int min=0;
    for(int i=1;i<n;i++){
        int y=points[i].y;
        if(y<ymin || (y==ymin && points[i].x<=points[min].x)){
            min=i;
        }
    }
    swap(points[0], points[min]);

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

    for(int i=3;i<m;i++){
        while(S.size()>1 orientation(nexttotop(S),S)!=2)
    }
}