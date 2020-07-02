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

vector<int> arr;
int n;

ll dp[14][2][2][14];

ll f(int i,bool canBig,bool canCount,int zcnt){
 
 if(i==n)return zcnt;
 if(dp[i][canBig][canCount][zcnt]!=-1)return dp[i][canBig][canCount][zcnt];

 ll res=0;
 if(i==0){

     for (int j = arr[i]; j>=0; --j)
     {
     	 res+=f( i+1,canBig| (j<arr[i]),canCount|(j!=0),(canCount && (j==0))+zcnt);
     }

 }
 else {
     int lm;
     if(canBig)lm=9;
     else lm=arr[i];

     for (int j = lm; j>=0; --j)
     {
     	 res+=f(i+1,canBig|| (j<arr[i]),canCount||(j!=0),(canCount && (j==0))+zcnt);
     }

 }

 return dp[i][canBig][canCount][zcnt]=res;


}

ll calcN(ll b){
       _1(dp);
        arr.clear();
        
        while(b){
        	arr.pb(b%10);
        	b/=10;
        }
        reverse(all(arr));
        n=arr.size();
        
        return f(0,0,0,0);
}

int main() {

    

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
        ll a,b;
        scanf("%lld%lld",&a,&b);
        
        
        printf("Case %d: ",caseno);
        
        if(a==0){
           printf("%lld\n",1+calcN(b));
        }
        else {
        	printf("%lld\n",calcN(b)-calcN(a-1));
        }
        
    }





    return 0;
}
