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

ll dp[205][20][11];
int arr[205];
int d, n;

ll f(int i, int sum, int m)
{

    if(m == 0)
    {
        if(sum == 0)return 1;
        else return 0;
    }
    if(i == n)return 0;

    if(dp[i][sum][m] != -1)return dp[i][sum][m];

    return dp[i][sum][m] = f(i + 1, (d+(sum + arr[i]) % d)%d,m-1) + f(i + 1, sum, m);
}


int main()
{



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn n;
        int q;
        cn q;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }

        printf("Case %d:\n", caseno);
        for (int i = 0; i < q; ++i)
        {
            int a;
            scanf("%d%d", &d, &a);
            _1(dp);
            printf("%lld\n", f(0, 0, a));
        }
    }





    return 0;
}
