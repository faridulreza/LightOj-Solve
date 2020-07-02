#include<stdio.h>
int min(int x,int y){
if(x<y)return x;
else return y;

}
int max(int x,int y){
if(x>y)return x;
else return y;

}

int main(){

    int T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--){
    int n,lowx[110],highx[110],lowy[110],highy[110],lowz[110],highz[110];
        scanf("%d",&n);

    for(int i=0;i<n; i++){
    scanf("%d%d%d%d%d%d",&lowx[i],&lowy[i],&lowz[i],&highx[i],&highy[i],&highz[i]);
    }
    int x1,x2,y1,y2,z1,z2;
    x1=y1=z1=0;
    x2=y2=z2=10000;
    for(int i=0;i<n; i++){
         x1=max(x1,lowx[i]);
         y1=max(y1,lowy[i]);
         z1=max(z1,lowz[i]);

         x2=min(x2,highx[i]);
         y2=min(y2,highy[i]);
         z2=min(z2,highz[i]);
    }
    result=((x2-x1)<=0?0:(x2-x1))*((y2-y1)<=0?0:(y2-y1))*((z2-z1)<=0?0:(z2-z1));
    printf("Case %d: %d\n",++caseno,result);
    }


    return 0;
}
