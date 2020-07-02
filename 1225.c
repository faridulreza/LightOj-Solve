#include<stdio.h>

int main(){

    int T,caseno=0,result=0;char ch[12];
    scanf("%d",&T);
    while(T--){
    gets(ch);
    result=sizeof(ch);
    printf("Case %d: %d\n",++caseno,result);
    result=0;
    }


    return 0;
}
