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
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ull pp(ull a,ull n,ull mod){

if(n==0)return 1;


if(n&1){

   return (a*pp(a,n-1,mod))%mod;

}

ull x=pp(a,n/2,mod);

return (x*x)%mod;




}
int main() {

 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){

    ull s,n,k,mod,inp;
    cn n>>k>>mod;
    s=0;
    for (int i = 0; i < n; ++i)
    {
        cn inp;
        s=(s+inp)%mod;
      
    }


   s=(s*pp(n,k-1,mod))%mod;
   s=(s*k)%mod;



printf("Case %d: %llu\n",caseno,s);
}






    return 0;
}
