#include  <iostream>
#include  <vector>
#include  <deque>
#include  <list>
#include  <set>
#include  <map>
#include  <stack>
#include  <queue>
#include  <algorithm>
#include  <string>
#include  <cmath>
#include  <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
long long gcd(long long a, long long b){
if(b==0)return a;
 return gcd(b,a%b);
}
char grid[30][30];
int main(){
int T,caseno=0,result=0;
scanf("%d",&T);
while(T--){


int n,m;
cn m>>n;
pair<int ,int >start;
for(int i=1;i<=n ; i++){
for(int j=1;j<=m ; j++){
cn grid[i][j];
if(grid[i][j]=='@')start.fs=i,start.sc=j;
}
}

int visited[30][30]={};
stack<pair<int,int>>st;
st.push(start);
int k=1;
while(!st.empty()){
    pair<int ,int>ind;
    ind=st.top();
    visited[ind.fs][ind.sc]=1;
    st.pop();
        if(ind.fs+1<=n && !visited[ind.fs+1][ind.sc] && grid[ind.fs+1][ind.sc]!='#' ){
                k++;
                visited[ind.fs+1][ind.sc]=1;
                st.push({ind.fs+1,ind.sc});
        }
    if(ind.fs-1>0 && !visited[ind.fs-1][ind.sc] && grid[ind.fs-1][ind.sc]!='#'){
             k++;
                visited[ind.fs-1][ind.sc]=1;
                st.push({ind.fs-1,ind.sc});
    }
    if(ind.sc+1<=m && !visited[ind.fs][ind.sc+1] && grid[ind.fs][ind.sc+1]!='#'){
               visited[ind.fs][ind.sc+1]=1;
               k++;
               st.push({ind.fs,ind.sc+1});

    }
    if(ind.sc-1>0 && !visited[ind.fs][ind.sc-1] && grid[ind.fs][ind.sc-1]!='#'){
               visited[ind.fs][ind.sc-1]=1;
               k++;
               st.push({ind.fs,ind.sc-1});

    }



}
printf("Case %d: %d\n",++caseno,k);
}
return 0;
}
