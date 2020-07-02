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

int arr[16][16];
int cost[15][1 << 15];
int dp[1 << 15];
int n;

int f(int st)
{

    if(st == (1 << n) - 1)
    {
        return 0;
    }

    if(dp[st] != -1)return dp[st];

    int cst = 1000000000;
    for (int i = 0; i < n; ++i)
    {
        if(!(st & (1 << i)))
        {
            cst = min(cst, cost[i][st] + f(st | (1 << i)));
        }
    }

    return dp[st] = cst;
}



void calcCost(int i, int st, int cst, int fr)
{

    if(i >= n)
    {
        cost[fr][st] = cst + arr[fr][fr];
        return;
    }
    
    if(i == fr)
    {
        calcCost(i + 1, st, cst, fr);
        return;
    }
    calcCost(i + 1, st, cst, fr);
    calcCost(i + 1, st | (1 << i), cst + arr[fr][i], fr);


}

int main()
{




    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn n;
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n ; j++)
            {
                cn arr[i][j];
            }
        }
        _1(dp);


        for (int i = 0; i < n; ++i)
        {
            calcCost(0, 0, 0, i);
        }

        printf("Case %d: %d\n", caseno, f(0));
    }




    return 0;
}
