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
int n,k;
int arr[1200];


bool isp(int val){
   
  //_(val);
  int ret=true;
  int stp=0;
  for (int i = 0; i < n;)
  {
  	int sm=0;

  	while(i<n){
       
       if(sm+arr[i]<=val)sm+=arr[i];
       else {stp++;break;}
       i++;

  	}
  	if(sm==0){ret=false;break;}


  }

  
  if(ret){
  	if(stp<=k)return true;
  }
  return false;

}


int main() {

    



 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
   cn n>>k;
   n++;

   for (int i = 0; i <n ; ++i)
   {
   	/* code */cn arr[i];
   }


   int up=10000000,dw=0;

   int mid=(up+dw)/2;

   while(dw<up){

     if(isp(mid))up=mid;
     else dw=mid+1;
     mid=(up+dw)/2;
   }

   
   printf("Case %d: %d\n",caseno,mid);
   int stp=0;
   vector<int>res[1110];

   for (int i = 0; i < n; )
   {  
   	   int sm=0;
   	   while(i<n){
         if(sm+arr[i]<=mid){
            res[stp].pb(arr[i]);
            sm+=arr[i];
         }
         else {
         	stp++;
         	break;
         }
         i++;
   	   }
   }
   
  
   stp++;
  // _(stp);
   
   stack<int>st;
   if(stp!=k+1){
      
     while(true){

         for (int i = res[stp-1].size()-1; i >=0; i--)
         {
         	st.push(res[stp-1][i]);
         	res[stp-1].pop_back();

         	if(stp+st.size()==k+1)break;
         }
          
         if(res[stp-1].size()==0)stp--;
         if(stp+st.size()==k+1)break;
         
     }
   }

   for (int i = 0; i < stp; ++i)
   {
   	  int sm=0;
   	  for(int x:res[i])sm+=x;
   	  ct sm,nl;	
   }

   while(!st.empty()){ct st.top();nl;st.pop();}


}



    return 0;
}
