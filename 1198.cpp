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


vector<int> Hungarian(vector<vector<int>> a,bool max){
 // array must be non-negative and 1base inedexed
 
  int n=a.size()-1;
  int m=a[0].size()-1;
  int INF=100000000;

  if(max){
       
     for (int i = 0; i <=n; ++i)
           for(int j=0; j<=m ; j++)
               a[i][j]*=-1;
          

  }
  
  int mn=INF;

   for (int i = 0; i <=n; ++i)
           for(int j=0; j<=m ; j++)
               mn=min(mn,a[i][j]);


   if(mn<0){
        mn=abs(mn);

         for (int i = 0; i <=n; ++i)
           for(int j=0; j<=m ; j++)
               a[i][j]+=mn;

   }
   
  vector<int> u(n+1),v(n+1),p(m+1),way(m+1);

  for (int i = 1; i <=n; ++i)
  {
  	 p[0]=i;
  	 int j0=0;
  	 vector<int> minv(m+1,INF),used(m+1,0);
     int cnt=1;

     do{

          used[j0]=true;
          int i0=p[j0],delta=INF,j1;

          for(int j=1;j<=m;j++)
          	if(!used[j]){

               int cur=a[i0][j]-u[i0]-v[j];
               if(cur<minv[j])
               	minv[j]=cur,way[j]=j0;

               if(minv[j]<delta)
               	    delta=minv[j],j1=j;


          	}

          	for(int j=0;j<=m;j++)
          		if(used[j])
          			u[p[j]]+=delta,v[j]-=delta;
          		else minv[j]-=delta;

          j0=j1;
     }while(p[j0]!=0);

      
      do{

          int j1=way[j0];
          p[j0]=p[j1];
          j0=j1;

      }while(j0);

   }


  
return p;

}

int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
   int n;
   cn n;
   int arr[55],arr2[55];
   for(int i=1;i<=n;i++)cn arr[i];
   for(int i=1;i<=n;i++)cn arr2[i];

   vector<vector<int>> v(n+1,vector<int>(n+1,0));


   for (int i = 1; i <= n; ++i)
   {
   	  for(int j=1; j<=n ; j++){
   	      
   	      if(arr[i]==arr2[j])v[i][j]=1;
   	      else if(arr[i]>arr2[j])v[i][j]=2;
   	  }
   }

   vector<int>p=Hungarian(v,true);
   
   int ans=0;

   for (int i = 1; i <=n; ++i)
   {
   	    int x=v[p[i]][i];
   	    if(x>0)ans+=x;
   }
   
   printf("Case %d: %d\n",caseno,ans);
   }





    return 0;
}
