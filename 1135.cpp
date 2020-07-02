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

struct node{
	int z=0,o=0,t=0;
};

node t[4*100000];
int lazy[4*100000];

void shift(node &v,int tm){
   
   if(tm==1){
   	 swap(v.z,v.o);
   	 swap(v.z,v.t);
   }
   if(tm==2){
   	                //1 ,2,3
   	 swap(v.z,v.o); //2 1 3
   	 swap(v.z,v.t); //3 1 2

   	 swap(v.z,v.o); //1 3 2
   	 swap(v.z,v.t); //2 3 1
   }

}


void build(int v,int tl,int tr){
  
   if(tl==tr){t[v].z=1,t[v].o=0,t[v].t=0; return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v].z=t[v*2].z+t[v*2+1].z;
   t[v].t=t[v*2].t+t[v*2+1].t;
   t[v].o=t[v*2].o+t[v*2+1].o;


}

void push(int v,int tl,int tr){

   if(lazy[v]){
      if(tl==tr){
        shift(t[v],lazy[v]%3);
        lazy[v]=0;
        return;
      }

      lazy[v*2]+=lazy[v];
      lazy[v*2+1]+=lazy[v];
      shift(t[v],lazy[v]%3);
      lazy[v]=0;
   }



}
 
int sum(int v, int tl, int tr, int l, int r) {
    
    push(v,tl,tr);

    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v].z;
    }
    int tm = (tl + tr) / 2;
    ll q= sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);

   t[v].z=t[v*2].z+t[v*2+1].z;
   t[v].t=t[v*2].t+t[v*2+1].t;
   t[v].o=t[v*2].o+t[v*2+1].o;

    return q;
    
}
 
 
void update(int v, int tl, int tr,int l, int r) {
   
      
    push(v,tl,tr);

    if (l > r) 
        return;

    if (l == tl && r == tr) {
      shift(t[v],1);   
      if(tl!=tr){
        lazy[v*2]+=1;
        lazy[v*2+1]+=1;
      }
        return;
    }



        int tm = (tl + tr) / 2;

        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1),r);


        t[v].z=t[v*2].z+t[v*2+1].z;
        t[v].t=t[v*2].t+t[v*2+1].t;
        t[v].o=t[v*2].o+t[v*2+1].o;
    
}




 

int main() {

    

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n,q;
    scanf("%d%d",&n,&q);

    build(1,0,n-1);
    printf("Case %d:\n",caseno);
    for (int i = 0; i < q; ++i)
    {
    	int qq,a,b;
    	scanf("%d%d%d",&qq,&a,&b);

    	if(qq){
    		printf("%d\n",sum(1,0,n-1,a,b));
    	}
    	else update(1,0,n-1,a,b);
    }
    _0(lazy);
    }





    return 0;
}
