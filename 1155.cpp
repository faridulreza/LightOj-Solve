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

vector<vector<int>> capacity, adj;
int inf = 100000000;
int n;


int bfs(int s, int t, vector<int> &parent)
{

    fill(all(parent), -1);
    parent[s]=-2;
    queue<pair<int, int>> q;
    q.push({s, inf});
    
    while(!q.empty())
    {

        int u = q.front().fs;
        int flow = q.front().sc;
        q.pop();

        for(int v : adj[u])
        {

            if(parent[v] == -1 && capacity[u][v])
            {
            	parent[v]=u;
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

    vector<int>parent(n + 1);

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

   
   #ifdef SAGOR
   freopen("in.txt","r+",stdin);
   freopen("out.txt","w+",stdout);
   #endif
   
    /*
      for every node v create two node v_in and v_out
      
      create a edge v_in to v_out . capacity of this edge is capacity of node v.

      now whenever there is a edge from x to v , create a edge x to v_in

      and if theres a edge from v to y ,create a edge v_out to y

      find max flow in this graph.

    */
    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        scanf("%d", &n);

       capacity.assign(2*n + 10, vector<int>(2*n + 10,0));
       adj.assign(2*n + 10, vector<int>(2*n + 10,0));
        
        int nodeMap[n+2][2];
        int cnt=1;

        for (int i = 1; i <= n; ++i)
        {
        	int u=nodeMap[i][0]=cnt++;
        	int v=nodeMap[i][1]=cnt++;
            adj[u].pb(v);
            adj[v].pb(u);
            scanf("%d", &capacity[u][v]);
        }

        int sink=cnt++;

        int m;
        scanf("%d", &m);

        for (int i = 0; i < m; ++i)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            int u=nodeMap[a][1];
            int v=nodeMap[b][0];
            capacity[u][v] = w;
            adj[u].pb(v);
            adj[v].pb(u);
            
        }

        int b, d;
        scanf("%d%d", &b, &d);
        for (int i = 0; i < b; ++i)
        {
            int a;
            scanf("%d", &a);
            int u=0;
            int v=nodeMap[a][0];
            capacity[u][v] = inf;
            adj[u].pb(v);
            adj[v].pb(u);
            
        }

        for (int i = 0; i < d; ++i)
        {
            int a;
            scanf("%d", &a);
            int u=nodeMap[a][1];
            int v=sink;
            capacity[u][v] = inf;
            adj[u].pb(v);
            adj[v].pb(u);
          }
        
        
        n=cnt;

        printf("Case %d: %d\n", caseno,max_flow(0, sink));
    }


    return 0;
}
