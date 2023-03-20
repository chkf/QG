#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printvalue(ElemType e)
{
    printf("%d<->",e);
}

void showcomlist(void)
{
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
    printf("���뷽ʽ:\n");
    printf("\n");
    printf("    1:�ڸý��ǰ����\n");
    printf("    2:�ڸý������\n");
    printf("\n");
}

int main()
{
    int command,newdata,i,j,d,deleteddata;
    bool res;
    DuLinkedList end,head=NULL,newnode;
    showcomlist();
    printf("����ָ����>");
    while (1)
    {
        z:
        res=scanf("%d",&command);
        while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
        {
            system("cls");
            showcomlist();
            printf("����ָ�����\n����ָ����>");
            goto z; 
        }
        switch(command)
        {
            case 1:
                res = InitList_DuL(&head);
                if(res)
                {
                    end=head;
                    system("cls");
                    showcomlist();
                    printf("˫����ͷ��㴴���ɹ�\n");
                    printf("�����ʼ����,��'-1'����>");
                    a:
                    res=scanf("%d",&newdata);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("�������ݴ���\n�����ʼ����,��'-1'����>");
                        goto a;
                    }
                    while (newdata!=-1)
                    {
                        newnode = (DuLNode*)malloc(sizeof(DuLNode));
                        newnode->data=newdata;
                        res = InsertAfterList_DuL(end, newnode);
                        end = newnode;
                        if(res)
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�����ʼ����,��'-1'����>");
                        }
                        else
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�����ʼ����,��'-1'����>");
                        }
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�������ݴ���\n�����ʼ����,��'-1'����>");
                            goto b;
                        }
                    }
                    system("cls");
                    showcomlist();
                    printf("�����ʼ���ɹ�\n");
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("����ָ����>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("������ʧ�ܣ�����ָ��>");
                }
                break;
            case 2:
                if(head==NULL)
                {
                    printf("�������ڣ�����ָ��>");
                }
                else
                {
                    DestroyList_DuL(&head);
                    system("cls");
                    showcomlist();
                    printf("����ɾ���ɹ�������ָ��>");
                }
                break;
            case 3:
                if(head==NULL)
                {
                    printf("�������ڣ�����ָ��>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("\n�������λ��>");
                    reinsert:
                    c:
                    res=scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("�������ݴ���\n�������λ��>");
                        goto c;
                    }
                    newnode = (DuLNode*)malloc(sizeof(DuLNode));
                    end=head;
                    for(i=0;i<j&&end!=NULL&&j>=0;i++)
                    {
                        end=end->next;
                    }
                    if(end==NULL||j<0)
                    {
                        printf("����λ�ô���\n");
                        printf("�����������λ��>");
                        goto reinsert;
                    }
                    else if(j==0)
                    {
                        goto pass;
                    }
                    system("cls");
                    showcomlist1();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("�������λ��>");
                    d:
                    res=scanf("%d",&d);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist1();
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("����λ�ô���\n");
                        printf("�����������λ��>");
                        goto d; 
                    }
                    switch (d)
                    {
                        case 1:
                            printf("\n�����������>");
                            e:
                            res=scanf("%d",&newnode->data);
                            while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                            {
                                system("cls");
                                showcomlist();
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("�������ݴ���\n�������λ��>");
                                goto e;
                            }
                            res = InsertBeforeList_DuL(end, newnode);
                            if(res)
                            {
                                system("cls");
                                showcomlist();
                                printf("�������ɹ�");
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("����ָ����>");
                            }
                            else
                            {
                                system("cls");
                                showcomlist();
                                printf("�������ʧ�ܣ�δ֪����");
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("����ָ����>");
                            }
                            break;
                        case 2:
                            pass:
                            printf("\n�����������>");
                            f:
                            res=scanf("%d",&newnode->data);
                            while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                            {
                                system("cls");
                                showcomlist();
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("�������ݴ���\n�������λ��>");
                                goto f;
                            }
                            res = InsertAfterList_DuL(end, newnode);
                            if(res)
                            {
                                system("cls");
                                showcomlist();
                                printf("�������ɹ�");
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("����ָ����>");
                            }
                            else
                            {
                                system("cls");
                                showcomlist();
                                printf("�������ʧ�ܣ�δ֪����");
                                printf("��ǰ����Ϊ��");
                                TraverseList_DuL(head, printvalue);
                                printf("����ָ����>");
                            }
                            break;
                        default:
                            system("cls");
                            showcomlist1();
                            printf("��ǰ����Ϊ��");
                            TraverseList_DuL(head, printvalue);
                            printf("�������ݴ���\n�����������λ��>");
                            goto d;
                            break;
                    }
                }
                break;
            case 4:
                if(head==NULL)
                {
                    printf("�������ڣ�����ָ��>");
                }
                else if(head->next==NULL)
                {
                    printf("����Ϊ�գ�����ָ��>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("\n����ɾ�����>");
                    redelete:
                    g:
                    res = scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("�������ݴ���\n����ɾ�����>");
                        goto g;
                    }
                    if(j==0)
                    {
                        printf("�޷�ɾ��ͷ���\n");
                        printf("��������ɾ�����>");
                        goto redelete;
                    }
                    end=head;
                    for(i=0;i<j-1&&end->next!=NULL&&j>=0;i++)
                    {
                        end=end->next;
                    }
                    if(end==NULL||end->next==NULL||j<0)
                    {
                        printf("ɾ��λ�ô���\n");
                        printf("��������ɾ�����>");
                        goto redelete;
                    }
                    res = DeleteList_DuL(end,&deleteddata);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("���ɾ���ɹ�����ɾ����������Ϊ%d\n",deleteddata);
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("����ָ����>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("���ɾ��ʧ�ܣ�ɾ��λ�ÿ��ܲ�����");
                        printf("��ǰ����Ϊ��");
                        TraverseList_DuL(head, printvalue);
                        printf("����ָ����>");
                    }
                }
                break;
            case 5:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("�������ڣ�����ָ��>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("����Ϊ�գ�����ָ��>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList_DuL(head, printvalue);
                    printf("����ָ����>");
                }
                break;
            default:
                system("cls");
                showcomlist();
                printf("����Ĳ���ָ�����������>");
                break;
        }
    }
    return 0;
}