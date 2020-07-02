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
double _eps=1e-6;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

namespace point{
int  g(double p,double q){
     return ((p>q) || fabs(p-q)<=_eps);
  }

  int  l(double p,double q){
   return ((p<q) || fabs(p-q)<=_eps);
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
  pt(){};
  pt(double _x,double _y){
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
    vector<double> eqn_by_slope(double m){
     double a,b,c;
      a=m;
      b=-1;
      c= y-m*x;
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


pt solve_eqn(vector<double> v,vector<double> v1){

   double ab=v[0]*v1[1]+v1[0]*v[1];

   if(fabs(ab)<_eps){
   	pt r(PI,PI);
   	return r;
   }

   double x=(v[2]*v1[1]+v1[2]*v[1])/ab;
   double y=(v[0]*v1[2]+v1[0]*v[2])/ab;
   pt r(x,y);
   return r;
}
int orientation(pt a,pt b,pt c){

   double r=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);

   if(fabs(r)<=_eps)return 0;
   else if(r<0) return -1;
   return 1;

}

double evaluate_x(vector<double> &v,double x){

    
    return ((-v[2]-x*v[0])/v[1]);

}
double evaluate_y(vector<double> &v,double y){

    return ((-v[2]-y*v[1])/v[0]);

}

vector<pt> solve_line_circle(vector<double> l,double h, double k, double r){

   double a=l[0];
   double b=l[1];
   double c=l[2];
   double x1,x2,y1,y2;

   if(fabs(b)<1e-7){
   	 c=-c;
   	   y1=sqrt(r*r-((h-c)*(h-c)))+k;
   	   y2=-sqrt(r*r-((h-c)*(h-c)))+k;
   	   x1=c;
   	   x2=c;
   	}
   	 
   else{

   	 double p=c+k*b;
     x1=-(b*sqrt((a*a*(r*r-h*h)-2*a*h*p+b*b*r*r-p*p))+a*p-b*b*h)/(a*a+b*b);
     x2=(b*sqrt((a*a*(r*r-h*h)-2*a*h*p+b*b*r*r-p*p))-a*p+b*b*h)/(a*a+b*b);
    
     if(fabs(l[0])<1e-7){
     	y1=-c;
     	y2=-c;
       }
     else{
     	y1=evaluate_x(l,x1);
     	y2=evaluate_x(l,x2);
     }

 } 
   pt aa(x1,y1),bb(x2,y2);
   std::vector<pt> v;
   v.pb (aa);
   v.pb (bb);
   return v;
}
}
using namespace point;

int main() {

    int n, m, l;
    
      int T;
         cn T;
     for(int caseno=1; caseno<=T  ;caseno++){
     

     pt a,b;
     a.in();
     b.in();

     double ab,bc,cd,da;
     ab=a.to(b);
     cn bc>>cd>>da;
    
     double x=(da*da-bc*bc+(ab-cd)*(ab-cd))/(2*(ab-cd));
    // _(x);
     double h=sqrt(da*da-(x*x));
    // _(h);
     vector<double>v=a.eqn(b);


     double cc1=h*sqrt(v[0]*v[0]+v[1]*v[1])+v[2];
     double c2=-h*sqrt(v[0]*v[0]+v[1]*v[1])+v[2];

     v[2]=cc1;
     pt test;
     test.x=a.x;
     test.y=evaluate_x(v,a.x);
     if(orientation(a,b,test)!=1)v[2]=c2;

     
      if(fabs(v[0])>_eps)v[2]/=v[0],v[1]/=v[0],v[0]/=v[0];
      else v[2]/=v[1],v[0]/=v[1],v[1]/=v[1];
     
     // _fl(line);
     // ct v[0] spc v[1] spc v[2];nl;
   

     vector<pt>   sol2=solve_line_circle(v,a.x,a.y,da);
     vector<pt>  sol=solve_line_circle(v,b.x,b.y,bc);
     
     // _fl(111);
     // sol[0].out();
     // sol[1].out();

     // sol2[0].out();
     // sol2[1].out();
     // _fl(111);
     
      pt c,d;
      for(auto x:sol){

      	for(auto y:sol2){

      		if(fabs(x.to(y)-cd)<=1e-7){
              c=x;
              d=y;
              break;
      		}
      	}
      }
      
    if(fabs(c.x)<_eps)c.x=0;
    if(fabs(c.y)<_eps)c.y=0;
    if(fabs(d.y)<_eps)d.y=0;
    if(fabs(d.x)<_eps)d.x=0;
     
      
     
    printf("Case %d:\n%.9f %.9f %.9f %.9f\n",caseno,c.x,c.y,d.x,d.y);
     }






    return 0;
}
