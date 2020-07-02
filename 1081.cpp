
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

int tr[4 * 500][4 * 500];
int grid[510][510];
int n, m;

void buildy(int vx, int tlx, int trx, int vy, int tly, int trY)
{

    if(tly == trY)
    {
        if(tlx == trx)tr[vx][vy] = grid[tlx][tly];
        else
        {
            tr[vx][vy] = max(tr[vx * 2][vy], tr[vx * 2 + 1][vy]);
        }
        return;
    }



    int mid = (tly + trY) / 2;
    buildy(vx, tlx, trx, vy * 2, tly, mid);
    buildy(vx, tlx, trx, vy * 2 + 1, mid + 1, trY);
    tr[vx][vy] = max(tr[vx][vy * 2], tr[vx][vy * 2 + 1]);
}

void buildx(int vx, int tlx, int trx)
{


    if(tlx != trx)
    {
        int mid = (tlx + trx) / 2;
        buildx(vx * 2, tlx, mid);
        buildx(vx * 2 + 1, mid + 1, trx);
    }

    buildy(vx, tlx, trx, 1, 0, m - 1);

}


int queryy(int vx, int vy, int tly, int trY, int y1, int y2)
{

    if(y1 > y2)return -1;

    if(tly == y1 && trY == y2)return tr[vx][vy];



    int mid = (tly + trY) / 2;
    int res1 = queryy(vx, vy * 2, tly, mid,  y1, min(mid, y2));
    int res2 = queryy(vx, vy * 2 + 1, mid + 1, trY,  max(mid + 1, y1), y2);
    return max(res1, res2);
}

int queryx(int vx, int tlx, int trx, int x1, int x2, int y1, int y2)
{
    if(x1 > x2)return -1;

    if(tlx == x1 && trx == x2)
    {

        return queryy(vx, 1, 0, m - 1, y1, y2);

    }



    int mid = (tlx + trx) / 2;

    int res1 = queryx(vx * 2, tlx, mid,   x1, min(mid, x2),  y1, y2);
    int res2 = queryx(vx * 2 + 1, mid + 1, trx,   max(mid + 1, x1), x2,  y1, y2);
    return max(res1, res2);
}



int main()
{

    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
       int q;

        cn n >> q;
        m=n;
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m ; j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }

        buildx(1, 0, n - 1);

        printf("Case %d:\n",caseno);

        for (int i = 0; i < q; ++i)
        {
            int x, y, w;
            scanf("%d%d%d",&x,&y,&w);
            x--;y--;
            int x2 = x + w - 1;
            int y2 = y + w - 1;
            printf("%d\n", queryx(1, 0, n - 1, x, x2, y, y2));
            
        }

    }
    return 0;
}
