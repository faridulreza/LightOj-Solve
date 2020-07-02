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

#define pii pair<int,pair<int,int>>
priority_queue<pii,vector<pii>,greater<pii>>pq;


int parent[10100];
int size[10100];

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


pair<int,int> mst(int n,int air){


   for (int i = 1; i <=n; ++i)
   {
   	make_set(i);
   }

   pair<ll,ll> res(1ll*n*air,n);

   int sets=n;
   ll cost=0;
   while(!pq.empty()){

         pii u=pq.top();

         pq.pop();

         if(union_sets(u.sc.fs,u.sc.sc)){
            sets--;
            cost+=u.fs;

            ll tmpcost=cost+sets*air;
            if(res.fs==tmpcost){
            	if(sets>res.sc)res={tmpcost,sets};
            }
            else if(tmpcost<res.fs)res={tmpcost,sets};
         }

   }


  return res;
}



int main() {

    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
   int n,m,a;

   scanf("%d%d%d",&n,&m,&a);

   for (int i = 0; i <m; ++i)
   {
   	  int u ,v,w;
      
      scanf("%d%d%d",&u,&v,&w);
      pq.push({w,{u,v}});
   }

   pair<ll,int> res=mst(n,a);
   
   printf("Case %d: %lld %d\n",caseno,res.fs,res.sc);
   }





    return 0;
}
