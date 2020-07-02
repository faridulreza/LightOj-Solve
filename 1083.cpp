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


int segtre[30000*4];
int arr[30000+10];

void build(int arr[],int v,int l,int r){


if(l==r){
  segtre[v]=l;
  return;
}
int tm=(l+r)/2;
build(arr,v*2,l,tm);
build(arr,v*2+1,tm+1,r);
if(arr[segtre[v*2]]<arr[segtre[v*2+1]]){
	segtre[v]=segtre[v*2];
}
else segtre[v]=segtre[v*2+1];

}

int minq(int v,int tl,int tr,int l,int r){

  if(l>r)return -1;
  if(tl==l && tr==r)return segtre[v];
  else{
    int tm=(tl+tr)/2;

    int lq=minq(v*2,tl,tm,l,min(tm,r));
    int rq=minq(v*2+1,tm+1,tr,max(tm+1,l),r);
    
    if(lq==-1)return rq;
    if(rq==-1)return lq;

    if(arr[lq]<arr[rq])return lq;
    return rq;

  }

}


int N;

ll area(int st,int ed){
if(st>ed)return 0;
if(st==ed)return arr[st]*1ll;

int minin=minq(1,0,N-1,st,ed);

ll ans=max(area(st,minin-1),area(minin+1,ed));

return max(ans,(ed-st+1)*1ll*arr[minin]);


}


int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   scanf("%d",&N);
   for (int i = 0; i < N; ++i)
   {
   	  scanf("%d",&arr[i]);
   }

   build(arr,1,0,N-1);
   
   printf("Case %d: %lld\n",caseno,area(0,N-1));
   _0(segtre);
   }






    return 0;
}
