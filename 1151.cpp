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



void system_of_linear_equation(vector<vector<double>>& a,vector<double> &ans){

         double EPS=1e-9;

        int n=a.size();
        int m=a[0].size()-1;
         
        vector<int> mem(m,-1);
         
        for (int row = 0,col=0; col<m && row<n ; col++,row++)
        {
            int replace_with=row;

            for(int i=row+1;i<n;i++)
            	if(abs(a[i][col])>abs(a[replace_with][col]))
            		replace_with=i;

             
            if(abs(a[replace_with][col])<EPS)
            	continue;

            for (int i = col; i <=m ; ++i)
                swap(a[replace_with][i],a[row][i]);
            
            mem[col]=row;

            for (int i = 0; i < n; ++i)
            {
                if(i!=row){
                     double c=a[i][col]/a[row][col];
                     for(int j=col; j<=m ; j++)
                     	a[i][j]-=a[row][j]*c;
                }
            }

        }

       
       for (int i = 0; i <m; ++i)
           if(mem[i]!=-1)
             ans.pb(a[mem[i]][m]/a[mem[i]][i]);


}




int main() {
   /**
     
     E(0)=1+ 1/6 (E(1)+ E(2) +E (3)... +E(6))
          roll once from current cell + 1/6 (Expected value of reached cell after rolling)

     or -1= -E(0) + 1/6 (E(1)+ E(2) +E (3)... +E(6))
     
     we will get 99 equation like that .. A equation for each cell
     But we dont need equation for 
         the cells that has a snake head or a ladder bottom ,
         As the equation will be same as the snake tail's cell's equation or ladder 
         top's


     the E(100) is 0 
        cz  we are already in cell 100 ,no more rolling needed

      if we are in cell 98 and dice roll results in value greater than 2 we need 
         to start over from cell 98 again

      so E(98)=1 + 1/6( E(99) + 0 + E(98) +E (98) + E (98) + E(98)) 
   **/

    int T;
       cn T;
   for(int caseno=1; caseno<=T  ;caseno++){
   
   
   int n;
   scanf("%d",&n);
   map<int,int> mp;

   for (int i = 0; i < n; ++i)
      {
         int a,b;
         scanf("%d %d",&a,&b);
         mp[--a]=--b;
         //_(mp[a]);
      }


   vector<vector<double>> a(99,vector<double>(100));
   // column 99 is for constants (-1)

   for (int i = 0; i <99 ; ++i)
   {    
   	    if(mp[i])
   	    	continue;
   	    
   	    
   	    for(int j=1; j<=6 ; j++){

   	        int var=i+j;
   	        if(mp.count(i+j))
   	        	var=mp[i+j];

   	        if(var>=99){
   	           if(var!=99)a[i][i]+=1/6.00;// if 99 E(100) is 0
   	                                      //  else start over
   	        }
   	        else a[i][var]+=1/6.0;  // you must add
   	                                // consider there is a ladder from 58 to 62
   	                                // while calculating for cell 57 you will get 62 twice
   	    }
   	 
   	    a[i][i]+=-1;
   	    a[i][99]=-1;
   
   }

  vector<double> ans;

  system_of_linear_equation(a,ans);

   printf("Case %d: %.10f\n",caseno,ans[0]);
   }







    return 0;
}
