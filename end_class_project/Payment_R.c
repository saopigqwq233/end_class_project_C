#include "pre_declaration.h"
void Payment(type_VIP*h_V,type_Trade_VIP*h_TV)
{
    printf("请输入你的会员账户-->");
    int Target_id;
    type_VIP *p=h_V;
    scanf("%d",&Target_id);
    while (Target_id)
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->id==Target_id)
            {
                type_Trade_VIP *new=(type_Trade_VIP*) malloc(sizeof (type_Trade_VIP));
                new->next=h_TV->next;
                new->id=p->id;
                h_TV->next=new;
                printf("已找到您的账户，请输入缴费额度->");
                scanf("%d",&(new->pay));
                p->balance+=new->pay;
                printf("请输入缴费的日期(如：20220101)\n-->");
                scanf("%d",&(new->time));
                FILE *fp= fopen("file_Trade_VIP.txt","a");
                fprintf(fp,"%d %d %d\n",new->id,new->pay,new->time);
                fclose(fp);
                printf("缴费成功，点击任意键退出\n");
                break;
            }
        }
        if(p->id==Target_id)
        {
            break;
        }
        if(p==NULL)
        {
            printf("未找到您的账号，请联系管理员或重新输入，或输入0结束缴费\n-->");
            scanf("%d",&Target_id);
        }
    }
}
