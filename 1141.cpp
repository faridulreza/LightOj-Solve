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

const int size=1000;
vector<int>primes(500);
bool mark[size+5];
int cnt=0;
void sieve(){
     
     ll lm=sqrt(size)+2;
     for(ll i=3; i<=lm;i+=2){
        if(mark[i])continue;
         for(ll j=i*i;j<=size; j+=i){
            mark[j]=true;
         }
     }

     primes[cnt++]=2;
     for (int i = 3; i <=size; i+=2)
     {
        if(!mark[i])primes[cnt++]=i;
     }

}


int inf=1000000000;
int dp[1010];

int f(int s,int t){
    
    if(s>t)return inf;
    if(s==t)return 0;
    if(dp[s]!=-1)return dp[s];

    int res=inf;
    for(auto x:primes){
    	if(x>=s)break;

    	if(s%x==0)
    		res=min(res,f(s+x,t)+1);
    }

    return dp[s]=res;
}

int main() {

    
   sieve();

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int a,b;

   scanf("%d%d",&a,&b);
   _1(dp);

   int res=f(a,b);
   if(res==inf)
     printf("Case %d: -1\n",caseno);
   else
     printf("Case %d: %d\n",caseno,res);
   }




    return 0;
}
