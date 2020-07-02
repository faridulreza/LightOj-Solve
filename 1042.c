#include<stdio.h>

int main() {
    int a[40];
    int n,T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int tmp=0,c=0,flag=0;
        while(n) {
            a[c]=n&1;
            n=n>>1;
            c++;
        }
//
//        for(int i=0;i<c; i++){
//             printf("%d ",a[i]);
//        }puts("");
        a[c]=0;
        while(tmp<c) {
            if(a[tmp]==1 && a[tmp+1]==0){
                a[tmp]=0;
                a[tmp+1]=1;
                flag=1;
                tmp++;
                break;
            }
            tmp++;
        }
      if(flag){
        int one=0;
        for(int i=0;i<tmp; i++){
            if(a[i])one++;
            a[i]=0;
        }
        for(int i=0;i<one ; i++){
            a[i]=1;
        }
        if(tmp==c)c++;

      }
      else{
        a[c]=1;
        c++;
      }
//              for(int i=0;i<c; i++){
//             printf("%d ",a[i]);
//        }puts("");
      for(int i=c-1;i>=0 ; i--){
        result=result<<1;
        result=result|a[i];
      }



        printf("Case %d: %d\n",++caseno,result);
        result=0;
    }

    return 0;
}
