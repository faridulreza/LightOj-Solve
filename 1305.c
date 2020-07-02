#include<stdio.h>
#include<math.h>

int main(){

    int T,caseno=0,ax,ay,bx,by,cx,cy,dx,dy,area;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
        dy=ay+cy-by;dx=ax+cx-bx;
        area=(ax-bx)*(by-cy)-(bx-cx)*(ay-by);

    printf("Case %d: %d %d %d\n",++caseno,dx,dy,abs(area));
    }


    return 0;
}
