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

int n,m;
int grid[102][102];
ll dp[102][102][102];

ll f(int r1,int c1,int r2,int c2){


  if(r1>=n || c1>=m || r2>=n || c2>=m)return 0;
  if(r1==r2 && c1==c2)return 0;

  if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
  /*
    why a four variable state is memoized by three variables?
    we are moving from both cell (0,1)  and (1,0) simultaneously.
    if (0,1) is moved twice (any direction) so is (1,0).
    say (r1 ,c1) is (1,2), we have moved both cells 2 times.
        now if r2 is 2 you can certainly say the c2 is 1.(because it must move 2 times and r2 is 2)
        if r2 is 3 c2 certainly is 0.
    so only r1,c1,r2 or any of the three variable out of four can represent an entire state.
    no need for the fourth variable.
   */

  ll ret=0;
  ret=max(ret,f(r1+1,c1,r2+1,c2));
  ret=max(ret,f(r1,c1+1,r2,c2+1));
  ret=max(ret,f(r1+1,c1,r2,c2+1));
  ret=max(ret,f(r1,c1+1,r2+1,c2));


  return dp[r1][c1][r2]=ret+grid[r1][c1]+grid[r2][c2];

}

int main() {

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
     cn n>>m;
     for (int i = 0; i <n; ++i)
     {
       for(int j=0; j<m ; j++){
           cn grid[i][j];
       }
     }
     _1(dp);
   
     printf("Case %d: %lld\n",caseno,f(0,1,1,0)+grid[0][0]+grid[n-1][m-1]);
   }
    return 0;
}
