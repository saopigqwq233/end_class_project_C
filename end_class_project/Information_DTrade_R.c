#include "pre_declaration.h"
void Information_DTrade(type_Trade_DVD *h_TD)
{
    printf("����DVD������Ϣ����\n");
    for(h_TD=h_TD->next;h_TD!=NULL;h_TD=h_TD->next)
    {
        printf("DVD���:%d ",h_TD->id);
        printf("�������˺�:%d ",h_TD->id_VIP);
        printf("����ʱ��:%d ",h_TD->time_rent);
        printf("����״̬:");
        if(h_TD->isrented)
            printf("δ�黹");
        else
            printf("�ѹ黹");
        printf("\n");
    }
    printf("DVD������Ϣ��ʾ���");
}