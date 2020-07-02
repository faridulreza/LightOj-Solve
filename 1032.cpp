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

ll table [70];
string bits;
int sz;

ll det(int i){

ll gun=1;
ll ret=0;
for(int j=sz-1; j>i ; j--){
    if(bits[j]=='1')ret+=gun;
    gun*=2;
}
return ret+1;
}



ll f(int i){

   if(i==sz-1)return 0;

   ll ret=table[sz-i-1];
   
   if(bits[i+1]=='1'){
   	   //if the right next bit is 1 ,determine for how many bits it is been 1 (by det())
   	   // add those count to result and proceed for counting  i+1 to last 
       return ret+det(i+1)+f(i+1);
   }

   for(int j=i+2; j<sz ; j++){
       if(bits[j]=='1'){
       	return ret+f(j);
       }
   }
   
   return ret;
}

int main() {

    table[2]=1;
    ll gun=2;
    for (int i = 3; i <=61; ++i)
    {
     table[i]=2*table[i-1]+gun;
     gun*=2;          
    }
    

   //100100 to count this 
       //lets fist count for 100000 which is similar to counting for
       //011111 . it can be obtained from table[5]
   //then re-count for 100 and add;  

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
     ll inp;

   cn inp;

   bits.clear();
   if(inp==0)bits="0";
   while(inp){
   
   bits.pb('0'+(inp&1));
   inp=inp>>1;

   }
   reverse(all(bits));
   sz=bits.size();
   // _(bits);
   printf("Case %d: %lld\n",caseno,f(0));
   }
    





    return 0;
}
