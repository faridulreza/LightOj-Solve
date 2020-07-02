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




int main() {

    ull n,res,u;

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    cn n;

    res=0;

    u=sqrt(n);
    for (ull i = 2; i <= u; ++i)
    {
    	ull last=n/i;
        res+=(last*(last+1))/2-(i*(i-1))/2;
        res+=(last-i)*i; 

    }


    
    printf("Case %d: %llu\n",caseno,res);
    }
    







    return 0;
}
