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

int person[100000+10];
bool vis[100000+10];
vector<vector<int>>adj;
int kcnt;

void dfs(int v){

    kcnt+=person[v];
	vis[v]=true;
	for(int x:adj[v])if(!vis[x])dfs(x);
}

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int k,n,m;
    cn k>>n>>m;
    _0(person);
    for (int i = 0; i < k; ++i)
    {
    	int a;
    	scanf("%d",&a);
    	person[a]++;
    }
    adj.clear();
    adj.assign(n+1,vector<int>());

    for (int i = 0; i < m; ++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[b].pb(a);
    }
    
    int cnt=0;
    for (int i = 1; i <= n; ++i)
    {
    	kcnt=0;
    	_0(vis);
    	dfs(i);
    	if(kcnt==k)cnt++;
    }

    
    printf("Case %d: %d\n",caseno,cnt);
    }







    return 0;
}
