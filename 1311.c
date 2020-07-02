#include<stdio.h>

int main(){

    int T,caseno=0;double t,v1,v2,v3,a1,a2,d;
    scanf("%d",&T);
    while(T--){
    scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
    d=(v1*v1/(2*a1))+(v2*v2/(2*a2));
    t=(v1/a1)>(v2/a2)?(v1/a1):(v2/a2);

    printf("Case %d: %lf %lf\n",++caseno,d,t*v3);
    }


    return 0;
}
