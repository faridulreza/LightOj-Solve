#include<stdio.h>


int main(){

    int T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--){
    long long n,c=0;
    scanf("%lld",&n);
    while(n){
        if(n&1)c++;
        n=n>>1;
    }
    if(c%2) printf("Case %d: odd\n",++caseno);
    else printf("Case %d: even\n",++caseno);
    }


    return 0;
}
