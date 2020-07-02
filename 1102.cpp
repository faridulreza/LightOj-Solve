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


 
ll fact[2000020];
ll mod=1000000007; 
ll egcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll miverse(ll a,ll m){
    
 
    ll x,y;
    egcd(a,m,x,y);
    return (x+m)%m;
}


ll ncr(ll n,ll r){

    return ( ( (fact[n]*miverse(fact[n-r],mod))%mod )*miverse(fact[r],mod))%mod;
}

int main() {

    fact[0]=1;;
    for (int i = 1; i <=2000000; ++i)
    {
    	fact[i]=(fact[i-1]*i)%mod;
    }
   
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int n,k;
   cn n>>k;

   
   printf("Case %d: %lld\n",caseno,ncr(n+k-1,k-1));
   }





    return 0;
}
