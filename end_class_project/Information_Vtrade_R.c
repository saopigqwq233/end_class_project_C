#include "pre_declaration.h"
void Information_Vtrade(type_Trade_VIP *h_TV)
{
    printf("会员缴费信息如下\n");
    for(h_TV=h_TV->next;h_TV!=NULL;h_TV=h_TV->next)
    {
        printf("会员账号:%d ",h_TV->id);
        printf("缴费额:%d ",h_TV->pay);
        printf("缴费时间:%d\n",h_TV->time);
    }
    printf("会员缴费信息显示完毕\n");

}