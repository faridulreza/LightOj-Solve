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

vector<int>adj[10100];
bool vis[10100];
int tin[10100];
int low[10100];
int timer;
unordered_set<int>st;

void dfs(int v,int p=-1){


    vis[v]=true;
    low[v]=tin[v]=timer++;
    int child=0;
    for(int to:adj[v]){
       if(to==p)continue;

       if(vis[to]){
       	   low[v]=min(low[v],tin[to]);
       }
       else{
           dfs(to,v);
           low[v]=min(low[v],low[to]);

           if(low[to]>=tin[v] && p!=-1){
           	st.insert(v);
           }
           child++;

       }


    }


  if(p==-1 && child>1)st.insert(v);
}



int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    int n,m;
    scanf("%d%d",&n,&m);

    for(int j=1; j<=n ; j++){
         adj[j].clear();
         vis[j]=0;
     }
     timer=0;

     for (int i = 0; i < m; ++i)
      {
      	int u,v;
      	scanf("%d%d",&u,&v);
      	adj[u].pb(v);
      	adj[v].pb(u);
      }

      st.clear();
     _1(tin);
     _1(low);
    
     for (int i =1; i <=n; ++i)
     {
     	if(!vis[i])dfs(i);
     }
    
    printf("Case %d: %d\n",caseno,st.size());
    }







    return 0;
}
