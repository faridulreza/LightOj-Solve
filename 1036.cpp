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
int uri[510][510];
int radi[510][510];
int dp[510][510];
int n,m;

int f(int col,int row){

if(col>m)return 0;

if(dp[col][row]!=-1)return dp[col][row];


int ret=0;
for (int i = row; i <=n+1; ++i)
{
	
    int tm=uri[i][col]+radi[i-1][col]+f(col+1,i);

    ret=max(ret,tm);
}

return dp[col][row]=ret;

}



int main() {

    



    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   scanf("%d%d",&n,&m);
   

   for (int i = 1; i <=m; ++i)
   {
   	 uri[n+1][i]=0;
   	 radi[n+1][i]=0;
   }
   
   for (int i = 1; i <= n; ++i)
   {
     for(int j=1; j<=m ; j++){
         scanf("%d",&uri[i][j]);
     }
   }

   for (int i = 1; i <= n; ++i)
   {
     for(int j=1; j<=m ; j++){
         scanf("%d",&radi[i][j]);
     }
   }


   for(int j=1; j<=m; j++){
       
      for (int i = 1; i <=n; ++i)
      {
      	radi[i][j]+=radi[i-1][j];
      }

   }
  
  for(int j=1; j<=m; j++){
       
      for (int i = n; i >0; i--)
      {
      	uri[i][j]+=uri[i+1][j];
      }

   }

   

  // for (int i = 1; i <=n; ++i)
  // {
  // 	/* code */
  // 	for(int j=1; j<=m ; j++){
  // 	    ct uri[i][j]<<" ";
  // 	}nl;
  // }nl;nl;
  // for (int i = 1; i <=n; ++i)
  // {
  // 	/* code */
  // 	for(int j=1; j<=m ; j++){
  // 	    ct radi[i][j]<<" ";
  // 	}nl;
  // }nl;nl;

  _1(dp);

   
   printf("Case %d: %d\n",caseno,f(1,1));
   }



    return 0;
}
