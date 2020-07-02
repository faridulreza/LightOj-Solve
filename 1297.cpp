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


int main() {

    
    /**
     V=(w-2*x)*(h-2*x)*x;

     function V should be maximum with respect to change of x
     So, dV/dx = 0
     or 12x^2 - 2x(w+h)+ wh= 0

        find x from this equation
     **/
	
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
      double w,h;
      cn w>>h;

      double x=w+h-sqrt(w*w+h*h-w*h);
      x/=6;

    
     printf("Case %d: %.10f\n",caseno,(w-2*x)*(h-2*x)*x);
    }







    return 0;
}
