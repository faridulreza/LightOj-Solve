#include<stdio.h>

int flag[60];
int main(){

    int c,h,m,n;
    scanf("%d%d%d",&c,&h,&m);
    for(int i=1;i<=c ; i++){
       flag[i]=h;
    }
    n=0;
    while(m--){
        int li,ri,xi;
        scanf("%d%d%d",&li,&ri,&xi);
        for(int i=li;i<=ri ; i++){
            if(flag[i]>xi){
                flag[i]=xi;
            }
        }

    }
    for(int i=1;i<=c ; i++){
    n+=flag[i]*flag[i];
    }
printf("%d\n",n);

    return 0;
}
