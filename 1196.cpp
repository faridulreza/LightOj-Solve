#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) puts("FLAG " #x),fflush(stdout);
#define  _(x)  cout<< #x <<" is "<< x <<endl;
#define fs first
#define sc second
#define pb push_back
#define all(v)  (v).begin(), (v).end()
#define _109 (1000000000)
#define _0(arr) memset(arr,0,sizeof ( arr ) )
#define _1(arr) memset(arr,-1,sizeof ( arr ) )
#define _ninp(n,arr) for(int i=0; i<n;i++)cin>>arr[i];
#define _nout(n,arr) for(int i=0; i<n;i++)cout<<arr[i]<<" \n"[i==n-1];
double _eps=1e-6;
 
struct pt {
 
    ll x,y;
    pt(){}
    pt(ll _x,ll _y){
        x=_x,y=_y;
    }
    pt(pair<ll,ll> a){
        x=a.fs,y=a.sc;
    }
    void out(){
        ct x spc y<<endl;
    }
    void in(){
        scanf("%lld %lld",&x,&y);
    }
 
    pt operator -(pt a){
           return pt(x-a.x,y-a.y);
    }
 
    ll cross(pt a){
        return x*a.y-y*a.x;
    }
    ll cross(pt &a,pt &b){
        pt o(x,y);
        return (a-o).cross(b-o);
    }
    ll sgn(pt &a){
        ll tm=cross(a);
        return tm>0?1:(tm==0?0:-1);
    }
    ll sgn(pt &a,pt &b){
        ll tm=cross(a,b);
        return tm>0?1:(tm==0?0:-1);
    }
    ll sqrLen(){
        return x*x+y*y;
    }
    ll dot(pt &a){
        return x*a.x+y*a.y;
    }
    bool operator <(pt &a){
        return (x<a.x)||(x==a.x && y<a.y);
    }
};
bool in_triangle(pt a,pt b,pt c,pt point){
 
     ll area1=abs(a.cross(b,c));
     ll area2=abs(point.cross(a,b))+abs(point.cross(b,c))+abs(point.cross(c,a));
 
     return area1==area2;
 
}
vector<pt> poly;
pt o;
int n;
void prepare(vector<pt> &a){
   
 
    int pos=0;
    for (int i = 0; i < a.size(); ++i)
    {
        if(a[i]<a[pos])pos=i;
    }
 
    rotate(a.begin(),a.begin()+pos,a.end());
 
    poly.clear();
    for (int i = 1; i < a.size(); ++i)
    {
        poly.pb(a[i]-a[0]);
    }
    n=poly.size();
    o=a[0];
 
}
 
bool inPoly(pt &point){
   point=point-o;
 
  if(poly[0].sgn(point) && poly[0].sgn(point)!=poly[0].sgn(poly[n-1]))
    return false;
 
  if(poly[n-1].sgn(point) && poly[n-1].sgn(point)!=poly[n-1].sgn(poly[0]))
    return false;
 
  if(poly[n-1].sgn(point)==0)
    return poly[n-1].sqrLen()>=point.sqrLen();
  if(poly[0].sgn(point)==0)
    return poly[0].sqrLen()>=point.sqrLen();
 
 
  int l=0,r=n-1;
 
  while(r-l>1){
    int mid=(l+r)/2;
 
    if(poly[mid].cross(point)>=0)l=mid;
    else r=mid;
  }
 
 
  return in_triangle(pt(0,0),poly[l],poly[l+1],point);
 
}
 
int main() {
 
   
      int T;
         cn T;
     for(int caseno=1; caseno<=T  ;caseno++){
     int nn;
     scanf("%d",&nn);
 
     std::vector<pt> v(nn);
 
     for (int i = 0; i < nn; ++i)
         v[i].in();
 
     prepare(v);
 
     int q;
     scanf("%d",&q);
     printf("Case %d:\n",caseno);
     while(q--){
 
        pt p;
        p.in();
 
        if(inPoly(p))puts("y");
        else puts("n");
 //       fflush(stdout);
 
     }
 
 
     
     
     }
    return 0;
}