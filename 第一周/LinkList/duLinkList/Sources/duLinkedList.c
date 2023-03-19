#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*initialize an empty linked list with only the head node*/
Status InitList_DuL(DuLinkedList *L)
{
    *L = (DuLNode*)malloc(sizeof(DuLNode));
    if(*L==NULL)return ERROR;               //if没有得到malloc给的指针
    (*L)->next=NULL;                          //指向自己
    (*L)->prior=NULL;
    return SUCCESS;
    printf("链表头结点成功！\n");
}

/*destroy a linked list*/
void DestroyList_DuL(DuLinkedList *L)
{
    DuLinkedList temp;                          //temp存储下个结点指针
    while (*L != NULL)                          //没走完链表
    {
        temp=(*L)->next;                        
        free(*L);                               //释放L指向的结点
        *L=temp;                                //*L指向下一个结点
    }
    printf("链表删除成功！\n");
}

/*insert node q before node p*/
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    if(p==NULL)                        //p指针指向NULL
    {
        printf("结点插入失败\n");
        return ERROR;           
    }
    if(p->prior!=NULL)
    {
        q->prior=p->prior;                          //q前趋指针指向p前趋结点
        p->prior->next=q;                           //p的前结点指向q
    }
    q->next=p;                                  //q的后趋指针指向p
    p->prior=q;                                 //p的前趋指针指向q
    printf("结点插入成功！\n");
    return SUCCESS;
}

/*insert node q after node p*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    if(p==NULL)                        //p指针指向NULL
    {
        printf("结点插入失败\n");
        return ERROR;           
    }
    if(p->next!=NULL)
    {
        q->next=p->next;                           //q前趋指针指向p前
        p->next->prior=q;                                 //p的前趋结点指向q
    }
    else
    {
        q->next=NULL;
    }
    q->prior=p;                                //q的后趋结点指向p
    p->next=q;                                 //p的前趋指针指向q
    printf("结点插入成功！\n");
    return SUCCESS;
}

/*delete the first node after the node p and assign its value to e*/
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
    DuLinkedList temp;
    if(!p)
    {
        printf("该结点不存在\n");
        return ERROR;
    }
    temp=p->next;                        
    *e=temp->data;                       //e存储p下一个结点的值
    p->next=temp->next;                  //p指向下下个结点
    if(temp->next)
    {
        temp->next->prior=p;             //后结点的前趋指针指向该结点
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
        printf("空");
    }
    while(temp!=NULL)
    {
        visit(temp->data);
        temp=temp->next;
    }
    printf("\n");
}