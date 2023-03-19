#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*initialize an empty linked list with only the head node without value*/
Status InitList(LinkedList *L)              //L是头节点指针的指针
{
    *L = (LNode*)malloc(sizeof(LNode));         
    if(*L==NULL)return ERROR;               //if没有得到malloc给的指针
    (*L)->next=NULL;                        //清空可能存在的值
    return SUCCESS;
    printf("链表头结点成功！\n");
}

/*destroy a linked list, free all the nodes*/
void DestroyList(LinkedList *L)
{
    LinkedList p,temp;                      //p，temp用于遍历链表
    if(L!=NULL)
    {
        p = (*L)->next;                         
        (*L)->next=NULL;                        //断开头节点，头节点没有数据项
        while (p != NULL)                       //p没走完链表
        {
            temp=p->next;
            free(p);                            //释放p指针指向的节点
            p=temp;
        }
        *L=NULL;
        printf("链表删除成功！\n");
    }
}

/*insert node q after node p*/
Status InsertList(LNode *p, LNode *q)
{
    if(p==NULL||q==NULL)                    //p/q指针指向NULL
    {
        printf("结点插入失败\n");
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
    printf("结点插入成功！\n");
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
    *e=temp->data;                       //e存储p下一个结点的值
    p->next=temp->next;                  //p指向下下个结点
    free(temp);
    return SUCCESS;
    printf("结点删除成功！\n");
}

/*traverse the linked list and call the funtion visit*/
void TraverseList(LinkedList L, void (*visit)(ElemType e))      //可填入一个函数指针，对结点的数值进行特定计算
{
    LinkedList temp;
    printf("当前链表为：");
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

/*find the first node in the linked list according to e*/
Status SearchList(LinkedList L, ElemType e)
{
    LinkedList temp;
    temp=L->next;
    if(temp==NULL)
    {
        printf("链表为空\n");
    }
    while(temp!=NULL)
    {
        if(temp->data==e)
        {
            printf("存在值为%d的结点\n",e);
            return SUCCESS;
        }
        temp=temp->next;
    }
    printf("找不到值为%d的结点\n",e);
    return ERROR;
}

/*reverse the linked list*/
Status ReverseList(LinkedList *L)
{   
/**************************非递归******************************/
    LinkedList p,temp,q;                       
    p=*L;                                                      //指向头结点
    q=temp=p->next;                                            //q，temp指向第一个结点
    p=NULL;                                              //断开头结点，未真正断开，最后一步才确认
    if(!(*L))                                                  //只有头结点
    {                   
        return ERROR;
    }
    while(temp)                                                //
    {                                           
        temp=temp->next;                                       //temp向前移
        q->next=p;                                             //q指向上一个，第一次时指向头结点
        p=q;                                                   //p指向q
        q=temp;                                                //q向前移
    }                                           
    (*L)->next=p;
    return SUCCESS;
}

/*judge whether the linked list is looped*/
Status IsLoopList(LinkedList L)             //快慢指针法
{
    LinkedList p,q;
    p=L;
    q=L;
    while(p!=NULL&&q!=NULL&&q->next!=NULL)                 //成环没有尽头
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
        {
            return SUCCESS;
        }
    }
    return ERROR;                           //有尽头，不成环
}

/*reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3*/
LNode* ReverseEvenList(LinkedList *L)
{    
/***********************交换数据****************************/                                           
    /*LinkedList p,q;    
    ElemType data;                
    if(!((*L)->next))                                                  //只有头结点或只有一个结点
    {
        return *L;
    }
    if (!((*L)->next->next))
    {
         return *L;
    }
    p=(*L)->next;                               //一单一双
    q=(*L)->next->next;
    while (q!=NULL&&q->next!=NULL&&p->next!=NULL&&p!=NULL)
    {
       data=p->data;                            //交换数据
       p->data=q->data;
       q->data=data;
       p=p->next->next;                         //各走两步
       q=q->next->next;
    }
    return *L;*/
/***********************交换结点****************************/
    LinkedList p,q,temp;
    temp=(LNode *)malloc(sizeof(LNode));
    int flag=0;
    temp->next=(*L)->next;
    p = *L;                                   //p指向head结点
    while(p->next&&p->next->next)
    {
        q = p->next;                          //q指向待换位的奇结点
        p->next = q->next;                    //奇结点的前一个结点指向偶结点
        q->next = q->next->next;              //奇结点的下一个指向偶结点的下一个
        p->next->next=q;                      //偶结点指向奇结点
        if(!flag)
        {
            temp->next=p->next;                //记录头结点
            flag=1;
        }
        p=q;                                  //p指向下一组奇偶的前一项
    }
    free(*L);
    return temp;
}


/*find the middle node in the linked list*/
LNode* FindMidNode(LinkedList *L)           //快慢指针法
{
    LinkedList p,q;
    if(!((*L)->next))                                                  //只有头结点或只有一个结点
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
