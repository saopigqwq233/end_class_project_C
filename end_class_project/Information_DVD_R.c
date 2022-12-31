#include "pre_declaration.h"
void Information_DVD(type_DVD*h_D)
{
    printf("DVD信息如下:\n");
    for(h_D=h_D->next;h_D!=NULL;h_D=h_D->next)
    {
        printf("id编码:%d ",h_D->id);
        printf("DVD作品名:%s ",h_D->name_DVD);
        printf("租赁状态:");
        if(h_D->available)
        {
            printf("可租出");
        } else
            printf("已租出");
        printf("\n");
    }
    printf("DVD查询程序结束\n");
    getchar();
}
