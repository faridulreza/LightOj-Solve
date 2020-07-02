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

unsigned int table[55][55];

unsigned int ncr(int n, int r)
{

    if(n == 0 && r == 0)return 1;
    if(n < 0)return 0;
    if(r == 0)return 1;
    if(table[n][r] != -1)return table[n][r];
    return table[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1));

}

int lim;


struct mat
{
    unsigned int arr[54][54] = {};

    int  make_mat()
    {
        arr[0][0] = 1;
        for (int k = lim - 2, l = 1; k >= 0 ; k--, l++)
        {
            for (int i = 0, m = l; i <= k ; i++, m++)
            {
                arr[l][m] = ncr(k, i);
            }
        }

        for (int i = 1; i < lim; ++i)
        {
            arr[0][i] = arr[1][i];
        }

    }

    mat operator *(mat o)
    {
        mat b;

        for (int i = 0; i < lim; ++i)
        {
            for(int j = 0; j < lim ; j++)
            {
                for(int k = 0; k < lim ; k++)
                {

                    b.arr[i][j] +=(arr[i][k] * o.arr[k][j]);

                }
            }
        }

        return b;
    }

};

void matpower(mat &a, ll b, mat &ans) //a is base, b is exponent
{
    for (int i = 0; i < lim; ++i)ans.arr[i][i]=1;
    	
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }

}





int main()
{

    //explanation http://lbv-pc.blogspot.com/2012/05/summing-up-powers.html
    _1(table);
    
    for (int i = 0; i <=50; ++i)
    {
    	ncr (50,i);
    }

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        ll n;
        int k;

        scanf("%lld %d", &n, &k);

        if(k == 0)
        {
            printf("Case %d: %lld\n", caseno, n%(1ll<<32));
            continue;
        }
        lim = k + 2;
        mat a, b;
        a.make_mat();

        matpower(a, n - 1, b);
        unsigned ans = 0;
        for (int i = 0; i < lim; ++i)
        {
            ans = (ans + b.arr[0][i]);
        }

        printf("Case %d: %u\n", caseno, ans);
    }

    return 0;
}
