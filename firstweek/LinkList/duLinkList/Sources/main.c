#include "dumain.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

DuLinkedList head;

int main()
{
    int command,newdata,i,j,d,deleteddata;
    bool res,mark;
    DuLinkedList end,newnode;
    showcomlist();
    printf("����ָ����>");
    while (1)
    {
        my_scanf(&command,"����Ĳ���ָ�����������>",false,0);
        switch(command)
        {
            case 1:
                res = InitList_DuL(&head);
                if(res)
                {
                    end=head;
                    showcomlist();
                    printf("˫����ͷ��㴴���ɹ�\n");
                    printf("�����ʼ����,��'-1'����>");
                    my_scanf(&newdata,"���������ʼ����,��'-1'����>",true,0);
                    while (newdata!=-1)
                    {
                        newnode = (DuLNode*)malloc(sizeof(DuLNode));
                        newnode->data=newdata;
                        res = InsertAfterList_DuL(end, newnode);
                        end = newnode;
                        res_react(res,"�����ʼ����,��'-1'����>");
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�������ݴ���\n�����ʼ����,��'-1'����>");
                            my_scanf(&newdata,"���������ʼ����,��'-1'����>",true,0);
                        }
                    }
                    showcomlist();
                    printf("�����ʼ���ɹ�\n");
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("����ָ����>");
                }
                else
                {
                    showcomlist();
                    printf("������ʧ�ܣ�����ָ��>");
                }
                break;
            case 2:
                if(!headcheck(false));
                else
                {
                    DestroyList_DuL(&head);
                    showcomlist();
                    printf("����ɾ���ɹ�������ָ��>");
                }
                break;
            case 3:
                if(!headcheck(false));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("\n�������λ��>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"�����������λ��>",true,0);
                        end=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("����λ�ô���\n");
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�����������λ��>");
                        }
                        else mark=true; 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            end=end->next;
                            if(end==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("����λ�ô���\n�����������λ��>");
                                break;
                            }
                        }
                    }
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    if(j!=0&&head->next!=NULL)
                    {
                        showcomlist1();
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("�������λ��>");
                    }
                    while(d!=1&&d!=2)
                    {
                        if(j!=0&&head->next!=NULL)                //0��㴦ֻ�ܺ��
                            my_scanf(&d,"�����������λ��>",true,1);      
                        else
                            d=2;
                        switch (d)
                        {
                            case 1:
                                printf("\n�����������>");
                                my_scanf(&newdata,"���������������>",true,1);
                                newnode = (DuLNode*)malloc(sizeof(DuLNode));
                                newnode->data=newdata;
                                res = InsertBeforeList_DuL(end, newnode);
                                res_react(res,"����ָ����>");
                                break;
                            case 2:
                                printf("\n�����������>");
                                my_scanf(&newdata,"���������������>",true,1);
                                newnode = (DuLNode*)malloc(sizeof(DuLNode));
                                newnode->data=newdata;
                                res = InsertAfterList_DuL(end, newnode);
                                res_react(res,"����ָ����>");
                                break;
                            default:
                                showcomlist1();
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("�������ݴ���\n�����������λ��>");
                                break;
                        }    
                    }
                }
                break;
            case 4:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("\n����ɾ�����>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"��������ɾ�����>",true,0);
                        j--;
                        end=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("ɾ��������\n");
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("��������ɾ�����>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            end=end->next;
                            if(end->next==NULL||end==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("ɾ��������\n");
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("��������ɾ�����>");
                                break;
                            }
                        }
                    }
                    res = DeleteList_DuL(end,&deleteddata);
                    res_react(res,NULL);
                    if(res)
                        printf("��ɾ����������Ϊ%d\n",deleteddata);
                    printf("����ָ����>");    
                }
                break;
            case 5:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("����ָ����>");
                }
                break;
            default:
                showcomlist();
                printf("����Ĳ���ָ�����������>");
                break;
        }
    }
    return 0;
}


void printvalue(ElemType e)
{
    printf("<-%d->",e);
}

void showcomlist(void)
{
    system("cls");
    printf("˫�������ָ��:\n");
    printf("\n");
    printf("    1:�½�������\n");
    printf("    2:ɾ������\n");
    printf("    3:����һ�����\n");
    printf("    4:ɾ��һ�����\n");
    printf("    5:������ȡ����\n");
    printf("\n");
}

void showcomlist1(void)
{
    system("cls");
    printf("���뷽ʽ:\n");
    printf("\n");
    printf("    1:�ڸý��ǰ����\n");
    printf("    2:�ڸý������\n");
    printf("\n");
}

/*Ӧ�Բ�ͬ�������ز�ͬ��statusֵ*/
void res_react(bool res,char * str)                     //����ɹ����Ҫ˵�Ļ�
{
    if(res)
    {
        showcomlist();
        printf("�����ɹ�");
        printf("��ǰ����Ϊ��");
        TraverseList_DuL(head, printvalue);
        if(str)printf(str);
    }
    else
    {
        showcomlist();
        printf("�����ˣ���\n");
        printf("��ǰ����Ϊ��");
        TraverseList_DuL(head, printvalue);
        if(str)printf(str);
    }
}

/*��ʾ�������*/
Status error_reshow(char * str,bool showlist,int menu)                          //�������ݴ���ʱ����������ʾ
{
    if(!menu)showcomlist();
    else showcomlist1();
    if(showlist)TraverseList_DuL(head, printvalue);
    printf("�������ݴ���\n");
    printf(str);
}

/*��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�*/
void my_scanf(ElemType * i,char * error_warn,bool showlist,int menu)                 //�������
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //û�յ�'\n'�Ϳ���
        if(!res)error_reshow(error_warn,showlist,menu);
    }
}

/*���ͷ����Ƿ���ڣ�Ҳ�ɼ���һ������Ƿ����*/
Status headcheck(bool checkfirst)
{
    if(head==NULL)
    {
        showcomlist();
        printf("�������ڣ�����ָ��>");
        return ERROR;
    }
    if(checkfirst)
    {
        if(head->next==NULL)
        {
            showcomlist();
            printf("����Ϊ�գ�����ָ��>");
            return ERROR;
        }
    }
    return SUCCESS;
}