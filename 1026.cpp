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

vector<int>adj[100000+10];
vector<pair<int,int>>bridge;
bool vis[100000+10];


int tin[100000+10];
int low[100000+10];
int timer=1;


void dfs(int v,int p=-1){

   vis[v]=1;
   tin[v]=low[v]=timer++;

   for(int to:adj[v]){

   	  if(to==p)continue;

      if(vis[to]){

      	low[v]=min(low[v],tin[to]);

      }
      else {
          
          dfs(to,v);

          low[v]=min(low[v],low[to]);

          if(low[to]>tin[v]){
          	bridge.pb({min(to,v),max(to,v)});
          }

      }



   }    




}




int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
     int n;
     cn n;
     
     bridge.clear();
     timer=1;
     for (int i = 0; i < n; ++i)
     {
     	adj[i].clear();
     	vis[i]=false;
     }

     for (int i = 0; i < n; ++i)
     {
     	int u,cnt;
     	scanf("%d (%d)",&u,&cnt);
     
     	for(int j=0; j<cnt ; j++){
     	    int v;
     	    scanf("%d",&v);
     	    adj[u].pb(v);
     	}

     }


     for (int i = 0; i < n; ++i)
     {
     	if(!vis[i])dfs(i);
     }

     sort(all(bridge));

    printf("Case %d:\n%d critical links\n",caseno,bridge.size());

    for(auto x:bridge){

    	printf("%d - %d\n",x.fs,x.sc);
    }


    }







    return 0;
}
