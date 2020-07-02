#include<stdio.h>


int main(){

    unsigned long long n,inp,p;
    double calcn;
    int T,caseno=0;
    scanf("%d",&T);
    while(T--){
        int row,col,flag=1;
        scanf("%llu",&inp);
         calcn=(1+sqrt(4*inp-3))/2.000;
         //printf("%lf\n",calcn);
         n=floor(calcn);
         p=n*n-n+1;
         if((inp>=p && inp<(p+n)) || (inp<=p && inp>(p-n))){
            if(n%2==0){
                if(inp<=p){
                    row=n;
                    col=n-(p-inp);
                }
                else {
                    col=n;
                    row=n-(inp-p);
                }
            }
            else{
                if(inp<=p){
                    col=n;
                    row=n-(p-inp);

                }
                else {
                    row=n;
                    col=n-(inp-p);

                }

            }
            flag=0;
         }
         n=ceil(calcn);
         p=n*n-n+1;
         if( flag   && ((inp>=p && inp<(p+n)) || (inp<=p && inp>(p-n)))){
            if(n%2==0){
                if(inp<=p){
                    row=n;
                    col=n-(p-inp);
                }
                else {
                    col=n;
                    row=n-(inp-p);
                }
            }
            else{
                if(inp<=p){
                    col=n;
                    row=n-(p-inp);

                }
                else {
                    row=n;
                    col=n-(inp-p);

                }

            }
         }


    printf("Case %d: %d %d\n",++caseno,col,row);
    }

    return 0;
}
