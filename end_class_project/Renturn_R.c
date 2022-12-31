#include "pre_declaration.h"
void Return(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD)
{
    int Target_VIP,password,Target_DVD;
    type_VIP *pV;
    type_DVD *pD;
    type_Trade_DVD *p_TD;
    printf("请输入您的账号和密码（空格隔开）\n-->");
    lable:scanf("%d %d",&Target_VIP,&password);
    if(((pV=FindTarget_VIP(h_V,Target_VIP))!=NULL)
    &&(pV->password==password))
    {
        printf("找到您的账户，你暂时未归还的DVD的编号\n"
               "0代表未租赁\n"
               "%d %d %d\n",
               pV->DVD_rent[0],pV->DVD_rent[1],pV->DVD_rent[2]);
        printf("选择你要归还的DVD"
               "(输入0直接退出归还程序)\n"
               "-->");
        scanf("%d",&Target_DVD);
        if(Target_DVD==0)
        {
            goto lable1;
        }
        for (int i = 0; i < 3; ++i)
        {
            if(Target_DVD==pV->DVD_rent[i])
            {
                pV->DVD_rent[i]=0;
                break;
            }
        }
        pD= FindTarget_DVD(h_D,Target_DVD);
        pD->available=1;
        p_TD= FindTarget_DVDinT(h_TD,Target_VIP,Target_DVD);
        p_TD->isrented=0;
        printf("归还程序已完成，按任意键退出\n");
    } else
    {
        printf("您输入的账号或密码有误，请重新输入账号和密码（空格隔开）\n"
               "-->");
        goto lable;
    }
    lable1:
    { printf("归还程序结束\n"); }
}