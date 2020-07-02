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

int i;
int n;
string s;

void dfs(string &ans)
{

    vector<string> tm;
    string an;
    //_(i);
    while(i < n && s[i] == '1')
    {
        an.clear();
        i++;
        dfs(an);
        tm.pb(an);
    }

    ans = "1";
    sort(all(tm));
    for(string x : tm)ans += x;
    ans += "0";
    i++;
    //  _(ans);
}





int main()
{

    //https://logic.pdmi.ras.ru/~smal/files/smal_jass08_slides.pdf

    int T;
    cn T;
    getchar();
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        getline(cin, s);

        i = 0;
        n = s.size();
        string a, b;
        dfs(a);
        getline(cin, s);

        i = 0;
        n = s.size();
        dfs(b);

        printf("Case %d: ", caseno);
        if(a == b)puts("Same");
        else puts("Different");
        a.clear();
        b.clear();
    }


    return 0;

}
