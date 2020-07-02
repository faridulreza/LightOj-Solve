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


int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n, m;

        scanf("%d%d", &n, &m);
        map<int,int>mp;

        mp[0]=1;
        ll ans=0;
        ll sum=0;
        for (int i = 0; i < n; ++i)
        {
        	int a;
        	scanf("%d",&a);
        	sum=(sum+a)%m;
        	ans+=mp[sum];
        	mp[sum]++;
        }


        printf("Case %d: %lld\n",caseno,ans);
    }







    return 0;
}
