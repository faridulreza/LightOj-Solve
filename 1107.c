#include<stdio.h>

int main(){

    int T,caseno=0,lowx,lowy,highx,highy;
    scanf("%d",&T);
    while(T--){
            scanf("%d%d%d%d",&lowx,&lowy,&highx,&highy);
            highx=highx-lowx;
            highy=highy-lowy;
            int cows,cowx,cowy;
            printf("Case %d:\n",++caseno);
            scanf("%d\n",&cows);
            while(cows--){
                scanf("%d%d",&cowx,&cowy);
                cowx=cowx-lowx;cowy=cowy-lowy;
               // printf("highx %d, Highy %d, Cowx %d, cowy %d",highx,highy,cowx,cowy);
                if((cowx>=0 && cowx<=highx)&&(cowy>=0 && cowy<=highy))printf("Yes\n");
                else printf("No\n");
            }
    }


    return 0;
}
