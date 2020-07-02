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
double _eps = 1e-6;



ll fact[4010];
ll mod = 100000007;
ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
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
ll miverse(ll a, ll m)
{


    ll x, y;
    egcd(a, m, x, y);
    return (x + m) % m;
}


ll ncr(ll n, ll r)
{

    return ( ( (fact[n] * miverse(fact[n - r], mod)) % mod ) * miverse(fact[r], mod)) % mod;
}



vector<ll> pf;

int main()
{
    int cnt = 0;
    ll x = 10000000000LL;

    for (ll i = 2; i <= 100000 ; ++i)
    {
        ll j = i * i;
        while(j <= x)
        {
            pf.pb(j);
            j *= i;
        }
    }


    sort(all(pf));
    auto it = unique(all(pf));
    pf.resize(distance(pf.begin(), it));


    fact[0] = 1;
    for (ll i = 1; i <= 4000 ; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        int n = upper_bound(all(pf), b) - lower_bound(all(pf), a);
      //  _(n);
        ll ans = (ncr(2 * n, n) - ncr(2 * n, n + 1)) % mod;
        ans = (ans + mod) % mod;
        if(n==0)ans=0;
        printf("Case %d: %lld\n", caseno, ans);
    }




    return 0;
}
