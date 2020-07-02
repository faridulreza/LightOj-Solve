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

int arr[1000010];
struct Q
{
    int l, r, id, ans;
};



int t[4 * 100000];


int sum(int v, int tl, int tr, int l, int r)
{


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

void update(int v, int tl, int tr, int pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}



bool compare1(Q a, Q b)
{

    return a.r < b.r;
}

bool compare2(Q a, Q b)
{

    return a.id < b.id;
}

int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        vector<Q>q(m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &q[i].l, &q[i].r);
            q[i].id = i;
            q[i].l--;
            q[i].r--;
        }

        sort(all(q), compare1);

        int lastSeen[100010];

        _1(lastSeen);
        _0(t);

        int qp = 0;
        for (int i = 0; i < n; ++i)
        {
            int v = arr[i];

            if(lastSeen[v] != -1)update(1, 0, n - 1, lastSeen[v], 0);

            lastSeen[v] = i;
            update(1, 0, n - 1, i, 1);

            while(q[qp].r == i)
            {

                q[qp].ans = sum(1, 0, n - 1, q[qp].l, q[qp].r);
                qp++;
            }



        }

        sort(all(q), compare2);
        printf("Case %d:\n", caseno);
        for(auto x : q)
        {
            printf("%d\n", x.ans);
        }
    }






    return 0;
}
