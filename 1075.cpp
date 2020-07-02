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

map<int,string>is;
map<string ,int>si;

vector<int> adj[500];
vector<int> order;

bool vis[500];

void dfs(int v){

   vis[v]=1;
//   _(v);
   for(int x:adj[v])if(!vis[x])dfs(x);

    order.pb(v);

}


int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    is.clear();     
    si.clear();
    order.clear();     

    int n;
    cn n;
    int cnt=1;
    for (int i = 0; i < n-1; ++i)
    {
      string a,b;
      cn a>>b;

      int u,v;

      if(si.count(a)){
        u=si[a];
      }
      else{
        u=cnt++;
        si[a]=u;
        is[u]=a;
      }

      if(si.count(b)){
        v=si[b];
      }
      else{
        v=cnt++;
        si[b]=v;
        is[v]=b;

      }

      adj[u].pb(v);


    }

    _0(vis);

    for(int i=1;i<cnt;i++){
      if(!vis[i])dfs(i);
    }

    reverse(all(order));
     
     printf("Case %d:\n",caseno);
    for(int x:order){
      
       ct is[x];nl;
    }nl;

    for (int i = 1; i <cnt; ++i)
    {
      adj[i].clear();
    }



    
    
    }







    return 0;
}
