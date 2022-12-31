#include "pre_declaration.h"
void Add_DVD(type_DVD*h_D)
{
    FILE *fp= fopen("file_DVD.txt","a");
    int number;
    printf("输入你要加入的DVD的个数\n-->");
    scanf("%d",&number);
    printf("输入DVD的编码（最多9位）和名字，数据之间空格隔开\n");
    while(number--)
    {
        type_DVD *new=(type_DVD*) malloc(sizeof (type_DVD));
        scanf("%d %s",&(new->id),(new->name_DVD));
        new->available=1;
        new->next=h_D->next;
        h_D->next=new;
        fprintf(fp,"%d %s %d\n",new->id,
                new->name_DVD,
                new->available);
    }
    fclose(fp);
    printf("DVD加入完毕\n");
}