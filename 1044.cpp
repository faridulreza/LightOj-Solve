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

int dp[1010];
bool isP[1010][1010];
string inp;



int main() {

    

 int T;
    cn T;
    getchar();
for(int caseno=1; caseno<=T  ;caseno++){

char ch[1010];
scanf("%s",ch);
inp.assign(ch);

_0(isP);

int sz=inp.size();

for (int i = 0; i < sz; ++i)
{
    isP[i][i]=true;
}

for (int i = 2; i <= sz; ++i)
{
	for(int j=0; j+i-1<sz ; j++){
	    int st=j;
	    int ed=j+i-1;

	    if(inp[st]==inp[ed]){
          if(i==2)isP[st][ed]=true;
          else isP[st][ed]=isP[st+1][ed-1];
	    }
         
	}
}

// count min cut for 0 to i by dp[i]

for (int i = 0; i < sz; ++i)
{
	if(isP[0][i]){
       dp[i]=0;
	}
	else {

      dp[i]=INT_MAX;

      for(int j=0; j<i ; j++){
          if(isP[j+1][i] && 1+dp[j]<dp[i])dp[i]=dp[j]+1;
      }

	}
}


printf("Case %d: %d\n",caseno,dp[sz-1]+1);
}




    return 0;
}
