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
int fruit[2][1010], cost[2][1010];
int n;

int dp[2][1010];

int f(int i, int tw)
{
    if(i == n)return 0;

    if(dp[tw][i] != -1)return dp[tw][i];


    int x = f(i + 1, tw) + fruit[tw][i];
    int y = f(i + 1, tw ^ 1) + fruit[tw][i] + cost[tw][i];

    return dp[tw][i] = min(x, y);


}


int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        scanf("%d", &n);
        _1(dp);
        for (int i = 0; i < n; ++i)
        {
            /* code */scanf("%d", &fruit[0][i]);
        }
        for (int i = 0; i < n; ++i)
        {
            /* code */scanf("%d", &fruit[1][i]);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            /* code */scanf("%d", &cost[0][i]);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            /* code */scanf("%d", &cost[1][i]);
        }



        printf("Case %d: %d\n", caseno, min(f(0, 0), f(0, 1)));
    }





    return 0;
}
