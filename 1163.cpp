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
 
 
bool f(ll n,ll i){
 
    ll md=(n%9);
 
    md-=(i%9);
 
    md=md%9;
 
    return md==0?true:false;
 
}
 
 
 
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    ll n;
    cn n;
 
 
    vector<ll>v;
 
    for (ll i = 0; i <10; ++i)
    {
        if(f(n,i)){
           ll y=n%9;
 
           ll x=(n-y)/9;
 
           x*=10;
 
           y=(10*y-i)/9;
 
           v.pb(x+y);
 
 
         
        }
    }
 
    sort(all(v));
 
 
   
    printf("Case %d:",caseno);
 
    for (auto x:v)
    {
        ct " "<<x;
    }
    nl;
    }
 
 
 
 
 
 
 
    return 0;
}
 