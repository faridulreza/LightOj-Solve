#include<stdio.h>
#include<stdio.h>
#include<math.h>

int primes[78550];
char arr[1000100];
int cnt=1;

void ops(int n) {
    for(long long i=3; i*i<=n; i+=2) {
        if(arr[i]==0) {
            for(long long j=i*i; j<=n ; j+=i) {
                arr[j]='a';
            }
        }
    }
    primes[0]=2;
    for(int i=3; i<=n; i+=2) {
        if(arr[i]==0)
            primes[cnt++]=i;
    }

}
int main() {


    ops(1000100);
    // printf("%d\n",primes[cnt-1]);
    int T,caseno=0;
    scanf("%d",&T);
    while(T--) {
        long long n,res;
        scanf("%lld",&n);
        int c;
        res=1;
            int root=round(sqrt(n));
            for(int i=0; primes[i]<=root; i++) {
                c=1;
                while(n%primes[i]==0) {
                    n=n/primes[i];
                    c++;
                }
                res*=c;
                root=sqrt(n);
            }
if(n!=1)res*=2;

        printf("Case %d: %lld\n",++caseno,res-1);

    }

    return 0;
}
