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
double _eps = 1e-6;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int size = 10000000;
vector<int>primes;
bool mark[size + 5];
void sieve()
{

    for(ll i = 3; i <= size; i += 2)
    {
        if(mark[i])continue;
        for(ll j = i * i; j <= size; j += i)
        {
            mark[j] = true;
        }
    }

    primes.pb(2);
    for (int i = 3; i <= size; i += 2)
    {
        if(!mark[i])primes.pb(i);
    }

}

void factor(vector<pair<int, int>> &xx, ll y )
{

    ll root = round(sqrt(y));
    for(auto x : primes)
    {
        if(x > root)break;
        int c = 0;
        //       _(x);
        while(y % x == 0)
        {
            y /= x;
            c++;
        }
        if(c)xx.pb({x, c});
    }
    if(y != 1)xx.pb({y, 1});
    //for(auto a:xx)ct a.fs spc a.sc,nl;
}


ull pp(ull x, int y)
{


    ull res = 1;
    for (int i = 0; i < y; ++i)
    {
        res *= x;
    }
    return res;
}

int main()
{
    sieve();

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        ll a, b, c;
        vector<pair<int, int>>aa, bb, cc;
        scanf("%lld%lld%lld", &a, &b, &c);
        factor(aa, a);
        factor(bb, b);
        factor(cc, c);
        map<int, int>m;
        for(auto x : cc)
        {
            m[x.fs] = x.sc;
           }

        map<int,int>m2(m);
        int br = 0;
        for(auto x : aa)
        {

            auto it = m2.find(x.fs);
            if(it == m2.end()|| (*it).sc<x.sc)
            {
                printf("Case %d: impossible\n", caseno);
                br = 1;
                break;
            }

            if((*it).sc == x.sc)m[x.fs]= 0;
        }
        if(br)continue;

        for(auto x : bb)
        {

            auto it = m2.find(x.fs);
            if(it == m2.end()|| (*it).sc<x.sc)
            {
                printf("Case %d: impossible\n", caseno);
                br = 1;
                break;
            }

            if((*it).sc == x.sc)m[x.fs]= 0;
        }
        if(br)continue;

        ull res=1;
        for(auto x : m)
        {
            //_(x.fs);
            res *= pp(x.fs, x.sc);

        }

        printf("Case %d: %llu\n", caseno, res);
    }







    return 0;
}
