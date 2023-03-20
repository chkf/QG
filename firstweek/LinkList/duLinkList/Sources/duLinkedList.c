#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*initialize an empty linked list with only the head node*/
Status InitList_DuL(DuLinkedList *L)
{
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    if(*L==NULL)return ERROR;               //ifû�еõ�malloc����ָ��
    (*L)->next=NULL;                          //ָ���Լ�
    (*L)->prior=NULL;
    return SUCCESS;
    printf("����ͷ���ɹ���\n");
}

/*destroy a linked list*/
void DestroyList_DuL(DuLinkedList *L)
{
    DuLinkedList temp;                          //temp�洢�¸����ָ��
    while (*L != NULL)                          //û��������
    {
        temp=(*L)->next;                        
        free(*L);                               //�ͷ�Lָ��Ľ��
        *L=temp;                                //*Lָ����һ�����
    }
    printf("����ɾ���ɹ���\n");
}

/*insert node q before node p*/
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    if(p==NULL)                        //pָ��ָ��NULL
    {
        printf("������ʧ��\n");
        return ERROR;           
    }
    if(p->prior!=NULL)
    {
        q->prior=p->prior;                          //qǰ��ָ��ָ��pǰ�����
        p->prior->next=q;                           //p��ǰ���ָ��q
    }
    q->next=p;                                  //q�ĺ���ָ��ָ��p
    p->prior=q;                                 //p��ǰ��ָ��ָ��q
    printf("������ɹ���\n");
    return SUCCESS;
}

/*insert node q after node p*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    if(p==NULL)                        //pָ��ָ��NULL
    {
        printf("������ʧ��\n");
        return ERROR;           
    }
    if(p->next!=NULL)
    {
        q->next=p->next;                           //qǰ��ָ��ָ��pǰ
        p->next->prior=q;                                 //p��ǰ�����ָ��q
    }
    else
    {
        q->next=NULL;
    }
    q->prior=p;                                //q�ĺ������ָ��p
    p->next=q;                                 //p��ǰ��ָ��ָ��q
    printf("������ɹ���\n");
    return SUCCESS;
}

/*delete the first node after the node p and assign its value to e*/
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
    DuLinkedList temp;
    if(!p)
    {
        printf("�ý�㲻����\n");
        return ERROR;
    }
    temp=p->next;                        
    *e=temp->data;                       //e�洢p��һ������ֵ
    p->next=temp->next;                  //pָ�����¸����
    if(temp->next)
    {
        temp->next->prior=p;             //�����ǰ��ָ��ָ��ý��
    }
    free(temp);
    return SUCCESS;
}

/*traverse the linked list and call the funtion visit*/
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    DuLinkedList temp;
    temp=L->next;
    if(temp==NULL)
    {
        printf("��");
    }
    while(temp!=NULL)
    {
        visit(temp->data);
        temp=temp->next;
    }
    printf("\n");
}