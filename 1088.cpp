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

 
int sum(int v, int tl, int tr, int l, int r) {
    
 
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

    
    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   int n,q;
   cn n>>q;



   pair<int,int> v[q];
   int numbers[n+q*2];
   int numcnt=0;
   int arr[n];


   for (int i = 0; i < n; ++i)
   {
   	  scanf("%d",&arr[i]);
       numbers[numcnt++]=arr[i];
   }

   for (int i = 0; i < q; ++i)
   {
   	  scanf("%d %d",&v[i].fs,&v[i].sc);
   	  numbers[numcnt++]=v[i].fs;
   	  numbers[numcnt++]=v[i].sc;
   }
   

   map<int,int> mp;
   int mpcnt=0;
   sort(numbers,numbers+numcnt);
   for(int x:numbers){
   	  if(!mp.count(x))mp[x]=mpcnt++;
   }


   for(int x:arr){
   	  update(1,0,mpcnt-1,mp[x],1);
   }
   
   printf("Case %d:\n",caseno);
   for(auto x:v){
       printf("%d\n",sum(1,0,mpcnt-1,mp[x.fs],mp[x.sc]));
   }


   _0(t);
   
   }






    return 0;
}
