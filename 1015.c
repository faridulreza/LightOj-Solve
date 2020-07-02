#include<stdio.h>
#include<stdlib.h>

int main(){

char arr[6500],narr[10];
int T,caseno=0,n,temp=0,result;
scanf("%d\n",&T);

while(T--){
scanf("%d\n",&n);
if(n==0)goto res;
gets(arr);
int rcount=0,count=0;
while(rcount<n){
        int  i=0;
    while(arr[count]!=' '){
        narr[i]=arr[count];
        i++;count++;
    }
    narr[i]='\0';
    result=atoi(narr);
    if(result>=0)temp=temp+result;
    count++;rcount++;i=0;
}

res:printf("Case %d: %d\n",++caseno,temp);
temp=0;
}

    return 0;
}
