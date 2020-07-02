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

double dp[100000+100];
bool mark[100000+100];

void factor(vector<int> & res,int n){
    for(ll j=2; j*j<=n; j++){
        
       if(n%j==0){
       	res.pb(j);
       	if(j!=n/j)res.pb(n/j);
       }

    }
}

double f(int n){

   if(n==1)return 0;
   if(mark[n])return dp[n];

   vector<int> fact;

   factor(fact,n);

   double res=0;


   for(int fc:fact){

    res+=f(n/fc);
   }
   double total=fact.size()+2;

   res/=total;
   res+=1;
   res=(res*total)/(total-1);   
   mark[n]=true;
   return dp[n]=res;

}




int main() {

       


 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
int n;
cn n;
printf("Case %d: %.10f\n",caseno,f(n));
}




   return 0;
}
