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

double dp[510][510];
bool mark[510][510];

double f(int red,int blue){

 if(red==0)return 1;

 if(blue==0){
 	return 0;
 }

if(mark[red][blue])return dp[red][blue];



  double tot=red+blue;

  double A=(red)*f(red-1,blue-1);
  
  double B=0;

  if(blue>=2)B=(blue)*f(red,blue-2);
  double res=(A+B)/tot;
  mark[red][blue]=true;
  return dp[red][blue]=res;

}

int main() {

  f(500,500);


   int T;
      cn T;
  for(int caseno=1; caseno<=T  ;caseno++){
  int n,m;
  cn n>>m;

  
  printf("Case %d: %.10f\n",caseno,f(n,m));
  }


    return 0;
}
