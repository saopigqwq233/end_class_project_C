#include "pre_declaration.h"
void Information_member(type_VIP*h_V)
{
    printf("���л�Ա��Ϣ����:\n");
    for(h_V=h_V->next;h_V!=NULL;h_V=h_V->next)
    {
        printf("�˺�:%d ",h_V->id);
        printf("����:%d ",h_V->password);
        printf("����:%s ",h_V->name_VIP);
        printf("�Ա�:");
        if(h_V->sex_male1_female_2==1)
            printf("��");
        else
            printf("Ů");
        printf(" ");
        printf("���ʱ��:%d ",h_V->time_join);
        printf("���:%d ",h_V->balance);
        printf("����DVD:%d %d %d\n",h_V->DVD_rent[0],
               h_V->DVD_rent[1],h_V->DVD_rent[2]);
    }
    printf("��Ա��Ϣ��ʾ���\n");
}
