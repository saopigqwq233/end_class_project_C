#include "pre_declaration.h"
int main()
{
    //初始化三个链表表头
    type_VIP VIP,*h_V=&VIP;h_V->next=NULL;//VIP信息链表表头
    type_DVD DVD,*h_D=&DVD;h_D->next=NULL;//DVD信息链表表头
    type_Trade_DVD Trade_DVD,*h_TD=&Trade_DVD;h_TD->next=NULL;//DVD交易信息链表表头
    type_Trade_VIP Trade_VIP,*h_TV=&Trade_VIP;h_TV->next=NULL;//VIP交易信息链表表头
    //形成三个链表
    read_file_VIP(h_V);
    read_file_DVD(h_D);
    read_file_Trade_DVD(h_TD);
    read_file_Trade_VIP(h_TV);
    //定义枚举变量
    enum choic
            {
                Register=1,Pay,RentD,ReturnD,Info_VIP,Info_DVD,Manage,Manual,Exit=0,
            };
    int input;//键盘输入选择功能
    do 
    {
        Menu();
        scanf("%d",&input);
        switch (input) 
        {
            case Register://注册
                VIP_register(h_V);
                break;
            case Pay://缴费
                Payment(h_V,h_TV);
                write_file_VIP(h_V);
                getchar();
                break;
            case RentD://租赁
                Rent(h_V,h_D,h_TD);
                write_file_VIP(h_V);
                write_file_DVD(h_D);
                getchar();
                break;
            case ReturnD://归还
                Return(h_V,h_D,h_TD);
                write_file_VIP(h_V);
                write_file_DVD(h_D);
                write_file_Trade_DVD(h_TD);
                getchar();
                break;
            case Info_VIP://会员查询功能
                Information_VIP(h_V);
                getchar();
                break;
            case Info_DVD://DVD信息查询
                Information_DVD(h_D);
                getchar();
                break;
            case Manage://管理员通道
                manager(h_V,h_D,h_TD,h_TV);
                getchar();
                break;
            case Manual://说明书
                manual();
                getchar();
                break;
            case Exit:
                printf("程序结束\n");
                break;
            default:
                printf("错误输入\n请重新输入");
                getchar();
        }
        getchar();
    } while (input);
    printf("按任意键关闭程序");
    getchar();
    return 0;
}
