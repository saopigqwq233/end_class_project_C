//预处理
#ifndef END_CLASS_PROJECT_PRE_DECLARATION_H
#define END_CLASS_PROJECT_PRE_DECLARATION_H
//头文件
#include "stdio.h"
#include "stdlib.h"
//宏定义
#define max_rent 3       //最大租赁DVD数量
#define max_name_VIP 30  //会员名字占用最大字节数
#define max_name_DVD 50  //DVD名字占用最大字节数
#define administrator 904139266 //管理员账号
#define PIN 20030615            //管理员密码
//
//
//
//数据文件需要保存在debug文件中，与程序文件放在同一目录中
//存放VIP会员的文件名为 file_VIP.txt
//存放DVD信息的文件名为 file_DVD.txt
//存放DVD交易信息的文件名为 DVD_Trade.txt
//存放VIP缴费信息的文件名为 VIP_Trade.txt
//
//结构体声明
//会员信息数据类型type_VIP
typedef struct NODE
{
    int id;//会员的ID账号，9位
    int password;//会员账户密码
    char name_VIP[max_name_VIP];//会员名字
    int sex_male1_female_2;//会员性别，男1女2
    int time_join;//入会年月日
    int balance;//账户余额
    int DVD_rent[max_rent];//借的DVD的编号，如果没有借则3个均为0
    struct NODE*next;//提供链表的链接操作
}type_VIP;
//DVD信息数据类型type_DVD
typedef struct node
{
    int id;//DVD的编号
    char name_DVD[max_name_DVD];//DVD的名字
    int available;//1为可借用，0为借出状态
    struct node*next;
}type_DVD;
//DVD交易信息数据类型type_Trade_DVD
typedef struct noded
{
    int id;//DVD编号
    int id_VIP;//租赁者账号
    int time_rent;//租赁时间
    int isrented;//1为未归还状态，0归还状态
    struct noded*next;
}type_Trade_DVD;
//缴费交易信息数据类型type_Trade_VIP
typedef struct tv{
    int id;//VIP会员编号
    int pay;//支付多少钱
    int time;//支付时间
    struct tv*next;
}type_Trade_VIP;
//
//模块函数声明
void manual();//说明书函数
void Menu(void);//主界面菜单，提供功能选择
void VIP_register(type_VIP*h_V);//会员注册模块,以会员信息链表节点作为参数
void Payment(type_VIP*h_V,type_Trade_VIP*h_TV);//缴费模块，以会员信息链表节点作为参数
//和VIP交易信息链表表头做参数
void Rent(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD);//租赁模块，以会员信息链表节点
// 和DVD信息链表表头,和DVD交易信息链表表头作为参数
void Return(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD);//归还模块，以会员信息链表节点
// 和DVD信息链表表头作为参数和交易信息链表表头作为参数
void Information_VIP(type_VIP*h_V);//查询会员信息模块，以会员信息链表节点为参数
void manager(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD *h_TD,type_Trade_VIP*h_TV);//管理员操作模块
void maneger_enum(void );//管理员选择界面
void Information_DVD(type_DVD*h_D);//查询DVD信息模块，以DVD信息链表表头作为参数
void Information_member(type_VIP*h_V);//管理员查询会员信息模块，以会员信息链表表头为参数
void Information_DTrade(type_Trade_DVD *h_TD);//管理员查询交易信息模块，以DVD交易信息链表表头为参数
void Information_Vtrade(type_Trade_VIP *h_TV);//管理员查询VIP缴费信息模块，以VIP交易信息表头为参数
void Add_DVD(type_DVD*h_D);//管理员添加DVD,已DVD链表表头为参数
//
//
//基本链表操作函数声明
void read_file_VIP(type_VIP*h_V);//把文件的信息读入链表，以表头为参数
void read_file_DVD(type_DVD*h_D);//把文件的信息读入链表，以表头为参数
void read_file_Trade_DVD(type_Trade_DVD*h_TD);//把文件的信息读入链表，以表头为参数
void read_file_Trade_VIP(type_Trade_VIP*h_TV);//把文件的信息读入链表，以表头为参数
void write_file_VIP(type_VIP*h_V);//把链表信息重新写入文件
void write_file_DVD(type_DVD*h_D);//把链表信息重新写入文件
void write_file_Trade_DVD(type_Trade_DVD*h_TD);//把链表信息重新写入文件
void Delete_VIP(type_VIP*h_V);//删除一个会员，以会员信息链表表头为参数
void Delete_DVD(type_DVD*h_D);//增加一个DVD，以DVD信息链表表头为参数
type_VIP *FindTarget_VIP(type_VIP*h_V,int Target_VIP);//找到ID是Target_VIP的链表单元地址
type_DVD *FindTarget_DVD(type_DVD*h_D,int Target_DVD);//找到编号是Target是的链表单元地址
type_Trade_DVD *FindTarget_DVDinT(type_Trade_DVD*h_TD,int Target_VIP,int Target_DVD);//在交易里面找到DVD
#endif //END_CLASS_PROJECT_PRE_DECLARATION_H
