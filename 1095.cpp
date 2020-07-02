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

 
ll fact[1200];
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

    fact[0]=1;
    for (int i = 1; i <=1000; ++i)
    {
    	fact[i]=(fact[i-1]*i)%mod;
    }

    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    
    int n,m,k;
    cn n>>m>>k;

    ll totalPerm=fact[n-k];

    /*
       f{}= permutations where the members of the sets must stays in place (others can also be in place )
      
       n!= f{1}+f{2}+{3}.....+f{n}-f{1,2}-f{1,3}-f{1,4}...+f{1,2,3}....-f{1,2,3,4}....+Dn (Inclusion-Exclusion)
        
         = nC1 * (n-1)! - nC2 *(n-2)! + nC3 * (n-3)! - .... +Dn 
      
       n!-RightHandSide = Dn= the permutations where no numbers are in their place .(derangement number) 

    */
    
    for (int i = 1; i <=m-k ; ++i)
    {
        if(i&1)totalPerm-=(ncr(m-k,i)*fact[n-k-i])%mod;
        else totalPerm+=(ncr(m-k,i)*fact[n-k-i])%mod;
        
        totalPerm%=mod;
        totalPerm+=mod;
        totalPerm%=mod;
    }

    
    
    printf("Case %d: %lld\n",caseno,(ncr(m,k)*totalPerm)%mod);
    
    }





    return 0;
}
