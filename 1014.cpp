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
 
 
const int size = 100000;
vector<int>primes;
bool mark[size + 5];
void sieve()
{
 
    for(ll i = 3; i <= size; i += 2)
    {
        if(mark[i])continue;
        for(ll j = i * i; j <= size; j += i)
        {
            mark[j] = true;
        }
    }
 
    primes.pb(2);
    for (int i = 3; i <= size; i += 2)
    {
        if(!mark[i])primes.pb(i);
    }
 
}
 
 
 
 
 
 
int main()
{
 
 
    sieve();
 
    // ct primes.size();
 
       // printf("Case %d: %lld\n", caseno,ans);
 
    int caseno=1;
 
       int t;
       cn t;
       for(;caseno<=t;caseno++)
{
    ll n,t;
    cn n>>t;
 
    if(!n && !t){printf("Case %d: 1\n",caseno);continue;}
 
 
    if(t>=n){
        printf("Case %d: impossible\n",caseno);
        continue;
    }
 
 
 
    ll nc=n-t;
    set<int>st;
 
    for(ll i=2;i*i<=n;i++){
       if(nc%i==0){
        st.insert(i);
        st.insert(nc/i);
       }
 
    }
 
    st.insert(1);
    st.insert(n-t);
 
    printf("Case %d:",caseno);
    int f=0;
    for(int x:st){
        if(x>t)f=1,ct " "<<x;
    }
 
    if(f)nl;
    else puts(" impossible");
 
 
 
 
 
}
 
 
 
 
 
 
 
 
 
    return 0;
}
 