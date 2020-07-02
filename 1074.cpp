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

ll dist[202][202];
ll inf=1000000000000000000;

int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
    ll arr[202];
    int n;
    cn n;
    for (int i = 1; i <=n; ++i)
    {
    	/* code */cn arr[i];
    }

    for (int i = 1; i <=n; ++i)
    {
    	for(int j=1; j<=n ; j++)dist[i][j]=inf;
    }

    int m;
    cn m;
    for (int i = 0; i < m; ++i)
    {
    	int a,b;
    	cn a>>b;
    	ll dif=arr[b]-arr[a];

    	dist[a][b]=dif*dif*dif;

    }

    for (int k = 1; k <=n; ++k)
    {
      for(int i=1; i<=n ; i++){
          for(int j=1; j<=n ; j++){
              
              if(dist[i][k]!=inf && dist[k][j]!=inf){
              	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
              }    
          
        }
      }
    }

   for (int k = 1; k <=n; ++k)
    {
      for(int i=1; i<=n ; i++){
          for(int j=1; j<=n ; j++){
              
              if(dist[i][k]!=inf && dist[k][j]!=inf){
              	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
              }    
          
        }
      }
    }
    int q;
    cn q;

   
     printf("Case %d:\n",caseno);
     for (int i = 0; i < q; ++i)
     {
     	int a;
     	cn a;
     
     	((dist[1][a]==inf || dist[1][a]<3)?(ct '?'):ct dist[1][a]);nl;
     }
   }



    return 0;
}
