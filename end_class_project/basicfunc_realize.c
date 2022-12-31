#include "pre_declaration.h"
void read_file_VIP(type_VIP*h_V)
{
    FILE *fp=fopen("file_VIP.txt", "r");
    while (1)
    {
        type_VIP *new= (type_VIP*)malloc(sizeof (type_VIP));
        new->next=NULL;
        if(fscanf(fp,"%d %d %s %d %d %d %d %d %d",&(new->id),
               &(new->password),(new->name_VIP),
               &(new->sex_male1_female_2),&(new->time_join),
               &(new->balance),&(new->DVD_rent[0]),
               &(new->DVD_rent[1]),&(new->DVD_rent[2]))!=EOF)
        {
            h_V->next = new;
            h_V = new;
        }
        else
        {
            free(new);
            break;
        }
    }
    fclose(fp);
}
void read_file_DVD(type_DVD*h_D)
{
    FILE *fp= fopen("file_DVD.txt","r");
    while (1)
    {
        type_DVD *new=(type_DVD*) malloc(sizeof (type_DVD));
        new->next=NULL;
        if(fscanf(fp,"%d %s %d",&(new->id),(new->name_DVD),
               &(new->available))!=EOF)
        {
            h_D->next=new;
            h_D=new;
        }
        else
        {
            free(new);
            break;
        }

    }
    fclose(fp);
}
void read_file_Trade_DVD(type_Trade_DVD *h_TD)
{
    FILE *fp= fopen("file_Trade_DVD.txt","r");
    while (1)
    {
        type_Trade_DVD *new=(type_Trade_DVD *) malloc(sizeof (type_Trade_DVD));
        h_TD->next=NULL;
        if (fscanf(fp,"%d %d %d %d",&(new->id),&(new->id_VIP),&(new->time_rent),
               &(new->isrented))!=EOF)
        {
            h_TD->next=new;
            h_TD=new;
        }
        else
        {
            free(new);
            break;
        }
    }
    fclose(fp);
}
void read_file_Trade_VIP(type_Trade_VIP*h_TV)
{
    FILE *fp= fopen("file_Trade_VIP.txt","r");
    while (1)
    {
        type_Trade_VIP *new=(type_Trade_VIP*) malloc(sizeof (type_Trade_VIP));
        new->next=NULL;
        if (fscanf(fp,"%d %d %d",&(new->id),
               &(new->pay),&(new->time))!=EOF)
        {
            h_TV->next=new;
            h_TV=new;
        }
        else
        {
            free(new);
            break;
        }
    }
    fclose(fp);
}
void write_file_VIP(type_VIP*h_V)
{
    FILE *fp= fopen("file_VIP.txt","w");
    for(h_V=h_V->next;h_V!=NULL;h_V=h_V->next)
    {
        fprintf(fp,"%d %d %s %d %d %d %d %d %d\n",
                (h_V->id),(h_V->password),(h_V->name_VIP),
                (h_V->sex_male1_female_2),(h_V->time_join),
                (h_V->balance),(h_V->DVD_rent[0]),
                (h_V->DVD_rent[1]),
                (h_V->DVD_rent[2]));
    }
    fclose(fp);
}
void write_file_DVD(type_DVD*h_D)
{
    FILE *fp= fopen("file_DVD.txt","w");
    for(h_D=h_D->next;h_D!=NULL;h_D=h_D->next)
    {
        fprintf(fp,"%d %s %d\n",h_D->id,h_D->name_DVD,h_D->available);
    }
    fclose(fp);
}
void Delete_VIP(type_VIP*h_V)
{
    int target_VIP;//删除目标的账号
    int lable=0;
    type_VIP *p=h_V;
    printf("请输入删除目标的账号-->");
    scanf("%d",&target_VIP);
    while (target_VIP)
    {
        for(;p->next!=NULL;p=p->next)
        {
            if(p->next->id==target_VIP)
            {
                type_VIP *tmp=p->next;
                p->next=tmp->next;
                free(tmp);
                printf("目标已删除\n");
                lable=1;
                break;
            }
        }
        if(lable==0)
        {
            p = h_V;
            printf("列表中未有此人，请重新输入，或输入0结束删除程序\n-->");
            scanf("%d", &target_VIP);
        } else break;
    }
}
void Delete_DVD(type_DVD*h_D)
{
    int target_DVD;//删除DVD的编号
    int lable=0;
    type_DVD *p=h_D;
    printf("请输入删除DVD的编号->");
    scanf("%d",&target_DVD);
    while (target_DVD)
    {
        for(;p->next!=NULL;p=p->next)
        {
            if(p->next->id==target_DVD)
            {
                type_DVD *tmp=p->next;
                p->next=tmp->next;
                free(tmp);
                printf("目标已删除");
                lable=1;
                break;
            }
        }
        if(lable==0)
        {
            p = h_D;
            printf("未找到目标DVD编号，请重新输入，或输入0结束删除程序\n-->");
            scanf("%d", &target_DVD);
        } else break;
    }
}
type_VIP *FindTarget_VIP(type_VIP*h_V,int Target_VIP)
{
    type_VIP *p=h_V;
    for(p=p->next;p!=NULL;p=p->next)
    {
        if(p->id==Target_VIP)
        {
            return p;
        }
    }
    if(p==NULL)
        return p;
}
type_DVD *FindTarget_DVD(type_DVD*h_D,int Target_DVD)
{
    type_DVD *p=h_D;
    for(p=p->next;p!=NULL;p=p->next)
    {
        if(p->id==Target_DVD)
        {
            return p;
        }
    }
    if(p==NULL)
        return NULL;
}
void write_file_Trade_DVD(type_Trade_DVD*h_TD)
{
    FILE *fp= fopen("file_Trade_DVD.txt","w");
    for(h_TD=h_TD->next;h_TD!=NULL;h_TD=h_TD->next)
    {
        fprintf(fp,"%d %d %d %d\n",h_TD->id,h_TD->id_VIP,
                h_TD->time_rent,h_TD->isrented);
    }
    fclose(fp);
}
void write_file_Trade_VIP(type_Trade_VIP*h_TV)
{
    FILE *fp= fopen("file_Trade_VIP.txt","w");
    for(h_TV=h_TV->next;h_TV!=NULL;h_TV=h_TV->next)
    {
        fprintf(fp,"%d %d %d",h_TV->id,h_TV->pay,h_TV->time);
    }
    fclose(fp);
}
type_Trade_DVD *FindTarget_DVDinT(type_Trade_DVD*h_TD,int Target_VIP,int Target_DVD)
{
    type_Trade_DVD *p=h_TD;
    for(p=p->next;p!=NULL;p=p->next)
    {
        if((p->id==Target_DVD)//id对的上，VIPid对的上，还是在租赁状态中
        &&(Target_VIP==p->id_VIP)
        &&(p->isrented))
        {
            return p;
        }
    }
    if (p==NULL)
        return p;
}


