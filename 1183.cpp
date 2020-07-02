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



ll t[4 * 100000];
ll lazy[4 * 100000];




void push(int v, int tl, int tr)
{

    if(lazy[v]!=-1)
    {
        if(tl == tr)
        {
            t[v] = lazy[v];
            lazy[v] = -1;
            return;
        }

        lazy[v * 2] = lazy[v];
        lazy[v * 2 + 1] = lazy[v];
        t[v] = (tr - tl + 1) * lazy[v];
        lazy[v] = -1;
    }



}

ll sum(int v, int tl, int tr, int l, int r)
{

    push(v, tl, tr);

    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    ll q = sum(v * 2, tl, tm, l, min(r, tm))
           + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

    t[v] = t[v * 2] + t[v * 2 + 1];

    return q;

}


void update(int v, int tl, int tr, int l, int r, ll val)
{


    push(v, tl, tr);

    if (l > r)
        return;

    if (l == tl && r == tr)
    {
        t[v] = (tr - tl + 1) * val;

        if(tl != tr)
        {
            lazy[v * 2] = val;
            lazy[v * 2 + 1] = val;
        }
        return;
    }



    int tm = (tl + tr) / 2;

    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);

    t[v] = t[v * 2] + t[v * 2 + 1];

}







int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {


        _0(t);
        _1(lazy);

        int n, q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n",caseno);

        for (int i = 0; i < q; ++i)
        {
            int qq;
            scanf("%d", &qq);
            int a, b, c;
            if(qq == 1)
            {
                scanf("%d %d %d", &a, &b, &c);
                update(1, 0, n - 1, a, b, c);
            }
            else
            {
                scanf("%d%d", &a, &b);
                ll up = sum(1, 0, n - 1, a, b);
                ll d = (b - a + 1);
                ll g = __gcd(up, d);
                up /= g;
                d /= g;

                if(d == 1)
                {
                    printf("%lld\n", up);
                }
                else
                {
                    printf("%lld/%lld\n", up, d);
                }
            }
        }

         }






    return 0;
}
