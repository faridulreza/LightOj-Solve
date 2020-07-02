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
   


   
   class HLD{
     //for edge maximum query
     
     vector<int>parent,depth,head,heavy,pos,vAtPos,t;
     int n,timer=0; 
     public : 
     vector<vector<int>> &adj;
     vector<int> &wts;
     
   
     HLD(int nn,vector<vector<int>> &tadj,vector<int> &wt,int root=1):adj(tadj),wts(wt){
       int n=nn+1;
       parent.resize(n);
       depth.resize(n);
       head.resize(n);
       pos.resize(n);
       vAtPos.resize(n);
       t.resize(4*n);
       heavy.assign(n,-1);
       
       dfs(root,parent);
       decompose(root,root);
       build(1,0,timer-1);
     }
   
     int dfs(int v,vector<int> &parent){
           
           int max_sub=0;
           int sz=1;
   
           for (auto c: adj[v])
           {   
            
             if(c==parent[v])continue;

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
            if(c!=parent[v] && c!=heavy[v])decompose(c,c);
          }
   
     }
   
     int query(int a,int b,int k){
       
       int res=0;
       while(head[a]!=head[b]) {
           
           if(depth[a]>depth[b])swap(a,b);
           int tmp=greatest(1,0,timer-1,pos[head[b]],pos[b],k);
           if(tmp!=-1)res=tmp;
           b=parent[head[b]];
   
       }
   
       if(depth[a]>depth[b])swap(a,b);
   
       int tmp=greatest(1,0,timer-1,pos[a],pos[b],k);
       if(tmp!=-1)res=tmp;
       return res;    
   
     }
   
     
   void build(int v,int tl,int tr){
     
      if(tl==tr){t[v]=wts[vAtPos[tl]]; return;}
   
      int mid=(tl+tr)/2;
      build(v*2,tl,mid);
      build(v*2+1,mid+1,tr);
   
      t[v]=max(t[v*2],t[v*2+1]);
   
   
   }
   
   //finding first wts[v]>=k in l r
   // as hld query will be from same set
   // the less positioned vertex in a set will have less depth

   int greatest(int v, int tl, int tr, int l,int r, int k) {
       
      if(tl>r || tr<l)return -1;

      if(l<=tl && tr<=r){

         if(t[v]<k)return -1;
         //ct tl spc tr;nl;
         while(tl!=tr){

             int mid=tl+(tr-tl)/2;
            // _(tl);
            // _(tr);
            // _(mid);
           //  nl;
             if(t[v*2]>=k){
             	v=v*2;
             	tr=mid;
             }
             else {
             	v=v*2+1;
             	tl=mid+1;
             }

         }

        return vAtPos[tl];

      }



      int mid=(tl+tr)/2;
      int rs=greatest(v*2,tl,mid,l,r,k);
      if(rs!=-1)return rs;
      return greatest(v*2+1,mid+1,tr,l,r,k);
   }
    
    
    
   };
   
   


int main() {

    vector<vector<int>> adj;
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   adj.clear();
   int n,q;
   scanf("%d%d",&n,&q);
   adj.assign(n,vector<int>());
   vector<int> wts(n);
   wts[0]=1;

   for (int i = 1; i < n; ++i)
   {
     	int a,b;
     	scanf("%d%d",&a,&b);
     	adj[i].pb(a);
     	adj[a].pb(i);
     	wts[i]=b;

   }

   HLD hld(n,adj,wts,0);


   printf("Case %d:\n",caseno);
   for (int i = 0; i < q; ++i)
   {
   	 int a,k;
     scanf("%d%d",&a,&k);
     printf("%d\n", hld.query(0,a,k));
   }
   
   
   }






    return 0;
}
