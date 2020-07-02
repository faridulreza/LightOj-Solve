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





int t[4*150000];
int lazy[4*150000];


void push(int v,int tl,int tr){

   if(lazy[v]){
      if(tl==tr){
        t[v]+=lazy[v];
        lazy[v]=0;
        return;
      }

      lazy[v*2]+=lazy[v];
      lazy[v*2+1]+=lazy[v];
      t[v]+=(tr-tl+1)*lazy[v];
      lazy[v]=0;
   }



}
 
int sum(int v, int tl, int tr, int l, int r) {
    
    push(v,tl,tr);

    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    ll q= sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);

    t[v] = t[v*2] + t[v*2+1];
    
    return q;
    
}
 
 
void update(int v, int tl, int tr,int l, int r, ll val) {
   
      
    push(v,tl,tr);

    if (l > r) 
        return;

    if (l == tl && r == tr) {
    	t[v]+=(tr-tl+1)*val;
    	
    	if(tl!=tr){
    		lazy[v*2]+=val;
    		lazy[v*2+1]+=val;
    	}
        return;
    }



        int tm = (tl + tr) / 2;

        update(v*2, tl, tm, l, min(r, tm),val);
        update(v*2+1, tm+1, tr, max(l, tm+1),r,val);

        t[v] = t[v*2] + t[v*2+1];
    
}



 


int main() {

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int n,q;
   cn n>>q;

   pair<int,int> v[n];
   int numbers[n*2+q];
   int numcnt=0;
   for (int i = 0; i < n; ++i)
   {
   	  scanf("%d %d",&v[i].fs,&v[i].sc);
   	  numbers[numcnt++]=v[i].fs;
   	  numbers[numcnt++]=v[i].sc;
   }
   int arrq[q];
   for (int i = 0; i < q; ++i)
   {
   	  scanf("%d",&arrq[i]);
       numbers[numcnt++]=arrq[i];
   }

   map<int,int> mp;
   int mpcnt=0;
   sort(numbers,numbers+numcnt);
   for(int x:numbers){
   	  if(!mp.count(x))mp[x]=mpcnt++;
   }


   for(auto x:v){
   	 // ct mp[x.fs] spc mp[x.sc],nl;
   	  update(1,0,mpcnt-1,mp[x.fs],mp[x.sc],1);
   }
   
   printf("Case %d:\n",caseno);
   for(int x:arrq){

   	   int y=mp[x];
       printf("%d\n",sum(1,0,mpcnt-1,y,y));
   }


   _0(t);
   _0(lazy);
   
   }






    return 0;
}
