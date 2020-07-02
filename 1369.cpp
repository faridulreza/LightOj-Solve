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
    ll arr[100000+50];
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&arr[i]);
    }
 
    int nn=n;
    ll res=0;
 
    for (int i = 0; i < n; ++i,nn--)
    {
        res+=(nn-1)*arr[i]-i*arr[i];
    }
    printf("Case %d:\n",caseno);
    while(q--){
        int qq;
        scanf("%d",&qq);
 
        if(qq==1)ct res,nl;
        else{
 
            int x,ind;
            scanf("%d%d",&ind,&x);
            //ind--;
 
            res+=ind*arr[ind];
            res-=(n-ind-1)*arr[ind];
            arr[ind]=x;
 
            res-=ind*arr[ind];
            res+=(n-ind-1)*arr[ind];
           
 
        }
 
 
 
    }
 
 
   
   
    }
 
 
 
 
 
 
 
    return 0;
}
 