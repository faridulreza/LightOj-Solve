#include<stdio.h>
unsigned long long fact[21],n;
int track[25];

int found;

unsigned long long fac(unsigned long long a) {
    if(a==0)
        return 1;
    if(fact[a])
        return fact[a];
    return fact[a]=a*fac(a-1);
}

int combination(int arr[],int start,int depth,unsigned long long sm,int lvl) {

    if(depth==0) {
        if(sm==n) {
            found=1;
            for(int i=0; i<lvl; i++) {
                track[i]=arr[i];
            }
            return 1;
        }
        return 0;
    }
    for(int i=start; i<=20; i++) {
        sm+=fact[i];
        arr[lvl]=i;
        combination(arr,i+1,depth-1,sm,lvl+1);
        sm-=fact[i];
    }

}

int main() {
    fact[0]=1;

    for(int i=0; i<=20; i++) {
        fac(i);
    }

    int arr[25];
    int T,caseno=0,result=0;
    scanf("%d",&T);
    while(T--){

     scanf("%llu",&n);
        found=0;
        int index=0;
        for(int i=1; i<=21; i++) {
            combination(arr,0,i,0,0);
            if(found) {
                index=i;
                break;
            }
        }
        printf("Case %d: ",++caseno);
        if(!index)printf("impossible\n");

        for(int i=0; i<index; i++) {
            printf("%d!",track[i]);
            if(i==index-1)printf("\n");
            else printf("+");
        }
    }
    return 0;
}
