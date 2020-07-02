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

vector<vector<int>>adj;
int capacity[210][210];
int inf = 100000000, n;
double d;


int bfs(int s, int t, vector<int> &parent)
{

    fill(all(parent), -1);

    queue<pair<int, int>>q;
    q.push({s, 1000000000});

    while(!q.empty())
    {

        int u = q.front().fs;
        int flow = q.front().sc;
        q.pop();

        for(int v : adj[u])
        {

            if(parent[v] == -1 && capacity[u][v] > 0)
            {

                parent[v] = u;

                int new_flow = min(flow, capacity[u][v]);

                if(v == t)return new_flow;

                q.push({v, new_flow});


            }
        }



    }

    return 0;
}

int max_flow(int s, int t)
{

    vector<int> parent(n);
    int flow = 0, new_flow;

    while(new_flow = bfs(s, t, parent))
    {

        flow += new_flow;

        int cur = t;

        while(cur != s)
        {

            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }


    }

    return flow;

}



int main()
{

    struct node
    {
        ll x, y;
        int p = 0, c = 0;


        bool ok(node a)
        {
            ll xd = x - a.x;
            ll yd = y - a.y;

            double dist = sqrt(xd * xd + yd * yd);
            if(fabs(dist - d) < 1e-6 || dist < d)return true;
            return false;
        }
    };


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int m;
        scanf("%d %lf", &m, &d);
        vector<node>arr(m + 1);
        int cnt = 1;
        int nodemap[2][110];
        int total = 0;


        for (int i = 1; i <= m; ++i)
        {
            scanf("%lld %lld %d %d", &arr[i].x, &arr[i].y, &arr[i].p, &arr[i].c);
            total += arr[i].p;
            nodemap[0][i] = cnt++;
            nodemap[1][i] = cnt++;
        }


        n = cnt;

        vector<int>ans;

        for (int i = 1; i <= m; ++i)
        {
            adj.assign(2 * m + 10, vector<int>());
            _0(capacity);

            for(int l = 1; l <= m; l++)
            {
                int u = nodemap[1][l];

                capacity[0][nodemap[0][l]] = arr[l].p;
                adj[0].pb(nodemap[0][l]);
                adj[nodemap[1][l]].pb(0);

                if(l == i)continue;
                for(int k = 1; k <= m; k++)
                {
                    int v = nodemap[0][k];
                    if(l != k && arr[l].ok(arr[k]))
                    {
                        capacity[u][v] = inf;
                        adj[u].pb(v);
                    }
                }

                capacity[nodemap[0][l]][u] = arr[l].c;

                adj[nodemap[0][l]].pb(u);
                adj[u].pb(nodemap[0][l]);


            }


            if(max_flow(0, nodemap[0][i]) == total )
                ans.pb(i - 1);

        }

        printf("Case %d: ", caseno);

        if(ans.empty())puts("-1");
        else
        {
            for(int x : ans)
            {
                printf("%d", x);
                if(x == ans.back())nl;
                else printf(" ");
            }
        }
    }




    return 0;
}


