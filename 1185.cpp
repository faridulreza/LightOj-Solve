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

int vis[120];
bool vis2[120];
int level[120];

bool dfs(int v,int l){
   
   if(level[v]%2==0 && l%2==0)return true;
   if(level[v]&1 && l&1)return true;
   if(vis2[v])return false;
   vis2[v]=true;
   for(int x:adj[v])
     if(dfs(x,l+1))return true;


   return false;
}

int bfs(int n)
{

    _0(vis);
    _0(level);

    int cnt = 0;

    queue<int>q;
    q.push(1);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = true;
        for(int x : adj[v])
        {

            if(!vis[x])
            {

                q.push(x);
                level[x] = level[v] + 1;
                vis[x] = true;
            }

        }
    }
    
    if(adj[1].size()>0)cnt=1;
    else return 0;
    
    for (int i = 2; i <= n; ++i)
    {

        if(level[i] && level[i]%2==0)cnt++;
        else if(level[i])
        {
            _0(vis2);
            if(dfs(i,0))cnt++;

        }

    }




    return cnt;
}

int main()
{



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        adj.assign(n + 2, vector<int>());
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        printf("Case %d: %d\n", caseno, bfs(n));
    }





    return 0;
}
