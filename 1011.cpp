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
 
int arr[20][20];
int n;
 
ll m=0;
int mp[66000];
 
 
int f(int i){
 
  if(i>=n)return 0;
  if(mp[m]!=-1)return mp[m];
 
 
 
   int mx=-1;
   for(int j=0; j<n ; j++){
       
       if(!(m & 1ll<<j)){
        m=st(m,j);
        int tm=f(i+1)+arr[i][j];
        mx=max(tm,mx);
        m=unst(m,j);
       }
   }
   mp[m]=mx;
   return mx;
 
 
}
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
   
    cn n;
    for (int i = 0; i < n; ++i)
    {
        for(int j=0; j<n ; j++){
            cn arr[i][j];
        }
    }
 
 
    _1(mp);
   
    printf("Case %d: %d\n",caseno,f(0));
    }
 
 
 
 
 
 
    return 0;
}
 
