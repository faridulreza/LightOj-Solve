#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
#define len (100000)
ll mx=-1000000000-100;
ll mn=1000000000+100;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int arr[50];
int cnt;

void comb(int pos,int ed,ll mw,int w,int n){

if(n==pos){
if(mw<=w)cnt++;
return;
}
for(int i=pos; i<ed  ;i++){
if(mw+arr[i]<=w)comb(i+1,ed,mw+arr[i],w,n);
}
}

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    memset(arr,0,sizeof(arr));
    int n,w;
    cn n>>w;
ll sum=0;
    for(int i=0; i<n  ;i++){
    cn arr[i];
    sum+=arr[i];
    }
    sort(arr,arr+n,[](int a, int b){return a>b;});
    if(sum<=w){

        printf("Case %d: %lld\n",caseno,1<<n);
        continue;
    }
    ll nm=0;
    for(int i=1; i<=n  ;i++){
    comb(0,n,0,w,i);
    nm+=cnt;
    cnt=0;
    }

     nm++;

    printf("Case %d: %lld\n",caseno,nm);
    }








    return 0;
}
