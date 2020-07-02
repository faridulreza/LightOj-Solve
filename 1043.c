#include <stdio.h>
#include <math.h>

int main(void) {
    double a,res,r,b,c;
    int co,count=0;
    scanf("%d",&co);
    while(count<co){
    count++;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&r);

    res=sqrt(r/(r+1))*a;
    printf("Case %d: %.10lf\n",count,res);
    }

getchar();
    return 0;
}
