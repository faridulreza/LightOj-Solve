#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) puts("FLAG " #x);
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
double _eps=1e-10;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
struct pt{
  double x,y;
  void in(){
    cn x;
    cn y;
  }
  void as(double _x,double _y){
    x=_x;
    y=_y;
  }
    void out(){ct x spc y,nl;}
    bool operator ==(const pt &a)const{
        if(fabs(a.x-x)<=_eps && fabs(a.y-y)<=_eps)return true;
        return false;
    }

    double to(pt a){
        return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
    }


  int  g(double p,double q){
     return ((p>q) || fabs(p-q)<=_eps);
  }

  int  l(double p,double q){
   return ((p<q) || fabs(p-q)<=_eps);
  }

  vector<double> eqn(pt p){
     double a,b,c;
      a=(p.y- y);
      b=-(p.x- x);
      c= y*(p.x- x)- x*(p.y- y);
      vector<double> r;
      r.pb(a);
      r.pb(b);
      r.pb(c);
      return r;
    }

    int on_this_line(pt p1,pt p2){
         vector<double> v=p1.eqn(p2);
         double r=v[0]*x+v[1]*y+v[2];
         if(fabs(r)<=_eps){
            if(g(x,(p1.x,p2.x)) && l(x,max(p1.x,p2.x)) && g(y,min(p1.y,p2.y)) && l(y,max(p1.y,p2.y)))
              return 1;
         }
         return 0;
    }

    vector<double> eqn_orthogonal_to(pt p, pt q){
          vector<double> v=p.eqn(q);
          double a=v[1];
          double b=-v[0];
          double c=-(a*x+b*y);
          vector <double> r;
          r.pb(a);
          r.pb(b);
          r.pb(c);
           return r;
    }
};


int main() {

    int n, m, l;
    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    double x,y,c;
    cn x>>y>>c;

    //if(x>y)swap(x,y);

    double lw=0,up=PI/2.00;
    pt xx,zero;
    zero.as(0,0);
    double bc;
    while(lw<=up){
        double mid=(lw+up)/2.0;

        xx.as(x*cos(mid),x*sin(mid));
        // xx.out();
        
        // _(mid);
        vector<double> v=zero.eqn(xx);

        pt o;
        o.as((-v[2]-v[1]*c)/v[0],c);

        pt on_x;
        on_x.as(xx.x,0);

        v=on_x.eqn(o);

        pt on_y;

        on_y.as(0,-v[2]/v[1]);


        double dist=on_y.to(on_x);

         bc=xx.x;
        // _(bc);
        // _(dist);
        // nl; 
         
        if(dist<y)up=mid-.1e-15;
        else if(dist>y)lw=mid+.1e-15;
      
         if(fabs(dist-y)<_eps)break;

    }

    printf("Case %d: %f\n",caseno,bc);
    }








    return 0;
}