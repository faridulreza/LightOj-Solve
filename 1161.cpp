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

ll num[10005];

void f(){
     
     int d;
     scanf("%d",&d);
     int lm=sqrt(d);

     for (int i = 1; i <=lm ; ++i)
     {
           if(d%i==0){
           	  int a=d/i;
           	  if(a!=i){
           	  	num[i]++;
           	  	num[a]++;
           	  }
           	  else num[a]++;
           }
     }


}

ll calc(ll x){

  return (x*(x-1)*(x-2)*(x-3))/24;

}
int main() {

    

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    
    int n;
    scanf("%d",&n);
    _0(num);
    for(int j=0; j<n ; j++){
        f();
    }
    
    for (int i = 10000; i>0 ; i--)
    {   
    
    	num[i]=calc(num[i]);
        if(!num[i])continue;

        for(int j=i*2; j<=10000 ; j+=i){
            num[i]-=num[j];
        }


    }

    
    printf("Case %d: %lld\n",caseno,num[1]);
    }





    return 0;
}
