#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*initialize an empty linked list with only the head node without value*/
Status InitList(LinkedList *L)              //L��ͷ�ڵ�ָ���ָ��
{
    *L = (LNode*)malloc(sizeof(LNode));         
    if(*L==NULL)return ERROR;               //ifû�еõ�malloc����ָ��
    (*L)->next=NULL;                        //��տ��ܴ��ڵ�ֵ
    return SUCCESS;
    printf("����ͷ���ɹ���\n");
}

/*destroy a linked list, free all the nodes*/
void DestroyList(LinkedList *L)
{
    LinkedList p,temp;                      //p��temp���ڱ�������
    if(L!=NULL)
    {
        p = (*L)->next;                         
        (*L)->next=NULL;                        //�Ͽ�ͷ�ڵ㣬ͷ�ڵ�û��������
        while (p != NULL)                       //pû��������
        {
            temp=p->next;
            free(p);                            //�ͷ�pָ��ָ��Ľڵ�
            p=temp;
        }
        *L=NULL;
        printf("����ɾ���ɹ���\n");
    }
}

/*insert node q after node p*/
Status InsertList(LNode *p, LNode *q)
{
    if(p==NULL||q==NULL)                    //p/qָ��ָ��NULL
    {
        printf("������ʧ��\n");
        return ERROR;
    }
    if(p->next!=NULL)
    {
        q->next=p->next;
        p->next=q;
    }
    else
    {
        p->next=q;
        q->next=NULL;
    }
    printf("������ɹ���\n");
    return SUCCESS;
}

/*delete the first node after the node p and assign its value to e*/
Status DeleteList(LNode *p, ElemType *e)
{
    LinkedList temp;
    if(p==NULL||e==NULL)
    {
        return ERROR;
    }
    temp=p->next;                        
    *e=temp->data;                       //e�洢p��һ������ֵ
    p->next=temp->next;                  //pָ�����¸����
    free(temp);
    return SUCCESS;
    printf("���ɾ���ɹ���\n");
}

/*traverse the linked list and call the funtion visit*/
void TraverseList(LinkedList L, void (*visit)(ElemType e))      //������һ������ָ�룬�Խ�����ֵ�����ض�����
{
    LinkedList temp;
    printf("��ǰ����Ϊ��");
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

/*find the first node in the linked list according to e*/
Status SearchList(LinkedList L, ElemType e)
{
    LinkedList temp;
    temp=L->next;
    if(temp==NULL)
    {
        printf("����Ϊ��\n");
    }
    while(temp!=NULL)
    {
        if(temp->data==e)
        {
            printf("����ֵΪ%d�Ľ��\n",e);
            return SUCCESS;
        }
        temp=temp->next;
    }
    printf("�Ҳ���ֵΪ%d�Ľ��\n",e);
    return ERROR;
}

/*reverse the linked list*/
Status ReverseList(LinkedList *L)
{   
/**************************�ǵݹ�******************************/
    LinkedList p,temp,q;                       
    p=*L;                                                      //ָ��ͷ���
    q=temp=p->next;                                            //q��tempָ���һ�����
    p=NULL;                                              //�Ͽ�ͷ��㣬δ�����Ͽ������һ����ȷ��
    if(!(*L))                                                  //ֻ��ͷ���
    {                   
        return ERROR;
    }
    while(temp)                                                //
    {                                           
        temp=temp->next;                                       //temp��ǰ��
        q->next=p;                                             //qָ����һ������һ��ʱָ��ͷ���
        p=q;                                                   //pָ��q
        q=temp;                                                //q��ǰ��
    }                                           
    (*L)->next=p;
    return SUCCESS;
}

/*judge whether the linked list is looped*/
Status IsLoopList(LinkedList L)             //����ָ�뷨
{
    LinkedList p,q;
    p=L;
    q=L;
    while(p!=NULL&&q!=NULL&&q->next!=NULL)                 //�ɻ�û�о�ͷ
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
        {
            return SUCCESS;
        }
    }
    return ERROR;                           //�о�ͷ�����ɻ�
}

/*reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3*/
LNode* ReverseEvenList(LinkedList *L)
{    
/***********************��������****************************/                                           
    /*LinkedList p,q;    
    ElemType data;                
    if(!((*L)->next))                                                  //ֻ��ͷ����ֻ��һ�����
    {
        return *L;
    }
    if (!((*L)->next->next))
    {
         return *L;
    }
    p=(*L)->next;                               //һ��һ˫
    q=(*L)->next->next;
    while (q!=NULL&&q->next!=NULL&&p->next!=NULL&&p!=NULL)
    {
       data=p->data;                            //��������
       p->data=q->data;
       q->data=data;
       p=p->next->next;                         //��������
       q=q->next->next;
    }
    return *L;*/
/***********************�������****************************/
    LinkedList p,q,temp;
    temp=(LNode *)malloc(sizeof(LNode));
    int flag=0;
    temp->next=(*L)->next;
    p = *L;                                   //pָ��head���
    while(p->next&&p->next->next)
    {
        q = p->next;                          //qָ�����λ������
        p->next = q->next;                    //�����ǰһ�����ָ��ż���
        q->next = q->next->next;              //�������һ��ָ��ż������һ��
        p->next->next=q;                      //ż���ָ������
        if(!flag)
        {
            temp->next=p->next;                //��¼ͷ���
            flag=1;
        }
        p=q;                                  //pָ����һ����ż��ǰһ��
    }
    free(*L);
    return temp;
}


/*find the middle node in the linked list*/
LNode* FindMidNode(LinkedList *L)           //����ָ�뷨
{
    LinkedList p,q;
    if(!((*L)->next))                                                  //ֻ��ͷ����ֻ��һ�����
    {
        return *L;
    }
    p=(*L)->next;
    q=(*L)->next;
    while(p!=NULL&&p->next!=NULL)
    {
        p=p->next->next;
        q=q->next;
    }
    return q;
}
