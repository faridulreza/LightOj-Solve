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

ll dp[66000][21];
bool taken[20];
ll b,k;
string s;
int size;

ll f(int state,int mod,int pos){

  if(pos==size){
     
     if(mod%k==0)return 1;
     else return 0;

  }

  if(dp[state][mod]!=-1)return dp[state][mod];



  ll base=1;
  for (int i = 0; i < pos; ++i)base=(base*b)%k;

  ll ans=0;
  for (int i = 0; i <size; ++i)
  {
  	if(!taken[i]){
        taken[i]=1;
        int dig;

        if(isalpha(s[i]))dig=s[i]-'A'+10;
        else dig=s[i]-'0';

        ll newmod=(mod+(dig*base)%k)%k;

        int newstate=(state|(1<<i));

        ans+=f(newstate,newmod,pos+1);
        taken[i]=0;

  	}
  }

  return dp[state][mod]=ans;


}


int main() {

    
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
      
     
     cn b>>k;
     cn s;
     reverse(all(s));
     _1(dp);
     _0(taken);
     size=s.size();

     printf("Case %d: %lld\n",caseno,f(0,0,0));
    }






    return 0;
}
