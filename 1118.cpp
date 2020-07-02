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






namespace Geometry{

// equation is in  ax+by+c=0 form

typedef double myType;  


int  g(myType p,myType q){
     return ((p>q) || fabs(p-q)<=_eps);
  }

  int  l(myType p,myType q){
   return ((p<q) || fabs(p-q)<=_eps);
  }

struct pt{
  myType x,y;
  void in(){
    cn x;
    cn y;
  }
  void assign( myType _x,myType _y){
    x=_x;
    y=_y;
  }
  pt(){};
  pt(myType _x,myType _y){
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

  vector<myType> eqn(pt p){
     myType a,b,c;
      a=(p.y- y);
      b=-(p.x- x);
      c= y*(p.x- x)- x*(p.y- y);
      vector<myType> r;
      r.pb(a);
      r.pb(b);
      r.pb(c);
      return r;
    }
    vector<myType> eqn_by_slope(myType m){
     myType a,b,c;
      a=m;
      b=-1;
      c= y-m*x;
      vector<myType> r;
      r.pb(a);
      r.pb(b);
      r.pb(c);
      return r;
    }

    int on_this_line(pt p1,pt p2){
         vector<myType> v=p1.eqn(p2);
         myType r=v[0]*x+v[1]*y+v[2];
         if(fabs(r)<=_eps){
            if(g(x,min(p1.x,p2.x)) && l(x,max(p1.x,p2.x)) && g(y,min(p1.y,p2.y)) && l(y,max(p1.y,p2.y)))
              return 1;
         }
         return 0;
    }

    vector<myType> eqn_orthogonal_to(pt p, pt q){
          vector<myType> v=p.eqn(q);
          myType a=v[1];
          myType b=-v[0];
          myType c=-(a*x+b*y);
          vector <myType> r;
          r.pb(a);
          r.pb(b);
          r.pb(c);
           return r;
    }
    
};


pt solve_eqn(vector<myType> v,vector<myType> v1,ll INF){
  

     v[2]=-v[2];
     v1[2]=-v1[2];
   myType ab=v[0]*v1[1]-(v1[0]*v[1]);

   if(fabs(ab)<_eps){
    pt r(INF,INF);
    ct "IN/f";
    return r;
   }

   myType x=(v[2]*v1[1]-(v1[2]*v[1]))/ab;
   myType y=(v[0]*v1[2]-(v1[0]*v[2]))/ab;
   pt r(x,y);
   return r;
}
int orientation(pt a,pt b,pt c){

   myType r=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);

   if(fabs(r)<=_eps)return 0;
   else if(r<0) return -1;
   return 1;

}

myType evaluate_x(vector<myType> &v,myType x){

    
    return ((-v[2]-x*v[0])/v[1]);

}
myType evaluate_y(vector<myType> &v,myType y){

    return ((-v[2]-y*v[1])/v[0]);

}
}




int main() {

    


     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    ll x1,x2,y1,y2,r1,r2;
    cn x1>>y1>>r1>>x2>>y2>>r2;

    Geometry::pt a(x1,y1),b(x2,y2);
    
    ll xdif=x1-x2;
    ll ydif=y1-y2;
    xdif*=xdif;
    ydif*=ydif;

    if(Geometry::l(r1+r2,a.to(b))){
         printf("Case %d: 0\n",caseno);
         continue;
    }

    else if(xdif+ydif-r2*r2<0 && Geometry::l(a.to(b)+r1,r2)){
    
         printf("Case %d: %.10f\n",caseno,PI*r1*r1);
         continue;
    }
    else if(xdif+ydif-r1*r1<0 && Geometry::l(a.to(b)+r2,r1)){
        
          printf("Case %d: %.10f\n",caseno,PI*r2*r2);
         continue;
    }
    
    vector<double>commonL;

    ll aa=-2*x1+2*x2;
    ll bb=-2*y1+2*y2;
    ll cc=x1*x1-x2*x2+y1*y1-y2*y2-(r1*r1-r2*r2);

    commonL.pb(aa);
    commonL.pb(bb);
    commonL.pb(cc);
       

    Geometry::pt inter=Geometry::solve_eqn(commonL,a.eqn(b),1000000);
    
    
    double c1d=a.to(inter);
    double c1up=sqrt(r1*r1-c1d*c1d);
    double c1Tarea=c1up*c1d;

    double c2d=b.to(inter);
    double c2up=sqrt(r2*r2-c2d*c2d);
    double c2Tarea=c2d*c2up;


    double c1angle=2*acos(c1d/r1);
    double c2angle=2*acos(c2d/r2);
    
    double c1Aarea=.5*r1*r1*c1angle;
    double c2Aarea=.5*r2*r2*c2angle;

    double total=c1Aarea+c2Aarea;


    if(fabs(a.to(b)+b.to(inter)-a.to(inter))<=1e-6){
        //c2 is inside c1 and the coomon line 
        //is after c2's center
        
        double c2OuterArea=c2Aarea-c2Tarea-(c1Aarea-c1Tarea);
        printf("Case %d: %.10f\n",caseno,PI*r2*r2-c2OuterArea);    
    }
    else if(fabs(a.to(b)+a.to(inter)-b.to(inter))<=1e-6){
        //c1 is inside c2 
        // common line is after c1's center

        double c1OuterArea=c1Aarea-c1Tarea-(c2Aarea-c2Tarea);

        printf("Case %d: %.10f\n",caseno,PI*r1*r1-c1OuterArea);
    }
    
     else printf("Case %d: %.10f\n",caseno,total-c1Tarea-c2Tarea);
    }

   




    return 0;
}
