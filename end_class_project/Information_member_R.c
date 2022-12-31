#include "pre_declaration.h"
void Information_member(type_VIP*h_V)
{
    printf("所有会员信息如下:\n");
    for(h_V=h_V->next;h_V!=NULL;h_V=h_V->next)
    {
        printf("账号:%d ",h_V->id);
        printf("密码:%d ",h_V->password);
        printf("姓名:%s ",h_V->name_VIP);
        printf("性别:");
        if(h_V->sex_male1_female_2==1)
            printf("男");
        else
            printf("女");
        printf(" ");
        printf("入会时间:%d ",h_V->time_join);
        printf("余额:%d ",h_V->balance);
        printf("在租DVD:%d %d %d\n",h_V->DVD_rent[0],
               h_V->DVD_rent[1],h_V->DVD_rent[2]);
    }
    printf("会员信息显示完毕\n");
}
