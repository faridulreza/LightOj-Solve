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






ll t[4*100000];

ll mod=1000000007;

void clear(int v,int tl,int tr){
  
   if(tl==tr){t[v]=0; return;}

   int mid=(tl+tr)/2;
   clear(v*2,tl,mid);
   clear(v*2+1,mid+1,tr);

   t[v]=t[v*2]+t[v*2+1];


}

ll sum(int v, int tl, int tr, int l, int r) {
    
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    ll q= sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);

    t[v] = (t[v*2] + t[v*2+1])%mod;
    
    return q;
    
}
 

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] + t[v*2+1])%mod;
    }
}
 
 


int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    cn n;
    int arr[n+1];
    int tmp[n+1];
    for (int i = 0; i < n; ++i)scanf("%d",&arr[i]),tmp[i]=arr[i];

    map<int,int>mp;
    sort(tmp,tmp+n);
    int cnt=0;

    for (int i = 0; i < n; ++i)
    {
    	if(!mp.count(tmp[i]))mp[tmp[i]]=cnt++;
    }
    

    for (int i = 0; i < n; ++i)
    {
    	int pos=mp[arr[i]];
        
        ll sm=sum(1,0,cnt-1,0,pos-1);
        update(1,0,cnt-1,pos,sm+1);

    }



    printf("Case %d: %lld\n",caseno,t[1]);
    clear(1,0,cnt-1);
    }







    return 0;
}
