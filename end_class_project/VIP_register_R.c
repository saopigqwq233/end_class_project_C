#include "pre_declaration.h"
void VIP_register(type_VIP*h_V)
{
    FILE *fp=fopen("file_VIP.txt", "a");
    printf("���Կ�ʼע��\n");
    int number0fregister;//ע�����
    printf("�����뼸����Ա��Ҫע��->");
    scanf("%d",&number0fregister);
    printf("������Ҫע��Ļ�Ա��\n"
           "ID�˺�(���9λ) �������루���9λ����Ա���� �Ա�(��1Ů2) ��������գ�����:20221211��"
           "\n");
    printf("����֮���Կո�Ͽ�\n");
    while (number0fregister--)
    {
        type_VIP *new=(type_VIP*) malloc(sizeof (type_VIP));
        new->next=NULL;
        new->balance=0;
        new->DVD_rent[0]=new->DVD_rent[1]=new->DVD_rent[2]=0;
        scanf("%d %d %s %d %d",&(new->id),&(new->password),
              (new->name_VIP),&(new->sex_male1_female_2),
              &(new->time_join));
        fprintf(fp,"%d %d %s %d %d %d %d %d %d\n",(new->id),(new->password),
                (new->name_VIP),(new->sex_male1_female_2),
                (new->time_join),(new->balance),(new->DVD_rent[0]),
                (new->DVD_rent[1]),(new->DVD_rent[2]));
        h_V->next=new;
        h_V=new;
    }
    fclose(fp);
    printf("ע��ɹ���\n");
    printf("�������������ע�����\n");
    getchar();
}
