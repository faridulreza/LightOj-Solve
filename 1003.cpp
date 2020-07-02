#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) puts("FLAG " #x);
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
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


map<string,int>mp;
vector<int>adj[10100],topo[2];
int deg[10100];
bool vis[10100];




int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
   int m;
   cn m;
   _0(deg);
   int cnt=1;
   for (int i = 0; i < m; ++i)
   {
     string a,b;
     cn a>>b;

     int u,v;
     if(mp.count(a))u=mp[a];
     else {
        u=cnt;
        mp [a]=cnt++;
     }

     if(mp.count(b))v=mp[b];
     else {
        v=cnt;
        mp[b]=cnt++;
     }


     adj[u].pb(v);
     deg[v]++;
   }

   
   _0(vis);
   topo[0].clear();
   topo[1].clear();

   for (int i = 1; i <cnt; ++i)
   {
     if(deg[i]==0)topo[0].pb(i);
   }

   
   int cur=0;

   while(!topo[cur].empty()){

        for (int x:topo[cur])
        {
           vis[x]=1;

           for (int u:adj[x])
           {
             deg[u]--;
             if(deg[u]==0 && !vis[u])topo[cur^1].pb(u);
           }
        }

        topo[cur].clear();
        cur^=1;

  }

  int count=0;
  for (int i = 1; i < cnt; ++i)
  {
    count+=vis[i];
  }


   
  if(count==cnt-1)printf("Case %d: Yes\n",caseno);
  else printf("Case %d: No\n",caseno);





   for (int i = 1; i <=cnt ; ++i)
   {
     adj[i].clear();
   }
   mp.clear();
   
   }





    return 0;
}
