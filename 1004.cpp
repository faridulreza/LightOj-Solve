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

vector<ull> v[110];
ull arr[110];

int main() {

 int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
    {
    	v[i].clear();
    	for(int j=0; j<i+1 ; j++){
    	    ull inp;
    	    scanf("%llu",&inp);
    	    v[i].pb(inp);
    	}
    }
    
    _0(arr);
    for (int i = 0; i < n-1; ++i)
    {
         for(int j=0; j<i+1 ; j++){
          arr[j]=max(arr[j],v[i][j]+v[i+1][j]);         
          arr[j+1]=max(arr[j+1],v[i][j]+v[i+1][j+1]);         
         }

         for(int j=0; j<i+2 ; j++){
             v[i+1][j]=arr[j];
            
         }
     }


     for (int i = n-2; i>=0; i--)
     {
         for(int j=0; j<i+1 ; j++){
         	   scanf("%llu",&v[i][j]);
         	}	
     }

     _0(arr);

     for (int i = n-1; i>0; i--)
     {
         for(int j=0; j<i+1 ; j++){
         	   if(j==0)arr[j]=max(arr[j],v[i][j]+v[i-1][j]);
         	   else  if (j==i)arr[j-1]=max(arr[j-1],v[i][j]+v[i-1][j-1]);
         	   else{
                arr[j]=max(arr[j],v[i][j]+v[i-1][j]);
         	    arr[j-1]=max(arr[j-1],v[i][j]+v[i-1][j-1]);
         	   }
         	}

         	 for(int j=0; j<i; j++){
                v[i-1][j]=arr[j];
               
             }
     }

    
    printf("Case %d: %llu\n",caseno,v[0][0]);
    }    







    return 0;
}