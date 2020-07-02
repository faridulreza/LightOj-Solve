#include<stdio.h>
#include<math.h>
double pi=2*acos(0.0);
int main(){

int t,n,caseno=1;double R,r,coscal;
scanf("%d",&t);
while(t--){
    scanf("%lf%d",&R,&n);
    coscal=sqrt(1-cos(2*pi/n));
    r=R*(coscal/(coscal+sqrt(2.0)));
    printf("Case %d: %lf\n",caseno++,r);

}
return 0;

}
