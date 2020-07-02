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
 
    ll gcd( ll a, ll b )
    {
        if(b==0)
        {
             return a;
        }
        else
        {
             return gcd( b, a%b );
        }
    }
 

struct node{

  ll dist;
  pair<int,int>slope,a,b;
  pair<ll,int> cp;


  bool operator ==(node a){

        if(dist==a.dist && slope==a.slope)return true;
        return false;

  } 

};

bool compare(node a,node b){

    if(a.dist==b.dist)return a.slope<b.slope;
    return a.dist<b.dist;

}

pair<ll,ll>normalize(pair<ll,ll> a){


  if(a.fs==0 && a.sc==0)return a;

  ll g=gcd(abs(a.fs),abs(a.sc));

  a.fs/=g;
  a.sc/=g;

  if(a.fs==0)a.sc=0;
  else if(a.sc==0)a.fs=1;
  else if(a.fs>0 && a.sc<0)a.fs*=-1,a.sc*=-1;
  else if(a.fs<0 && a.sc<0)a.fs*=-1,a.sc*=-1;

  return {a.fs,a.sc};
}


vector<node>mp;

ll solve(bool show){
 
    int n;
    cn n;
    vector<pair<int,int>> v;
    int cnt=1;
    int slopeCnt=1;
 
    for (int i = 0; i < n; ++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v.pb({a,b});
    }
 
   for (int i = 0; i < n; ++i)
   {
    for(int j=i+1; j<n ; j++){
        if(v[i]==v[j])continue;
        
        ll xdif=v[i].fs-v[j].fs;
        ll ydif=v[i].sc-v[j].sc;

        ll cUp=xdif*v[i].sc-ydif*v[i].fs;
        ll dist=xdif*xdif+ydif*ydif;
       
        pair<int,int>slope(ydif,xdif);
        pair<ll,int>cp(cUp,xdif);

        if(xdif==0){
           slope={1,0};
           cp={v[i].fs,1};

        }
        else if(ydif==0){
            slope={0,1};
            cp={v[i].sc,1};
        }

        slope=normalize(slope);
        cp=normalize(cp);
        
        
        node tmp;
        tmp.dist=dist;
        tmp.slope=slope;
        tmp.cp=cp;
        tmp.a=v[i];
        tmp.b=v[j];
        
         mp.pb(tmp);
 
     }
   }

   
   ll res=0;
   sort(all(mp),compare);
   int msz= mp.size();
 
   for (int i = 0; i <msz;)
   {  
       
       multiset<pair<ll,int>>lineSet;
       node tmp=mp[i];
 
       while(mp[i]==tmp && i<msz){
        if(show)ct mp[i].dist<<"    "<<mp[i].slope.fs<<" "<<mp[i].slope.sc<<"     "<<mp[i].cp.fs<<" "<<mp[i].cp.sc<<

                "      ("<<mp[i].a.fs<<","<<mp[i].a.sc <<")"<<
              " ("<<mp[i].b.fs<<","<<mp[i].b.sc <<")"
                 <<endl;
        lineSet.insert(mp[i].cp),i++;

      }

      if(show)ct "##############################\n";
 
       // for(auto x:lineSet[i])ct x.fs spc x.sc<<endl;
       // nl;  
       while(!lineSet.empty()){
 
          pair<ll,int> x= *lineSet.begin();
          ll c=lineSet.count(x);
 
          ll nm=lineSet.size()-c;
 
          res+=nm*c;
         
          lineSet.erase(x);
       }
 
   }
   
   mp.clear();  
   _(res);
 
   return res/2;
 
}
 
 
int main() {
 
     //make lines .count number of parallel lines with same distance
 
      
      
      int T;
          cn T;
      for(int caseno=1; caseno<=T  ;caseno++){
       
        printf("Case %d: %lld\n",caseno,solve(true));nl;nl;
      }
 
 
 
 
    return 0;
}
 