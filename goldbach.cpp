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

const int size=10000010;
vector<int>primes;
bool mark[size+5];
void sieve(){

     for(ll i=3; i<=size;i+=2){
        if(mark[i])continue;
         for(ll j=i*i;j<=size; j+=i){
         	mark[j]=true;
         }
     }

     primes.pb(2);
     for (int i = 3; i <=size; i+=2)
     {
     	if(!mark[i])primes.pb(i);
     }

}


int main() {
    
sieve();

 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){

ll n;
cn n;
ll to=n/2;
int c=0;

for(int x:primes){
     if(x>to)break;
    // _(n-x);
    if( ((n-x)&1ll ||(n-x==2)) && !mark[n-x])c++;
}


printf("Case %d: %d\n",caseno,c);
}



    return 0;
}
