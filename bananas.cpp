#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _flag(x) puts("FLAG " #x);
#define  _(y,x)  cout<<y<<". "<< #x <<" is "<< x <<endl;
#define fs first
#define sc second
#define pb push_back
#define _105 (100000)
#define _109 (1000000000)
#define _0(arr) memset(arr,0,sizeof ( arr ) )
#define _ninp(n,arr) for(int i=0; i<n;i++)cin>>arr[i];
#define _nout(n,arr) for(int i=0; i<n;i++)cout<<arr[i]<<" \n"[i==n-1];

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct pt{
double x,y;
};


int cw(pt a, pt b ,pt c){

return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;

}
int ccw(pt a, pt b ,pt c){

return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;

}


void convex(vector<pt> & pts){

int n=pts.size();
if(n<=3)return;

pt a,b;

a=pts[0];
b=pts.back();

vector<pt>up,down;

up.pb (a);
down.pb (a);

for(int i=1; i<n  ;i++){

if(i==n-1 || cw(a,pts[i],b)){
    int un=up.size();
    while(un>=2 && !cw(up[un-2],up[un-1],pts[i])){
        up.pop_back();
        un--;
    }
    up.pb (pts[i]);
}

if(i==n-1 || ccw(a,pts[i],b)){
    int ud=down.size();
    while(ud>=2 && !ccw(down[ud-2],down[ud-1],pts[i])){
        down.pop_back();
        ud--;
    }
    down.pb (pts[i]);
}
}

pts.clear();

for(int i=0; i<up.size()  ;i++){
pts.pb (up[i]);
}

for(int i=down.size()-2; i>0  ;i--){
pts.pb (down[i]);
}
}



double dist(pt a, pt b){
return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double ang( pt c, pt o , pt d){

double oc=dist(o,c);
double od=dist(o,d);
double cd=dist(c,d);

return acos((oc*oc+od*od-cd*cd)/(2*oc*od));

}

struct cmpr{
bool operator()(const pt &a , const pt &b)const{
     if(a.x==b.x)return a.y<b.y;
     else return a.x<b.x;
     }
};

int main() {



 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
int n;
scanf("%d",&n);

set<pt,cmpr> pts_set;
for(int i=0; i<n  ;i++){
pt p;
scanf("%lf%lf",&p.x,&p.y);
pts_set.insert(p);
}
vector<pt>pts;
for(auto i: pts_set)pts.pb (i);

convex(pts);
int sz=pts.size();
if(sz<3){
    printf("Case %d: 0\n",caseno);
    continue;
}
     double mn=ang(pts[1],pts[0],pts[sz-1]);
//
//     _flag(22);
//     for(int i=0; i<sz  ;i++){
//     cout<<pts[i].x spc pts[i].y,nl;
//     }

    double tmp;
    for(int i=1; i<sz-1 ;i++){
      tmp=ang(pts[i-1],pts[i],pts[i+1]);
     if(tmp<mn)mn=tmp;
    }
    tmp=ang(pts[sz-2],pts[sz-1],pts[0]);
    mn=min(tmp,mn);

printf("Case %d: %f\n",caseno,mn*180/PI);
}
    return 0;
}

