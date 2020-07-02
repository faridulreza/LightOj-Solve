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

vector<ll> L,R;
ll arr[30];

void comb(ll i,ll lm,ll w,ll wlm,vector<ll> &v){

    if(w>wlm)return;

    if(i==lm){
    	v.pb(w);
    	return;
    }


	comb(i+1,lm,w+arr[i],wlm,v);
	comb(i+1,lm,w,wlm,v);
}



int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   ll n,w;
   cn n;
   cn w;
   for (ll i = 0; i < n; ++i)
   {
   	 scanf("%lld",&arr[i]);
   }
   sort(arr,arr+n);

     comb(0,n/2,0,w,L);
     comb(n/2,n,0,w,R);

     sort(all(R));
     ll ans=0;

     for(ll x:L){
         ll toFind=w-x;
         ans+=upper_bound(all(R),toFind)-R.begin();

     }
     printf("Case %d: %lld\n",caseno,ans);
     L.clear();
     R.clear();
   }






    return 0;
}
