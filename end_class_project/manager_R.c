#include "pre_declaration.h"
void manager(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD *h_TD,type_Trade_VIP*h_TV)
{
    int ID,password;
    printf("�������Ա�˺ź�����(�ո����)\n-->");
    scanf("%d %d",&ID,&password);
    enum {info_VIP=1,info_Trade_VIP,info_Trade_DVD,add_DVD,
            delete_DVD,delete_VIP,
            Exit=0
    };
    if((ID==administrator)&&(password==PIN))
    {
        int input=1;
        while (input)
        {
            maneger_enum();
            printf("��������Ҫ���еĲ���\n"
                   "-->");
            scanf("%d", &input);
            switch (input)
            {
                case info_VIP://1
                    Information_member(h_V);
                    getchar();
                    break;
                case info_Trade_VIP://2
                    Information_Vtrade(h_TV);
                    getchar();
                    break;
                case info_Trade_DVD://3
                    Information_DTrade(h_TD);
                    getchar();
                    break;
                case add_DVD://4
                    Add_DVD(h_D);
                    getchar();
                    break;
                case delete_DVD://5
                    Delete_DVD(h_D);
                    write_file_DVD(h_D);
                    getchar();
                    break;
                case delete_VIP://6
                    Delete_VIP(h_V);
                    write_file_VIP(h_V);
                    getchar();
                    break;
                case Exit://0
                    printf("�˳�����Աͨ��\n");
                    getchar();
                    break;
                default:
                    printf("�������룬������ѡ��\n-->");
            }
            printf("��������ֵ���ع���Ա���˵�\n");
            getchar();
        }
    }
    else
        printf("����Ա�˻����������\n");
    printf("����������\n"
           "��������������˵�\n");
}