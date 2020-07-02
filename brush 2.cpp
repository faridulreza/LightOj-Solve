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

struct point{
int x,y;
};

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int arr[50110];
    int n,w,inp;
    cn n>>w;
    for(int i=0; i<n  ;i++){
        cn inp>>arr[i];
    }

    sort(arr,arr+n);

         int cnt =0, *p=arr,st;
         while(1){
            st= *p+w;
            p=upper_bound(arr,arr+n,st);
            cnt++;
            if(p==arr+n)break;
         }

   printf("Case %d: %d\n",caseno,cnt);
    }
    return 0;
}
