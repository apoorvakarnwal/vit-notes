#include <iostream>
using namespace std;

struct Point{
    int x,y;
};
int orientation(Point p,Point q,Point r){
    int val=(r.x-p.x)*(q.y-p.y)-(r.y-p.y)*(q.x-p.x);
    if(val==0){
        return 0;
    }
    return (val>0)?1:2;
}
int onsegment(Point p,Point q,Point r){
    if(q.x<=max(r.x,p.x) && q.y<=max(r.y,p.y) && q.x>=min(r.x,p.x) && q.y>=min(r.y,p.y)){
        return true;
    }
    return false;
}
bool doIntersect(Point p1,Point p2,Point q1,Point q2){
    int o1=orientation(p1,q1,p2);
    int o2=orientation(p1,q1,q2);
    int o3=orientation(p2,q2,p1);
    int o4=orientation(p2,q2,q1);
    if(o1!=o2 && o3!=o4){
        return true;
    }
    if(o1==0 && onsegment(p1,p2,q1))
        return true;
    if(o2==0 && onsegment(p1,q2,q1))
        return true;
    if(o3==0 && onsegment(p2,p1,q2))
        return true;
    if(o4==0 && onsegment(p2,q1,q2))
        return true;
    return false;
}
int main(){
    Point p1,p2,q1,q2;
    cin>>p1.x>>p1.y;
    cin>>q1.x>>q1.y;
    cin>>p2.x>>p2.y;
    cin>>q2.x>>q2.y;
    if(doIntersect(p1,p2,q1,q2)){
        cout<<"Line segment intersect";
    }
    else{
        cout<<"Line segment do not intersect";
    }
    return 0;    
}