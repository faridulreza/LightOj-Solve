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

double p;
int n;
vector<pair<double,int>>arr;
int res;
double dp[105][10010];
bool vis[105][10010];


double f(int i,int money){
   

   if(money==0)return 0;
   if(i==n){
   	     return 1e100;
   }

   if(vis[i][money])return dp[i][money];

    
   double prob=arr[i].fs+(1-arr[i].fs)*f(i+1,money-arr[i].sc);
   prob=min(prob,f(i+1,money));

   vis[i][money]=true;
   return dp[i][money]=prob;

}



int main() {

    
    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
    cn p>>n;
    
    for (int i = 0; i < n; ++i)
    {
    
    	int a;double b;
    	cn a>>b;
    	arr.pb({b,a});
    }
    // f(0,i) returns the lowest probability to make money i

    for (int i = 1; i <=10000; ++i)
           if(p>f(0,i))res=i;
    
    printf("Case %d: %d\n",caseno,res);
    
    arr.clear();
    _0(vis);
    res=0;
   }




    return 0;
}
