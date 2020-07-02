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

#define pii pair<int,int>

ll concat(ll a, ll b)
{
    if(b >= 10000)return a * 10000 + b;
    if(b >= 1000)return a * 1000 + b;
    if(b >= 100)return a * 1000 + b;
    if(b >= 10)return a * 100 + b;
    return a * 10 + b;
}

ll toHash(pii pos[])
{

    ll hs = concat(pos[0].fs, pos[0].sc);
    ll hs2 = concat(pos[1].fs, pos[1].sc);
    ll hs3 = concat(pos[2].fs, pos[2].sc);

    hs = concat(hs, hs2);
    hs = concat(hs, hs3);

    return hs;
}
struct tp
{
    pii pos[3];
    tp(const pii ps[])
    {
        pos[0] = ps[0];
        pos[1] = ps[1];
        pos[2] = ps[2];
    }
    tp() {}

};


char grid[12][12];
int n;

map<ll, int>mp;
vector<int>adj[200000];
int node_cnt;

tp go(const pii ps[], int xp, int yp)
{
    tp tmp(ps);
    pii pos[3];
    pos[0] = ps[0];
    pos[1] = ps[1];
    pos[2] = ps[2];
    bool moved[3];
    _0(moved);
    int mv = 0;

    //loop while all 3 points are not moved
    while(mv != 3)
    {
        //try to move all three
        for (int i = 0; i < 3; ++i)
        {
            if(moved[i])continue;
            int x = tmp.pos[i].fs + xp;
            int y = tmp.pos[i].sc + yp;


            if(x > 0 && x <= n && y > 0 && y <= n && grid[x][y] != '#')
            {
                pii p = {x, y};
                bool matched = false;

                //check if this new point 'p' point collides with other two existing point
                for(int j = 0; j < 3; j++)
                {
                    if( i != j && pos[j] == p)
                    {
                        //ok p collides with pos[j]
                        matched = true;

                        if(moved[j])
                        {
                            //pos[j] is already moved. nothing to do here we cant move pos[i]
                            // so mark it as moved
                            moved[i] = true;
                            mv++;
                            break;
                        }
                        else
                        {
                            //ok p collides with pos[j]. but pos[j] hasnt been moved yet .
                            //we will try to move pos[j] and later try with pos[i] again
                            break;
                        }


                    }

                }

                if(!matched)
                {
                    //not collided with any other points .so update;
                    tmp.pos[i] = p;
                    moved[i] = true;
                    pos[i] = p;
                    mv++;
                }

            }
            else
            {
                //new positon collides with boundary or obstacle .mark it as moved
                moved[i] = true;
                mv++;
            }
        }

    }

    //sort so that ABC is same as BCA
    sort(tmp.pos, tmp.pos + 3);
    return tmp;

}


void make_graph(const pii strt[])
{

    //each unique position is a node

    for (int i = 0; i < 200000; ++i)
    {
        adj[i].clear();
    }
    mp.clear();

    node_cnt = 1;
    queue<tp>q;
    set<ll>qset;

    tp pos(strt);
    sort(pos.pos, pos.pos + 1);
    ll hs = toHash(pos.pos);

    q.push(pos);
    qset.insert(hs);
    mp[hs] = node_cnt++;



    while(!q.empty())
    {

        tp node = q.front();
        q.pop();

        ll thisHs = toHash(node.pos);
        int  thisNode = mp[thisHs];

        tp up = go(node.pos, -1, 0),
           down = go(node.pos, 1, 0),
           left = go(node.pos, 0, -1),
           right = go(node.pos, 0, 1);

        ll uphs = toHash(up.pos),
           dhs = toHash(down.pos),
           lhs = toHash(left.pos),
           rhs = toHash(right.pos);
        int unode, dnode, lnode, rnode;

        if(uphs == thisHs || qset.count(uphs))
        {
            unode = mp[uphs];
        }
        else
        {
            mp[uphs] = unode = node_cnt++;
            qset.insert(uphs);
            q.push(up);
        }

        if(dhs == thisHs || qset.count(dhs))
        {
            dnode = mp[dhs];
        }
        else
        {
            mp[dhs] = dnode = node_cnt++;
            qset.insert(dhs);
            q.push(down);
        }


        if(lhs == thisHs || qset.count(lhs))
        {
            lnode = mp[lhs];
        }
        else
        {
            mp[lhs] = lnode = node_cnt++;
            qset.insert(lhs);
            q.push(left);
        }

        if(rhs == thisHs || qset.count(rhs))
        {
            rnode = mp[rhs];
        }
        else
        {
            mp[rhs] = rnode = node_cnt++;
            qset.insert(rhs);
            q.push(right);
        }

        if(thisNode != unode)adj[thisNode].pb(unode);
        if(thisNode != dnode)adj[thisNode].pb(dnode);
        if(thisNode != rnode)adj[thisNode].pb(rnode);
        if(thisNode != lnode)adj[thisNode].pb(lnode);


    }

}



int bfs(pii strt[], pii edn[])
{

    sort(strt, strt + 3);
    sort(edn, edn + 3);

    int st = mp[toHash(strt)];
    int ed = mp[toHash(edn)];

    bool vis[node_cnt + 10];
    int dist[node_cnt + 10];
    for (int i = 0; i <= node_cnt; ++i)
    {
        vis[i] = false;
        dist[i] = 1000000000;
    }
    queue<int>q;
    q.push(st);
    dist[st] = 0;
    while(!q.empty())
    {

        int u = q.front();
        q.pop();

        if(vis[u])continue;
        vis[u] = true;
        for(int v : adj[u])
        {

            if(!vis[v])
            {
                dist[v] = min(dist[v], 1 + dist[u]);
                q.push(v);
            }

        }


    }

    return (dist[ed] == 1000000000 ? -1 : dist[ed]);

}

int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        cn n;

        pii strt[3], ed[3];
        int s = 0, e = 0;
        for (int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n ; j++)
            {

                cn grid[i][j];
                char c = grid[i][j];

                if(c == 'A' || c == 'B' || c == 'C')strt[s++] = {i, j};
                if(grid[i][j] == 'X')ed[e++] = {i, j};

            }
        }

        make_graph(strt);

        int dist = bfs(strt, ed);

        if(dist == -1)printf("Case %d: trapped\n", caseno);
        else printf("Case %d: %d\n", caseno, dist);
    }

    return 0;
}
