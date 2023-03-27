#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

LQueue *Q;

void showcmdlist(void)
{
    system("cls");
    printf("��ʽ���в���ָ��:\n");
    printf("\n");
    printf("    1:��ʽ���г�ʼ��\n");
    printf("    2:ɾ����ʽ����\n");
    printf("    3:�ж϶����Ƿ�Ϊ��\n");
    printf("    4:�鿴��ͷԪ��\n");
    printf("    5:ȷ�����г���\n");
    printf("    6:��Ӳ���\n");
    printf("    7:���Ӳ���\n");
    printf("    8:��ն���\n");
    printf("    9:������������\n");
    printf("\n");
}

void error_reshow(char * str)                          //�������ݴ���ʱ����������ʾ
{
    int topdata;
    bool res;
    showcmdlist();
    printf(str);
}

/*��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�*/
void my_scanf_double(double* i,char * error_warn)
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%lf",i);
        while(getchar()!='\n');                             //û�յ�'\n'�Ϳ���
        if(!res)error_reshow(error_warn);
    }
}

/*��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�*/
void my_scanf_int(int* i,char * error_warn)
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //û�յ�'\n'�Ϳ���
        if(!res)error_reshow(error_warn);
    }
}

int main()
{
    int command,length,e,*data;
    bool res;
    showcmdlist();
    printf("����ָ����>");
    while (1)
    {
        my_scanf_int(&command,"�����ָ���������������>");
        switch(command)
        {
            case 1:
                Q = InitLQueue(Q);
                if(Q!=NULL)printf("��ʽ���г�ʼ���ɹ�\n");
                printf("����ָ����>");
                break;
            case 2:
                if(Q!=NULL)
                {
                    showcmdlist();
                    DestoryLQueue(Q);
                    Q=NULL;
                    if(Q==NULL)printf("��ʽ����ɾ���ɹ�\n");
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                break;
            case 3:
                if(Q!=NULL)
                {
                    res = IsEmptyLQueue(Q);
                    if(res)printf("��ʽ����Ϊ��\n");
                    else printf("��ʽ���зǿ�\n");
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                break;
            case 4:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    GetHeadLQueue(Q,&e);
                    printf("����Ԫ��Ϊ��");
                    printf("%d",e);
                    printf("����ָ����>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("����Ϊ��\n");
                    printf("����ָ����>");
                }
                break;
            case 5:
                if(Q!=NULL)
                {
                    showcmdlist();
                    length = LengthLQueue(Q);
                    printf("���г���Ϊ%d\n",length);
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                break;
            case 6:
                if(Q!=NULL)
                {
                    //system("cls");
                    printf("��������(�ݲ�֧��):\n");
                    printf("    1.int\n");
                    printf("    2.int\n");
                    printf("    3.int\n");
                    printf("������Ҫ��ӵ��������ͱ��>");
                    /*res=0;
                    while(!res)
                    {
                        my_scanf_int(&command,"�����ָ���������������>");
                        switch(command)
                        {
                            case 1:*/
                                data = (int*)malloc(sizeof(int));
                                printf("�����������>");
                                my_scanf_int(data,"��������ݴ�������������>");
                                /*res=1;
                                break;
                            case 2:
                                data = (double*)malloc(sizeof(double));
                                printf("�����������>");
                                my_scanf_double(data,"��������ݴ�������������>");
                                res=1;
                                break;
                            case 3:
                                data = (char*)malloc(sizeof(char));
                                printf("�����������>");
                                scanf("%c",data);
                                res=1;
                                break;
                            default:
                                printf("��������ݴ�������������>");
                                break;
                        }
                    }*/
                    EnLQueue(Q,data);
                    showcmdlist();
                    printf("��ӳɹ�\n");
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                break;
            case 7:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    DeLQueue(Q);
                    length = LengthLQueue(Q);
                    printf("������ɣ����г���Ϊ%d\n",length);
                    printf("����ָ����>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("����Ϊ��\n");
                    printf("����ָ����>");
                }
                break;
            case 8:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    ClearLQueue(Q);
                    printf("�������\n");
                    printf("����ָ����>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("����Ϊ��\n");
                    printf("����ָ����>");
                }
                break;
            case 9:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    TraverseLQueue(Q, LPrint);
                    printf("����ָ����>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("���в�����\n");
                    printf("����ָ����>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("����Ϊ��\n");
                    printf("����ָ����>");
                }
                break;
            default:
                showcmdlist();
                printf("�����ָ���������������>");
                break;
        }
    }
}