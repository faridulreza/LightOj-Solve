#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _flag(x) puts("FLAG " #x);
#define  _(y,x)  cout<<y<<". "<< #x <<" is "<< x <<endl;
#define fs first
#define sc second
#define pb push_back
#define _105 (100000)
#define _109 (1000000000)
#define _0(arr) memset(arr,0,sizeof ( arr ) )
#define _ninp(n,arr) for(int i=0; i<n;i++)cin>>arr[i];
#define _nout(n,arr) for(int i=0; i<n;i++)cout<<arr[i]<<" \n"[i==n-1];
 
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
const int size = 10000000;
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
 
    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n;
        cn n;
 
        int tr = n / 2;
       
        int cnt=0;
        for(int x:primes){
            if(x>tr)break;
            if(((n-x)&1 || n-x==2) && !mark[n-x])cnt++;
           
        }
 
 
        printf("Case %d: %d\n",caseno,cnt);
    }
 
 
 
    return 0;
}
 