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
double _eps = 1e-6;

int n,m;
bool mp[20];
ll dp[15][15];

ll f(int i,int prevD){
 
   if(i==m)return 1;

   if(dp[i][prevD]!=-1)return dp[i][prevD];
   
   int lw=max(1,prevD-2);
   ll res=0;
   for(int j=lw; j<=prevD+2; j++){
       
       if(mp[j])res+=f(i+1,j);

   }
   
   return dp[i][prevD]=res;
}

int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn n>>m;
         
         _0(mp);
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
        	cn v[i];
        	mp[v[i]]=true;

        }
        _1(dp);
        
        ll res=0;
        for(int x:v){
          res+=f(1,x);
        }
        

        printf("Case %d: %lld\n",caseno,res);
    }







    return 0;
}
