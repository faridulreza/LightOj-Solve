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
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
     int n;
 
     cn n;
     map<int,int>mp;
 
     for (int i = 0; i < n; ++i)
     {
        int inp;
        cn inp;
        mp[inp]++;
 
 
     }
     ll pp=0;
 
     for(auto x:mp){
        int nm=x.fs;
        int occ=x.sc;
 
        if(nm!=0){
            pp+=( occ/(nm+1))*(nm+1);
            if(occ%(nm+1))pp+=nm+1;
 
        }
        else {
            pp+=occ;
        }
 
     }
   
    printf("Case %d: %lld\n",caseno,pp);
    }
 
 
    return 0;
}
 