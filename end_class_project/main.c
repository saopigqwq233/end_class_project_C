#include "pre_declaration.h"
int main()
{
    //��ʼ�����������ͷ
    type_VIP VIP,*h_V=&VIP;h_V->next=NULL;//VIP��Ϣ�����ͷ
    type_DVD DVD,*h_D=&DVD;h_D->next=NULL;//DVD��Ϣ�����ͷ
    type_Trade_DVD Trade_DVD,*h_TD=&Trade_DVD;h_TD->next=NULL;//DVD������Ϣ�����ͷ
    type_Trade_VIP Trade_VIP,*h_TV=&Trade_VIP;h_TV->next=NULL;//VIP������Ϣ�����ͷ
    //�γ���������
    read_file_VIP(h_V);
    read_file_DVD(h_D);
    read_file_Trade_DVD(h_TD);
    read_file_Trade_VIP(h_TV);
    //����ö�ٱ���
    enum choic
            {
                Register=1,Pay,RentD,ReturnD,Info_VIP,Info_DVD,Manage,Manual,Exit=0,
            };
    int input;//��������ѡ����
    do 
    {
        Menu();
        scanf("%d",&input);
        switch (input) 
        {
            case Register://ע��
                VIP_register(h_V);
                break;
            case Pay://�ɷ�
                Payment(h_V,h_TV);
                write_file_VIP(h_V);
                getchar();
                break;
            case RentD://����
                Rent(h_V,h_D,h_TD);
                write_file_VIP(h_V);
                write_file_DVD(h_D);
                getchar();
                break;
            case ReturnD://�黹
                Return(h_V,h_D,h_TD);
                write_file_VIP(h_V);
                write_file_DVD(h_D);
                write_file_Trade_DVD(h_TD);
                getchar();
                break;
            case Info_VIP://��Ա��ѯ����
                Information_VIP(h_V);
                getchar();
                break;
            case Info_DVD://DVD��Ϣ��ѯ
                Information_DVD(h_D);
                getchar();
                break;
            case Manage://����Աͨ��
                manager(h_V,h_D,h_TD,h_TV);
                getchar();
                break;
            case Manual://˵����
                manual();
                getchar();
                break;
            case Exit:
                printf("�������\n");
                break;
            default:
                printf("��������\n����������");
                getchar();
        }
        getchar();
    } while (input);
    printf("��������رճ���");
    getchar();
    return 0;
}
