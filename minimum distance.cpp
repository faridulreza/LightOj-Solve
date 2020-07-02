#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
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
struct point{
double x,y;
};

double dist(point a,point b){
return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
#define eps 1e-12

double src(point a,point b,point c,point d){
double f=dist(a,c);
double s=dist(b,d);

while(fabs(f-s)>eps){
    point na,nb,nc,nd;
    ///a----|-----------b
    ///      1  na             2

    na.x=(a.x*2+b.x)/3.0;
    na.y=(a.y*2+b.y)/3.0;

    ///d-----------|----c
    ///            2           nc 1

    nc.x=(c.x*2+d.x)/3.0;
    nc.y=(c.y*2+d.y)/3.0;


    nb.x=(b.x*2+a.x)/3.0;
    nb.y=(b.y*2+a.y)/3.0;

    nd.x=(d.x*2+c.x)/3.0;
    nd.y=(d.y*2+c.y)/3.0;


    if(dist(na,nc)<dist(nb,nd))b=nb,d=nd;
    else a=na,c=nc;
f=dist(a,c),s=dist(b,d);
}


return (f+s)/2.00;

}

int main() {


#ifdef SAGOR
freopen("in.txt","r+",stdin);
freopen("out.txt","w+",stdout);
#endif

 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){

point arr[5];
for(int i=0; i<4  ;i++){
cn arr[i].x>>arr[i].y;
}


printf("Case %d: %0.6f\n",caseno,src(arr[0],arr[1],arr[2],arr[3]));
}


    return 0;
}
