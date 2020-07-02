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

pair<ll, ll> orig;

int orient(pair<ll, ll> a, pair<ll, ll> b)
{
    a.fs -= orig.fs, b.fs -= orig.fs;
    a.sc -= orig.sc, b.sc -= orig.sc;

    ll res = a.fs * b.sc - a.sc * b.fs;

    if(res < 0)return -1;
    if(res > 0)return 1;
    return 0;

}

int quad(pair<ll, ll> a)
{

    if(a.fs < orig.fs)
    {
        if(a.sc < orig.sc)return 3;
        else return 2;
    }
    else
    {
        if(a.sc < orig.sc)return 4;
        else return 1;
    }


}
bool onseg(pair<ll,ll> a,pair<ll,ll> b){


     return (orig.fs>=min(a.fs,b.fs)&& orig.fs<=max(a.fs,b.fs) && 
      orig.sc>=min(a.sc,b.sc) && orig.sc<=max(a.sc,b.sc));


}

bool inPoly(vector<pair<ll, ll>> &v)
{

  /**
       determines by the winding number;
       details https://www.gamasutra.com/view/feature/131836/crashing_into_the_new_year_.php
  **/

    int n=v.size();
    int lastQ = quad(v[0]);
    pair<ll, ll>lastp = v[0];
    int wn = 0;
    for (int j = 1; j < n + 1; ++j)
    {
      int i = j % n;
        if(v[i] == orig)return true;

        
        int dif = abs(lastQ - quad(v[i]));
        int ort = orient(lastp, v[i]);
        if(ort==0 && onseg(lastp,v[i]))return true;
        //        _(quad(v[i]));

        if(dif == 1 || dif == 3)
        {
            wn += ort;
        }
        else if(dif == 2)
        {
            wn += ort * 2;
        }

        // _(ort);
        // _(dif);
        // nl;

        lastQ = quad(v[i]);
        lastp = v[i];
    }

    //  _(wn);

    if(wn == 4 || wn == -4)return true;
    return false;


}

int main()
{


    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
    int n;
    cn n;
    vector<pair<ll,ll>>v(n);
    for (int i = 0; i < n; ++i)
    {
      /* code */cn v[i].fs >> v[i].sc;
    }

    int q;
    cn q;
    printf("Case %d:\n",caseno);
    while(q--){
     
       cn orig.fs >> orig.sc;
       if(inPoly(v))ct "Yes";
       else ct "No";
       nl;
    }
   
   
   }



    return 0;
}
