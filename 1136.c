#include<stdio.h>


int main(){

    int T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--){
    long long int a ,b,c=0,c2=0;
    scanf("%lld %lld",&a,&b);
       a--;

        c2=(a/3)*2;
        if((a%3))c2=c2+(a%3)-1;

        c=(b/3)*2;
        if((b%3))c=c+(b%3)-1;

    printf("Case %d: %lld\n",++caseno,c-c2);
    }

    return 0;
}
