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

int n, m;
vector< pair<int, pair<int, int>> > v;
bool vis[13][13];
int turns[13][13][120];
int r(int x, int y)
{

    if(x >= 0 && x < n && y >= 0 && y < m)return 1;
    return 0;


}
int cc(int t, int x)
{
    if(t % x)return t / x + 1;
    else return t / x;
}

int main()
{


 int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
    
    v.clear();
    _0(turns);

    cn n >> m;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m ; j++)
        {
            int c;
            if((c = getchar()) != '.')
            {
                c = c - '0';
                v.pb ({c, {i, j}});
            }
        }
        getchar();
    }

    int tc=0;
    for(auto x : v)
    {

        int k = x.fs;
        _0(vis);
        queue< pair<int,pair<int,int>> >q;
        q.push({0, x.sc});
        turns[x.sc.fs][x.sc.sc][tc]=-1;
        int t=1;

        while(!q.empty())
        {


            int pr = q.front().fs;
            pair<int, int>p = q.front().sc;
            q.pop();


            t = cc(pr+1, k);

            if(!vis[p.fs][p.sc])
            {
                vis[p.fs][p.sc] = true;
                int x, y;

                x = p.fs + 1, y = p.sc + 2;
                if(r(x, y) && !vis[x][y])
                {
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
   
                    q.push({pr + 1, {x, y}});
                }

                x = p.fs + 1, y = p.sc - 2;
                if(r(x, y) && !vis[x][y])
                {
                	if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;

                    q.push({pr + 1, {x, y}});
                }
                x = p.fs + 2, y = p.sc + 1;
                if(r(x, y) && !vis[x][y])
                {
                	
                	if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }
                x = p.fs + 2, y = p.sc - 1;
                if(r(x, y) && !vis[x][y])
                {
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }
                x = p.fs - 1, y = p.sc + 2;
                if(r(x, y) && !vis[x][y])
                {
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }
                x = p.fs - 1, y = p.sc - 2;
                if(r(x, y) && !vis[x][y])
                {
       
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }
                x = p.fs - 2, y = p.sc + 1;
                if(r(x, y) && !vis[x][y])
                {
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }

                x = p.fs - 2, y = p.sc - 1;
                if(r(x, y) && !vis[x][y])
                {
                    if(turns[x][y][tc])turns[x][y][tc]=min(turns[x][y][tc],t);
                	else turns[x][y][tc]=t;
                	q.push({pr + 1, {x, y}});
                }

            }

            
                    // _(p.fs);
                    // _(p.sc);
                    // for(int z: turns[0][0])ct " ",_(z);
                    // 	nl;
             


        }
        tc++;

    }




    int mn = _109;
    int kk=v.size();

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m ; j++)
        {
        	int c=0;
        	int sum=0;
           for(int k=0; k<kk ; k++){
               if(turns[i][j][k]!=-1)sum+=turns[i][j][k];
               if(turns[i][j][k])c++;
            //_(turns[i][j][k]);
               
           }
           if(c==kk)mn=min(mn,sum);
           //_(c);

        }
    }


    if(mn==_109) printf("Case %d: -1\n",caseno);
    else printf("Case %d: %d\n",caseno,mn);

    }
    return 0;
}