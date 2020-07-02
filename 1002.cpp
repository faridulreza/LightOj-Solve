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
 
int arr[550];
vector<pair<int, int>> adj[550];
int t;
bool vis[550];
 
 
void dfs(int u, int cost)
{
 
    if(!vis[u])
    {
        vis[u] = 1;
        arr[u] = cost;
        for (auto x : adj[u])
        {
            int v = x.sc;
            int w = x.fs;
 
            if(!vis[v])dfs(v, max(cost, w));
            else
            {
                if(v != t && arr[v] > max(cost, w))
                {
                    vis[v] = 0;
                    dfs(v, max(cost, w));
                }
 
            }
 
        }
 
 
    }
 
 
}
 
 
int main()
{
 
 
    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;
        cn n >> m;
        for (int i = 0; i <= n; ++i)
        {
            arr[i] = 20000000;
            adj[i].clear();
        }
 
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cn u >> v >> w;
            adj[u].pb({w, v});
            adj[v].pb({w, u});
        }
 
        for (int i = 0; i < n; ++i)
        {
            sort(all(adj[i]));
        }
 
        cn t;
        _0(vis);
        dfs(t, 0);
 
 
 
        printf("Case %d:\n", caseno);
 
        for (int i = 0; i <n; ++i)
        {
            if(arr[i]==20000000)ct "Impossible";
            else ct arr[i];
            nl;
        }
    }
 
 
 
 
 
 
    return 0;
}
 