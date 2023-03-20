#include "main.h"

LinkedList head;

int main()
{
    int command,j,i,newdata,deleteddata;
    bool res,mark;
    LinkedList p,q,end,MidNode,newnode;
    showcomlist();
    printf("输入指令编号>");
    while (1)
    {   
        my_scanf(&command,"输入的不是指令，请重新输入>",false);
        switch (command)
        {
            case 1:
                res = InitList(&head);
                if(res)
                {
                    end=head;                                           //先指向头结点
                    showcomlist();
                    printf("链表头结点创建成功\n");
                    printf("输入初始数据,以'-1'结束>");
                    my_scanf(&newdata,"重新输入初始数据,以'-1'结束>",true);
                    while(newdata!=-1)
                    {   
                        newnode = (LNode*)malloc(sizeof(LNode));
                        newnode->data = newdata;                              //存入数据
                        res = InsertList(end, newnode);                                      
                        end=newnode;                                          //尾指针指向新结点              
                        res_react(res,"输入初始数据,以'-1'结束>");
                        my_scanf(&newdata,"重新输入初始数据,以'-1'结束>",true);
                    }
                    showcomlist();
                    printf("链表初始化成功\n");
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
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
                    DestroyList(&head);
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
                    TraverseList(head, printvalue);
                    printf("\n输入插入位置>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"重新输入插入位置>",true);
                        p=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("插入位置错误\n");
                            printf("重新输入插入位置>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            p=p->next;
                            if(p==NULL||p->next==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("插入位置错误\n重新输入插入位置>");
                                break;
                            }
                        }
                    }
                    printf("\n输入插入数据>");
                    my_scanf(&newdata,"重新输入插入数据>",true);
                    newnode = (LNode*)malloc(sizeof(LNode));
                    newnode->data=newdata;
                    res = InsertList(p, newnode);
                    res_react(res,"输入指令编号>");
                }
                break;
            case 4:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("\n输入删除结点>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"重新输入删除结点>",true);
                        j--;
                        p=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("删除结点错误\n重新输入删除结点>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            p=p->next;
                            if(p->next==NULL||p==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("删除结点错误\n重新输入删除结点>");
                                break;
                            }
                        }
                    }
                    res = DeleteList(p,&deleteddata);
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
                    TraverseList(head, printvalue);
                    printf("输入指令编号>");
                }
                break;
            case 6:
                if(!headcheck(true));
                else
                {
                    system("cls");
                    showcomlist();
                    printf("要查找的数据为>");
                    my_scanf(&j,"输入要查找的数据>",false);
                    res = SearchList(head, j);
                    res_react(res,"输入指令编号>");
                }
                break;
            case 7:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    #if ReverseList_use_algo 
                        res = ReverseList_algo(&head,head);
                    #else
                        res = ReverseList(&head);
                    #endif
                    if(res)
                    {
                        printf("调转后,当前链表为：");
                        TraverseList(head, printvalue);
                        printf("输入指令编号>");
                    }
                    else
                    {
                        res_react(res,"输入指令编号>");
                    }
                }
                break;
            case 8:
                if(!headcheck(true));
                else
                {
                    res = IsLoopList(head);
                    if(res)
                    {
                        showcomlist();
                        printf("链表成环\n");
                    }
                    else
                    {
                        showcomlist();
                        printf("链表不成环\n");
                    }
                    printf("输入指令编号>");
                }
                break;
            case 9:
                if(!headcheck(true));
                else
                {
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
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("当前链表为：");
                    TraverseList(head, printvalue);
                    printf("中间节点为:");
                    MidNode = FindMidNode(&head);
                    printvalue(MidNode->data);
                    printf("输入指令>");
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


void showcomlist(void)
{
    system("cls");
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

/*visit 函数*/
void printvalue(ElemType e)                               
{
    printf("%d->",e);
}

/*倒转链表递归法*/
Status ReverseList_algo(LinkedList *L,LinkedList q)      //把头结点传递到最后
{
/***************************递归*******************************/
    if(!q)                                               //只有头结点
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
        q->next->next=q;                                 //后一个节点指向前一个，前一个结点指向NULL
        q->next=NULL;
    }
}

/*显示输入错误*/
Status error_reshow(char * str,bool showlist)                          //输入数据错误时，清屏并提示
{
    showcomlist();
    if(showlist)TraverseList(head, printvalue);
    printf("输入数据错误\n");
    printf(str);
}

/*防止错误输入，但不能检测输入数字在链表中位置是否合法*/
void my_scanf(ElemType * i,char * error_warn,bool showlist)                 //精简代码
{
    bool res=0;
    while(!res)
    {
        res=scanf("%d",i);
        while(getchar()!='\n'||!res)                     //吞掉字符，防止跑飞
        {
            error_reshow(error_warn,showlist);
        }
    }
}

/*应对不同函数返回不同的status值*/
void res_react(bool res,char * str)                     //输入成功与否都要说的话
{
    if(res)
    {
        showcomlist();
        printf("操作成功");
        printf("当前链表为：");
        TraverseList(head, printvalue);
        if(str)printf(str);
    }
    else
    {
        showcomlist();
        printf("出错了！！\n");
        printf("当前链表为：");
        TraverseList(head, printvalue);
        if(str)printf(str);
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
