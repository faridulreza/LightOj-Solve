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

ll fact[24];

string f(multiset<char> &mst, ll n)
{

    if(n == 0)
    {

        string ret;

        for(char ch : mst)ret.pb(ch);

        return ret;
    }

    set<char>st;
    for(char ch : mst)st.insert(ch);

    for(char ch : st)
    {

        ll prm = fact[mst.size() - 1];

        for(char c : st)
        {

            if(c == ch)
            {
                prm /= fact[mst.count(c) - 1];
            }
            else prm /= fact[mst.count(c)];

        }

        if(prm <= n)n -= prm;
        else
        {
            string s;
            s.pb(ch);

            multiset<char>nmst(mst);
            nmst.erase(ch);
            int cnt = mst.count(ch) - 1;

            for (int i = 0; i < cnt; ++i)
            {
                nmst.insert(ch);
            }

            return s + f(nmst, n);
        }
    }
}

int main()
{

    fact[0] = 1;

    for (int i = 1; i < 21; ++i)
    {
        fact[i] = fact[i - 1] * i;
    }


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        string inp;
        cn inp;
        ll n;
        cn n;
        n--;

        multiset<char>st;
        set<char>tmst;
        for(char ch : inp)st.insert(ch), tmst.insert(ch);

        ll prm = fact[inp.size()];

        for(char ch : tmst)
        {
            prm /= fact[st.count(ch)];
        }


        printf("Case %d: ", caseno);
        if(n + 1 > prm)ct "Impossible";
        else ct f(st, n);
        nl;
    }

    return 0;
}
