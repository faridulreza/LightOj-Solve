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


    ll mod=1000;

	ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a)%mod;
		ll q = power(a,b/2);
		return (q*q)%mod;
	}


int main() {

    
      int T;
         cn T;
     for(int caseno=1; caseno<=T  ;caseno++){
     ll n,k;

     cn n>>k;

     ll last=power(n,k);

     double pw=k*log10(n);

     pw=pw-trunc(pw);

     double xx=pow((double)10.00,pw);
     ll x=0;
     ll gun=100;
     while(1){
         
         x=xx*gun;
         gun*=10;

         if((ll)(xx*gun)>999)break;
        
     }


     
     printf("Case %d: %lld %03lld\n",caseno,x,last%1000);
     }






    return 0;
}
