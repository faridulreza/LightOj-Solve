#include<bits\stdc++.h>
using namespace std;
vector<int > five;
vector<int > two;

int cnt5(int x) {
    int cnt=0;
    for(int y: five) {
        cnt+=x/y;
    }
    return cnt;
}
int cnt2(int x) {
    int cnt=0;
    for(int y: two) {
        cnt+=x/y;
    }
    return cnt;
}

int cnt(int x, int y){
    int cnt=0;
while(x%y==0){
cnt++;
x/=y;
}
return cnt;
}

int main() {

    for(long long  i=5; i<INT_MAX ; i=i*5) {
        five.push_back(i);
    }
    for(long long  i=2; i<INT_MAX ; i=i*2) {
        two.push_back(i);
    }
    //cout<<INT_MAX;
    int T,caseno=0;
    scanf("%d",&T);
    while(T--) {
        int n,r,p,q;
        cin>>n>>r>>p>>q;
        long long  fives,twos;
//        cout<<cnt5(n)<<" "<<cnt5(r)<<" "<<cnt5(n-r)<<" "<<cnt(p,5)<<endl;
//        cout<<cnt2(n)<<" "<<cnt2(r)<<" "<<cnt2(n-r)<<" "<<cnt(p,2)<<endl;
        fives=cnt5(n)-cnt5(r)-cnt5(n-r)+q*cnt(p,5);
        twos=cnt2(n)-cnt2(r)-cnt2(n-r)+q*cnt(p,2);

        printf("Case %d: %lld\n",++caseno,min(fives,twos));
    }

    return 0;
}
