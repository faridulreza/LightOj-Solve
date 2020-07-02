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

int cmp(double a_A){

return (a_A<=0 || a_A<1e-6);
}


int main() {



int T;
cn T;
for(int caseno=1;caseno<=T;caseno++){

long double a,b,c;
cin>>a>>b>>c;

///fc perpendicular be, bx=1;

long double cx=2*b;

long double fx=2*a;

long double ex= 2*c/cx;





}










    return 0;
}
