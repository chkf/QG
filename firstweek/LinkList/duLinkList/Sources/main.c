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
    printf("输入指令编号>");
    while (1)
    {
        my_scanf(&command,"输入的不是指令，请重新输入>",false,0);
        switch(command)
        {
            case 1:
                res = InitList_DuL(&head);
                if(res)
                {
                    end=head;
                    showcomlist();
                    printf("双链表头结点创建成功\n");
                    printf("输入初始数据,以'-1'结束>");
                    my_scanf(&newdata,"重新输入初始数据,以'-1'结束>",true,0);
                    while (newdata!=-1)
                    {
                        newnode = (DuLNode*)malloc(sizeof(DuLNode));
                        newnode->data=newdata;
                        res = InsertAfterList_DuL(end, newnode);
                        end = newnode;
                        res_react(res,"输入初始数据,以'-1'结束>");
                        b:
                        res=scanf("%d",&newdata);
                        while(getchar()!='\n'||!res)                                         //吞掉字符，防止跑飞
                        {
                            system("cls");
                            showcomlist();
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("输入数据错误\n输入初始数据,以'-1'结束>");
                            my_scanf(&newdata,"重新输入初始数据,以'-1'结束>",true,0);
                        }
                    }
                    showcomlist();
                    printf("链表初始化成功\n");
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("输入指令编号>");
                }
                else
                {
                    showcomlist();
                    printf("链表创建失败，输入指令>");
                }
                break;
            case 2:
                if(!headcheck(false));
                else
                {
                    DestroyList_DuL(&head);
                    showcomlist();
                    printf("链表删除成功，输入指令>");
                }
                break;
            case 3:
                if(!headcheck(false));
                else
                {
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("\n输入插入位置>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"重新输入插入位置>",true,0);
                        end=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("插入位置错误\n");
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("重新输入插入位置>");
                        }
                        else mark=true; 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            end=end->next;
                            if(end==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("插入位置错误\n重新输入插入位置>");
                                break;
                            }
                        }
                    }
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    if(j!=0&&head->next!=NULL)
                    {
                        showcomlist1();
                        printf("当前链表为：");
                        TraverseList_DuL(head, printvalue);
                        printf("输入插入位置>");
                    }
                    while(d!=1&&d!=2)
                    {
                        if(j!=0&&head->next!=NULL)                //0结点处只能后插
                            my_scanf(&d,"重新输入插入位置>",true,1);      
                        else
                            d=2;
                        switch (d)
                        {
                            case 1:
                                printf("\n输入插入数据>");
                                my_scanf(&newdata,"重新输入插入数据>",true,1);
                                newnode = (DuLNode*)malloc(sizeof(DuLNode));
                                newnode->data=newdata;
                                res = InsertBeforeList_DuL(end, newnode);
                                res_react(res,"输入指令编号>");
                                break;
                            case 2:
                                printf("\n输入插入数据>");
                                my_scanf(&newdata,"重新输入插入数据>",true,1);
                                newnode = (DuLNode*)malloc(sizeof(DuLNode));
                                newnode->data=newdata;
                                res = InsertAfterList_DuL(end, newnode);
                                res_react(res,"输入指令编号>");
                                break;
                            default:
                                showcomlist1();
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("输入数据错误\n重新输入插入位置>");
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
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("\n输入删除结点>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"重新输入删除结点>",true,0);
                        j--;
                        end=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("删除结点错误\n");
                            printf("当前链表为：");
                            TraverseList_DuL(head, printvalue);
                            printf("重新输入删除结点>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            end=end->next;
                            if(end->next==NULL||end==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("删除结点错误\n");
                                printf("当前链表为：");
                                TraverseList_DuL(head, printvalue);
                                printf("重新输入删除结点>");
                                break;
                            }
                        }
                    }
                    res = DeleteList_DuL(end,&deleteddata);
                    res_react(res,NULL);
                    if(res)
                        printf("被删除结点的数据为%d\n",deleteddata);
                    printf("输入指令编号>");    
                }
                break;
            case 5:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList_DuL(head, printvalue);
                    printf("输入指令编号>");
                }
                break;
            default:
                showcomlist();
                printf("输入的不是指令，请重新输入>");
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
    system("cls");
    printf("插入方式:\n");
    printf("\n");
    printf("    1:在该结点前插入\n");
    printf("    2:在该结点后插入\n");
    printf("\n");
}

/*应对不同函数返回不同的status值*/
void res_react(bool res,char * str)                     //输入成功与否都要说的话
{
    if(res)
    {
        showcomlist();
        printf("操作成功");
        printf("当前链表为：");
        TraverseList_DuL(head, printvalue);
        if(str)printf(str);
    }
    else
    {
        showcomlist();
        printf("出错了！！\n");
        printf("当前链表为：");
        TraverseList_DuL(head, printvalue);
        if(str)printf(str);
    }
}

/*显示输入错误*/
Status error_reshow(char * str,bool showlist,int menu)                          //输入数据错误时，清屏并提示
{
    if(!menu)showcomlist();
    else showcomlist1();
    if(showlist)TraverseList_DuL(head, printvalue);
    printf("输入数据错误\n");
    printf(str);
}

/*防止错误输入，但不能检测输入数字在链表中位置是否合法*/
void my_scanf(ElemType * i,char * error_warn,bool showlist,int menu)                 //精简代码
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //没收到'\n'就卡着
        if(!res)error_reshow(error_warn,showlist,menu);
    }
}

/*检查头结点是否存在，也可检查第一个结点是否存在*/
Status headcheck(bool checkfirst)
{
    if(head==NULL)
    {
        showcomlist();
        printf("链表不存在，输入指令>");
        return ERROR;
    }
    if(checkfirst)
    {
        if(head->next==NULL)
        {
            showcomlist();
            printf("链表为空，输入指令>");
            return ERROR;
        }
    }
    return SUCCESS;
}