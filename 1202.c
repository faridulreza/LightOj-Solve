#include<stdio.h>
#include<math.h>

int main(){

 int T,caseno=0,result=0,firstx,firsty,secx,secy;
 scanf("%d",&T);
 while(T--){
 scanf("%d%d%d%d",&firstx,&firsty,&secx,&secy);
 result=abs(firstx-secx)%2;
 if(result==0){
    if(abs(firsty-secy)%2!=0){
        printf("Case %d: impossible\n",++caseno);
        continue;
    }
 }
 else{
    if(abs(firsty-secy)%2==0){
        printf("Case %d: impossible\n",++caseno);
        continue;
    }
 }
if((firsty-secy)!=0){
//long double result=(firstx-secx)/(firsty-secy);
 if(abs(firstx-secx)==abs(firsty-secy))printf("Case %d: 1\n",++caseno);
 else printf("Case %d: 2\n",++caseno);
}
 else printf("Case %d: 2\n",++caseno);

 }


    return 0;
}
