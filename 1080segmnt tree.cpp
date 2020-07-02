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
double _eps = 1e-6;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int segtre[100000*4];


void update(int v,int tl,int tr,int l,int r){


   if(l>r)return;
   if(l==tl && r==tr){
    // _(l);
    // _(r);
    // nl;
    segtre[v]++;
    return;
   }
   else{
    int tm=(tl+tr)/2;
    update(v*2,tl,tm,l,min(tm,r));
    update(v*2+1,tm+1,tr,max(tm+1,l),r);
   }

}


 int sm(int v,int tl,int tr,int pos){

     if(tl==tr)return segtre[v];
     else{
        int tm=(tl+tr)/2;

        if(pos<=tm) return segtre[v]+sm(v*2,tl,tm,pos);
        else return segtre[v]+sm(v*2+1,tm+1,tr,pos);

     }

 }


int main()
{

    int T;
    cn T;
    getchar();
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        printf("Case %d:\n", caseno);
        char s[100000+10];
        scanf("%s",s);
        int n = strlen(s);

        int m;
        cn m;
        getchar();

        for (int i = 0; i < m; ++i)
        {

          char q=getchar();
          if(q=='I'){
            int l,r;
            scanf("%d %d",&l,&r);
            l--,r--;
            update(1,0,n-1,l,r);
          }
          else{
             int r;
             scanf("%d",&r);
             r--;
             int sum=sm(1,0,n-1,r);

             if(sum&1)ct (s[r]=='1'?0:1);
             else ct (s[r]=='1'?1:0);
             nl;


          }
          getchar();
          
        }


      _0(segtre);
       
    }


    //update(1,0,15,5,15);




    return 0;
}
