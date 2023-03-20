#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ReverseList_use_algo  1

void printvalue(ElemType e)
{
    printf("%d->",e);
}

Status ReverseList_algo(LinkedList *L,LinkedList q)     //��ͷ��㴫�ݵ����
{
/***************************�ݹ�*******************************/
    if(!q)                                                //ֻ��ͷ���
    {                   
        return ERROR;
    }
    if(q->next==NULL)
    {
        (*L)->next=q;                                    //�ҵ����һ������ͷ���ָ����
        return SUCCESS;
    }
    ReverseList_algo(L,(q->next));
    if(q!=(*L))
    {
        q->next->next=q;                                //��һ���ڵ�ָ��ǰһ����ǰһ�����ָ��NULL
        q->next=NULL;
    }
}

void showcomlist(void)
{
    printf("���������ָ��:\n");
    printf("\n");
    printf("    1:�½�������\n");
    printf("    2:ɾ������\n");
    printf("    3:����һ�����\n");
    printf("    4:ɾ��һ�����\n");
    printf("    5:������ȡ����\n");
    printf("    6:���ҽ��\n");
    printf("    7:��ת����\n");
    printf("    8:�ж��Ƿ�Ϊѭ������\n");
    printf("    9:������ż����\n");
    printf("    10:���м���\n");
    printf("\n");
}

int main()
{
    int command,j,i,newdata,deleteddata;
    bool res;
    LinkedList head=NULL,p,q,end,MidNode;
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
        switch (command)
        {
            case 1:
                res = InitList(&head);
                if(res)
                {
                    end=head;                                           //��ָ��ͷ���
                    system("cls");
                    showcomlist();
                    printf("����ͷ��㴴���ɹ�\n");
                    printf("�����ʼ����,��'-1'����>");
                    a:
                    res=scanf("%d",&newdata);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�������ݴ���\n�����ʼ����,��'-1'����>");
                        goto a;
                    }
                    while(newdata!=-1)
                    {   
                        q = (LNode*)malloc(sizeof(LNode));
                        q->data = newdata;                                    //��������
                        res = InsertList(end, q);                                      
                        end=q;                                          //βָ��ָ���½��              
                        if(res)
                        {   
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList(head, printvalue);
                            printf("�����ʼ����,��'-1'����>");
                        }
                        else
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList(head, printvalue);
                            printf("�����ʼ����,��'-1'����>");
                        }
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                        {
                            system("cls");
                            showcomlist();
                            printf("��ǰ����Ϊ��");
                            TraverseList(head, printvalue);
                            printf("�������ݴ���\n�����ʼ����,��'-1'����>");
                            goto b;
                        }
                    }
                    system("cls");
                    showcomlist();
                    printf("�����ʼ���ɹ�\n");
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
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
                    system("cls");
                    showcomlist();
                    printf("�������ڣ�����ָ��>");
                }
                else
                {
                    DestroyList(&head);
                    system("cls");
                    showcomlist();
                    printf("����ɾ���ɹ�������ָ��>");
                }
                break;
            case 3:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("�������ڣ�����ָ��>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("\n�������λ��>");
                    reinsert:
                    c:
                    res=scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�������ݴ���\n�������λ��>");
                        goto c;
                    }
                    q = (LNode*)malloc(sizeof(LNode));
                    p=head;
                    for(i=0;i<j&&p!=NULL&&j>=0;i++)
                    {
                        p=p->next;
                    }
                    if(p==NULL||j<0)
                    {
                        printf("����λ�ô���\n");
                        printf("�����������λ��>");
                        goto reinsert;
                    }
                    printf("\n�����������>");
                    d:
                    res=scanf("%d",&q->data);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�������ݴ���\n�������λ��>");
                        goto d;
                    }
                    res = InsertList(p, q);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("�������ɹ�");
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("����ָ����>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("�������ʧ�ܣ�δ֪����");
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("����ָ����>");
                    }
                }
                break;
            case 4:
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
                    TraverseList(head, printvalue);
                    printf("\n����ɾ�����>");
                    redelete:
                    e:
                    res = scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�������ݴ���\n����ɾ�����>");
                        goto e;
                    }
                    if(j==0)
                    {
                        printf("�޷�ɾ��ͷ���\n");
                        printf("��������ɾ�����>");
                        goto redelete;
                    }
                    p=head;
                    for(i=0;i<j-1&&p!=NULL&&j>=0;i++)
                    {
                        p=p->next;
                    }
                    if(p==NULL||j<0)
                    {
                        printf("ɾ��λ�ô���\n");
                        printf("��������ɾ��λ��>");
                        goto redelete;
                    }
                    res = DeleteList(p,&deleteddata);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("���ɾ���ɹ�����ɾ����������Ϊ%d\n",deleteddata);
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("����ָ����>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("���ɾ��ʧ�ܣ�ɾ��λ�ÿ��ܲ�����");
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
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
                    TraverseList(head, printvalue);
                    printf("����ָ����>");
                }
                break;
            case 6:
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
                        printf("Ҫ���ҵ�����Ϊ>");
                        f:
                        res=scanf("%d",&j);
                        while(getchar()!='\n'||!res)                                         //�̵��ַ�����ֹ�ܷ�
                        {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�������ݴ���\n����Ҫ���ҵ�����>");
                        goto f;
                        }
                        SearchList(head, j);
                        printf("����ָ����>");
                    }
                break;
            case 7:
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
                    TraverseList(head, printvalue);
                    #if ReverseList_use_algo 
                        ReverseList_algo(&head,head);
                    #else
                        ReverseList(&head);
                    #endif
                    printf("��ת��,");
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("����ָ��>");
                }
                break;
            case 8:
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
                    res = IsLoopList(head);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("����ɻ�\n");
                        printf("����ָ��>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("�����ɻ�\n");
                        printf("����ָ��>");
                    }
                }
                break;
            case 9:
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
                    TraverseList(head, printvalue);
                    printf("��ż������,");
                    head = ReverseEvenList(&head);
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("����ָ��>");
                }
                break;
            case 10:
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
                    if((head->next))
                    {
                        system("cls");
                        showcomlist();
                        printf("��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("�м�ڵ�Ϊ:");
                        MidNode = FindMidNode(&head);
                        printvalue(MidNode->data);
                        printf("����ָ��>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("����Ϊ�գ�����ָ��>");
                    }
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