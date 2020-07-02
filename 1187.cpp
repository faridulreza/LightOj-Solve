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

 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
//order_of_key
//find_by_order  
#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 


int main() {

    int T;
           cn T;
       for(int caseno=1; caseno<=T  ;caseno++){
       int n;
       scanf("%d",&n);
       oset st;
       for (int i = 1; i <=n; ++i)
       {
           st.insert(i);
       }

       int arr[n];
       for(int i=0;i<n;i++)scanf("%d",&arr[i]);
       int res;
       int l=n;
       for (int i = n-1; i >=0; --i)
       {
           res=*st.find_by_order(l-arr[i]-1);
           //_(res);
           st.erase(res);
           l--;
       }


       
       printf("Case %d: %d\n",caseno,res);
       }    







    return 0;
}
