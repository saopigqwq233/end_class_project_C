#include "pre_declaration.h"
void Rent(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD)
{
    int Target_VIP,password_VIP,Target_DVD,time;
    type_VIP *pV=h_V;
    type_DVD *pD=h_D;
    printf("请输入您的账号\n-->");
    scanf("%d",&Target_VIP);
    printf("请输入您的密码\n-->");
    scanf("%d",&password_VIP);
    pV= FindTarget_VIP(h_V,Target_VIP);
    lable1:if(pV->password!=password_VIP)
    {
        printf("您的密码错误，请重新输入\n-->");
        scanf("%d",&password_VIP);
        goto lable1;
    }
    else
    {
        printf("输入您要租赁的DVD编码\n-->");
        scanf("%d",&Target_DVD);
        printf("输入租赁的日期（如20220101）\n-->");
        scanf("%d",&time);
        pD= FindTarget_DVD(h_D,Target_DVD);
        if(!(pD->available))
        {
            printf("这个DVD已被租赁\n"
                   "请选择其它DVD");
        } else
        {
            for (int i = 0; i < max_rent; ++i)
            {
                if (pV->DVD_rent[i] != 0)
                {
                    continue;
                }
                else
                {
                    pD->available=0;
                    pV->DVD_rent[i] = Target_DVD;
                    type_Trade_DVD *new=(type_Trade_DVD*) malloc(sizeof (type_Trade_DVD));
                    new->id_VIP=Target_VIP;
                    new->id=Target_DVD;
                    new->time_rent=time;
                    new->isrented=1;
                    new->next=h_TD->next;
                    h_TD->next=new;
                    FILE *fp= fopen("file_Trade_DVD.txt","a");
                    fprintf(fp,"%d %d %d %d\n",new->id,new->id_VIP,
                            new->time_rent,new->isrented);
                    fclose(fp);
                    printf("租赁成功\n"
                           "输入任意值退出租赁程序\n");
                    getchar();
                    break;
                }
            }
        }
    }
}