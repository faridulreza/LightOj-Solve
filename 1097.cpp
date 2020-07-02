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






int t[4*1500000];

void build(int v,int tl,int tr){
  
   if(tl==tr){t[v]=(tl&1); return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v]=t[v*2]+t[v*2+1];


}

 
int find(int v, int tl, int tr,int k) {
    

    if (tl==tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int q;

    if(k<=t[v*2])q=find(v*2, tl, tm, k);
    else q=find(v*2+1, tm+1, tr, k-t[v*2]);

    return q;
    
}
 
 



void update(int v, int tl, int tr, int pos, ll new_val) {
    
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
 
 
int main() {

    

  int sz=1500000;
  build(1,0,sz-1);
  
  int rIndex=2;

  while(rIndex<=100000){
       
       int remove=find(1,0,sz-1,rIndex);
      // _(remove);
       
       vector<int> removelist;
       for (int i = remove; i <sz ; i+=remove)
       {
       	 if(i<=t[1])removelist.pb(find(1,0,sz-1,i));
       	 else break;
       	 //_(removelist.back());
       }

       for(int x:removelist)update(1,0,sz-1,x,0);
       rIndex++;
  }
   


   int T;
      cn T;
  for(int caseno=1; caseno<=T  ;caseno++){
  int n;
  scanf("%d",&n);
  
  printf("Case %d: %d\n",caseno,find(1,0,sz-1,n));
  }


    return 0;
}
