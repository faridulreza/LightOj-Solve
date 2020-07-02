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



vector<int>adj[10000+10];
int vis[10000+10];
int visb[10000+10];


int cur=1;

void dfs(int v){

    vis[v]=cur;
    for(int to:adj[v]){
    	if(vis[to]!=cur)dfs(to);
    }

}

vector<int>order;

void rdfs(int v){

    visb[v]=1;
    for(int to:adj[v]){
    	if(!visb[to])rdfs(to);
    }

    order.pb(v);

}



int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n,m;
    cn n>>m;
     
    cur=1;
    order.clear();
    for (int i = 1; i <= n; ++i)
    {
    	adj[i].clear();
    }  

    for (int i = 0; i < m; ++i)
    {
    	int a,b;
    	scanf("%d %d",&a,&b);
    	adj[a].pb(b);
    }


    

    int cnt=0;
    _0(vis);
    _0(visb);


    for (int i = 1; i <=n; ++i)
    {
    	if(!visb[i]){
    	   rdfs(i);
    	}
    		
    }

    reverse(all(order));

    for (int x:order)
    {
    	if(!vis[x]){
    		dfs(x);
    		cur++;
    		cnt++;
    	}
    }





    
    printf("Case %d: %d\n",caseno,cnt);
    }







    return 0;
}
