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
     //http://www.murderousmaths.co.uk/books/trap.htm
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
      double a,b,c,d;
      cn a>>b>>c>>d;
      
      if(c>a)swap(a,c);
      double s=a+b+c+d;
      double area=(a+b-c+d)*(a+b-c-d)*(a-b-c+d)*(-a+b+c+d);
      area=sqrt(area);

      area*=(a+c)/((a-c)*4);

    
      printf("Case %d: %.10f\n",caseno,area);
    }







    return 0;
}
