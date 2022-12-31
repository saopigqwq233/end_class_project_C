#include "pre_declaration.h"
void VIP_register(type_VIP*h_V)
{
    FILE *fp=fopen("file_VIP.txt", "a");
    printf("可以开始注册\n");
    int number0fregister;//注册个数
    printf("请输入几个会员需要注册->");
    scanf("%d",&number0fregister);
    printf("输入需要注册的会员的\n"
           "ID账号(最多9位) 设置密码（最多9位）会员姓名 性别(男1女2) 入会年月日（例如:20221211）"
           "\n");
    printf("数据之间以空格断开\n");
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
    printf("注册成功！\n");
    printf("输入任意键结束注册程序\n");
    getchar();
}
