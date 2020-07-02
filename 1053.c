#include<stdio.h>

int main(){

    int T,caseno=0;long long a,b,c,temp;
    scanf("%d",&T);
    while(T--){
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a>b&&a>c){
            temp=c;
            c=a;
            a=temp;
    }
    else if(b>c&& b>a){
            temp=c;
            c=b;
            b=temp;
    }
   if(c*c==a*a+b*b)   printf("Case %d: yes\n",++caseno);
   else{
      printf("Case %d: no\n",++caseno);
   }

    }

    return 0;
}
