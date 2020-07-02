#include<stdio.h>
#include<math.h>
int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int tr[110];
int track[110][25];
int main(){
for(int i=0;i<25; i++){
tr[primes[i]]=i;
}



 int c;
    for(int k=2;k<=100; k++){
            int n=k;
            int root=round(sqrt(n));
            for(int i=0; primes[i]<=root; i++) {
                c=0;
                while(n%primes[i]==0) {
                    n=n/primes[i];
                    c++;
                }
                track[k][i]=c;
                root=sqrt(n);
            }
if(n!=1)track[k][tr[n]]++;

}
for(int i=2;i<=100 ; i++){
       // printf("%d|| ",i);
for(int j=0;j<25 ; j++){

   track[i][j]+=track[i-1][j];
//lprintf("%d ",track[i][j]);
}
//puts(" ");
}

int T,caseno=0;
scanf("%d",&T);
while(T--){
int m;
scanf("%d",&m);
printf("Case %d: %d =",++caseno,m);
int flag;
flag=0;
for(int i=0;i<25 ; i++){
if(track[m][i]){
    if(flag)printf(" *");
    printf(" %d (%d)",primes[i],track[m][i]);
    flag=1;
}
}
printf("\n");
}


}
