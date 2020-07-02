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

#define int long

 main(){
  int n,r=0;
  cin>>n;
  vector<int> p(n),q(n);
  for(int i=0;i<n;++i)cin>>p[i],q[i]=i;
  sort(q.begin(),q.end(),[&](int a,int b){return p[a]>p[b];});
  
  multiset<int> s;
  s.insert(-1);s.insert(-1);
  s.insert(n);s.insert(n);
_nout(n,q);nl;nl;


  for(auto i:q){
    s.insert(i);
    auto c=s.find(i);
    for(auto x:s)ct x<<" ";
    nl;

    int l1,l2,r1,r2;
    c--;c--;
    l2=*(c++); l1=*(c++);
    r1=*(++c); r2=*(++c);
    r+=((r2-r1)*(i-l1) + (r1-i)*(l1-l2))*p[i];
    _(r2-r1);_(i-l1) ; _(r1-i) ;_(l1-l2);
    _(p[i]);nl;nl;
  }
  cout<<r;

}