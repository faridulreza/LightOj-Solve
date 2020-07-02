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


int dp[110][110][2];
int arr[110];

int f(int i,int j,int a){
   
   if(i>j)return 0;
   if(j<i)return 0;

   if(dp[i][j][a])return dp[i][j][a];


   if(a){
       
       int res=-1000000000;
       int sm=0;
       for(int l=i;l<=j;l++){
          sm+=arr[l];
          res=max(res,sm+f(l+1,j,0));
       }
       sm=0;
       for(int l=j;l>=i;l--){
         sm+=arr[l];
         res=max(res,sm+f(i,l-1,0));
       }
      return dp[i][j][a]=res;
   }

   else {
      
       int res=1000000000;
       int sm=0;
       for(int l=i;l<=j;l++){
          sm+=arr[l];
          res=min(res,-sm+f(l+1,j,1));
       }
       sm=0;
       for(int l=j;l>=i;l--){
         sm+=arr[l];
         res=min(res,-sm+f(i,l-1,1));
       }
      return dp[i][j][a]=res;
   }


}


int main() {

    


 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
int n;
cn n;
for (int i = 0; i < n; ++i)
{
	/* code */
	cn arr[i];
}
_0(dp);

printf("Case %d: %d\n",caseno,f(0,n-1,1));
}




    return 0;
}
