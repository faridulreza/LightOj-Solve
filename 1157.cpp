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

int dp[1005][1005];
int dp2[1005][1005];
int nextIndex[2][26][1005];

string a, b;
int n, m;

int f(int i, int j)
{


    if(i >= n || j >= m)return dp[i][j] = 0;

    if(dp[i][j] != -1)return dp[i][j];
    int ans;
    if(a[i]==b[j])ans=1+f(i+1,j+1);
    else ans=max(f(i+1,j),f(i,j+1));

    return dp[i][j] = ans;

}

int md=1000007;

int calc(int i,int j){
  
  int l=f(i,j);
  
  if(l==0)return 1;
  else if(l<0)return 0;
 
  if(i>=n ||j>=m)return 0;

  if(dp2[i][j]!=-1)return dp2[i][j];
  
  ll ret=0;

  for (int k = 0; k < 26; ++k)
  {
  	 int x=nextIndex[0][k][i],y=nextIndex[1][k][j];
  	 
  	 if(f(x,y)==l)ret=(ret+calc(x+1,y+1))%md;
  }

  return dp2[i][j]=ret;
}


int main()
{
    

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn a >> b;
        n = a.size();
        m = b.size();
        _1(dp);
        _1(dp2);

        f(0, 0);
        for (int i = 0; i < 26; ++i)
        {   
        	nextIndex[0][i][n]=n;
        	for (int j = a.size()-1; j >=0 ; --j)
        	{
        		if(i==a[j]-'a')nextIndex[0][i][j]=j;
        		else nextIndex[0][i][j]=nextIndex[0][i][j+1];
        	}
        }

        for (int i = 0; i < 26; ++i)
        {   
        	nextIndex[1][i][m]=m;
        	for (int j = b.size()-1; j >=0 ; --j)
        	{
        		if(i==b[j]-'a')nextIndex[1][i][j]=j;
        		else nextIndex[1][i][j]=nextIndex[1][i][j+1];
        	}
        }
    
        printf("Case %d: %d\n", caseno,calc(0,0));

    }



    return 0;
}
