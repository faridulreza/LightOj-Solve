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

int main() {

    int n, m, l;
     int T;
            cn T;
        for(int caseno=1; caseno<=T  ;caseno++){
        
        int n;
        cn n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; ++i)
        {
        	int x,y;
        	cn x>>y;
        	v[i]={x,y};
        }

        map<pair<int,int>, int> mp;
        int maxx=0;
        for(auto f: v){
               for(auto s:v){
               	      if(f==s)continue;
               	      int y=f.sc-s.sc;
               	      int x=f.fs-s.fs;
                      int g=gcd(abs(y),abs(x));
                      if(y==0){
                      	mp[{0,f.sc}]++;
                      }
                      else if(x==0){
                      	mp[{f.fs,0}]++;
                      }
                      else{
                      	y/=g;
                      	x/=g;

                      	if(x*y<0){
                      		x=abs(x);
                      		y=-abs(y);
                      	}
                      	else{
                            x=abs(x);
                            y=abs(y);

                      	}

                      	mp[{y,x}]++;

                      }

               	}

              for(auto pp: mp){
                  if(pp.sc>maxx)maxx=pp.sc;

              }
             mp.clear();

        }

        
        printf("Case %d: %d\n",caseno,maxx+1);
        }    







    return 0;
}
