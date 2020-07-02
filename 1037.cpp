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

int dp[(1<<15)+100];
int health[20];
int dam[17][17];
int n;

int f(int st){

  
 if(st==(1<<n)-1)return 0;
 if(dp[st]!=-1)return dp[st];
 int res=100000000;


 for (int i = 0; i <n ; ++i)
 {
 	if(!(st&(1<<i))){
      
      int dm=1;
      for(int j=0; j<n ; j++){
          if(st&(1<<j)){
            dm=max(dam[j][i],dm);
          }
      }

      int tmp=health[i]/dm+!!(health[i]%dm)+f(st|(1<<i));
//      _(tmp);
      res=min(res,tmp);
     
 	}
 }


return dp[st]=res;

}




int main() {

    

 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){

cn n;
for (int i = 0; i <  n; ++i)
{
	cn health[i];
	/* code */
}

for (int i = 0; i < n; ++i)
{
	/* code */
	for(int j=0; j<n ; j++){
	    scanf("%1d",&dam[i][j]);
	}
}

_1(dp);

printf("Case %d: %d\n",caseno,f(0));
}





    return 0;
}
