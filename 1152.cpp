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
bool vis[500];

bool kuhn(int v){

     if(vis[v])return false;
     vis[v]=true;
     for(int x:adj[v])
     	if(mt[x]==-1 || kuhn(mt[x])){
     		mt[x]=v;
     		return true;
     	}

     return false;

}



int main()
{

    /**
       if we could somehow maximize the number of gold cells that  can be covered
       by non-intersecting domino we would get our ans


       construct a graph using each gold cell as a node.
       there is a directed edge between two node if they are adjacent to each other

       Now if we find the maximum matching in this graph (learn bipartite matching , kuhn algorithm)
         the matching number is the domino that we need to cover the matched vertecies
         so ans should be = total gold cell- maximum matching


       as we are finding maximum matching in undirected graph
       the maximum
       matching number found by the kuhn algorithm would be twice as the actual matching


     **/

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        char grid[n][m];
        vector<vector<int>> node (n,vector<int>(m));
        int cnt = 0;
        
        for (int i = 0; i < n; ++i)
        {
            getchar();
            for(int j = 0; j < m ; j++)
            {
                char c = grid[i][j] = getchar();
                if(c == '*')node[i][j] = ++cnt;
            }
        }

       


        adj.assign(cnt+1,vector<int>());
        mt.assign(cnt+1,-1);

        auto go=[&](pair<int,int>f,int x,int y){
             if(x>=0 && x<n && y>=0 && y<m && node[x][y]){
                 adj[ node[f.first][f.second] ].pb( node[x][y] );
             }
        };

        for (int i = 0; i < n; ++i)
            for(int j = 0; j < m ; j++)
                if(node[i][j])
                {
                  pair<int,int> p={i,j};
                  go(p,i+1,j);
                  go(p,i-1,j);
                  go(p,i,j+1);
                  go(p,i,j-1);
                  
                }

        int matching=0;
        for (int i = 1; i <=cnt ; ++i)
        {
              _0(vis);
              if(kuhn(i))matching++;        	
        }

        matching/=2;


        printf("Case %d: %d\n",caseno,cnt-matching);
    }

    return 0;
}

