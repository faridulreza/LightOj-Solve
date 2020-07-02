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


 
#define lim 2
ll mod;

struct mat
{
  

  int arr[lim][lim]={};

  int  make_mat(){
      arr[0][0]=1;
      arr[0][1]=1;
      arr[1][0]=1;
      arr[1][1]=0;
      return 0;
  }
  mat operator *(mat o){
      mat b;

      for (int i = 0; i < lim; ++i)
      {
        for(int j=0; j<lim ; j++){
            for(int k=0; k<lim ; k++){
                
                b.arr[i][j]=(b.arr[i][j]+(1ll*(arr[i][k]*o.arr[k][j]))%mod)%mod;
            
            }
        }
      }

      return b;
  }

};

mat matpower(mat a, ll b)  //a is base, b is exponent
  {
    if(b==0){
      mat b;
      for(int k=0; k<lim ; k++){
          b.arr[k][k]=1;
      }
      return b;
    }
    if(b==1){
        mat b;
        b.make_mat();
        return b;
    }
      
    if(b%2 == 1)
      return (matpower(a,b-1)*a);
    mat q = matpower(a,b/2);
    return (q*q);
  }


 


int main() {

    


    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
   ll a,b,n,m;
   cn a>>b>>n>>m;
   mod=1;
   for (int i = 0; i < m; ++i)mod*=10;
   
   if(n==0){

      printf("Case %d: %d\n",caseno,a%mod);	
   }

  else{
   mat x;
   x.make_mat();
   mat res=matpower(x,n-1);
   int rs=res.arr[0][0]*b+res.arr[0][1]*a;
   rs%=mod;
   printf("Case %d: %d\n",caseno,rs);

  }

   
   
   }




    return 0;
}
