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

bool vow[150];

char inp[60];
bool vw(int i){

   if(vow[inp[i]])return true;
   return false;

}
bool cut[55][4][6];

bool isB,isG;
int len;

void f(int i,int v,int c){


 if(v==3 || c==5){isB=true;return;}
 if(i==len){isG=true;return;}
 
 if(cut[i][v][c])return;


  if(vw(i)){
  	f(i+1,v+1,0);
  }
  else if(inp[i]=='?'){
  	f(i+1,v+1,0);
  	f(i+1,0,c+1);
  }
  else f(i+1,0,c+1);

  
 cut[i][v][c]=true;



}

int main() {

    

 int T;
    cn T;

    vow['E']=true;
    vow['A']=true;
    vow['I']=true;
    vow['O']=true;
    vow['U']=true;
    
for(int caseno=1; caseno<=T  ;caseno++){

scanf(" %s",inp);
len=strlen(inp);

_0(cut);
isB=false;
isG=false;
//_fl(sdfj);
f(0,0,0);

if(isB && isG)printf("Case %d: MIXED\n",caseno);
else if(isB)printf("Case %d: BAD\n",caseno);
else printf("Case %d: GOOD\n",caseno);

}





    return 0;
}
