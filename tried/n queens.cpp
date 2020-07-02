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

char q[10][10];
bool mark[10][10];
vector<pair<int,int>>res[100];
int sz;

void find(int row){
if(row==8){
 
  for (int i = 0; i < 8; ++i)
     for(int j=0; j<8 ; j++)
         if(q[i][j]=='q'){
           res[sz].pb({i,j});
         }

     sz++;
return;
}


for(int col=0; col<8 ; col++){
    if(!mark[row][col]){

      
       bool tmp[10][10];
       for (int i=0;i<8;++i)
       	 for(int j=0;j<8;j++)
       	    tmp[i][j]=mark[i][j];
       	
       


       for(int k=0; k<8 ; k++){
       	mark[row][k]=true,mark[k][col]=true;
        
        int cl=k-row+col;
        int cl2=-k+row+col;
        if(cl>=0 && cl<8)mark[k][cl]=true;
        if(cl2>=0 && cl2<8)mark[k][cl2]=true;
       }

       q[row][col]='q';


       find(row+1);

      for (int i=0;i<8;++i)
       	 for(int j=0;j<8;j++)
       	    mark[i][j]=tmp[i][j];
       	
       
       q[row][col]='.';
    }

}

}


int match(int res_no){








}

int main() {

    


memset(q,'.',sizeof q);
find(0);






  return 0;
}
