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

ll mod=10007;
struct mat
{
    
    int arr[4][4]={};


    void print(){

        for (int i = 0; i < 4; ++i)
        {
        	for(int j=0; j<4 ; j++){
        	    ct arr[i][j]<<" ";
        	}nl;
        }nl;

    }
    mat operator *(mat &a){
        mat nw;
        
        //print();
        //a.print();
        for (int i = 0; i < 4; ++i)
        {
        	for(int j=0; j<4 ; j++){
        	    for(int k=0; k<4 ; k++){
        	        nw.arr[i][j]+=(arr[i][k]*a.arr[k][j])%mod;
        	        nw.arr[i][j]%=mod;
        	        
        	    }
        	}
        }
       // nw.print();
       
        return nw;

    }

};


  mat power(mat a, ll b)	//a is base, b is exponent
	{
		if(b==0){
            
            mat x;
            for (int i = 0; i < 4; ++i)
            {
            	x.arr[i][i]=1;
            }

            return x;

		}
		if(b==1)
			return a;

		if(b%2 == 1)
			return (power(a,b-1)*a);

		mat q = power(a,b/2);
		return (q*q);
	}




int main() {

   
     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n,a,b,c;

    cn n>>a>>b>>c;


    mat nw;

    nw.arr[0][0]=a;
    nw.arr[0][2]=b;
    nw.arr[0][3]=c;

    nw.arr[1][0]=1;
    nw.arr[2][1]=1;
    nw.arr[3][3]=1;



    if(n<=2)printf("Case %d: 0\n",caseno);
    else{

        n-=2;

        mat x=power(nw,n);
         printf("Case %d: %d\n",caseno,x.arr[0][3]);



    }
    }







    return 0;
}
