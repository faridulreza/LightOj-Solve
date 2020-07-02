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
double _eps = 1e-6;

vector<vector<int>> capacity,adj;
int n;

int bfs(int s,int t,vector<int> &parent){

    fill(all(parent),-1);

    queue<pair<int,int>>q;
    q.push({s,1000000000});

    while(!q.empty()){

         int u=q.front().fs;
         int flow=q.front().sc;
         q.pop();

         for(int v: adj[u]){

         	if(parent[v]==-1 && capacity[u][v]>0){
                
                parent[v]=u;

                int new_flow=min(flow,capacity[u][v]);

                if(v==t)return new_flow;

                q.push({v,new_flow});


         	}
         }



    }

  return 0;
}

int max_flow(int s,int t){
   
   vector<int> parent(n);
   int flow=0,new_flow;


   while(new_flow=bfs(s,t,parent)){

         flow+=new_flow;

         int cur=t;

         while(cur!=s){

         	int prev=parent[cur];
         	capacity[prev][cur]-=new_flow;
         	capacity[cur][prev]+=new_flow;
         	cur=prev;
         }


   }


 return flow;

}


int main()
{

   //ford-fulkerson O(VE^2)


    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
    int s,t,c;

    scanf("%d %d %d %d",&n,&s,&t,&c);

    capacity.assign(n,vector<int>(n,0));
    adj.assign(n,vector<int>(n,0));

    for (int i = 0; i < c; ++i)
    {
    	int a,b,w;
    	scanf("%d%d%d",&a,&b,&w);
    	capacity[--a][--b]+=w;
    	capacity[b][a]+=w;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

   
   printf("Case %d: %d\n",caseno,max_flow(s-1,t-1));
   }





    return 0;
}
