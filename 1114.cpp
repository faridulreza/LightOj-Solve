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


struct node
{
    map<pair<int, char>, int>mp;
    int cnt = 0;
    vector<node *> v;
    int end = 0;
};

map<string, int> startMp;
map<char, int>charMp;
vector<node *> stv;
int stcnt;

void deleter(node *u)
{

    for(node *w : u->v)
    {
        deleter(w);
        delete w;
    }
    u->mp.clear();
    u->v.clear();
}

ll getC(string w)
{


    string tmp;
    tmp.pb(w[0]);
    tmp.pb(w.back());

    int idx;
    if(startMp.count(tmp))idx = startMp[tmp];
    else return 0;

    int arr[140];
    _0(arr);

    for (int i = 1; i < w.size() - 1 ; ++i)
    {
        arr[w[i]]++;
    }

    node *cur = stv[idx];


    for (int i = 'a'; i <= 'z' ; ++i)
    {
        if(arr[i])
        {
            pair<int, char> p = {arr[i], i};
            if(cur->mp.count(p))
            {
                idx = cur->mp[p];
            }
            else
            {
                return 0;
            }

            cur = cur->v[idx];
        }
    }

    for (int i = 'A'; i <= 'Z' ; ++i)
    {
        if(arr[i])
        {
            pair<int, char> p = {arr[i], i};
            if(cur->mp.count(p))
            {
                idx = cur->mp[p];
            }
            else
            {
                return 0;
            }

            cur = cur->v[idx];
        }
    }

    return cur->end;

}


int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        int n;
        cn n;
        char w[110];
        stcnt = 0;
        for (int i = 0; i < n; ++i)
        {
            getchar();
            scanf("%s", w);

            int len = strlen(w);
            if(len == 1)
            {
                charMp[w[0]]++;
                continue;
            }
            string tmp;
            tmp.pb(w[0]);
            tmp.pb(w[len - 1]);

            int idx;
            if(startMp.count(tmp))
            {
                idx = startMp[tmp];
            }
            else
            {
                startMp[tmp] = idx = stcnt++;
                stv.pb(new node());
            }

            int arr[140];
            _0(arr);

            for (int i = 1; i < len - 1 ; ++i)
            {
                arr[w[i]]++;
            }

            node *cur = stv[idx];
            node *head = cur;

            for (int i = 'a'; i <= 'z' ; ++i)
            {
                if(arr[i])
                {
                    pair<int, char> p = {arr[i], i};
                    if(cur->mp.count(p))
                    {
                        idx = cur->mp[p];
                    }
                    else
                    {
                        cur->mp[p] = idx = cur->cnt++;
                        cur->v.pb(new node());
                    }

                    cur = cur->v[idx];
                }
            }
            for (int i = 'A'; i <= 'Z' ; ++i)
            {
                if(arr[i])
                {
                    pair<int, char> p = {arr[i], i};
                    if(cur->mp.count(p))
                    {
                        idx = cur->mp[p];
                    }
                    else
                    {
                        cur->mp[p] = idx = cur->cnt++;
                        cur->v.pb(new node());
                    }

                    cur = cur->v[idx];
                }
            }
            cur->end++;

        }

        int m;
        scanf("%d", &m);

        getchar();

        printf("Case %d:\n", caseno);

        for (int i = 0; i < m; ++i)
        {
            char c;
            string tmp;
            ll res = 1;

            while((c = getchar()) != '\n')
            {

                if(c == ' ')
                {
                    int sz = tmp.size();
                    if(sz == 1)res *= (ll)charMp[tmp[0]];
                    else if(sz)res *= getC(tmp);
                    tmp.clear();
                }
                else tmp.pb(c);

            }

            int sz = tmp.size();
            if(sz == 1)res *= (ll)charMp[tmp[0]];
            else if(sz)res *= getC(tmp);
            
            printf("%lld\n", res);
        }


        for(auto x : stv)deleter(x);
        startMp.clear();
        stv.clear();
        charMp.clear();


    }




    return 0;
}
