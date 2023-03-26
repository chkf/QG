#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkStack.h" 

LinkStack *top=NULL;

void showcmdlist(void)
{
    system("cls");
    printf("链栈操作指令：\n");
    printf("    1.创建链栈\n");
    printf("    2.判断栈是否为空\n");
    printf("    3.查看栈顶值\n");
    printf("    4.清空链栈\n");
    printf("    5.销毁链栈\n");
    printf("    6.检测链栈长度\n");
    printf("    7.入栈X1\n");
    printf("    8.出栈X1\n");
    printf("\n");
}

/*检查是否为存在*/
Status topcheck(void)
{
    if(top==NULL)
    {
        printf("链栈不存在\n");
        return ERROR;
    }
    else return SUCCESS;
}

/*应对不同函数返回不同的status值*/
void res_react(bool res,char * str)                     //输入成功与否都要说的话
{
    if(res)
    {
        showcmdlist();
        printf("操作成功\n");
        if(str)printf(str);
    }
    else
    {
        showcmdlist();
        printf("出错了！！\n");
        if(str)printf(str);
    }
}

/*显示输入错误*/
Status error_reshow(char * str,bool showtop)                          //输入数据错误时，清屏并提示
{
    int topdata;
    bool res;
    showcmdlist();
    if(showtop)
    {
        res = getTopLStack(top,&topdata);
        if(res)printf("当前栈顶值为%d\n",topdata);
        else printf("当前栈为空\n");
    }
    printf("输入数据错误\n");
    printf(str);
}

/*防止错误输入，但不能检测输入数字在链表中位置是否合法*/
void my_scanf(ElemType * i,char * error_warn,bool showtop)                 //精简代码
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //没收到'\n'就卡着
        if(!res)error_reshow(error_warn,showtop);
    }
}
int main()
{
    int command,newdata,topdata,length,outdata;
    bool res;
    showcmdlist();
    printf("输入指令编号>");
    while (1)
    {
        my_scanf(&command,"输入的不是指令，请重新输入>",false);
        switch(command)
        {
            case 1:
                top = initLStack(top);
                showcmdlist();
                printf("链栈创建成功\n");
                printf("输入初始数据入栈,以'-1'结束>");
                my_scanf(&newdata,"重新输入初始数据，以'-1'结束>",true);
                while(newdata!=-1)
                {
                    res = pushLStack(top,newdata);
                    getTopLStack(top,&topdata);
                    if(res&&getTopLStack(top,&topdata))printf("当前栈共%d个元素，当前栈顶值为%d\n",top->count,topdata);
                    printf("输入初始数据,以'-1'结束>");
                    my_scanf(&newdata,"重新输入初始数据，以'-1'结束>",true);
                }
                showcmdlist();
                printf("链栈初始化成功\n");
                res = getTopLStack(top,&topdata);
                if(res)printf("当前栈共%d个元素，栈顶值为%d\n",top->count,topdata);
                else printf("当前栈为空\n");
                printf("输入指令编号>");
                break;
            case 2:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    if(isEmptyLStack(top))
                    {
                        printf("链栈为空\n");
                    }
                    else
                    {
                        printf("链栈非空\n");
                    }
                    printf("输入指令编号>");
                }
                break;
            case 3:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    res = getTopLStack(top,&topdata);
                    if(res)printf("当前栈顶值为%d\n",topdata);
                    else printf("当前栈为空\n");
                    printf("输入指令编号>");
                }
                break;
            case 4:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    clearLStack(top);
                    res = getTopLStack(top,&topdata);
                    if(res)printf("出错了，当前栈顶值为%d\n",topdata);
                    else printf("栈已清空\n");
                    printf("输入指令编号>");
                }
                break;
            case 5:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("l.fshd");
                    res = destroyLStack(top);
                    top=NULL;
                    res_react(res,"输入指令编号>");
                }
                break;
            case 6:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    LStackLength(top,&length);
                    printf("当前链栈的长度为%d\n",length);
                    printf("输入指令编号>");
                }
                break;
            case 7:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("输入入栈数值>");
                    my_scanf(&newdata,"重新输入数据>",true);
                    res = pushLStack(top,newdata);
                    getTopLStack(top,&topdata);
                    if(res&&getTopLStack(top,&topdata))printf("当前栈共%d个元素，当前栈顶值为%d\n",top->count,topdata);
                    printf("输入指令编号>");
                }
                break;
            case 8:
                if(!topcheck())
                {
                    printf("输入指令编号>");
                }
                else if (!top->count)
                {
                    showcmdlist();
                    printf("链栈为空\n输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    res = popLStack(top,&outdata);
                    getTopLStack(top,&topdata);
                    if(top->count==0)
                    {
                        if(res)printf("出栈数值为%d，当前栈共%d个元素\n",outdata,top->count);
                    }
                    else
                    if(res)printf("出栈数值为%d，当前栈共%d个元素，当前栈顶值为%d\n",outdata,top->count,topdata);
                    printf("输入指令编号>");
                }
                break;
            default:
                showcmdlist();
                printf("输入的不是指令，请重新输入>");
            break;
        }
    }
    return 0;
}