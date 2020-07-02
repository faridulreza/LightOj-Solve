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

ll  egcd(ll a,ll b,ll *x, ll *y){

if(a==0){
    *x=0,*y=1;
    return b;
}

ll x1,y1;
ll gcd=egcd(b%a,a,&x1,&y1);
//cout<< x1 spc y1<<endl;
*x= y1 - (b/a)*x1;
*y=x1;

return gcd;
}

ll fsol(ll a, ll b,ll c,ll *x,ll *y){

ll gcd=egcd(abs(a),abs(b),x,y);

if(c%gcd)return 0;

(*x)*=c/gcd;
(*y )*=c/gcd;


if(a<0)(*x)*=-1;
if(b<0)(*y)*=-1;

return gcd;
}

void shift(ll a,ll b,ll &x,ll &y, ll t){
x+=t*b;
y-=t*a;
}

ll sol(ll a,ll b,ll c,ll minx,ll maxx,ll miny,ll maxy){
ll x, y;


if(a==0 && b==0){
    if(!c)return (maxx-minx+1)*(1+maxy-miny);
    return 0;
}

if(a==0){

    if(c%abs(b))return 0;
    else {
        c/=b;

        return (c>=miny && c<=maxy)*(maxx-minx+1);

    }

}
if(b==0){

    if(c%abs(a)) return 0;
    else {
        c/=a;

        return (c>=minx && c<=maxx)*(maxy-miny+1);

    }

}


ll g=fsol(a,b,c,&x,&y);
//cout<<g spc x spc y<<endl;
if(!g)return 0;

a/=g,b/=g;


ll sa,sb;
sa=a>0?1:-1;
sb=b>0?1:-1;

shift(a,b,x,y,(minx-x)/b);
if(x<minx)shift(a,b,x,y,sb);
if(x>maxx)return 0;
ll lx=x;
//ct "lx "<<lx<< endl;
shift(a,b,x,y,(maxx-x)/b);
if(x>maxx)shift(a,b,x,y,-sb);
ll rx=x;
//ct "rx "<<rx<<endl;


shift(a,b,x,y,-(miny-y)/a);
if(y<miny)shift(a,b,x,y,-sa);
if(y>maxy)return 0;
ll lx1=x;
//ct "lx1 "<<lx1<<endl;
//ct (maxy-y)/a<<endl;
shift(a,b,x,y,-(maxy-y)/a);
if(y>maxy) {
        //cout<<"KKK  "<<y<<" "<<maxy<<endl;

        shift(a,b,x,y,sa);
}
ll rx1=x;
//ct "rx1 "<<x<<endl;


if(lx1>rx1)swap(lx1,rx1);
//ct rx spc lx spc rx1 spc lx1<<endl;


ll l=max(lx,lx1);
ll r=min(rx,rx1);
//ct l spc r<<endl;
if(l>r)return 0;

return ((r-l)/abs(b)+1);


}



int main() {

   int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){

    int a,b,c,x1,x2,y1,y2;
    cn a>>b>>c>>x1>>x2>>y1>>y2;
    printf("Case %d: %lld\n",caseno,sol(a,b,-c,x1,x2,y1,y2));
    }


    return 0;
}
