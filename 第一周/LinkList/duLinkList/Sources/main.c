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
    printf("双链表操作指令:\n");
    printf("\n");
    printf("    1:新建空链表\n");
    printf("    2:删除链表\n");
    printf("    3:插入一个结点\n");
    printf("    4:删除一个结点\n");
    printf("    5:遍历读取链表\n");
    printf("\n");
}

void showcomlist1(void)
{
    printf("插入方式:\n");
    printf("\n");
    printf("    1:在该结点前插入\n");
    printf("    2:在该结点后插入\n");
    printf("\n");
}

int main()
{
    int command,newdata,i,j,d,deleteddata;
    bool res;
    DuLinkedList end,head=NULL,newnode;
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
        switch(command)
        {
            case 1:
                res = InitList_DuL(&head);
                if(res)
                {
                    end=head;
                    system("cls");
                    showcomlist();
                    printf("双链表头结点创建成功\n");
                    printf("输入初始数据,以'-1'结束>");
                    a:
                    res=scanf("%d",&newdata);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("输入数据错误\n输入初始数据,以'-1'结束>");
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
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("输入初始数据,以'-1'结束>");
                        }
                        else
                        {
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("输入初始数据,以'-1'结束>");
                        }
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                        {
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("输入数据错误\n输入初始数据,以'-1'结束>");
                            goto b;
                        }
                    }
                    system("cls");
                    showcomlist();
                    printf("链表初始化成功\n");
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
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
                    printf("链表不存在，输入指令>");
                }
                else
                {
                    DestroyList_DuL(&head);
                    system("cls");
                    showcomlist();
                    printf("链表删除成功，输入指令>");
                }
                break;
            case 3:
                if(head==NULL)
                {
                    printf("链表不存在，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("\n输入插入位置>");
                    reinsert:
                    c:
                    res=scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("输入数据错误\n输入插入位置>");
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
                        printf("插入位置错误\n");
                        printf("重新输入插入位置>");
                        goto reinsert;
                    }
                    else if(j==0)
                    {
                        goto pass;
                    }
                    system("cls");
                    showcomlist1();
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("输入插入位置>");
                    d:
                    res=scanf("%d",&d);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist1();
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("插入位置错误\n");
                        printf("重新输入插入位置>");
                        goto d; 
                    }
                    switch (d)
                    {
                        case 1:
                            printf("\n输入插入数据>");
                            e:
                            res=scanf("%d",&newnode->data);
                            while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                            {
                                system("cls");
                                showcomlist();
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入数据错误\n输入插入位置>");
                                goto e;
                            }
                            res = InsertBeforeList_DuL(end, newnode);
                            if(res)
                            {
                                system("cls");
                                showcomlist();
                                printf("链表插入成功");
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入指令编号>");
                            }
                            else
                            {
                                system("cls");
                                showcomlist();
                                printf("链表插入失败，未知错误");
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入指令编号>");
                            }
                            break;
                        case 2:
                            pass:
                            printf("\n输入插入数据>");
                            f:
                            res=scanf("%d",&newnode->data);
                            while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                            {
                                system("cls");
                                showcomlist();
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入数据错误\n输入插入位置>");
                                goto f;
                            }
                            res = InsertAfterList_DuL(end, newnode);
                            if(res)
                            {
                                system("cls");
                                showcomlist();
                                printf("链表插入成功");
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入指令编号>");
                            }
                            else
                            {
                                system("cls");
                                showcomlist();
                                printf("链表插入失败，未知错误");
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入指令编号>");
                            }
                            break;
                        default:
                            system("cls");
                            showcomlist1();
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("输入数据错误\n重新输入插入位置>");
                            goto d;
                            break;
                    }
                }
                break;
            case 4:
                if(head==NULL)
                {
                    printf("链表不存在，输入指令>");
                }
                else if(head->next==NULL)
                {
                    printf("链表为空，输入指令>");
                }
                else
                {
                    system("cls");
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("\n输入删除结点>");
                    redelete:
                    g:
                    res = scanf("%d",&j);
                    while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                    {
                        system("cls");
                        showcomlist();
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("输入数据错误\n输入删除结点>");
                        goto g;
                    }
                    if(j==0)
                    {
                        printf("无法删除头结点\n");
                        printf("重新输入删除结点>");
                        goto redelete;
                    }
                    end=head;
                    for(i=0;i<j-1&&end->next!=NULL&&j>=0;i++)
                    {
                        end=end->next;
                    }
                    if(end==NULL||end->next==NULL||j<0)
                    {
                        printf("删除位置错误\n");
                        printf("重新输入删除结点>");
                        goto redelete;
                    }
                    res = DeleteList_DuL(end,&deleteddata);
                    if(res)
                    {
                        system("cls");
                        showcomlist();
                        printf("结点删除成功，被删除结点的数据为%d\n",deleteddata);
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("输入指令编号>");
                    }
                    else
                    {
                        system("cls");
                        showcomlist();
                        printf("结点删除失败，删除位置可能不存在");
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
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
                    TraverseList_DuL(head, printvalue);
                    printf("输入指令编号>");
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