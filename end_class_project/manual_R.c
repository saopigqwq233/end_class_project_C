#include "pre_declaration.h"
void manual()
{
    printf("\t\t程序说明:\n");
    printf("注册会员账号和密码均为不超过9位的数字，请在注册时注意，"
           "且注册后不可更改\n");
    printf("会员名字输入汉字或者拼音均可,中间不能有空格\n");
    printf("性别，如果是男则填写1，女则填写2\n");
    printf("时间请按年月日方式填，如20221010\n");
    printf("注册会员的余额和租赁DVD均为0\n");
    printf("用户信息中在租DVD为0表示未租\n");
    printf("DVD只有一个，被租用时别人无法租用\n");
    printf("租用时间无限\n");
    printf("每个会员最多租用%d个DVD",max_rent);
    printf("每月会员需要缴费\n");
    printf("管理员账号密码分别只有一个\n");
    printf("管理员可在程序头文件查看账号密码\n");
    printf("有任何问题请联系管理员\n");
    getchar();
}