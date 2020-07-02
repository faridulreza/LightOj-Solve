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
#define st(x,i) (x | (1ll<<i) )
#define unst(x,i) ((~st(0,i))&x)
 
int arr[1100];
int n;
int dp[1100][2];
 
int f(int i,int st){
 
    if(i+st>=n)return 0;
    if(dp[i][st]!=-1)return dp[i][st];
 
    //_(i);
 
 
    if(i==0){
 
       int x=f(i+1,0);
       int y=f(i+2,1)+arr[i];
       
       return max(x,y);
 
    }
 
    int x=max(f(i+1,st),f(i+2,st)+arr[i]);
 
  //  _(x);
    return dp[i][st]=x;
 
 
 
}
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
   
    cn n;
    for (int i = 0; i < n; ++i)
    {
       cn arr[i];
    }
 
 
    _1(dp);
    int x=f(0,0);
 
    printf("Case %d: %d\n",caseno,x);
    }
 
 
 
 
 
 
    return 0;
}
 
