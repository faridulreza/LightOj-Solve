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
double _eps = 1e-6;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
string a, b;
ll ans;
ll dp2[31][31][65];
 
ll un(int ai,int bi,int num){
   
   if(dp2[ai][bi][num]!=-1)return dp2[ai][bi][num];
 
    if(ai>=a.size()){
      if(num+b.size()-bi==ans)return 1;
      else return 0;
   }
 
    if(bi>=b.size()){
      if(num+a.size()-ai==ans)return 1;
      else return 0;
   }
   
   ll an=0;
   if(a[ai]==b[bi])an=un(ai+1,bi+1,num+1);
   else an=un(ai+1,bi,num+1)+un(ai,bi+1,num+1);
 
   return dp2[ai][bi][num]=an;
 
}
 
 
#define vp vector<pair<int,int>>
vector<pair<int,int>> dp[40][40];
 
 
vp f(int ai, int bi)
{
    if(dp[ai][bi].size())return dp[ai][bi];
 
    if(a.size() <= ai || b.size() <= bi){
        vp x;
        return x;
    }
 
    vp cnt;
 
    for(int j = ai; j < a.size() ; j++)
    {
        for (int i = bi; i < b.size(); ++i)
 
        {
         
            if(a[j] == b[i])
            {
                vp x;
                x.pb({j,i});
               
                vp y=f(j+1,i+1);
                for(auto tm:y)x.pb(tm);
               
                if(x.size()>cnt.size())cnt=x;
 
            }
        }
    }
    dp[ai][bi]=cnt;
 
    return cnt;
}
 
 
 
int main()
{
 
    int T;
    cn T;
    getchar();
 
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
 
 
        cn a >> b;
       
        for (int i = 0; i <30; ++i)
        {
            for(int j=0; j<30 ; j++){
                dp[i][j].clear();
            }
        }
 
       
 
        vp r=f(0, 0);
        ans=a.size()+b.size()-r.size();
        _1(dp2);
 
       
        ll an=un(0,0,0);
 
        printf("Case %d: %lld %lld\n",caseno,ans,an);
 
    }
 
 
 
 
 
 
 
    return 0;
}