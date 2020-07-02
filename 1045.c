#include<stdio.h>
#include<math.h>
 double arr[1011];
int main(){
    int T,caseno=1;double li=2;
    while(caseno<1011){
        arr[caseno]=log10(li)+arr[caseno-1];
        caseno++;li++;
    }
    caseno=0;
    scanf("%d",&T);
    int i,base;

    while(T--){
    scanf("%d%d",&i,&base);
    li=(arr[i-1])/log10(base);
    printf("Case %d: %.lf\n",++caseno,floor(li)+1);
    }


    return 0;
}
