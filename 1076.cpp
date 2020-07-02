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

int arr[1010];
int n,m;
bool pos(ll ctn){
    ll sm=0;
    int cnt=0;
    for (int i = 0; i < n;i++)
    {   
    	if(arr[i]>ctn)return false;
    	if(sm+arr[i]<=ctn)sm+=arr[i];
    	else cnt++,sm=0,i--;
    }
    if(cnt+1>m)return false;
    return true;


}
int main() {

    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   cn n>>m;


   for (int i = 0; i < n; ++i)cn arr[i];

   ll up=10000000000,dw=1;
   ll mid=up+dw;
   mid/=2;


   while(dw<up){
//      _(mid);
      if(pos(mid))up=mid;
      else dw=mid+1;
      mid=(up+dw)/2;

   }

   
   printf("Case %d: %lld\n",caseno,mid);
   
   }





    return 0;
}
