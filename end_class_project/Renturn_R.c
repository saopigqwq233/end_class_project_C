#include "pre_declaration.h"
void Return(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD)
{
    int Target_VIP,password,Target_DVD;
    type_VIP *pV;
    type_DVD *pD;
    type_Trade_DVD *p_TD;
    printf("�����������˺ź����루�ո������\n-->");
    lable:scanf("%d %d",&Target_VIP,&password);
    if(((pV=FindTarget_VIP(h_V,Target_VIP))!=NULL)
    &&(pV->password==password))
    {
        printf("�ҵ������˻�������ʱδ�黹��DVD�ı��\n"
               "0����δ����\n"
               "%d %d %d\n",
               pV->DVD_rent[0],pV->DVD_rent[1],pV->DVD_rent[2]);
        printf("ѡ����Ҫ�黹��DVD"
               "(����0ֱ���˳��黹����)\n"
               "-->");
        scanf("%d",&Target_DVD);
        if(Target_DVD==0)
        {
            goto lable1;
        }
        for (int i = 0; i < 3; ++i)
        {
            if(Target_DVD==pV->DVD_rent[i])
            {
                pV->DVD_rent[i]=0;
                break;
            }
        }
        pD= FindTarget_DVD(h_D,Target_DVD);
        pD->available=1;
        p_TD= FindTarget_DVDinT(h_TD,Target_VIP,Target_DVD);
        p_TD->isrented=0;
        printf("�黹��������ɣ���������˳�\n");
    } else
    {
        printf("��������˺Ż��������������������˺ź����루�ո������\n"
               "-->");
        goto lable;
    }
    lable1:
    { printf("�黹�������\n"); }
}