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

int arr[102][102];
int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    int n,m;
    cn n>>m;

    for (int i = 1; i <=n; ++i)
    {
    	for(int j=1; j<=n ; j++){
    	    arr[i][j]=100000000;
    	}
    }


    for (int i = 0; i < m; ++i)
    {
        int u,v,w;
        cn u>>v>>w;
        if(w<arr[u][v])arr[u][v]=arr[v][u]=w;

    }

      for (int i = 1; i <=n; ++i)
      {
      	for(int j=1; j<=n ; j++){
      	    for(int k=1; k<=n ; k++){
      	        
      	        if(arr[j][i]+arr[i][k]<arr[j][k])arr[j][k]=arr[j][i]+arr[i][k];
      	    
      	    }
      	}
      }



    
    if(arr[1][n]==100000000)printf("Case %d: Impossible\n",caseno);
     else printf("Case %d: %d\n",caseno,arr[1][n]);
    }







    return 0;
}
