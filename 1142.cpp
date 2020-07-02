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

int lim;
int mod = 10;

struct mat
{
    typedef char TYPE;

    int arr[32][32]={};


    int  make_mat()
    {
        arr[0][0] = 1;
        arr[0][1] = 1;
        arr[1][0] = 1;
        arr[1][1] = 0;
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

                    b.arr[i][j] = (b.arr[i][j] + (1l * (arr[i][k] * o.arr[k][j])) % mod) % mod;

                }
            }
        }

        return b;
    }

    mat operator +(mat o)
    {
        mat r;

        for (int i = 0; i < lim; ++i)
        {
            for(int j = 0; j < lim ; j++)
            {
                r.arr[i][j] = (0l + arr[i][j] + o.arr[i][j]) % mod;
            }
        }
        return r;
    }

    void identity()
    {
        for (int i = 0; i < lim; ++i)
        {
        	for(int j=0; j<lim ; j++){
        	    arr[i][j]=0;
        	}
        }

        for (int i = 0; i < lim; ++i)
        {
            arr[i][i] = 1;
        }
    }

};


mat matpower(mat a, ll b)
{
    mat ans;
    ans.identity();

    while (b > 0)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}


mat powerSum(mat x, int k)
{
    
    if(k == 0)
    {
        mat i;
        i.identity();
        return i;
    }
    if(k == 1)
    {
        mat i;
        i.identity();
        i = i + x;
        return i;
    }

    mat res;

    if(k & 1)
    {
        res = powerSum(x*x, k / 2);
        res = res + x * res;
    }
    else
    {
        res = powerSum(x, k - 1);
        mat i;
        i.identity();

        res = i + x * res;
    }

    return res;

}



int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n,k;

        scanf("%d%d",&n,&k);
        lim=n;

        mat a;
        
        for (int i = 0; i < n; ++i)
        {
        	for(int j=0; j<n ; j++){
        	    scanf("%d",&a.arr[i][j]);
        	}
        }

        a=a*powerSum(a,k-1);


        printf("Case %d:\n",caseno);
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		printf("%d",a.arr[i][j]);
        	}nl;
        }
    }






    return 0;
}
