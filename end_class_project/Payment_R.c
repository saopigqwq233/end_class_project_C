#include "pre_declaration.h"
void Payment(type_VIP*h_V,type_Trade_VIP*h_TV)
{
    printf("��������Ļ�Ա�˻�-->");
    int Target_id;
    type_VIP *p=h_V;
    scanf("%d",&Target_id);
    while (Target_id)
    {
        for(;p!=NULL;p=p->next)
        {
            if(p->id==Target_id)
            {
                type_Trade_VIP *new=(type_Trade_VIP*) malloc(sizeof (type_Trade_VIP));
                new->next=h_TV->next;
                new->id=p->id;
                h_TV->next=new;
                printf("���ҵ������˻���������ɷѶ��->");
                scanf("%d",&(new->pay));
                p->balance+=new->pay;
                printf("������ɷѵ�����(�磺20220101)\n-->");
                scanf("%d",&(new->time));
                FILE *fp= fopen("file_Trade_VIP.txt","a");
                fprintf(fp,"%d %d %d\n",new->id,new->pay,new->time);
                fclose(fp);
                printf("�ɷѳɹ������������˳�\n");
                break;
            }
        }
        if(p->id==Target_id)
        {
            break;
        }
        if(p==NULL)
        {
            printf("δ�ҵ������˺ţ�����ϵ����Ա���������룬������0�����ɷ�\n-->");
            scanf("%d",&Target_id);
        }
    }
}
