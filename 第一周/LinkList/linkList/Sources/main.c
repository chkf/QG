#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ReverseList_use_algo  1

void printvalue(ElemType e)
{
    printf("%d->",e);
}

Status ReverseList_algo(LinkedList *L,LinkedList q)     //把头结点传递到最后
{
/***************************递归*******************************/
    if(!q)                                                //只有头结点
    {                   
        return ERROR;
    }
    if(q->next==NULL)
    {
        (*L)->next=q;                                    //找到最后一个结点后，头结点指向它
        return SUCCESS;
    }
    ReverseList_algo(L,(q->next));
    if(q!=(*L))
    {
        q->next->next=q;                                //后一个节点指向前一个，前一个结点指向NULL
        q->next=NULL;
    }
}

void showcomlist(void)
{
    printf("单链表操作指令:\n");
    printf("\n");
    printf("    1:新建空链表\n");
    printf("    2:删除链表\n");
    printf("    3:插入一个结点\n");
    printf("    4:删除一个结点\n");
    printf("    5:遍历读取链表\n");
    printf("    6:查找结点\n");
    printf("    7:倒转链表\n");
    printf("    8:判断是否为循环链表\n");
    printf("    9:链表奇偶调换\n");
    printf("    10:找中间结点\n");
    printf("\n");
}

int main()
{
    int command,j,i,newdata,deleteddata;
    bool res;
    LinkedList head=NULL,p,q,end,MidNode;
    showcomlist();
    printf("输入指令编号>");
    while (1)
    {   
        z:
        res=scanf("%d",&command);
        while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
        {
            system("cls");
            showcomlist();
            printf("输入指令错误\n输入指令编号>");
            goto z; 
        }
        switch (command)
        {
            case 1:
                res = InitList(&head);
                if(res)
                {
                    end=head;                                           //先指向头结点
                    system("cls");
                    showcomlist();
                    printf("链表头结点创建成功\n");
                    printf("输入初始数据,以'-1'结束>");
                    a:
                    res=scanf("%d",&newdata);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入数据错误\n输入初始数据,以'-1'结束>");
                        goto a;
                    }
                    while(newdata!=-1)
                    {   
                        q = (LNode*)malloc(sizeof(LNode));
                        q->data = newdata;                                    //存入数据
                        res = InsertList(end, q);                                      
                        end=q;                                          //尾指针指向新结点              
                        if(res)
                        {   
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList(head, printvalue);
                            printf("输入初始数据,以'-1'结束>");
                        }
                        else
                        {
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList(head, printvalue);
                            printf("输入初始数据,以'-1'结束>");
                        }
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                        {
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList(head, printvalue);
                            printf("输入数据错误\n输入初始数据,以'-1'结束>");
                            goto b;
                        }
                    }
                    system("cls");
                    showcomlist();
                    printf("链表初始化成功\n");
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("输入指令编号>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("链表创建失败，输入指令>");
                }
                break;
            case 2:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else
                {
                    DestroyList(&head);
                    system("cls");
                    showcomlist();
                    printf("链表删除成功，输入指令>");
                }
                break;
            case 3:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("\n输入插入位置>");
                    reinsert:
                    c:
                    res=scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入数据错误\n输入插入位置>");
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
                        printf("插入位置错误\n");
                        printf("重新输入插入位置>");
                        goto reinsert;
                    }
                    printf("\n输入插入数据>");
                    d:
                    res=scanf("%d",&q->data);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入数据错误\n输入插入位置>");
                        goto d;
                    }
                    res = InsertList(p, q);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("链表插入成功");
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入指令编号>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("链表插入失败，未知错误");
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入指令编号>");
                    }
                }
                break;
            case 4:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("\n输入删除结点>");
                    redelete:
                    e:
                    res = scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入数据错误\n输入删除结点>");
                        goto e;
                    }
                    if(j==0)
                    {
                        printf("无法删除头结点\n");
                        printf("重新输入删除结点>");
                        goto redelete;
                    }
                    p=head;
                    for(i=0;i<j-1&&p!=NULL&&j>=0;i++)
                    {
                        p=p->next;
                    }
                    if(p==NULL||j<0)
                    {
                        printf("删除位置错误\n");
                        printf("重新输入删除位置>");
                        goto redelete;
                    }
                    res = DeleteList(p,&deleteddata);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("结点删除成功，被删除结点的数据为%d\n",deleteddata);
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入指令编号>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("结点删除失败，删除位置可能不存在");
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入指令编号>");
                    }
                }
                break;
            case 5:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("输入指令编号>");
                }
                break;
            case 6:
                if(head==NULL)
                    {
                        system("cls");
                        showcomlist();
                        printf("链表不存在，输入指令>");
                    }
                    else if(head->next==NULL)
                    {
                        system("cls");
                        showcomlist();
                        printf("链表为空，输入指令>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("要查找的数据为>");
                        f:
                        res=scanf("%d",&j);
                        while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                        {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入数据错误\n输入要查找的数据>");
                        goto f;
                        }
                        SearchList(head, j);
                        printf("输入指令编号>");
                    }
                break;
            case 7:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    #if ReverseList_use_algo 
                        ReverseList_algo(&head,head);
                    #else
                        ReverseList(&head);
                    #endif
                    printf("调转后,");
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("输入指令>");
                }
                break;
            case 8:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    res = IsLoopList(head);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("链表成环\n");
                        printf("输入指令>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("链表不成环\n");
                        printf("输入指令>");
                    }
                }
                break;
            case 9:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("奇偶调换后,");
                    head = ReverseEvenList(&head);
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("输入指令>");
                }
                break;
            case 10:
                if(head==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    system("cls");
                    showcomlist();
                    printf("链表为空，输入指令>");
                }
                else
                {
                    if((head->next))
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList(head, printvalue);
                        printf("中间节点为:");
                        MidNode = FindMidNode(&head);
                        printvalue(MidNode->data);
                        printf("输入指令>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("链表为空，输入指令>");
                    }
                }
                break;
            default:
                system("cls");
                showcomlist();
                printf("输入的不是指令，请重新输入>");
                break;
        }
    }
    return 0;
}