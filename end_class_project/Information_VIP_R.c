#include "pre_declaration.h"
void Information_VIP(type_VIP*h_V)
{
    int Target_VIP=1,password;
    type_VIP *p;
    printf("输入您的账号和密码（空格隔开）\n-->");
    scanf("%d %d", &Target_VIP, &password);
    lable1:p = FindTarget_VIP(h_V, Target_VIP);
    if ((p == NULL)||(p->password != password))
    {
        printf("您的账号或密码有误，请重新输入账号和密码\n"
                   "或输入0 0 结束查询\n"
                   "-->");
        scanf("%d %d",&Target_VIP,&password);
        if(Target_VIP==0||password==0)
            goto lable2;
        else
            goto lable1;
    }
    else
    {
        printf("您的信息如下:\n");
        printf("账号:%d\n",p->id);
        printf("密码:%d\n",p->password);
        printf("姓名:%s\n",p->name_VIP);
        printf("性别:");
        if(p->sex_male1_female_2==1)
            printf("男");
        else if(p->sex_male1_female_2==2)
            printf("女");
        printf("\n");
        printf("入会时间:%d\n",p->time_join);
        printf("账户余额:%d\n",p->balance);
        printf("在租DVD(0代表未租用):%d %d %d\n",p->DVD_rent[0],p->DVD_rent[1],
               p->DVD_rent[2]);
    }
    lable2:
    printf("查询程序结束\n");
}
