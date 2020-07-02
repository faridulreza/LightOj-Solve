#include<stdio.h>

long long a[50][50];
long long b[50][50];
int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n ; i++){
    for(int j=0;j<m; j++){
        scanf("%lld",&a[i][j]);
    }
    }

    for(int i=0;i<n ; i++){
    for(int j=0;j<m; j++){
        scanf("%lld",&b[i][j]);
        a[i][j]+=b[i][j];
    }
    }
m--;
int flagr,flagc;
flagr=flagc=1;
    for(int i=0;i<n ; i++){
    for(int j=0;j<m; j++){
        if((a[i][j]>=a[i][j+1])){
            flagr=0;
            break;
        }
    }
    }
    m++;n--;
    for(int i=0;i<m ; i++){
    for(int j=0;j<n; j++){
        if((a[j][i]>=a[j+1][i])){
            flagr=0;
            break;
        }
    }
    }
    if(flagr && flagc)puts("Possible");
    else puts("Impossible");
    return 0;
}
