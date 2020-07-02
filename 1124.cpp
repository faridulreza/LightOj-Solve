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

ll mod = 100000007;


int arr[15];
ll cofOf[1000000 + 10]; //cofficient of x in this from exmple x^3 (1-x^5).(1 - x^3)

void calcCof(int i, ll nowpow,int cof, int n, int m)
{

    if(i == n)
    {
        if(nowpow <= m)
            cofOf[nowpow] = (cofOf[nowpow] + cof);
        return ;
    }

    calcCof(i + 1, nowpow + arr[i],cof*-1,n, m);
    calcCof(i + 1, nowpow, cof,n, m);

}


ll fact[1000000 + 10];
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
    if(r == 0)return  1;
    if(n < 0)return 0;
    return ( ( (fact[n] * miverse(fact[n - r], mod)) % mod ) * miverse(fact[r], mod)) % mod;
}



int main()
{
    /*
      2 10
      (1 5) (2 4)

      for this input we have to find cofficient of x^10 in

        (x+ x^2 + x^3 + x^4 +x^ 5)(x^2 + x^3 +x^ 4 )

      =x .(1+x+x^2+x^3+x^4) .x^2 .(1+x+x^2)

         (1- x^(4+1))        (1- x^(2+1))
     = x ------------- .x^2  -----------
           (1- x)               (1-x)

     =x^3 . (1-x^5).(1 - x^3). (1-x)^-2

    */

    fact[0] = 1;
    for (int i = 1; i <= 1000000 ; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int n, m ;
        cn n >> m;
        int extrapow = 0; // counting power of lone x (x^3)

        int cnt = 0;
        int mxp = 0;
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            mxp += b;
            extrapow += a;
            if(b - a)arr[cnt++] = b - a + 1;

        }

        if(mxp < m)
        {
         printf("Case %d: 0\n",caseno);
         continue;
        }

        _0(cofOf);

        calcCof(0, extrapow, 1,cnt, m);
        ll res = 0;
        for (int i = 0; i <= m; ++i)
        {
            if(cofOf[i])
            {
                int k = m - i; //needed power of x in (1-x)^-2
                res += (mod+(cofOf[i] * ncr(cnt + k - 1, k)) % mod)%mod;
                res %= mod;
            }

        }


        printf("Case %d: %lld\n", caseno, res);
    }






    return 0;
}
