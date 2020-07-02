#include<stdio.h>
#include<stdlib.h>

int main(){

    int T,caseno=0,result,mylc,lflc;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&mylc,&lflc);
       result=(abs(mylc-lflc))*4+11+mylc*4+8;

    printf("Case %d: %d\n",++caseno,result);
    }


    return 0;
}
