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

vector<int>adj[120];

int path[120][120];
bool vis[120];

void dfs(int v,int &a,int &b,int &last){

    vis[v]=1;
    
    int l=1;
    for(int x:adj[v]){

        if(!vis[x]){
            if(path[v][x]<0)b+=path[v][x];
            else a+=path[v][x];
            dfs(x,a,b,last);
            l=0;
        }
    }

    if(l)last=v;

}

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    cn n;

    for (int i = 0; i <=n; ++i)
    {
        adj[i].clear();
    }

    _0(path);
    _0(vis);

    for (int i = 0; i < n; ++i)
    {
        int a,b,c;
        cn a>>b>>c;

        path[a][b]=c;
        path[b][a]=-c;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int a=0,b=0,last;


    dfs(1,a,b,last);

    if(path[last][1]<0)b+=path[last][1];
    else a+=path[last][1];





    
    printf("Case %d: %d\n",caseno,min(a,abs(b)));
    }







    return 0;
}
