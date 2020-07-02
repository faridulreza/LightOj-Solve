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

char grid[60][60];
int  vis[51][51];
int n, m;
bool collideWithBoundary;


void dfs(int i, int j, char obstacle, int color)
{

    vis[i][j] = color;

    auto go = [&](int xx, int yy, int x, int y)
    {

        xx += x;
        yy += y;
        if(xx >= 0 && xx < n && yy >= 0 && yy < m)
        {
            if(grid[xx][yy] != obstacle && !vis[xx][yy])
                dfs(xx, yy, obstacle, color);
        }
        else collideWithBoundary = true;
    };

    go(i, j, 0, 1);
    go(i, j, 1, 0);
    go(i, j, -1, 0);
    go(i, j, 0, -1);


}

void print()
{

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m ; j++)
        {
            ct vis[i][j] << " ";
        }
        nl;
    }
    nl;
    nl;
}

int main()
{



    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        cn n >> m;
        set<char>st;

        for (int i = 0; i < n; ++i)
        {
            getchar();
            for(int j = 0; j < m ; j++)
            {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')st.insert(grid[i][j]);
            }
        }


        for(char c : st)
        {
            _0(vis);
            int color = 1;
            set<int>colorList;

            for (int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m ; j++)
                {

                    collideWithBoundary = 0;
                    if(grid[i][j] != c && !vis[i][j])dfs(i, j, c, color);

                    if(!collideWithBoundary)
                        colorList.insert(color);
                    
                    color++;
                }
            }

            for(int k = 0; k < n ; k++)
            {
                for(int l = 0; l < m; l++)
                {
                    if(colorList.count(vis[k][l]))
                    {
                        grid[k][l] = c;
                    }
                }

            }

        }

        printf("Case %d:\n", caseno);

        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m ; j++)
            {
                putchar(grid[i][j]);
            }
            nl;
        }






    }





    return 0;
}
