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

string a,b,c;
int n,m,l;
int dp[52][52][52];

int f(int i,int j,int k){
   
   if(i>=n || j>=m || k>=l)return 0;
   if(dp[i][j][k]!=-1)return dp[i][j][k];
   int ans=0;
   if(a[i]==b[j] && b[j]==c[k])ans=f(i+1,j+1,k+1)+1;

   ans=max(ans,f(i,j,k+1));
   ans=max(ans,f(i,j+1,k));
   ans=max(ans,f(i+1,j,k));

   return dp[i][j][k]=ans;

}

int main() {

    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
    cn a;
    cn b;
    cn c;

    n=a.size();
    m=b.size();
    l=c.size();
     _1(dp);
    printf("Case %d: %d\n",caseno,f(0,0,0));
   }





    return 0;
}
