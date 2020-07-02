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
double _eps=1e-6;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#define inf 100000

char arr[30][30];
int dist[410][410];
map<pair<int,int>,int>mp;
int n,m;

int dp[(1<<15)+10][21];
bool taken[25];
vector<pair<int,int>>gold;
pair<int ,int> head;




int f(int st,int j,int priv,pair<int,int> h){

if(j>=gold.size())return dist[mp[h]][mp[head]];

if(dp[st][priv]!=-1)return dp[st][priv];


int u=mp[h];
int mn=INT_MAX;
for (int i = 0; i < gold.size(); ++i)
{
    if(!taken[i]){

          taken[i]=1;
          int nst=(st|(1<<i));

          int tmp=dist[u][mp[gold[i]]]+f(nst,j+1,i,gold[i]);
          taken[i]=0;
        mn=min(mn,tmp);

    }
}


return dp[st][priv]=mn;



}





int main() {

    
     int T;
            cn T;
        for(int caseno=1; caseno<=T  ;caseno++){
        gold.clear();
        mp.clear();

        cn m>>n;

        for (int i = 1; i <=m; ++i)
        {
            for(int j=1; j<=n ; j++){
                char c;
                cn c;
                arr[i][j]=c;
                if(c=='x')head.fs=i,head.sc=j;
                if(c=='g')gold.pb({i,j}); 
            }
        }

        int total=m*n;

        for (int i = 1; i <= total; ++i)
        {
            for(int j=1; j<=total ; j++){
                dist[i][j]=inf;
            }
        }

        int cnt=1;

        for(int i=1; i<=m ; i++){
            for(int j=1; j<=n ; j++){
                mp[{i,j}]=cnt++; 
            }
        }



        for (int i = 1; i <=m ; ++i)
            for(int j=1; j<=n ; j++)
        {
            int x=i,y=j;
            int u=mp[{x,y}];

            for(int k=-1;k<2;k++)
                for(int l=-1;l<2;l++){

                  if(mp.count({x+k,y+l})){
                    int v=mp[{x+k,y+l}];
                    dist[u][v]=1;
                  }     

                }
        }


        for (int i = 1; i <=total; ++i)
        {
            dist[i][i]=0;
        }


        for (int k = 1; k <=total ; ++k)
        {
            for(int i=1;i<=total;i++){
                for(int j=1; j<=total ; j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                       dist[i][j]=dist[i][k]+dist[k][j];                        
                    }
                }
            }
            
        }
     
          


        _1(dp);
        _0(taken);


        printf("Case %d: %d\n",caseno,f(0,0,0,head));
        }    







    return 0;
}
