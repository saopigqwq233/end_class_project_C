#include "pre_declaration.h"
void Information_VIP(type_VIP*h_V)
{
    int Target_VIP=1,password;
    type_VIP *p;
    printf("���������˺ź����루�ո������\n-->");
    scanf("%d %d", &Target_VIP, &password);
    lable1:p = FindTarget_VIP(h_V, Target_VIP);
    if ((p == NULL)||(p->password != password))
    {
        printf("�����˺Ż��������������������˺ź�����\n"
                   "������0 0 ������ѯ\n"
                   "-->");
        scanf("%d %d",&Target_VIP,&password);
        if(Target_VIP==0||password==0)
            goto lable2;
        else
            goto lable1;
    }
    else
    {
        printf("������Ϣ����:\n");
        printf("�˺�:%d\n",p->id);
        printf("����:%d\n",p->password);
        printf("����:%s\n",p->name_VIP);
        printf("�Ա�:");
        if(p->sex_male1_female_2==1)
            printf("��");
        else if(p->sex_male1_female_2==2)
            printf("Ů");
        printf("\n");
        printf("���ʱ��:%d\n",p->time_join);
        printf("�˻����:%d\n",p->balance);
        printf("����DVD(0����δ����):%d %d %d\n",p->DVD_rent[0],p->DVD_rent[1],
               p->DVD_rent[2]);
    }
    lable2:
    printf("��ѯ�������\n");
}
