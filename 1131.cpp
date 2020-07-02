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
 
#define lim 6
ll mod;
int a1,b1,c1,a2,b2,c2;

struct mat
{


  ll arr[lim][lim]={};

  int  make_mat(){
      arr[0][0]=a1;arr[0][1]=b1;arr[0][5]=c1;
      arr[1][0]=1;
      arr[2][1]=1;
      arr[3][2]=c2;arr[3][3]=a2;arr[3][4]=b2;
      arr[4][3]=1;
      arr[5][4]=1;
      
      return 0;
  }
  mat operator *(mat o){
      mat b;

      for (int i = 0; i < lim; ++i)
      {
        for(int j=0; j<lim ; j++){
            for(int k=0; k<lim ; k++){
                
                b.arr[i][j]=(b.arr[i][j]+(1ll*(arr[i][k]*o.arr[k][j]))%mod)%mod;
                
                if(b.arr[i][j]<0)b.arr[i][j]+=mod;
            
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
      _0(b.arr);
      for(int k=0; k<lim ; k++){
          b.arr[k][k]=1;
      }
      return b;
    }
    if(b==1){
        mat x;
        x.make_mat();
        return x;
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
    
   ll f[3];
   ll g[3];

   scanf("%d%d%d",&a1,&b1,&c1);
   scanf("%d%d%d",&a2,&b2,&c2);
   scanf("%lld%lld%lld",&f[0],&f[1],&f[2]);
   scanf("%lld%lld%lld",&g[0],&g[1],&g[2]);
   scanf("%lld",&mod);

   mat a,b;
   a.make_mat();
   
   int q;
   scanf("%d",&q);

   printf("Case %d:\n",caseno);
   for(int j=0; j<q ; j++){
       int n;
       scanf("%d",&n);
       
       if(n<3){
          printf("%lld %lld\n",(f[n]+mod)%mod,(g[n]+mod)%mod);
          continue;
       }

       b=matpower(a,n-2);
       int fn=0,gn=0;

       for (int i = 2,k=0; i >=0 ;i--,k++)
       {
           fn=(fn+(1ll*b.arr[0][k]*f[i])%mod)%mod;
           gn=(gn+(1ll*b.arr[3][k]*f[i])%mod)%mod;
           if(fn<0)fn+=mod;
           if(gn<0)gn+=mod;

       }

       for (int i = 2,k=3; i >=0 ; --i,k++)
       {
           fn=(fn+(1ll*b.arr[0][k]*g[i])%mod)%mod;
           gn=(gn+(1ll*b.arr[3][k]*g[i])%mod)%mod;
           if(fn<0)fn+=mod;
           if(gn<0)gn+=mod;

       }

       printf("%d %d\n",fn,gn);

   }
  
   }





    return 0;
}
