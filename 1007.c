#include<stdio.h>
#define sz 5000001

unsigned long long arr[sz];

void phi(){
for(int i=2;i<sz ; i++){
arr[i]=i;
}
for(int i=2;i<sz ; i++){
if(arr[i]==i){
    for(int j=i;j<sz ; j+=i){
    arr[j]-=arr[j]/i;
    }
}
}

for(int i=1;i<sz ; i++){
arr[i]=arr[i-1]+arr[i]*arr[i];
//printf("%llu ",arr[i]);
}
}

int main(){
//freopen("out.txt","w+",stdout);
phi();
int T,caseno=0;
scanf("%d",&T);
int a,b;
while(T--){
scanf("%d %d",&a,&b);
a--;
printf("Case %d: %llu\n",++caseno,arr[b]-arr[a]);
}

    return 0;
}
