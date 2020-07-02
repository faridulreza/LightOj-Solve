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

const int size=10000;
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

deque<int>res,tmp;

void mult(int x){
    auto it=res.end();
    ll c=0;
    while(it!=res.begin()){
         it--;
         ll r=(*it)*x*1ll+c;
         tmp.push_front(r%10);
         c=r/10;
    }
    
    while(c){
        tmp.push_front(c%10);
        c/=10;
    }

    res.assign(all(tmp));
    tmp.clear();
}

int main() {
sieve();
 int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d",&arr[i]);
    }
    res.clear();
    res.pb(1);

    for(int x:primes){
         
         int mx=-1;
         for (int i = 0; i < n; ++i)
         {
         	int c=0;
         	while(arr[i]%x==0){
         		arr[i]/=x;
         		c++;
         	}
         	mx=max(c,mx);
         }
         for (int i = 0; i < mx; ++i)
         {
         	mult(x);
         }
    }
    

    for (int i = 0; i < n; ++i)
    {
        if(arr[i]!=1)mult(arr[i]);
    }

    printf("Case %d: ",caseno);
    for(int c:res)printf("%d",c);nl;

}


    return 0;
}
