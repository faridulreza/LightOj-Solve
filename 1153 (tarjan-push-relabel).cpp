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

vector<vector<int>> capacity, flow;
vector<int> excess, height;
int inf = 1000000000;
int n;

void push(int u, int v)
{

    int c = min(excess[u], capacity[u][v] - flow[u][v]);

    excess[v] += c;
    excess[u] -= c;
    flow[u][v] += c;
    flow[v][u] -= c;

}

void relabel(int u)
{

    int d = inf;
    for(int j = 0; j < n ; j++)
    {
        if(capacity[u][j] - flow[u][j] > 0)d = min(d, height[j]);
    }

    if(d < inf)height[u] = d + 1;

}

vector<int> get_max_height_nodes(int s, int t)
{

    vector<int> rt;
    for (int i = 0; i < n ; ++i)
    {
        if(i != s && i != t && excess[i] > 0)
        {

            if(!rt.empty() && height[i] > height[ rt[0] ])
                rt.clear();
            if(rt.empty() || height[i] == height[rt[0]])
                rt.pb(i);
        }

    }

    return rt;
}

int max_flow(int s, int t)
{

    height.assign(n + 1, 0);
    height[s] = n;

    excess.assign(n + 1, 0);
    excess[s] = inf;

    for (int i = 0; i < n; ++i)
    {
        if(i != s)push(s, i);
    }


    vector<int> current;

    while(!(current = get_max_height_nodes(s, t)).empty())
    {
        
        for(int u : current)
        {
            bool pushed = false;

            for(int v = 0; v < n && excess[u] ; v++)
            {
                if(capacity[u][v] - flow[u][v] > 0 && height[u] == height[v] + 1)
                {
                    push(u, v);
                    pushed = true;
                }

            }

            if(!pushed)
            {
                relabel(u);
                break;
            }
        }
    }

    int fl = 0;
    for (int i = 0; i < n; ++i)
    {
        fl += flow[s][i];
    }

    return fl;
}


int main()
{

    //push-relabel O(V^2 . sqrt(E)) / O(V^3)
    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
    int s,t,c;

    scanf("%d %d %d %d",&n,&s,&t,&c);

    capacity.assign(n,vector<int>(n,0));
    flow.assign(n,vector<int>(n,0));

    for (int i = 0; i < c; ++i)
    {
    	int a,b,w;
    	scanf("%d%d%d",&a,&b,&w);
    	capacity[--a][--b]+=w;
    	capacity[b][a]+=w;
    }

   
   printf("Case %d: %d\n",caseno,max_flow(s-1,t-1));
   }





    return 0;
}
