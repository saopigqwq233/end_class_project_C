#include "pre_declaration.h"
void Rent(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD)
{
    int Target_VIP,password_VIP,Target_DVD,time;
    type_VIP *pV=h_V;
    type_DVD *pD=h_D;
    printf("�����������˺�\n-->");
    scanf("%d",&Target_VIP);
    printf("��������������\n-->");
    scanf("%d",&password_VIP);
    pV= FindTarget_VIP(h_V,Target_VIP);
    lable1:if(pV->password!=password_VIP)
    {
        printf("���������������������\n-->");
        scanf("%d",&password_VIP);
        goto lable1;
    }
    else
    {
        printf("������Ҫ���޵�DVD����\n-->");
        scanf("%d",&Target_DVD);
        printf("�������޵����ڣ���20220101��\n-->");
        scanf("%d",&time);
        pD= FindTarget_DVD(h_D,Target_DVD);
        if(!(pD->available))
        {
            printf("���DVD�ѱ�����\n"
                   "��ѡ������DVD");
        } else
        {
            for (int i = 0; i < max_rent; ++i)
            {
                if (pV->DVD_rent[i] != 0)
                {
                    continue;
                }
                else
                {
                    pD->available=0;
                    pV->DVD_rent[i] = Target_DVD;
                    type_Trade_DVD *new=(type_Trade_DVD*) malloc(sizeof (type_Trade_DVD));
                    new->id_VIP=Target_VIP;
                    new->id=Target_DVD;
                    new->time_rent=time;
                    new->isrented=1;
                    new->next=h_TD->next;
                    h_TD->next=new;
                    FILE *fp= fopen("file_Trade_DVD.txt","a");
                    fprintf(fp,"%d %d %d %d\n",new->id,new->id_VIP,
                            new->time_rent,new->isrented);
                    fclose(fp);
                    printf("���޳ɹ�\n"
                           "��������ֵ�˳����޳���\n");
                    getchar();
                    break;
                }
            }
        }
    }
}