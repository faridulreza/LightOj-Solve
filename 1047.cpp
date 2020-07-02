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
 
int arr[22][4];
int n;
 
int mp[22][4];
 
 
int f(int i,int priv){
if(i>=n)return 0;
if(mp[i][priv]!=-1)return mp[i][priv];
 
int mx=100000000;
for(int j=0; j<3 ; j++){
      if(j!=priv){
        int tm=f(i+1,j)+arr[i][j];
         mx=min(mx,tm);
      }      
  }
 
 
 
  if(priv==3)return mx;
 
  return mp[i][priv]=mx;  
 
}
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
   
    cn n;
    for (int i = 0; i < n; ++i)
    {
        for(int j=0; j<3 ; j++){
            cn arr[i][j];
        }
    }
 
 
    _1(mp);
    int x=f(0,3);
 
    printf("Case %d: %d\n",caseno,x);
    }
 
 
 
 
 
 
    return 0;
}
 