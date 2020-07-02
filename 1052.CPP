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
 
ll arra[100];
ll arrb[100];
 
ll mod=1000000007;
 
struct mat{
 
   ll arr[2][2]={};
 
   
 
  mat operator *(mat o){
 
      mat r;
     
      for (int i = 0; i < 2; ++i)
      {
          for (int j = 0; j <2; j++)
          {
              for (int k = 0; k <2 ; k++)
              {
                  r.arr[i][j]= (r.arr[i][j] + (arr[i][k]*o.arr[k][j])%mod)%mod;
              }
          }
      }
 
    return r;
  }
 
 
};
 
 
    mat power(mat a,ll b)    //a is base, b is exponent
    {
        if(b==0)
            {
               mat r;
                r.arr[0][0]=1;
                r.arr[0][1]=0;
                r.arr[1][0]=0;
                r.arr[1][1]=1;
 
              return r;
            }
 
        if(b==1){
           
           mat r;
 
 
                r.arr[0][0]=1;
                r.arr[0][1]=1;
                r.arr[1][0]=1;
                r.arr[1][1]=0;
 
 
           return r;
 
        }
           
        if(b%2 == 1)
            return (power(a,b-1)*a);
 
        mat q = power(a,b/2);
        return (q*q);
    }
 
 
int main() {
 
     arra[1]=arrb[1]=1;
     arra[2]=1;
     arrb[2]=2;
 
 
     for (int i = 3; i <70 ; ++i)
     {
         arra[i]=arra[i-1]+arra[i-2];
         arrb[i]=arrb[i-1]+arrb[i-2];
       
     }
   
 
     
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
   
    int n,x ,m,y, k;
 
    cn n>>x>>m>>y>>k;
 
   
ll a,b;
 
 
 
 
 
 
if(k>=2){
 
 
   mat r,aa;
 
 
                r.arr[0][0]=1;
                r.arr[0][1]=1;
                r.arr[1][0]=1;
                r.arr[1][1]=0;
 
 
    aa=power(r,k-2);
 
    a=(aa.arr[0][0]+aa.arr[0][1])%mod;
    b=(aa.arr[0][1]+aa.arr[0][0]*2)%mod;
 
}
 
else {
    a=1;
    b=1;
}
 
    if(n>43 || m>43){
         
 
     printf("Case %d: Impossible\n",caseno);
     continue;
 
    }
 
 
    ll a1=arra[n],b1=arrb[n],c1=x;
    ll a2=arra[m],b2=arrb[m],c2=y;
 
    ll d=a1*b2-a2*b1;
 
 
 
    if(d==0){
 
     printf("Case %d: Impossible\n",caseno);
     continue;  
    }    
 
    ll xu=c1*b2-c2*b1;
    ll yu=a1*c2-a2*c1;
 
 
    if(xu%d!=0 || yu%d!=0){
 
     printf("Case %d: Impossible\n",caseno);
     continue;
     }
 
 
    xu/=d;
    yu/=d;
 
 
    if(xu<0 || yu<0){
     
     printf("Case %d: Impossible\n",caseno);
     continue;
 
    }
 
     
 
 
 
   
     printf("Case %d: %lld\n",caseno, (((a*xu)%mod+(b*yu)%mod)%mod+mod)%mod);
     
 
 
   }
 
 
 
  return 0;
}
 
