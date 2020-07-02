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



int t[4*100000][2];
int arr[100010];

void build(int v,int tl,int tr){
  
   if(tl==tr){t[v][0]=t[v][1]=arr[tl]; return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v][0]=min(t[v*2][0],t[v*2+1][0]);
   t[v][1]=max(t[v*2][1],t[v*2+1][1]);


}

 
int sum(int v, int tl, int tr, int l, int r,int ind) {
    
 
    if (l > r) 
        if(ind)return -1;
        else return 1000000000;

    if (l == tl && r == tr) {
        return t[v][ind];
    }
    int tm = (tl + tr) / 2;
    int q=sum(v*2, tl, tm, l, min(r, tm),ind);

    int p=sum(v*2+1, tm+1, tr, max(l, tm+1), r,ind);

   
    if(ind==0)return min(p,q);
    return max(p,q);
    
}




 

int main() {

    

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int n,d;
   cn n>>d;
   for (int i = 0; i < n; ++i)
   {
   	scanf("%d",&arr[i]);
   }

   build(1,0,n-1);

   int res=-1;

   for (int i = 0; i+d-1 <n ; ++i)
   {
   	   res=max(res,sum(1,0,n-1,i,i+d-1,1)-sum(1,0,n-1,i,i+d-1,0));
   }
   
   printf("Case %d: %d\n",caseno,res);
   }





    return 0;
}
