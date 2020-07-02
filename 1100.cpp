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

int arr[100000+10];

int main() {

     int T;
        cn T;
    for(int caseno=1; caseno<=T  ;caseno++){
    int n
    ,q;
    scanf("%d%d",&n,&q);
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d",&arr[i]);
    }

    
    
    
    printf("Case %d:\n",caseno);
    
    for (int i = 0; i < q; ++i)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);

    	if(b-a+1>1000)puts("0");
    	else{
            
            set<int>st;
            int ans=10000;
            for (int i = a; i <= b; ++i)
            {
            	if(st.count(arr[i])){ans=0;break;}
            	else st.insert(arr[i]);
            	
            }

            if(ans){
                int prev=-1000000000;
            	for (int it:st)
            	{
            		ans=min(ans,it-prev);
                    prev=it;

            	}
            }

            printf("%d\n",ans);

    	}

    }
    
    }







    return 0;
}
