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

int cnt=0;
int kk;

void f(string s,vector<char>v){


   if(v.size()==0){
   	ct s;nl;
   	cnt++;
   	return;
   }

   sort(all(v));

   for (int i = 0; i <v.size(); ++i)
   {

 //  	   _(v[i]);cout<<endl;
   	   char c=v[i];
   	   s.pb(v[i]);
   	   v.erase(v.begin()+i);
   	   f(s,v);
   	   v.insert(v.begin()+i,c);
   	   s.pop_back();
   	   if(cnt==kk)return;

   }

}



int main() {
    
 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
int n,k;
cn n>>k;

vector<char>st;
for (int i = 'A'; i < 'A'+n; ++i)
{
	st.pb(i);

}

if(n<=4){
    int fct=1;
    for (int i = 1; i <=n; ++i)fct*=i;
    k=min(k,fct);
}

cnt=0;
kk=k;

printf("Case %d:\n",caseno);
f("",st);





}




    return 0;
}