#include<stdio.h>

int main() {
    int row,col,row_r,row_r1,total,n,count=1;
   scanf("%d",&n);
    while(n--){
    scanf("%d%d",&row,&col);
    if(row==1 || col==1){
        total=col*row;
    }
    else if(row==2 || col==2){
        int quads=(row*col)/4;
        if(quads%2==0){
            total=(quads/2)*4+row*col-(quads*4);
        }
        else{
            total=((quads/2)+1)*4;
        }
    }

    else if(col%2==0){
        total=row*(col/2);
    }
    else if(col%2!=0){
        row_r=(col+1)/2;
        row_r1=row_r-1;
        total=(row/2)*row_r1+(row-row/2)*row_r;

    }
    printf("Case %d: %d\n",count++,total);
    }

    return 0;
}
