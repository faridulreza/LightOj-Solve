#include<stdio.h>


int main(){

    int T,caseno=0;
    scanf("%d",&T);
    while(T--){
    int n,m,arr[100];
    char c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n; i++){
        scanf("%d",&arr[i]);
    }
    getchar();
    while(m){
        c=getchar();

        if(c=='S'){
            int inp;
            scanf("%d",&inp);
            for(int i=0;i<n; i++){
                   arr[i]+=inp;
            }
        }
        else if(c=='M'){
            int inp;
            scanf("%d",&inp);
            for(int i=0;i<n; i++){
                   arr[i]*=inp;
            }

        }
       else if(c=='D'){
            int inp;
            scanf("%d",&inp);
            for(int i=0;i<n; i++){
                   arr[i]/=inp;
            }

        }
        else if(c=='P'){
            int x,y;
            scanf("%d%d",&x,&y);
            int tmp;
            tmp=arr[x];
            arr[x]=arr[y];
            arr[y]=tmp;
        }
       else  if(c=='R'){
            int tm;
            for(int i=0;i<n-i-1; i++){
               tm=arr[i];
                arr[i]=arr[n-i-1];
                arr[n-i-1]=tm;
            }
        }
        else continue;
        m--;
    }
    printf("Case %d:\n",++caseno);
    for(int i=0;i<n; i++){
      printf("%d",arr[i]);
      if(i==n-1)printf("\n");
      else printf(" ");
    }

    }


    return 0;
}
