#include "pre_declaration.h"
void Information_DTrade(type_Trade_DVD *h_TD)
{
    printf("所有DVD租赁信息如下\n");
    for(h_TD=h_TD->next;h_TD!=NULL;h_TD=h_TD->next)
    {
        printf("DVD编号:%d ",h_TD->id);
        printf("租赁者账号:%d ",h_TD->id_VIP);
        printf("租赁时间:%d ",h_TD->time_rent);
        printf("租赁状态:");
        if(h_TD->isrented)
            printf("未归还");
        else
            printf("已归还");
        printf("\n");
    }
    printf("DVD租赁信息显示完毕");
}