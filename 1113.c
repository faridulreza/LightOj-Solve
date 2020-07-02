#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st {
    struct st *priv;
    char url[120];
} stack;
stack *forward;
stack *back;
stack *current;


void visit (char arr[],int x) {
    stack *tmp,*cur=(stack *)malloc(sizeof(stack));
    strcpy(cur->url,arr);

    cur->priv=back;
    back=cur;
    current=back;
    if(x)
        puts(current->url);
    while(forward!=NULL) {
        tmp=forward;
        forward=forward->priv;
        free(tmp);
    }
}

void Back() {
    if(back==NULL) {
        puts("Ignored");
        return;
    }
    stack *tmp ;
    if(current==back) {

        tmp=back;

        if((back->priv)!=NULL) {
            back=back->priv;
            current=back;

            tmp->priv=forward;
            forward=tmp;
        } else
            current=NULL;
    } else {
        tmp=back;

        if(back->priv!=NULL)
        {
            back=back->priv;

        tmp->priv=forward;
        forward=current=tmp;
        }
        else current=NULL;
    }

    if(current==NULL) {
        puts("Ignored");
        return;
    }
    puts(current->url);
}



void Forward() {
    if(forward==NULL) {
        puts("Ignored");
        return;
    }
    stack *tmp ;
    if(current==forward) {

        tmp=forward;
        forward=forward->priv;
        current=forward;
        tmp->priv=back;
        back=tmp;
    } else {
        tmp=forward;

        forward=forward->priv;

        tmp->priv=back;
        back=current=tmp;
    }

    if(current==NULL) {
        puts("Ignored");
        return;
    }
    puts(current->url);
}


int main() {
    char cmd[20],ch[60];

    int T,caseno=0;
    scanf("%d ",&T);
    while(T--) {
        forward=back=current=NULL;
        visit("http://www.lightoj.com/",0);
        printf("Case %d:\n",++caseno);
        while(1) {
            scanf("%s",cmd);
            if(strcmp(cmd,"VISIT")==0) {
                getchar();
                gets(ch);
                visit(ch,1);

            } else if(strcmp(cmd,"BACK")==0) {
                Back();

            } else if(strcmp(cmd,"FORWARD")==0)
                Forward();
            else if(strcmp(cmd,"QUIT")==0)
                break;

        }
        stack *tmp;
        while(forward!=NULL) {
            tmp=forward;
            forward=forward->priv;
            free(tmp);
        }

        while(back!=NULL) {
            tmp=back;
            back=back->priv;
            free(tmp);
        }
    }
    return 0;
}
