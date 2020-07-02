#include  <iostream>
#include  <vector>
#include <iomanip>
#include  <deque>
#include  <list>
#include  <set>
#include  <map>
#include  <stack>
#include  <queue>
#include  <algorithm>
#include  <cstring>
#include  <cmath>
#include  <cctype>
#include  <cstdlib>
#include  <stdio.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (3.14159265)
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
#define len (100000)
ll mx=-1000000000-100;
ll mn=1000000000+100;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
double getTh(double x1,double x2, double y1, double y2){
if(x1-x2==0 ) return PI/2.00;
if(y1-y2==0)return  0;
return atan((y1-y2)/(x1-x2));
}

double getV(double di,double ii,double t){
return t*t*di+t*ii;
}

int main() {

    int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){

        int ax,ay,bx,by ,cx,cy,ddx,ddy;

        cn ax>>ay>>bx>>by>>cx>>cy>>ddx>>ddy;

        double dx=ax-cx;
        double dy=ay-cy;
         double vab=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
         double vcd=sqrt((ddx-cx)*(ddx-cx)+(cy-ddy)*(cy-ddy));

          double th1=getTh(ax,bx,ay,by);
          double th2=getTh(cx,ddx,cy,ddy);

          double a=vab*cos(th1)+vcd*cos(th2);
          double b=vab*sin(th1)+vcd*sin(th2);

          double di=a*a+b*b;
          double ii=(a*dx+b*dy)*2;


          double start=0;
          double ed=1;
         long  double mid=0;

          while (start<=ed){

            mid=(start+ed)/2.00;
            if(getV(di,ii,mid)<getV(di,ii,start))start=mid+1e-12;
            else ed=mid-1e-12;

          }

        ct mid,nl;
          ct sqrt(dx*dx+dy*dy+getV(di,ii,mid));nl;


}


    return 0;
}
