//Ԥ����
#ifndef END_CLASS_PROJECT_PRE_DECLARATION_H
#define END_CLASS_PROJECT_PRE_DECLARATION_H
//ͷ�ļ�
#include "stdio.h"
#include "stdlib.h"
//�궨��
#define max_rent 3       //�������DVD����
#define max_name_VIP 30  //��Ա����ռ������ֽ���
#define max_name_DVD 50  //DVD����ռ������ֽ���
#define administrator 904139266 //����Ա�˺�
#define PIN 20030615            //����Ա����
//
//
//
//�����ļ���Ҫ������debug�ļ��У�������ļ�����ͬһĿ¼��
//���VIP��Ա���ļ���Ϊ file_VIP.txt
//���DVD��Ϣ���ļ���Ϊ file_DVD.txt
//���DVD������Ϣ���ļ���Ϊ DVD_Trade.txt
//���VIP�ɷ���Ϣ���ļ���Ϊ VIP_Trade.txt
//
//�ṹ������
//��Ա��Ϣ��������type_VIP
typedef struct NODE
{
    int id;//��Ա��ID�˺ţ�9λ
    int password;//��Ա�˻�����
    char name_VIP[max_name_VIP];//��Ա����
    int sex_male1_female_2;//��Ա�Ա���1Ů2
    int time_join;//���������
    int balance;//�˻����
    int DVD_rent[max_rent];//���DVD�ı�ţ����û�н���3����Ϊ0
    struct NODE*next;//�ṩ��������Ӳ���
}type_VIP;
//DVD��Ϣ��������type_DVD
typedef struct node
{
    int id;//DVD�ı��
    char name_DVD[max_name_DVD];//DVD������
    int available;//1Ϊ�ɽ��ã�0Ϊ���״̬
    struct node*next;
}type_DVD;
//DVD������Ϣ��������type_Trade_DVD
typedef struct noded
{
    int id;//DVD���
    int id_VIP;//�������˺�
    int time_rent;//����ʱ��
    int isrented;//1Ϊδ�黹״̬��0�黹״̬
    struct noded*next;
}type_Trade_DVD;
//�ɷѽ�����Ϣ��������type_Trade_VIP
typedef struct tv{
    int id;//VIP��Ա���
    int pay;//֧������Ǯ
    int time;//֧��ʱ��
    struct tv*next;
}type_Trade_VIP;
//
//ģ�麯������
void manual();//˵���麯��
void Menu(void);//������˵����ṩ����ѡ��
void VIP_register(type_VIP*h_V);//��Աע��ģ��,�Ի�Ա��Ϣ����ڵ���Ϊ����
void Payment(type_VIP*h_V,type_Trade_VIP*h_TV);//�ɷ�ģ�飬�Ի�Ա��Ϣ����ڵ���Ϊ����
//��VIP������Ϣ�����ͷ������
void Rent(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD);//����ģ�飬�Ի�Ա��Ϣ����ڵ�
// ��DVD��Ϣ�����ͷ,��DVD������Ϣ�����ͷ��Ϊ����
void Return(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD*h_TD);//�黹ģ�飬�Ի�Ա��Ϣ����ڵ�
// ��DVD��Ϣ�����ͷ��Ϊ�����ͽ�����Ϣ�����ͷ��Ϊ����
void Information_VIP(type_VIP*h_V);//��ѯ��Ա��Ϣģ�飬�Ի�Ա��Ϣ����ڵ�Ϊ����
void manager(type_VIP*h_V,type_DVD*h_D,type_Trade_DVD *h_TD,type_Trade_VIP*h_TV);//����Ա����ģ��
void maneger_enum(void );//����Աѡ�����
void Information_DVD(type_DVD*h_D);//��ѯDVD��Ϣģ�飬��DVD��Ϣ�����ͷ��Ϊ����
void Information_member(type_VIP*h_V);//����Ա��ѯ��Ա��Ϣģ�飬�Ի�Ա��Ϣ�����ͷΪ����
void Information_DTrade(type_Trade_DVD *h_TD);//����Ա��ѯ������Ϣģ�飬��DVD������Ϣ�����ͷΪ����
void Information_Vtrade(type_Trade_VIP *h_TV);//����Ա��ѯVIP�ɷ���Ϣģ�飬��VIP������Ϣ��ͷΪ����
void Add_DVD(type_DVD*h_D);//����Ա���DVD,��DVD�����ͷΪ����
//
//
//�������������������
void read_file_VIP(type_VIP*h_V);//���ļ�����Ϣ���������Ա�ͷΪ����
void read_file_DVD(type_DVD*h_D);//���ļ�����Ϣ���������Ա�ͷΪ����
void read_file_Trade_DVD(type_Trade_DVD*h_TD);//���ļ�����Ϣ���������Ա�ͷΪ����
void read_file_Trade_VIP(type_Trade_VIP*h_TV);//���ļ�����Ϣ���������Ա�ͷΪ����
void write_file_VIP(type_VIP*h_V);//��������Ϣ����д���ļ�
void write_file_DVD(type_DVD*h_D);//��������Ϣ����д���ļ�
void write_file_Trade_DVD(type_Trade_DVD*h_TD);//��������Ϣ����д���ļ�
void Delete_VIP(type_VIP*h_V);//ɾ��һ����Ա���Ի�Ա��Ϣ�����ͷΪ����
void Delete_DVD(type_DVD*h_D);//����һ��DVD����DVD��Ϣ�����ͷΪ����
type_VIP *FindTarget_VIP(type_VIP*h_V,int Target_VIP);//�ҵ�ID��Target_VIP������Ԫ��ַ
type_DVD *FindTarget_DVD(type_DVD*h_D,int Target_DVD);//�ҵ������Target�ǵ�����Ԫ��ַ
type_Trade_DVD *FindTarget_DVDinT(type_Trade_DVD*h_TD,int Target_VIP,int Target_DVD);//�ڽ��������ҵ�DVD
#endif //END_CLASS_PROJECT_PRE_DECLARATION_H
