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
 
ull mx=100000000000000000;
 
ull arr[1000000+10];
 
int main() {
 
    arr[0]=0;
 
    ull ans=0;
 
    for (int i =1 ; i <=100000000 ; ++i)
    {
        ans+=(mx/i);
        if(i%100==0)arr[i/100]=ans ;
 
 
    }
 
 
 
      int T;
         cn T;
     for(int caseno=1; caseno<=T  ;caseno++){
     ull l;
     scanf("%llu",&l);
     ull x=l/100;
 
     ans=arr[x];
 
     x=x*100+1;
     for (int i = x; i <=l ; ++i)
     {
        ans+=(mx/i);
     }
 
     printf("Case %d: %.10f\n",caseno,ans/(1.00*mx));
     fflush(stdout);
     }
 
 
 
 
 
 
 
    return 0;
}
 