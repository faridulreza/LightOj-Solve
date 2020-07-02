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

char grid[25][25];
int dist[25][25];
int n;
bool viss[25][25];
    
void bfs(pair<int,int> &s){
          
      
      queue<pair<int,int>>q;
      q.push(s);
      _0(dist);
      _0(viss);
      
         auto go=[&](pair<int,int> to,pair<int,int> &v){
               
               if(to.fs>=0 && to.fs<n && to.sc>=0&& to.sc<n && !viss[to.fs][to.sc]  && grid[to.fs][to.sc]!='#'){
                   q.push(to);
                   dist[to.fs][to.sc]=dist[v.fs][v.sc]+1;
                   viss[to.fs][to.sc]=true;
               }

         };

      while(!q.empty()){

         pair<int,int> v=q.front();
         q.pop();
         viss[v.fs][v.sc]=true;


         go({v.fs+1,v.sc},v);
         go({v.fs-1,v.sc},v);
         go({v.fs,v.sc+1},v);
         go({v.fs,v.sc-1},v);

      }

}

bool vis[50];
int mt[50];
vector<vector<int>> adj;

bool kuhn(int v){

     if(vis[v])return false;
     vis[v]=true;
     for(int x:adj[v])
        if(mt[x]==-1 || kuhn(mt[x])){
            mt[x]=v;
            return true;
        }

     return false;


}

bool bmb(int graph[][50],int nn,int m,int mxAllowed){
       
   adj.assign(nn,vector<int>());

   for (int i = 0; i < nn; ++i)
   {
       for(int j=0; j<m ; j++){
           if(graph[i][j] && graph[i][j]<=mxAllowed){
            adj[i].pb(j);
           }
       }
   }

   _1(mt);
   int cnt=0;

   for (int i = 0; i < nn; ++i)
   {
       _0(vis);
       if(kuhn(i))cnt++;
   }

  return (cnt==nn);

}



int main() {
    
    #ifdef SAGOR
    freopen("in.txt","r+",stdin);
    freopen("out.txt","w+",stdout);
    #endif
    
    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    scanf("%d",&n);
    vector<pair<int,int>> H,G;
    
    for (int i = 0; i < n; ++i)
    {
        getchar();
        for(int j=0; j<n ; j++){
            char c=grid[i][j]=getchar();
            if(c=='H')H.pb({i,j});
            else if(c=='G')G.pb({i,j});
        }
    }
    
    int hsz=H.size();
    int gsz=G.size();
    
    int arr[hsz][50]={};
    int hc=0;
    int low=1000000,up=-1;
    for(auto h:H){
        bfs(h);
        int gc=0;

        for(auto g:G){
            int mx=arr[hc][gc++]=dist[g.fs][g.sc];
            low=min(low,mx);
            up=max(up,mx);
        }
        hc++;
    }
    
    
    printf("Case %d: ",caseno);
    
    if(up==-1 || !bmb(arr,hsz,gsz,100000)){
        puts("Vuter Dol Kupokat");
        fflush(stdout);    
        continue;
    }
   

    while(low<up){
         
       int mid=(low+up)/2;
       if(!bmb(arr,hsz,gsz,mid))low=mid+1;
       else up=mid;
       
    }

    printf("%d\n",low*2+2);
    
        
    
    }





    return 0;
}


