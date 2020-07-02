  #include<stdio.h>

int main(){

    long long pn,m;
    int T,caseno=0,n;
    scanf("%d",&T);
    while(T--){
    scanf("%d%lld",&n,&m);
    pn=n/(2*m);

    printf("Case %d: %lld\n",++caseno,pn*m*m);
    }


    return 0;
}
