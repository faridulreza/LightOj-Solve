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
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int arr[120];
int n,w,k;
 
int dp[110][110];
 
int f(int i,int c){
 
    if(i>=n)return 0;
    if(c>=k)return 0;
    if(dp[i][c]!=-1)return dp[i][c];
   
   
   
    int st =arr[i];
    int j=i,ini=i;
    while(j< n && arr[j]==st)j++;
    int x=f(j,c);
   
    ll ed=arr[i]+w;
    int cnt=0;
    for (; i  < n && arr[i]<=ed; ++i)cnt++;
    int y=f(i,c+1)+cnt;
 
    x=max(x,y);
 
    return dp[ini][c]=x;
 
}
 
 
int main() {
 
 
    #ifdef SAGOR
    freopen("in.txt","r+",stdin);
    freopen("out.txt","w+",stdout);
    #endif
   
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    cn n>>w>>k;
 
    for (int i = 0; i < n; ++i)
    {
        int x,y;
        cn x>>y;
        arr[i]=y;
    }
 
    sort(arr,arr+n);
 
   
    _1(dp);
   
    printf("Case %d: %d\n",caseno,f(0,0));
    }
 
 
 
 
 
 
 
    return 0;
}