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

vector<vector<int>> flow, capacity;
vector<int>excess, height;
int inf = 100000000;
int n;
void push(int u, int v)
{

    int c = min(excess[u], capacity[u][v] - flow[u][v]);

    flow[u][v] += c;
    flow[v][u] -= c;
    excess[u] -= c;
    excess[v] += c;

}

void relabel(int u)
{

    int d = inf;

    for (int i = 0; i < n; ++i)
    {
        if(excess[u] && capacity[u][i] - flow[u][i] > 0)d = min(d, height[i]);
    }

    if(d < inf)height[u] = d + 1;
}

vector<int> get_max(int s, int t)
{

    vector<int> rt;

    for (int i = 0; i < n; ++i)
    {
        if(i != s && i != t && excess[i])
        {
            if(!rt.empty() && height[i] > height[rt[0]])rt.clear();
            if(rt.empty() || height[i] == height[rt[0]])rt.pb(i);
        }
    }

    return rt;

}


int maxflow(int s, int t)
{


    excess.assign(n, 0);
    height.assign(n, 0);

    height[s] = n;
    excess[s] = inf;

    for (int i = 0; i < n; ++i)
        if(i != s)push(s, i);

    vector<int>cur;

    while(!(cur = get_max(s, t)).empty())
    {

        for(int i : cur)
        {


            bool pushed = false;
            for (int j = 0; j < n && excess[i]; ++j)
            {
                if(capacity[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1)
                {
                    push(i, j);
                    pushed = true;
                }
            }

            if(!pushed)
            {
                relabel(i);
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


    map<string, int>mp;
    mp["XXL"] = 0;
    mp["XL"] = 1;
    mp["L"] = 2;
    mp["M"] = 3;
    mp["S"] = 4;
    mp["XS"] = 5;

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int nn, m;
        scanf("%d %d", &nn, &m);

        n = 6 + m + 2 + 5;
        capacity.assign(n, vector<int>(n, 0));
        flow.assign(n, vector<int>(n, 0));


        for (int i = 6; i < m + 6; ++i)
        {
            string a, b;
            cn a >> b;
            capacity[i][ mp[a] ] = 1;
            capacity[i][ mp[b] ] = 1;

        }

        int s = m+6+1, t = m+6+2;
        //_(s);_(t);
        for (int i = 0; i < 6; ++i)
        {
            capacity[i][t] = nn;
        }

        for (int i = 6; i < m + 6 ; ++i)
        {
            capacity[s][i] = 1;
        }


        int fl = maxflow(s, t);
        //_(fl);
        if(fl == m)printf("Case %d: YES\n", caseno);
        else printf("Case %d: NO\n", caseno);
    }






    return 0;
}
