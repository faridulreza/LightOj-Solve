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
int arr[40];

ull vag(ull res,int k){


    for (int i = 2; i <=k; ++i)
    {
    	if(arr[i] && res%i==0)res/=i,arr[i]=0;
    }
    return res;

}

int main() {


     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    ull n,k;
    cn n>>k;

    for (int i = 2; i <=k; ++i)
    {
    	arr[i]=i;
    }
    
    if(k==0 || k>n){
    	  printf("Case %d: %d\n",caseno,!k);
    	  continue;
    }
    ull tmp=k;
     ull res=1;
    for (int i = 0; i <tmp; ++i)
    {
    	res*=(n*n);
    	n--;
    	res=vag(res,tmp);
    }
   res=vag(res,tmp);
    

    
    printf("Case %d: %llu\n",caseno,res);
    }







    return 0;
}
