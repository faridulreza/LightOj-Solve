#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) puts("FLAG " #x),fflush(stdout);
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


int main() {
    

    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    cn n;
    int x1=(int)ceil(sqrt(-2*n*log(.5)));

    double ans=1;

    ll tmpn=n;

    for (int i = 1; i < x1; ++i)
    {   
    	double up=tmpn-i;
    	ans*=(up/n);
    }
    ans=1-ans;
    
    
    int i=ans*100;
    if(i<50)x1++;

    printf("Case %d: %d\n",caseno,x1-1);
    }







    return 0;
}
