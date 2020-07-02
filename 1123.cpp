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



vector<int>parent;
vector<int> size;
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int n)
{
    parent.clear();
    size.clear();
    parent.resize(n + 1);
    size.assign(n + 1, 1);

    for (int i = 1; i <= n; ++i)
        parent[i] = i;
}

int union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return 1;
    }
    else return 0;
}


using pii = pair<int, pair<int, int>>;

int mst(int n, vector<pii> &lst, int sign, set<pii> &st)
{
    make_set(n);

    priority_queue<pii>pq;

    for(auto x : lst)pq.push({x.fs * sign, x.sc});

    int res = 0;
    int sets = n;

    while(!pq.empty())
    {

        pii  v = pq.top();
        v.fs *= sign;
        pq.pop();
        if(union_sets(v.sc.fs, v.sc.sc))
        {
            st.insert(v);
            res += v.fs;
            sets--;
        }

    }

    if(sets == 1)return res;
    return -1;


}



int main()
{



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int n, m;
        cn n >> m;

        vector<pii>lst;


        if(n == 1)
        {
            printf("Case %d:\n", caseno);
            for(int j = 0; j < m; j++)
            {

                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                printf("0\n");
            }
            continue;
        }


        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            lst.pb({c, {a, b}});
        }

        vector<int>res;
        set<pii>edges;

        int r = mst(n, lst, -1, edges);
        res.pb(r);



        for (int i = m - 1; i >= 1; i--)
        {
            if(r == -1)
            {
                res.pb(r);
                continue;
            }

            pii v = lst[i];
            lst.pop_back();
            m--;
            if(edges.count(v))
            {
                //_fl(dff);
                edges.erase(v);

                for(int j = 1; j <= n ; j++)
                {
                    parent[j] = j;
                    size[j] = 1;
                }

                for(auto x : edges)union_sets(x.sc.fs, x.sc.sc);

                int a, b, mnindx = -1;
                int mnval = 1000000000;

                for(int j = 0; j < m ; j++)
                {
                    a = find_set(lst[j].sc.fs);
                    b = find_set(lst[j].sc.sc);

                    if(a != b && lst[j].fs < mnval)mnval = lst[j].fs, mnindx = j;
                }

                if(mnindx == -1)r = -1;
                else
                {
                    r -= v.fs;
                    r += lst[mnindx].fs;
                    edges.insert(lst[mnindx]);
                    // _(mnindx);
                }



            }


            res.pb(r);
        }

        printf("Case %d:\n", caseno);
        for (int i = res.size() - 1; i >= 0; --i)
        {
            printf("%d\n", res[i]);
        }



    }





    return 0;
}
