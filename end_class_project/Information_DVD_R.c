#include "pre_declaration.h"
void Information_DVD(type_DVD*h_D)
{
    printf("DVD��Ϣ����:\n");
    for(h_D=h_D->next;h_D!=NULL;h_D=h_D->next)
    {
        printf("id����:%d ",h_D->id);
        printf("DVD��Ʒ��:%s ",h_D->name_DVD);
        printf("����״̬:");
        if(h_D->available)
        {
            printf("�����");
        } else
            printf("�����");
        printf("\n");
    }
    printf("DVD��ѯ�������\n");
    getchar();
}
