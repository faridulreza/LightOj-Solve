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
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int dp[(1<<16) +10];
int isdp[(1<<16)+10];
int mem[20][20];


int cur; 
vector<pair<int,int>> p;

 
void calculate(){

 _0(mem);

 int n=p.size();

 for (int i = 0; i <n; ++i)
 {
   for(int j=i+1; j<n ; j++){

      
       int y1=p[i].sc-p[j].sc;
       int x1=p[i].fs-p[j].fs;
       int a=y1,b=-x1,c=-y1*p[i].fs+x1*p[i].sc;
 
       for(int k=0; k<n ; k++){
          
          int x=p[k].fs,y=p[k].sc;

          if(a*x+b*y+c==0){

            mem[i][j]^=(1<<k);
            mem[j][i]^=(1<<k);
       
           }
      }
   }
 }


}



int f(int st){
 
 
 
  if(isdp[st]==cur)return dp[st];  
 
  int i=-1;
 
  for (int l = 0; l < p.size(); ++l)
  {
    if(!(st & (1<<l)) ){
      i=l;
      break;
    }
  }
 
  if(i==-1)return 0;

  int rt=20;
 
  for(int j=0;j<p.size();j++)
  {
   
    if(i!=j && !(st & (1<<j)) ){
          int nst=st|mem[i][j];
          rt=min(rt,f(nst)+1);  
    }
 
  }
 
  rt=(rt==20)?1:rt;
  isdp[st]=cur;
 
  return dp[st]=rt;

}
 
 
int main() {
 
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
     cur=caseno;
 
     int n;
     scanf("%d",&n);
     p.clear();
 
     for (int i = 0; i < n; ++i)
     {
       
       int x,y;
       scanf("%d %d",&x,&y);
       p.pb({x,y});
 
     }
 
     calculate();    
     printf("Case %d: %d\n",caseno,f(0));
     
   
    }
 
 
 
 
 
 
 
    return 0;
}
 