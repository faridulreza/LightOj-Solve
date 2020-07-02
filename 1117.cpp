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
double _eps = 1e-6;
ll n, m;
ll res;
ll arr[20];
	
	ll gcd( ll a, ll b )
	{
		if(b==0)
		{
		     return a;
		}
		else
		{
		     return gcd( b, a%b );
		}
	}
	

void calc(int i, int level, int up, ull val)
{
    if(level == up)
    {

        if(level & 1)res += (n / val);
        else res -= (n / val);
    }

    for (; i < m; ++i){
      ll g=gcd(val,arr[i]);
      ll tma=val/g;
      ll tmb=arr[i]/g;

      ull v=tma*tmb*1ull*g;
      if(v<=n)
      	calc(i + 1, level + 1, up, v);
    }


}


int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn n >> m;

        int tmp[20];

        for (int i = 0; i < m; ++i)
            cn tmp[i];

        sort(tmp, tmp + m);

        for (int i = 0; i < m; ++i)
            for(int j = i + 1; j < m && tmp[i]; j++)
                if(tmp[j] % tmp[i] == 0)tmp[j] = 0;

        int cnt=0;

        for(int i=0;i<m;i++)if(tmp[i])arr[cnt++]=tmp[i];

        m=cnt;
        res = 0;

        for (int i = 1; i <= m ; ++i)
            calc(0, 0, i, 1);



        printf("Case %d: %lld\n", caseno, n - res);
    }







    return 0;
}
