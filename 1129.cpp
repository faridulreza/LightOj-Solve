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

char* solve(vector<string> &v,unordered_set<string> &st){


    for (int i = 0; i < v.size(); ++i)
    {
    	st.erase(v[i]);
        string tmp=v[i];

        while(tmp.size()){
        	tmp.pop_back();
        	if(st.count(tmp))return "NO\n";
        }
        st.insert(v[i]);

    }

    return "YES\n";


}



int main() {

    
   int T;
      cn T;
  for(int caseno=1; caseno<=T  ;caseno++){
  
  int n;
  scanf("%d",&n);
  unordered_set<string> st;

  vector<string> v(n);
  int br=1;
  for (int i = 0; i < n; ++i)
  {
  	cn v[i];
  	if(st.count(v[i])){
       br=0;     
  	}
  	st.insert(v[i]);

  }


  if(!br){printf("Case %d: NO\n",caseno);continue;}
  
  printf("Case %d: %s",caseno,solve(v,st));
  }






    return 0;
}
