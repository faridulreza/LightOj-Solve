#include  <iostream>
#include  <vector>
#include <iomanip>
#include  <deque>
#include  <list>
#include  <set>
#include  <map>
#include  <stack>
#include  <queue>
#include  <algorithm>
#include  <cstring>
#include  <cmath>
#include  <cctype>
#include  <cstdlib>
#include  <stdio.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (3.14159265)
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define fs first
#define sc second
#define pb(a) push_back(a)
#define len (100000)
ll mx=-1000000000-100;
ll mn=1000000000+100;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

double ang(double a,double b, double c){


return  acos((a*a+b*b-c*c)/(2*a*b));

}

int main() {



 int T;

    cn T;
for(int caseno=1; caseno<=T  ;caseno++){
double r1,r2,r3;
cn r1>>r2>>r3;
double res=(r1+r2)*(r1+r3)*sin(ang((r1+r2),(r1+r3),r2+r3))-ang(r1+r2,r1+r3,r2+r3)*r1*r1 - ang(r2+r1,r2+r3,r1+r3)*r2*r2-ang(r3+r2,r3+r1,r2+r1)*r3*r3;

printf("Case %d: %.10f\n",caseno,res*.5);
}





    return 0;
}
