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

int par[60];

int f(int v){
	if(v==par[v])return v;
	return par[v]=f(par[v]);
}

#define pii pair<int,pair<int,int>>
ll mst(int n){

     
     priority_queue<pii,vector<pii>, greater<pii>> pq;

    for (int i = 0; i <=n; ++i)
    {
    	par[i]=i;
    }

    ll sum=0;

    for (int i = 1; i <= n; ++i)
    {
    	for(int j=1; j<=n ; j++){
    	    int a;
    	    cn a;
    	    if(a)pq.push({a,{i,j}});
            sum+=a;
    	}
    }


    int setcnt=n;

    ll msum=0;

    while(!pq.empty()){
       
       int w=pq.top().fs;
       int u=pq.top().sc.fs;
       int v=pq.top().sc.sc;

       pq.pop();

       int a=f(u);
       int b=f(v);

       if(a!=b){
       	par[a]=b;
       	msum+=w;
       	setcnt--;
       }

    }


    if(setcnt!=1)return -1;
    else return sum-msum;






}




int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    cn n; 
    
    printf("Case %d: %lld\n",caseno,mst(n));
    }







    return 0;
}
