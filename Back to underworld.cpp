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
double _eps = 1e-6;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int color[20100];

ll cc[4];
int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        vector<int> v[20010];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int u, x;
            scanf("%d%d", &u, &x);
            v[u].pb(x);
            v[x].pb(u);
        }

        _0(color);
        _0(cc);
        ull res=0;
        for(int i = 0; i < 20001; i++)
        {
            if(!color[i] && v[i].size())
            {
                _0(cc);

                queue<pair<int, int>> q;
                q.push({1, i});

                while(!q.empty())
                {
                    int u = q.front().sc;
                    int clr = q.front().fs;
                    q.pop();

                    if(!color[u])
                    {
                        color[u] = clr;
                        cc[clr]++;
                        int cl = (clr == 1) ? 2 : 1;

                        for(int x : v[u])
                        {
                            if(!color[x])
                            {
                                q.push({cl, x});
                            }
                        }
                    }


                }
                res+=max(cc[1],cc[2]);

            }

        }


 
   printf("Case %d: %llu\n",caseno,res);
   


    }


    return 0;
}
