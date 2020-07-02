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


const int size=200;
vector<int>primes(100);
bool mark[size+5];
int cnt=0;
void sieve(){
     
     ll lm=sqrt(size)+2;
     for(ll i=3; i<=lm;i+=2){
        if(mark[i])continue;
         for(ll j=i*i;j<=size; j+=i){
            mark[j]=true;
         }
     }

     primes[cnt++]=2;
     for (int i = 3; i <=size; i+=2)
     {
        if(!mark[i])primes[cnt++]=i;
     }

}

	ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a);
		ll q = power(a,b/2);
		return (q*q);
	}



int bigInt[11000];
int base=10000;
int last=0;
void multiply(ll a){
  
ll carry=0;
for (int i = 0;; ++i)
  {
  	ll res=bigInt[i]*a+carry;
  	if(!res && i>=last)break;
  	bigInt[i]=(res)%base;
    carry=res/base;
    last=i;
  }

}






int main() {

  sieve();

   int T;
      cn T;
  for(int caseno=1; caseno<=T  ;caseno++){
    map<int,int>mp;

    int n;
    cn n;
    for (int i = 0; i < n; ++i)
    {
    	
        int inp;
        cn inp;

        for(int pr:primes){
            
            if(pr*pr>inp)break;
            
            int ocur=0;
            while(inp%pr==0){
              inp/=pr;
              ocur++;
            }


            if(mp.count(pr) && ocur){
                 mp[pr]=max(mp[pr],ocur);

            }
            else if(ocur){
            	mp[pr]=ocur;
            }

        }

        if(inp!=1){
        	mp[inp]=max(mp[inp],1);
        }
    }


        bigInt[0]=1;
        last=0;
        for(auto x:mp){
         ll a=power(x.fs,x.sc);
          multiply(a);
        }

        int sw=0;
        printf("Case %d: ",caseno );
        for(int i = last; i>=0; i--)
        {    

        	if(bigInt[i] && !sw)printf("%d",bigInt[i]),sw=1;
            else if(sw) printf("%04d",bigInt[i]);
        }
        
        nl;
        _0(bigInt);

       //printf("Case %d: %lf\n",caseno,res);
  }
                                                                    





    return 0;
}
