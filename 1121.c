
#include<stdio.h>
#include<stdlib.h>




int main(){
int T,caseno=0;
scanf("%d",&T);
while(T--){
    int xlow=0,xhigh=10000,ylow=0,yhigh=10000,zlow=0,zhigh=10000;
    int txlow=0,txhigh=10000,tylow=0,tyhigh=10000,tzlow=0,tzhigh=10000,flag=1;
    int n;
    scanf("%d",&n);

    int xl,yl,zl,xu,yu,zu;
    while(n--){
        scanf("%d%d%d%d%d%d",&xl,&yl,&zl,&xu,&yu,&zu);


         txlow=xlow,txhigh=xhigh,tylow=ylow,tyhigh=yhigh,tzlow=zlow,tzhigh=zhigh;

        if(flag && !(xl>xhigh && xu>xhigh) && !(xl<xlow && xu<xlow)){

            if(xl>=txlow && xl<=txhigh)xlow=xl;
            if(xu>=txlow && xu<=txhigh)xhigh=xu;

        }
        else flag=0;


        if(flag && !(yl>yhigh && yu>yhigh) && !(yl<ylow && yu<ylow)){

            if(yl>=tylow && yl<=tyhigh)ylow=yl;
            if(yu>=tylow && yu<=tyhigh)yhigh=yu;

        }
        else flag=0;


        if(flag && !(zl>zhigh && zu>zhigh) && !(zl<zlow && zu<zlow)){

            if(zl>=tzlow && zl<=tzhigh)zlow=zl;
            if(zu>=tzlow && zu<=tzhigh)zhigh=zu;

        }
        else flag=0;
    }


    if(flag)printf("Case %d: %d\n",++caseno,(xhigh-xlow)*(yhigh-ylow)*(zhigh-zlow));
    else printf("Case %d: 0\n",++caseno);

}

}
