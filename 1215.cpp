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
 
 
const int size = 1000000;
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
        ll a, b, l;
        cn a >> b >> l;
 
        ll la=a,lb=b,Ll=l;
 
        map<int, int>mp;
        for(int x : primes)
        {
            if(x * x > la)break;
            int cnt = 0;
            while(a % x == 0)
            {
                cnt++;
                a /= x;
            }
            if(cnt)mp[x] = cnt;
        }
        if(a != 1)mp[a] = 1;
 
 
        for(int x : primes)
        {
            if(x * x > lb)break;
            int cnt = 0;
            while(b % x == 0)
            {
                cnt++;
                b /= x;
            }
            if(mp.count(x))mp[x] = max(mp[x], cnt);
            else  if(cnt) mp[x] = cnt;
 
       
        }
        if(b != 1)    
            if(mp.count(b))mp[b] = max(mp[b], 1);
            else  mp[b] = 1;
 
 
        map<int, int>mp2;
 
        for(int x : primes)
        {
            if(x * x > Ll)break;
            int cnt = 0;
            while(l % x == 0)
            {
                cnt++;
                l /= x;
            }
            if(cnt)mp2[x] = cnt;
        }
        if(l != 1)mp2[l] = 1;
 
        int f = 1;
 
       
        for(auto x : mp)
        {
 
 
            if(!mp2.count(x.fs) || mp2[x.fs]<x.sc)
            {
                f = 0;
                break;
            }
        }
 
        if(!f)
        {
            printf("Case %d: impossible\n", caseno);
            continue;
        }
       
        ll ans=1;
        for(auto x:mp2){
           
           if(mp[x.fs]==x.sc)continue;
 
           for (int i = 0; i <x.sc; i++)ans*=x.fs;
           
        }
 
 
        printf("Case %d: %lld\n", caseno,ans);
 
 
 
 
 
 
    }
 
 
 
    return 0;
}
 