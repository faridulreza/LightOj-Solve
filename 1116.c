#include<stdio.h>
#include<math.h>

int main(){

    int T,caseno=0; unsigned long long r,result,lim;
    scanf("%d",&T);
    while(T--){
    scanf("%llu",&result);
    if(result%2==0){

            int i=0;
            r=1;
            while(1){
               r=r<<1;
                if(result/r==1){
                    i=1;
                    break;
                }
                if((result/r)%2)break;
            }

        if(i) printf("Case %d: Impossible\n",++caseno);
        else printf("Case %d: %llu %llu\n",++caseno,result/r,r);
    }
    else printf("Case %d: Impossible\n",++caseno);
    }


    return 0;
}
