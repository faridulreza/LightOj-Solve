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
 
 
 ll md(int p,int m){
    if(p==0)return 1;
    ll x=md(p/2,m);
    if(p&1){
        x=(x*x*10)%m;
    }
    else {
        x=(x*x)%m;
       
    }
    return x;
 
 }
 
 int main() {
 
     
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n,dig;
    cn n>>dig;
    ll res=0;
    for (int i = 0; i <2*n; ++i)
    {
        res=(res+md(i,n)*dig)%n;
        if(res==0){
        printf("Case %d: %d\n",caseno,i+1);
        break;        
        }
    }
   
   
   
    }
 
 
 
     return 0;
 }
 