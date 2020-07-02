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


int blue[100010];
int blueh[100010];




vector<int> t[4*100000];



void build(int v,int tl,int tr){
  
   if(tl==tr){t[v].pb(blueh[tl]); return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v].assign(t[v*2].size()+t[v*2+1].size(),1);

   merge(all(t[v*2]),all(t[v*2+1]),t[v].begin());

}

void destroy(int v,int tl,int tr){
  
   if(tl==tr){t[v].clear(); return;}

   int mid=(tl+tr)/2;
   destroy(v*2,tl,mid);
   destroy(v*2+1,mid+1,tr);
   
   t[v].clear();

}

 
ll sum(int v, int tl, int tr, int l, int r,int k,bool less) {
    
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
      
       
      if(less){
       auto it=lower_bound(all(t[v]),k);
       if(it==t[v].end())return t[v].size();
       
       if(*it==k)return it-t[v].begin()+1;
       else return it-t[v].begin();  
      }

      auto it=lower_bound(all(t[v]),k);

      if(it==t[v].end())return 0;

      return t[v].size()-(it-t[v].begin());
     
    }

    int tm = (tl + tr) / 2;
    ll q= sum(v*2, tl, tm, l, min(r, tm),k,less)
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r,k,less);

   
    return q;
    
}
 
 

int main() {

    

   int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int n,m;
   cn n>>m;
   vector<pair<int,int>> v(n);

   for (int i = 0; i < n; ++i)
   {
      
     scanf("%d%d",&v[i].fs,&v[i].sc);
   }
    vector<pair<int,int>> bluev(m);

    for (int i = 0; i < m; ++i)
    {
    	scanf("%d%d",&bluev[i].fs,&bluev[i].sc);
    }

    sort(all(bluev));

    for (int i = 0; i < m; ++i)
    {
       blue[i]=bluev[i].fs;
       blueh[i]=bluev[i].sc;
    }

   build(1,0,m-1);
   
   ll ans=0;
   for(auto x: v){
     
     int rdp=x.fs;
     int rdh=x.sc;

     auto it=upper_bound(blue,blue+m,rdp);

     if(it==blue+m){
        ans+=sum(1,0,m-1,0,m-1,rdh,false);   
     	continue;
     }

     int indx=it-blue;
   
     ans+=sum(1,0,m-1,indx,m-1,rdh,true);
     ans+=sum(1,0,m-1,0,indx-1,rdh,false);
    
     
   }

   
    printf("Case %d: %lld\n",caseno,ans);
    destroy(1,0,m-1);
   }





    return 0;
}
