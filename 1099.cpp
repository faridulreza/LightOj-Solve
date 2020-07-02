
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
double _eps=1e-6;

vector<pair<int,int>> adj[5010];

void dijkstra(int s, vector<int> & d, vector<int> & d2,int n) {
    
    const int INF = 1000000000;	
    d.assign(n, INF);
    d2.assign(n, INF);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d2[v]<d_v)
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            int dst=d_v + len;

            if (dst < d[to]) {
                swap(d[to] , dst);
                q.push({d[to], to});
            }

            if(dst<d2[to] && dst!=d[to]){
            	
            	d2[to]=dst;
            	q.push({d2[to],to});
            }
        }
    }
}


int main() {

    

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    int n,r;
    cn n>>r;

    for (int i = 0; i <=n; ++i)
    {
    	adj[i].clear();
    }

    for (int i = 0; i < r; ++i)
    {
    	int a,b,c;
    	scanf("%d%d%d",&a,&b,&c);
    	adj[a].pb({b,c});
    	adj[b].pb({a,c});
    }
     
     vector<int> d1,d2;

     dijkstra(1,d1,d2,n+1);
    
    printf("Case %d: %d\n",caseno,d2[n]);
    }





    return 0;
}
