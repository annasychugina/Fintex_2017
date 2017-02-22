#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef long long tint;

struct Point
{
    long long x, y;
    
    void read(){
        tint x, y;
        cin >> x >> y;
        this -> x = x;
        this -> y = y;
    }
    void print(){
        cout << this -> x << " " << this -> y;
    }
    Point() {}
    Point(tint x, tint y) : x(x), y(y) {}
    Point operator - (const Point & that) const{
        return Point(x - that.x, y - that.y);
    }
    Point operator + (const Point & that) const{
        return Point(x + that.x, y + that.y);
    }
    bool operator < (const Point & that) const{
        return (x < that.x || (x == that.x && (y < that.y)));
    }
    bool operator == (const Point & that) const{
        return (x == that.x && y == that.y);
    }
    double abs(){
        return hypot(y, x);
    }
};
tint signum(tint a){
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
}
tint area(Point pt1, Point pt2, Point pt3){
    return ((pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt3.x - pt1.x) * (pt2.y - pt1.y));
}
tint intersect1(tint a, tint b, tint c, tint d){
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}
bool intersect(Point a, Point b, Point c, Point d){
    return intersect1(a.x, b.x, c.x, d.x)
            && intersect1(a.y, b.y, c.y, d.y)
            && ((signum(area(a, c, b)) * signum(area(a, d, b))) <= 0)
            && ((signum(area(c, a, d)) * signum(area(c, b, d))) <= 0);
}
int main(){

    Point x[4];
    for(int i = 0; i < 4; ++i){
        x[i].read();
    }
    if(intersect(x[0], x[1], x[2], x[3])){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}