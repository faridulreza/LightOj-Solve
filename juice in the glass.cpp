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

int main() {

#ifdef SAGOR
freopen("in.txt","r+",stdin);
freopen("out.txt","w+",stdout);
#endif


     int T;
     cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    double r1,r2,h,p;
    cn r1>>r2>>h>>p;
    double res=r2*r2*h*h*p  +  r1*r2*h*p*p+ r1*r1*p*p*p/3 - r2*r2*h*p*p -2*r1*r2*p*p*p/3 + r2*r2*p*p*p/3;
    res=res*PI/(h*h);
    printf("Case %d: %.6f\n",caseno,res);

    }







    return 0;
}
