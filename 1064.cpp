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

ull dp[27][200];


ull f(int i,int sm){

    if(sm==0){
        if(i==0)return 1;
    	return 0;
    }
    if(sm<0 || i<1)return 0;
    if(dp[i][sm]!=-1)return dp[i][sm];
   
   ull res=0;
   for(int j=1; j<7 ; j++){
       
     res+=f(i-1,sm-j);
   }

   return dp[i][sm]=res;

}

	ull gcd( ull a, ull b )
	{
		if(b==0)
		{
		     return a;
		}
		else
		{
		     return gcd( b, a%b );
		}
	}


int main() {

    

   _1(dp);


    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   

   ull res=0;
   int n,s;

   cn n>>s;

   for(int j=s; j<=n*6; j++){
       res+=f(n,j);
       //ct f(n,j);nl;
   }
   
   ull by=1;
   for (int i = 0; i < n; ++i)
   {
   	/* code */by*=6;
   }

   ll g=gcd(by,res);
   
   by/=g;
   res/=g;
   
   if(res==0)printf("Case %d: 0\n",caseno);
   else if(res==by)printf("Case %d: 1\n",caseno);
   else printf("Case %d: %lld/%lld\n",caseno,res,by);
   }





    return 0;
}
