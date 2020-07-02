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

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int nodeMap[2][220];
int source, postSource, sink, postSink, D;



int main()
{   

	/**
       we will binary search for the ans.

       to answer whether it is possible to come back by jumping not more than x. 
       we will use flow

       each stone is a node. Big stone has "node" capacity 2 ans small has "node" capacity 1
       (for flow with node capacity refer lightoj problem 1155)

       each node is connected to next others by an edge with capacity 1.
       only two big stone is connected with edge capacity 2;

       now we need a post source node and a pre sink node which will connect to every 
       node of our graph with capcity 1 or 2(connected small or big)

       add a edge to source to postSource , preSink to sink  with capacity 2

       for 1 10
           B-4 S-5 
                                   ------2---------v
       source--2-->postSource--2-->B--1-->S--1-->preSink---2-->sink
                        ---------1-------^
       
       we will make this kind of graph by only adding those edges with distance less than x

       if the created graph has flow 2 which is maximum,then taking two disjoint path is possible 
       
       only dinic algo has complexity O(sqrt(V)E) for unit capacity graph
	**/

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int cnt = 1;
        int m,n;
        scanf("%d %d", &m, &D);
        vector<int> arr(m + 1);

        for (int i = 1; i <= m ; ++i)
        {
            char c;
            getchar();
            scanf("%c-%d", &c, &arr[i]);
            nodeMap[0][i] = cnt++;
            nodeMap[1][i] = cnt++;

            if(c == 'B')
                arr[i] *= -1;
        }


        sink = cnt++;
        source = 0;
        postSource = cnt++;
        postSink = cnt++;
        n = cnt;

        ll up = D, low = 1;


        while(low < up)
        {

            int mid = (low + up) / 2;

            Dinic dn(n,source,sink);

            dn.add_edge(source,postSource,2);
            dn.add_edge(postSink,sink,2);

            for (int i = 1; i <= m; ++i)
            {
                int d = abs(arr[i]);
                int c = arr[i] < 0 ? 2 : 1;

                int u = nodeMap[0][i];
                int v = nodeMap[1][i];

                int c2 = (arr[i] < 0 ? 2 : 1);

                dn.add_edge(u,v,c2);

                if(d <= mid)dn.add_edge(postSource,u,c);
                if(D - d <= mid)dn.add_edge(v,postSink,c);
            }

            for (int i = 1; i <= m ; ++i)
            {
                for(int j = i + 1; j <= m ; j++)
                {

                    int u = nodeMap[1][i];
                    int v = nodeMap[0][j];

                    int d = abs(abs(arr[i]) - abs(arr[j]));

                    int c=1;
                    if(arr[i]<0 && arr[j]<0)c=2;
                    if(d <= mid)dn.add_edge(u,v,c);

                    
                }
            }

            if(dn.flow()!=2)low = mid + 1;
            else up = mid;
        }


        printf("Case %d: %d\n", caseno, low);
    }

    return 0;
}
