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

vector<vector<int>> adj;

void bfs(int s,vector<int> &lv){

    fill(all(lv),-1);
    lv[s]=0;

    queue<int> q;
    q.push(s);
    while(!q.empty()){

          int v=q.front();
          q.pop();

          for (int x:adj[v])
          {
          	if(lv[x]==-1){
          		lv[x]=lv[v]+1;
          		q.push(x);
          	}
          }
    }


}
int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
      int n;
      int m;

      scanf("%d%d",&n,&m);
      adj.assign(n,vector<int>());
      
      vector<int> level(n),level2(n);

      for (int i = 0; i < m; ++i)
      {
      	int a,b;
      	cn a>>b;
      	adj[a].pb(b);
      	adj[b].pb(a);
      }
      int s,t;
      cn s>>t;

      bfs(s,level);
      bfs(t,level2);

      int mn=0;

      for (int i = 0; i < n; ++i)
      {
      	mn=max(mn,level2[i]+level[i]);
      }
    printf("Case %d: %d\n",caseno,mn);
    }







    return 0;
}
