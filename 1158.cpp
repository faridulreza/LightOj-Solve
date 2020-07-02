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

vector<int> v;
int md, n;
int dp[1034][1001];

int f(int j, int st, int sm)
{

    if(j == n)
    {
        return (!sm);
    }
      
    if(dp[st][sm]!=-1)return dp[st][sm];

    int last = -1;
    int ans = 0;
    ll base = 1;
    for (int i = 0; i < j; ++i)
    {
        base *= 10;
    }

    for (int i = 0; i < n; ++i)
    {
        if(v[i] == last || (st&(1<<i)))continue;
        last = v[i];
        ans += f(j + 1, st | (1 << i), (sm + v[i] * base) % md);
    }

    return dp[st][sm]=ans;

}

int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        string s;
        cn s >> md;
        v.clear();

        for(char c : s)
        {
            v.pb(c - '0');
        }

        n = v.size();
        sort(all(v));


         _1(dp);

        printf("Case %d: %d\n",caseno,f(0,0,0));
    }







    return 0;
}
