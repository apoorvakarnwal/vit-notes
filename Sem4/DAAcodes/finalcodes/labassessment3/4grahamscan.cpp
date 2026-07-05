#include <iostream>
#include <stack>
using namespace std;
struct Point{
    int x,y;
};
Point p0;
void swap(Point &p1,Point &p2){
    Point temp=p1;
    p1=p2;
    p2=temp;
}
Point nextToTop(stack<Point> s){
    Point temp=s.top();
    s.pop();
    Point res=s.top();
    s.push(temp);
    return res;
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - p.x) - (q.x - p.x) * (r.y - p.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int distSq(Point p1,Point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y);
}
int compare(const void* vp1, const void* vp2){
    Point *p1=(Point *)vp1;
    Point *p2=(Point *)vp2;
    int o=orientation(p0,*p1,*p2);
    // 1 => p2 comes first
    // -1 => p1 comes first

    // if collinear nearest comes first
    if(o==0){
        return (distSq(*p1,p0)>=distSq(*p2,p0))?1:-1;
    }
    return (o==2)?-1:1;
}
void convexHull(Point points[],int n){
    // finding ymin
    int ymin=points[0].y;
    int min=0;
    for(int i=1;i<n;i++){
        int y=points[i].y;
        if(y<ymin || (y==ymin && points[i].x<points[min].y)){
            min=i;
            ymin=y;
        }
    }
    // setting bottommost pointer
    swap(points[0],points[min]);

    p0=points[0];
    
    // sorting anticlockwise
    qsort(&points[1], n - 1, sizeof(Point), compare);

    //filtering all collinear points
    int m=1;
    for(int i=1;i<n;i++){
        while( i<n-1 && orientation(p0,points[i],points[i+1])==0){
            i++;
        }
        points[m]=points[i];
        m++;
    }
    if (m < 3)
        return;

    stack<Point> S;
    S.push(p0);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=3;i<m;i++){
        while(S.size()>1 && orientation(nextToTop(S),S.top(),points[i])!=2){
            S.pop();
        }
        S.push(points[i]);
    }
    cout<<endl;
    while (!S.empty()){
        Point p = S.top();
        cout << p.x << " " << p.y << endl;
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