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
 
int n;
int dp[51][1010];
int arr[55];
int cnt[55];
int md=100000007;
 
 
ll cng(int i,int s){
 
if (dp[i][s]!=-1)return dp[i][s];
 
 
ll ans=0;
 
for (int j = 0; j <=cnt[i] && j*arr[i]<=s; ++j)
{
    ans+=cng(i-1,s-j*arr[i]);
    ans%=md;
}
 
return dp[i][s]=ans;
 
}
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int k;
    scanf("%d%d",&n,&k);
 
    for (int i = 1; i <=n; ++i)
    {
        scanf("%d",&arr[i]);
    }
 
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d",&cnt[i]);
    }
    _1(dp);
    _0(dp[0]);
    dp[0][0]=1;
 
    printf("Case %d: %d\n",caseno,cng(n,k));
    }
 
 
 
 
 
 
 
    return 0;
}
 