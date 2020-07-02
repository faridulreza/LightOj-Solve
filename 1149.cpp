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
vector<int> mt;
vector<bool>vis;

bool kuhn(int v)
{

    if(vis[v])return false;
    vis[v] = true;

    for(int x : adj[v])

        if(mt[x] == -1 || kuhn(mt[x]))
        {
            mt[x] = v;
            return true;
        }


    return false;

}

int main()
{

    /*
       learn
        * Vertex cover
        * Maximum matching in bipartite graph
        * Kőnig's theorum

        * Kuhn's algorithm for maximum bipartite matching

      ***finding vertex cover ( which vertices to remove)
         L= left side vertices
         R= Right side vertices

         * find vertices of left side which are not in the matching - U
         * find vertices connected to those vertices of U by altering path - Z
         * ans= (L/Z) U (Z cap R)

    */

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int n, m;
        int a[110], b[110];
        cn n;
        for (int i = 0; i < n; ++i)
            cn a[i];

        cn m;
        for (int i = 0; i < m; ++i)
            cn b[i];


        adj.assign(n + 1, vector<int> ());
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m ; j++)
            {

                if(a[i] == 0)
                {
                    if(b[j] == 0)adj[i].pb(j);
                }
                else if(b[j] % a[i] == 0)adj[i].pb(j);
            }
        }

        mt.assign(m + 1, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            vis.assign(n + 1, false);
            if(kuhn(i))ans++;
        }

        printf("Case %d: %d\n", caseno, ans);
    }


    return 0;
}
