#include "pre_declaration.h"
void Information_Vtrade(type_Trade_VIP *h_TV)
{
    printf("��Ա�ɷ���Ϣ����\n");
    for(h_TV=h_TV->next;h_TV!=NULL;h_TV=h_TV->next)
    {
        printf("��Ա�˺�:%d ",h_TV->id);
        printf("�ɷѶ�:%d ",h_TV->pay);
        printf("�ɷ�ʱ��:%d\n",h_TV->time);
    }
    printf("��Ա�ɷ���Ϣ��ʾ���\n");

}