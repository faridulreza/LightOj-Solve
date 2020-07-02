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
double _eps=1e-6;

const int inf = 1000000000;

int n;
vector<vector<int>> capacity, flow;
vector<int> height, excess;

void push(int u, int v)
{
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}

void relabel(int u)
{
    int d = inf;
    for (int i = 0; i < n; i++) {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}

vector<int> find_max_height_vertices(int s, int t) {
    vector<int> max_height;
    for (int i = 0; i < n; i++) {
        if (i != s && i != t && excess[i] > 0) {
            if (!max_height.empty() && height[i] > height[max_height[0]])
                max_height.clear();
            if (max_height.empty() || height[i] == height[max_height[0]])
                max_height.push_back(i);
        }
    }
    return max_height;
}

int max_flow(int s, int t)
{
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<int>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (int i = 0; i < n; i++) {
        if (i != s)
            push(s, i);
    }

    vector<int> current;
    while (!(current = find_max_height_vertices(s, t)).empty()) {
        for (int i : current) {
            bool pushed = false;
            for (int j = 0; j < n && excess[i]; j++) {
                if (capacity[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1) {
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed) {
                relabel(i);
                break;
            }
        }
    }

    int max_flow = 0;
    for (int i = 0; i < n; i++)
        max_flow += flow[i][t];
    return max_flow;
}



int main() {

    

   int T;
      cn T;
  for(int caseno=1; caseno<=T  ;caseno++){
       
      int nn,m;
      scanf("%d %d",&nn,&m);
      int s=1;
      int t=nn;
      int nodeMap[2][60];
      int cnt=s+1;
      n=nn+(nn-2)*2+10;

      capacity.assign(n,vector<int> (n));
      flow.assign(n,vector<int> (n));
      
      for (int i = 2; i <=nn-1 ; ++i)
      {
      	 int a;
      	 scanf("%d",&a);
      	 
      	 if(cnt==t)cnt++;
      	 nodeMap[0][i]=cnt++;
         if(cnt==t)cnt++;
         nodeMap[1][i]=cnt++;

         int u=nodeMap[0][i],v=nodeMap[1][i];
         capacity[u][v]=capacity[v][u]=a;

      }
      nodeMap[0][1]=nodeMap[1][1]=s; nodeMap[0][nn]=nodeMap[1][nn]=nn;

      for (int i = 0; i < m; ++i)
      {
          int a,b,c;

          scanf("%d %d %d",&a,&b,&c);

          int u=nodeMap[1][a],v=nodeMap[0][b];

          capacity[u][v]=c;
          capacity[nodeMap[1][b]][nodeMap[0][a]]=c;

      }

      ll flow=max_flow(s,t);

  
     printf("Case %d: %lld\n",caseno,flow);
  }





    return 0;
}
