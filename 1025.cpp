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

string inp;
ll dp[70][70];


ll f(int i, int j){

    if(j-i==1){
        
        if(inp[i]==inp[j])
        	return dp[i][j]=3;
        else return dp[i][j]=2;

    }

    if(i==j)return dp[i][j]=1;


    if(dp[i][j])return dp[i][j];

    if(inp[i]==inp[j]){
     
     return dp[i][j]=f(i+1,j)+f(i,j-1)+1;

    }

    else {
    	return dp[i][j]=f(i+1,j)+f(i,j-1)-f(i+1,j-1);
    }




}


int main() {

    
    int T;
    cn T;

    for(int caseno=1; caseno<=T  ;caseno++){
    cn inp;
    _0(dp);
    printf("Case %d: %lld\n",caseno,f(0,inp.size()-1) );
    }


    return 0;
}
