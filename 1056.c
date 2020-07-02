#include<stdio.h>
#include<math.h>


int main(){

    int l,w;
    int T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--){
    scanf("%d : %d",&l,&w);
    double len,width;
    len=200/(1+sqrt(l*l+w*w)*atan(w/(double)l)/(double)l);
    width=w/(double)l*len;
    printf("Case %d: %lf %lf\n",++caseno,len,width);
    }


    return 0;
}
