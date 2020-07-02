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

ll mem[100];

ll power(ll a, ll b)	//a is base, b is exponent
{
    if(b < 0)return 0;
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b % 2 == 1)
        return (power(a, b - 1) * a);
    ll q = power(a, b / 2);
    return (q * q);
}

ll getN(ll num,vector<bool> &nm)
{
    //returns the n of the number 
    //if num is not in the series 
    //returns the n of the greatest number < num that is on the series

    ll tmp = num;

    nm.clear();
    while(num)
    {
        nm.pb(num & 1);
        num = num >> 1;
    }
    reverse(all(nm));
    int sz = nm.size();

    ll notcnt = mem[sz - 1];

    for (int i = 1; i < sz; ++i)
    {

        if(nm[i] == 1)
        {
        	
            notcnt += mem[sz - i - 1];

            if(nm[i - 1] == 1)
            {
            	// num is not in the series 
            	// so count the serial number of num in the not series(3,6,7,11...)

                ll x = 0;
                for(int j = i + 1; j < sz ; j++)
                {
                    if(nm[j])
                    {
                        x += power(2, sz - j - 1);
                    }
                }
                notcnt += x + 1;
                break;
            }

        }
    }


    return tmp - notcnt;
}


int main()
{


    mem[2] = 1;

    ll tm = 2;

    /*
       mem[i] is count of (numbers of binary length 1 to i) that 
       are not in the series 

    */

    for (int i = 3; i < 64; ++i)
    {

        mem[i] += mem[i - 2] + tm;
        /*
          to count of length 4 (1000 to 1111)
          need to count for length 2 ,for this case 10 00<- (count for this last two bits) 
          plus
          for this case 11 00 ,count for how many numbers 2nd bit was set.   
        */
        tm *= 2;
        mem[i] += mem[i - 1];
    }



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n;
        cn n;


        ll low = 1, up = 1ll << 44;
        printf("Case %d: ", caseno);
        vector<bool>nm;
        while(1)
        {

            ll mid = (low + up) / 2;
            ll x = getN(mid,nm);

            if(low == up)
            {
                for(int xx:nm)printf("%d",xx);nl;
                break;
            }


            if(n < x)up = mid - 1;
            else if(n==x)up=mid;
            else low = mid + 1;


        }


    }






    return 0;
}
