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

map<string,int>mp;
vector<int>adj[26*26*26+10];

void genarate_graph(){

string st="aaa";
unordered_set<string>inq_set;
queue<string> q;
int cnt_node=1;
q.push(st);
mp[st]=cnt_node++;
inq_set.insert(st);

while(!q.empty()){

   string snode=q.front();
   q.pop();
   int cur_node=mp[snode];

   for(int i=0;i<3;i++)
   	  for(int k=-1;k<2 ;k+=2){
          int a,b,c;
             if(i==0){
             a=(int)snode[0]-'a'+k;    
             b=(int)snode[1]-'a';    
             c=(int)snode[2]-'a';
             }
             else if(i==1){
             a=(int)snode[0]-'a';    
             b=(int)snode[1]-'a'+k;    
             c=(int)snode[2]-'a';
             }
             else {

             a=(int)snode[0]-'a';    
             b=(int)snode[1]-'a';    
             c=(int)snode[2]-'a'+k;
             }
          a=(a+26)%26;    
          b=(b+26)%26;    
          c=(c+26)%26;    
          string nnode;
          nnode.pb(a+'a');
          nnode.pb(b+'a');
          nnode.pb(c+'a');
          int tmp_node;
          if(!inq_set.count(nnode)){
            q.push(nnode);
            inq_set.insert(nnode);
            mp[nnode]=tmp_node=cnt_node++;
           }
          else tmp_node=mp[nnode];

            adj[cur_node].pb(tmp_node);
            adj[tmp_node].pb(cur_node);
          
   	}
}

}




int solve(){

string st,ed;
cn st>>ed;
int n;
cn n;
set<int>avoid_set;

//_fl(hdkjak0);

for (int i = 0; i < n; ++i)
{
	string a,b,c;
	cn a>>b>>c;

	for (char aa:a){
       if(avoid_set.size()==17577)break;
	   for(char bb:b){
	   	if(avoid_set.size()==17577)break;
	   	  for(char cc:c){
	   	  	string s;
	   	  	s.pb(aa);
	   	  	s.pb(bb);
	   	  	s.pb(cc);
	   	  	avoid_set.insert(mp[s]);
	   	  }
	   }
	}
}


int st_node=mp[st];
int ed_node=mp[ed];

if(avoid_set.count(st_node) || avoid_set.count(ed_node))return -1;
if(st_node==ed_node)return 0;



queue<int>q;
q.push(st_node);
int dist[20000];
for (int i = 0; i < 20000; ++i)
{
	dist[i]=2000000;
}

dist[st_node]=0;
bool vis[20000];
_0(vis);

while(!q.empty()){

    int u=q.front();
    q.pop();
    
    if(vis[u])continue;
    vis[u]=true;
    for(int v:adj[u]){
    	if(avoid_set.count(v) || vis[v])continue;
        if(dist[u]+1<dist[v])dist[v]=dist[u]+1;
        q.push(v);
       // _(v);
    }
}


return dist[ed_node]==20000?-1:dist[ed_node];
}


int main() {

//generate a graph whose nodes are every possible word of length 3
// two nodes are connected if we can obtain another by one move (eg. aab -- aac,aab--aaa..)

genarate_graph();

int T;
    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
printf("Case %d: %d\n",caseno,solve());
}

  return 0;
}
