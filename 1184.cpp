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

bool vis[60];
int mt[60];

vector<vector<int>>adj;

bool kuhn(int v){

     if(vis[v])return false;
     vis[v]=true;

     for(int x: adj[v])
     	if(mt[x]==-1 || kuhn(mt[x])){
     		mt[x]=v;
     		return true;
     	}
    return false;

}


struct D{
	int a,b,c;
};

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
      
      int n,m;

      scanf("%d %d",&n,&m);
      
      D arr[n+1];
      D arr2[m+1];

      for (int i = 0; i < n; ++i)
      {
      	scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
      }
      for (int i = 0; i < m; ++i)
      {
      	scanf("%d %d %d",&arr2[i].a,&arr2[i].b,&arr2[i].c);
      }

      adj.assign(n+1,vector<int>());

      for (int i = 0; i < n; ++i)
      {
      	for(int j=0; j<m ; j++){
      	    
      	    if(abs(arr[i].a-arr2[j].a)<=12 && abs(arr[i].b-arr2[j].b)<=5 && arr[i].c==arr2[j].c){

      	    	adj[i].pb(j);
      	    }
      	}
      }

      int cnt=0;
      _1(mt);
      for (int i = 0; i < n; ++i)
      {
      	   _0(vis);
      	   if(kuhn(i))cnt++;

      }
    
     printf("Case %d: %d\n",caseno,cnt);
    }







    return 0;
}
