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


   
class LCA
{

    vector<vector<int>>up;
    vector<int> tin, tout;
    int n;
    int l;
    int timer = 0;
public :
    vector<vector<pair<int,int>>> &adj;

    LCA(int nn, vector<vector<pair<int,int>>> &tadj, int root = 1): adj(tadj)
    {
        n = nn + 1;
        l = ceil(log2(n));
        tin.resize(n);
        tout.resize(n);

        up.assign(n, vector<int>(l + 1));

        dfs(root, root);

    }


    void dfs(int v, int p)
    {

        tin[v] = timer++;
        up[v][0] = p;
        for (int i = 1; i <= l ; ++i)
            up[v][i] = up[ up[v][i - 1] ][i - 1];


        for(auto c : adj[v]){
            if(c.fs != p)dfs(c.fs, v);
          }
        tout[v] = timer++;

    }

    bool is_ancess(int u, int v)
    {

        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {  
        if(is_ancess(u, v))return u;
        if(is_ancess(v, u))return v;
        for (int i = l; i>=0 ; i--)
            if(!is_ancess(up[u][i],v))
                u=up[u][i];
        
        return up[u][0];
    }

};



class HLD{
  //for edge maximum query
  
  vector<int>parent,depth,head,heavy,pos,wts,vAtPos,t;
  int n,timer=0; 
  public : 
  vector<vector<pair<int,int>>> &adj;
  

  HLD(int nn,vector<vector<pair<int,int>>> &tadj,int root=1):adj(tadj){
    int n=nn+1;
    parent.resize(n);
    depth.resize(n);
    head.resize(n);
    pos.resize(n);
    vAtPos.resize(n);
    wts.resize(n);
    t.resize(4*n);
    heavy.assign(n,-1);
    
    dfs(root,parent);
    decompose(root,root);
    build(1,0,timer-1);
  }

  int dfs(int v,vector<int> &parent){
        
        int max_sub=0;
        int sz=1;

        for (auto x: adj[v])
        {   
          int c=x.fs;
          if(c==parent[v])continue;
          wts[c]=x.sc;
            parent[c]=v;depth[c]=depth[v]+1;
            
            int tmp_sub=dfs(c,parent);
            sz+=tmp_sub;

            if(tmp_sub>max_sub){
              max_sub=tmp_sub;
               heavy[v]=c;
            }
        }
       
        return sz;

  }

  void decompose(int v,int h){

       head[v]=h; pos[v]=timer++;vAtPos[pos[v]]=v;

       if(heavy[v]!=-1)decompose(heavy[v],h);

       for(auto c:adj[v]){
         if(c.fs!=parent[v] && c.fs!=heavy[v])decompose(c.fs,c.fs);
       }

  }

  int query(int a,int b){
    
    int res=0;
    while(head[a]!=head[b]) {
        
        if(depth[a]>depth[b])swap(a,b);
        res=max(res,sum(1,0,timer-1,pos[head[b]],pos[b]));

        b=parent[head[b]];

    }

    if(depth[a]>depth[b])swap(a,b);

    res=max(res,sum(1,0,timer-1,pos[a]+1,pos[b]));
    return res;    

  }

  
void build(int v,int tl,int tr){
  
   if(tl==tr){t[v]=wts[vAtPos[tl]]; return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v]=max(t[v*2],t[v*2+1]);


}

 
int sum(int v, int tl, int tr, int l, int r) {
  
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    ll q= max(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
    return q;
    
}
 
};






vector<int>parent,size;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return 1;
    }
    else return 0;
}
using pii=pair<int,pair<int,int>>;

int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
     
     int n,m;
     scanf("%d%d",&n,&m);

     priority_queue<pii>pq;

     for (int i = 0; i < m; ++i)
     {
     	int a,b,c;
     	scanf("%d%d%d",&a,&b,&c);
     	pq.push({-c,{a,b}});
     }

     parent.clear();size.clear();
     parent.resize(n+1);
     size.resize(n+1);
     for (int i = 1; i <=n; ++i)
     {
     	make_set(i);
     }

     vector<vector<pair<int,int>>> adj(n+1);

     while(!pq.empty()){

        int w=pq.top().fs;
        int a=pq.top().sc.fs;
        int b=pq.top().sc.sc;
        pq.pop();
        if(union_sets(a,b)){
          adj[a].pb({b,-w});
          adj[b].pb({a,-w});
        }


     }

     LCA lca(n,adj);
     HLD hld(n,adj);
     printf("Case %d:\n",caseno);
     int q;
     cn q;

     for (int i = 0; i < q; ++i)
     {
     	int a,b;
     	scanf("%d%d",&a,&b);

     	int l=lca.lca(a,b);
     	printf("%d\n", max(hld.query(l,a),hld.query(l,b)));
     }
   }

    return 0;
}
