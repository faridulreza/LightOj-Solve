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
 

 
int main()
{
 
    int T;
    cn T;
    getchar();
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
 
        printf("Case %d:\n", caseno);
        char arr[100000+10];
        scanf("%s",arr);
        int n = strlen(arr);
 
        int ts = (int)sqrt(n + .0) + 1;
 
        int tre[ts];
 
        _0(tre);
 
        int m;
        cn m;
        getchar();
 
        for (int i = 0; i < m; ++i)
        {
            char q = getchar();
 
            if(q == 'I')
            {
                int r, l;
                scanf("%d %d",&r,&l);
                r--;
                l--;
                getchar();
                if(r==l){
                  arr[r]=arr[r]=='0'?'1':'0';
                  continue;
                }
               
 
 
                while(r % ts != 0 )
                {
                    arr[r] = arr[r]=='0'?'1':'0';
                    r++;
                }
                while((l + 1) % ts != 0 )      
 
                {
                    arr[l] = arr[l]=='0'?'1':'0';
                    l--;
                }
 
                while(r < l)
                {
                    int seg = r / ts;
                    tre[seg]++;
                    r += ts;
                }
               
                // _fl(arr);
                // for (int i = 0; i <n; ++i)
                // {
                //   ct (arr[i]?1:0)<<" ";
                // }nl;
                // _fl(tre);
                // for (int i = 0; i < ts; ++i)
                // {
                //   ct tre[i]<<" ";
                // }nl;
                // nl;
                // nl;
 
 
            }
            else
            {
 
                int ind;
                scanf("%d",&ind);
                ind--;
                getchar();
                int seg = ind / ts;
 
                if(tre[seg] & 1){int kk=(arr[ind]=='0'?1:0);ct kk;}
                else {int kk=(arr[ind]=='0'?0:1);ct kk;}
                nl;
 
 
            }
           
        }
 
    }
 
 
 
 
 
 
 
    return 0;
}
 