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

char grid[15][15];
bool vis[15][15];

int n,m;
using pi=pair<int,int>;


bool go(pi fr,int xp,int yp,pi &to){

   fr.fs+=xp;
   fr.sc+=yp;

   if(fr.fs>0 && fr.fs<=n && fr.sc>0 && fr.sc<=m && grid[fr.fs][fr.sc]=='.' && !vis[fr.fs][fr.sc]){
   	to=fr;
   	return true;
   }
   return false;

}
int dst(pi a, pi b){

    int dist[15][15];

    for (int i = 0; i <15; ++i)
    {
    	for (int  j= 0; j< 15; ++j)
    	{
    		dist[i][j]=100000000;
    	}
    }
    _0(vis);

    queue<pi>q;
    q.push(a);
    dist[a.fs][a.sc]=0;
    while(!q.empty()){
       
       pi u=q.front();
       q.pop();
       
       vis[u.fs][u.sc]=true;
       pi to;
       auto update=[&](){
       	     q.push(to);
             dist[to.fs][to.sc]=min(dist[to.fs][to.sc],1+dist[u.fs][u.sc]);
         };

       if(go(u,0,1,to))update();
       if(go(u,0,-1,to))update();
       if(go(u,1,0,to))update();
       if(go(u,-1,0,to))update();

    }
    

	return (dist[b.fs][b.sc]==100000000?-1:dist[b.fs][b.sc]);
}



int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    
    cn n;
    m=n;
    
    pi arr[30];
    int cnt=0;

    for (int i = 1; i <=n; ++i)
         for(int j=1; j<=n ; j++){
             cn grid[i][j];
             char c=grid[i][j];
             if(c>='A' && c<='Z'){
             	arr[c-'A']={i,j};
             	cnt++;
             }
         }

     int res=0;
     pi from=arr[0];
     grid[from.fs][from.sc]='.';

     for (int i = 1; i <cnt; ++i)
     {
         grid[arr[i].fs][arr[i].sc]='.';
         int tmp=dst(from,arr[i]);
         if(tmp==-1){res=-1;break;}
         
         res+=tmp;
         from=arr[i];
     }
     
     if(res==-1)printf("Case %d: Impossible\n",caseno);
     else printf("Case %d: %d\n",caseno,res);
    }







    return 0;
}
