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

int dp[10010];

int f(int s)
{

    if(s == 1 || s == 2)return 0;


    if(dp[s] != -1)return dp[s];

    int lm = s / 2;
    unordered_set<int> st;
    if(s % 2 == 0)lm--;

    for (int i = 1; i <= lm ; ++i)
    {

        int x = f(i)^f(s - i);
        st.insert(x);

    }

    int i = 0;

    while(st.find(i) != st.end())
        i++;

    return dp[s] = i;


}

int main()
{


    _1(dp);

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int a;
        scanf("%d", &a);
        int ans = 0;
        for (int i = 0; i < a; ++i)
        {
            int b;
            scanf("%d", &b);
            ans ^= f(b);
        }
        
        if(ans)
            printf("Case %d: Alice\n", caseno);
        else printf("Case %d: Bob\n", caseno);
    }




    return 0;
}
