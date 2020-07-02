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






int t[4 * 150000];
int arr[150010];



void build(int v,int tl,int tr){
  
   if(tl==tr){t[v]=(arr[tl]!=0); return;}

   int mid=(tl+tr)/2;
   build(v*2,tl,mid);
   build(v*2+1,mid+1,tr);

   t[v]=t[v*2]+t[v*2+1];


}

int sum(int v, int tl, int tr, int k)
{

    if (tl == tr)
    {

    	t[v]=0;
        return tl;
      
    }


    int tm = (tl + tr) / 2;
    int q;
    if(k<=t[v*2]){
           q=sum(v * 2, tl, tm, k);
     }
    else q=sum(v * 2 + 1, tm + 1, tr,k-t[v*2]);

    t[v] = t[v * 2] + t[v * 2 + 1];

    return q;

}


void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}




int main()
{


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {

        int n,q;
        scanf("%d%d",&n,&q);
        int sz=n+q;
        

        for (int i = 0; i <n ; ++i)
        {
        	scanf("%d",&arr[i]);
        }
        build(1,0,sz-1);
           
        printf("Case %d:\n",caseno);

        for (int i = 0; i < q; ++i)
        {
        	char qu;int id;
             getchar();
        	 scanf("%c %d",&qu,&id);
        	if(qu=='a'){

                update(1,0,sz-1,n,1);
                arr[n++]=id;
        	}
        	else {
                
                if(id>t[1]){
                	puts("none");
                }

                else {
                	int ind=sum(1,0,sz-1,id);
                    printf("%d\n",arr[ind]);
                    arr[ind]=0;
                }

        	}
        }

        for (int i = 0; i < sz; ++i)
        {
        	arr[i]=0;
        }


    }






    return 0;
}
