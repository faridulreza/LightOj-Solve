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

vector<int>primes;
bool flag[100000+10];

void s(){
    
    int n=100000;
    for (ll i = 3; i <=n ; i+=2)
    {
    	if(flag[i])continue;

    	for(ll j=i*i; j<n ; j+=i){
    	    flag[j]=true;
    	}
    }

primes.pb (2);

for (int i = 3; i <=n; i+=2)
{
	if(!flag[i]) primes.pb (i);
}


}
  ull mod=1000000000+7;
ull pp(ull a, ull p){

if(p==1)return (a+1)%mod;

ull x;

if(p%2==0){

x=pp(a%mod,p-1);
x=(1+a*x)%mod;

}
else {

  x=pp((a*a)%mod,p/2);
  x=(x+(a*x)%mod)%mod;

}
return x;


}
int main() {

    int n, m, l;
    
    s();

      int T;
         cn T;
     for(int caseno=1; caseno<=T  ;caseno++){
     vector<pair<int,ull>> v;

     ull inp,p;
     cn inp>>p;
      
     if(p==0){
     printf("Case %d: 1\n",caseno);
     continue;
     }

     for(auto x: primes){
          if(x>inp)break;

          int cnt=0;
          while(inp%x==0){
              inp/=x;
              cnt++;

          }

          if(cnt)v.pb({x,cnt*p});

     }

     if(inp!=1)v.pb({inp,p});

  
     
     

     ull res=1;

     for(auto x: v){
        res=(res*pp(x.fs,x.sc)%mod)%mod;
     }
     
     printf("Case %d: %llu\n",caseno,res);
     v.clear();
    

     
     }




    return 0;
}
