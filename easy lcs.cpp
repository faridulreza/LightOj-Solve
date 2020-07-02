#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define dbg(x) puts("HERE" #x);
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
#define len (100000)
ll mx=-1000000000-100;
ll mn=1000000000+100;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string mini(string x,string y){

if(x.size()>y.size())return x;
if(x.size()<y.size())return y;

if(x.size()==0)return string("");
for(int i=0; i<x.size()  ;i++){
if(x[i]<y[i])return x;
if(x[i]>y[i])return y;
}
return x;



}

int main() {

string x,y;
char xx[110],yy[110];

 int T;
    scanf("%d",&T);
for(int caseno=1; caseno<=T  ;caseno++){
string tmp[110][110];

getchar();
getchar();
scanf("%s",xx);
scanf("%s",yy);
x=xx;
y=yy;

int m=x.size();
int n=y.size();
//dbg(1);
for(int i=m; i>=0  ;i--){
for(int j=n; j>=0 ;j--){

        if(i==m || j==n){
            tmp[i][j]="";
            continue;
        }

        if(x[i]==y[j]){

            tmp[i][j]=x[i]+tmp[i+1][j+1];
            continue;
        }

        tmp[i][j]=mini(tmp[i+1][j],tmp[i][j+1]);
}
}

//dbg(2);
//cout<<tmp[0][0]<<endl;
strcpy(xx,tmp[0][0].c_str());
if(tmp[0][0].size()==0)printf("Case %d: :(\n",caseno);
else printf("Case %d: %s\n",caseno,xx);
}







    return 0;
}
