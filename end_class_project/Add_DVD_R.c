#include "pre_declaration.h"
void Add_DVD(type_DVD*h_D)
{
    FILE *fp= fopen("file_DVD.txt","a");
    int number;
    printf("������Ҫ�����DVD�ĸ���\n-->");
    scanf("%d",&number);
    printf("����DVD�ı��루���9λ�������֣�����֮��ո����\n");
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
    printf("DVD�������\n");
}