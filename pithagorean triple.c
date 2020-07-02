#include<stdio.h>
#include<math.h>

int main(){

    double a,b,c;
    unsigned long long d,e,f;
    scanf("%lf",&a);
    for(double i=0.000001;i<1.6; i+=0.000001){
        c=a/sin(i);
        b=a/tan(i);
//        c=round(c);
//        b=round(b);
        printf("%f %f\n",c,b);
//        if(c<=0 || b<=0 )continue;
//        d=c;
//        e=b;
//        f=a;
//        if(a*a+b*b==c*c){
//            printf("%0.0f %.0f\n",c,b);
//            return 0;
//       }
    }
//    for(double i=0.000001;i<1.6; i+=0.000001){
//        c=a*sin(i);
//        b=a*cos(i);
//        c=round(c);
//        b=round(b);
//        if(c<=0 || b<=0 )continue;
//
//        if(b*b+c*c==a*a){
//            printf("%.0f %.0f\n",c,b);
//            return 0;
//       }
//    }
//printf("-1\n");
//
   return 0;
}
////1250000000 750000000
