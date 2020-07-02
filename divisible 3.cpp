#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (3.14159265)
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
#define len (100000)
ll mx=-1000000000-100;
ll mn=1000000000+100;


ll sti(string s){

ll tmp=0;

for(int i=0; i<s.size()  ;i++){
tmp*=10;
tmp+=(s[i]-48);
}
return tmp;

}

string tostring(ll tmp){
string s;
while(tmp){
    s.push_back((tmp%10)+48);
    tmp/=10;
}

reverse(s.begin(),s.end());
return s;

}
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {




 int T;
    cn T;

for(int caseno=1; caseno<=T  ;caseno++){
string s;

ll md;
cn s>>md;
int c=0;string ss;

for(int i=s[0]=='-' ? 1: 0; i<s.size() ;i++){
    ss.pb(s[i]);
    if(sti(ss)>=md){
        ll tmp=sti(ss)%md;
           if (tmp)ss.assign(tostring(tmp));
           else ss.clear();
    }

}
ll res;
        if(!ss.empty())res=sti(ss)%md;
        else res=0;

if(!res)printf("Case %d: divisible\n",caseno);
else printf("Case %d: not divisible\n",caseno);
}






    return 0;
}

