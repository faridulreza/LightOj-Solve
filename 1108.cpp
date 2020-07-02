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

vector<vector<int>> adj;
vector<bool> vis;
void dfs(int v, vector<int> &c)
{

    vis[v] = true;
    c.pb(v);
    for(int x : adj[v])if(!vis[x])dfs(x, c);

}

struct eg
{
    int a, b, c;
};

int main()
{



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;
        cn n >> m;
        vector<eg> v(m);
        vector<ll> d(n + 1);

        adj.clear();
        adj.assign(n + 1, vector<int>());

        
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
            adj[v[i].b].pb(v[i].a);
        }

        int xx;
        
        for (int i = 1; i < n; ++i)
        {
            for(eg x : v)
            {

                if(d[x.b] + x.c < d[x.a])
                {
                    d[x.a] = d[x.b] + x.c;
                    xx = x.a;
                }

            }

        }


        vector<int> cycle;

        vis.clear();
        vis.assign(n + 1, false);

        xx = -1;
        for(eg x : v)
        {

            if(d[x.b] + x.c < d[x.a])
            {

                d[x.a] = d[x.b] + x.c;
                if(!vis[x.b])dfs(x.b, cycle);
                xx = x.a;
            }

        }


        if(xx == -1)
        {
            printf("Case %d: impossible\n", caseno);
            continue;
        }




        sort(all(cycle));
        printf("Case %d:", caseno);
        for (int x : cycle)printf(" %d", x);
        nl;
    }







    return 0;
}
