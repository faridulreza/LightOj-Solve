#include<stdio.h>

long long a, b, c, d, e, f,result;
int fn( int n ) {
    if( n == 0 ) return a%10000007;
    if( n == 1 ) return b%10000007;
    if( n == 2 ) return c%10000007;
    if( n == 3 ) return d%10000007;
    if( n == 4 ) return e%10000007;
    if( n == 5 ) return f%10000007;
    else {
        int count=0;
        while(count<n-5){
            result=(a+b+c+d+e+f)%10000007;
            a=b,b=c,c=d,d=e,e=f,f=result;
            count++;
}
return result;
    }
}
int main() {
    int n,count=0,cases;
    scanf("%d", &cases);
    while( count<cases ) {
        scanf("%lld %lld %lld %lld %lld  %lld %d", &a, &b,&c, &d, &e,&f, &n);


        printf("Case %d: %d\n", count+1, fn(n));
        count++;
    }

    return 0;
}
