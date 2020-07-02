#include<stdio.h>

int arr[1002],devisor[1002];
int count(int a){
int c=0;
for(int i=1;i<=a; i++){
   if(a%i==0)c++;
}
return c;
}

int main(){

    for(int i=1;i<=1000; i++){
        //printf("  %d    %d\n",i,count(i));
        arr[i]=i;
        devisor[i]=count(i);
    }

    for(int t=1;t<=1000;t++){
        for(int i=1; i<=1000-t;i++){
            if(devisor[i]>=devisor[i+1]){
                int tmp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=tmp;
                tmp=devisor[i+1];
                devisor[i+1]=devisor[i];
                devisor[i]=tmp;
            }
        }
    }
    int start=2;
  for(int j=2;j<=1000; j++){
     if(devisor[j]!=devisor[j+1]){
        for(int t=start;t<j+1;t++){
            for(int i=j  ; i>t  ;i--){
                if(arr[i-1]<arr[i]){
                    int tmp=arr[i-1];
                    arr[i-1]=arr[i];
                    arr[i]=tmp;
                }
            }
        }

        start=j+1;
     }
    }

int T,caseno=0,result;
scanf("%d",&T);
while(T--){
scanf("%d",&result);
printf("Case %d: %d\n",++caseno,arr[result]);
result=0;
}



    return 0;
}
