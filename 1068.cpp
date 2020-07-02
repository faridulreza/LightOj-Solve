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

vector<int> v;
int k;
ll dp[15][90][90][2];

ll f(int i,ll digitSum,ll sum,int canBig){

  if(i==v.size()){
  	if(digitSum+sum==0){
  		return 1;
  	}
  	return 0;
  }

 if(dp[i][digitSum][sum][canBig]!=-1)return dp[i][digitSum][sum][canBig];

  ll b=1;
  for(int j=0; j<v.size()-i-1; j++)b*=10;

  ll res=0;
  int lim;
  if(canBig)lim=9;
  else lim=v[i];

  for(int j=0; j<=lim; j++){
      
      res+=f(i+1,(digitSum+j)%k,(sum+b*j)%k,(j<v[i] || canBig));

  }
   
   return dp[i][digitSum][sum][canBig]=res;
  
}



int main() {

    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    ll a,b;
    cn a>>b>>k;

    if(k>85){
        printf("Case %d: 0\n",caseno);
        continue;	
    }
    else {
          
         a--;
         ll tma=a;
         v.clear();
         while(a){
           v.pb(a%10);
           a/=10;
         }
         reverse(all(v));
         _1(dp);


         ll res;
         if(tma==0)res=1;
         else res=f(0,0,0,0);

         v.clear();
         while(b){
           v.pb(b%10);
           b/=10;
         }
         reverse(all(v));
         _1(dp);
         res=f(0,0,0,0)-res;

         
         printf("Case %d: %lld\n",caseno,res);
         
    }

    
    
    }







    return 0;
}
