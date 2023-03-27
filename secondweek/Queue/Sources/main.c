#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

LQueue *Q;

void showcmdlist(void)
{
    system("cls");
    printf("链式队列操作指令:\n");
    printf("\n");
    printf("    1:链式队列初始化\n");
    printf("    2:删除链式队列\n");
    printf("    3:判断队列是否为空\n");
    printf("    4:查看队头元素\n");
    printf("    5:确定队列长度\n");
    printf("    6:入队操作\n");
    printf("    7:出队操作\n");
    printf("    8:清空队列\n");
    printf("    9:遍历函数操作\n");
    printf("\n");
}

void error_reshow(char * str)                          //输入数据错误时，清屏并提示
{
    int topdata;
    bool res;
    showcmdlist();
    printf(str);
}

/*防止错误输入，但不能检测输入数字在链表中位置是否合法*/
void my_scanf_double(double* i,char * error_warn)
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%lf",i);
        while(getchar()!='\n');                             //没收到'\n'就卡着
        if(!res)error_reshow(error_warn);
    }
}

/*防止错误输入，但不能检测输入数字在链表中位置是否合法*/
void my_scanf_int(int* i,char * error_warn)
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //没收到'\n'就卡着
        if(!res)error_reshow(error_warn);
    }
}

int main()
{
    int command,length,e,*data;
    bool res;
    showcmdlist();
    printf("输入指令编号>");
    while (1)
    {
        my_scanf_int(&command,"输入的指令错误，请重新输入>");
        switch(command)
        {
            case 1:
                Q = InitLQueue(Q);
                if(Q!=NULL)printf("链式队列初始化成功\n");
                printf("输入指令编号>");
                break;
            case 2:
                if(Q!=NULL)
                {
                    showcmdlist();
                    DestoryLQueue(Q);
                    Q=NULL;
                    if(Q==NULL)printf("链式队列删除成功\n");
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                break;
            case 3:
                if(Q!=NULL)
                {
                    res = IsEmptyLQueue(Q);
                    if(res)printf("链式队列为空\n");
                    else printf("链式队列非空\n");
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                break;
            case 4:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    GetHeadLQueue(Q,&e);
                    printf("队首元素为：");
                    printf("%d",e);
                    printf("输入指令编号>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("队列为空\n");
                    printf("输入指令编号>");
                }
                break;
            case 5:
                if(Q!=NULL)
                {
                    showcmdlist();
                    length = LengthLQueue(Q);
                    printf("队列长度为%d\n",length);
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                break;
            case 6:
                if(Q!=NULL)
                {
                    //system("cls");
                    printf("数据类型(暂不支持):\n");
                    printf("    1.int\n");
                    printf("    2.int\n");
                    printf("    3.int\n");
                    printf("输入需要入队的数据类型编号>");
                    /*res=0;
                    while(!res)
                    {
                        my_scanf_int(&command,"输入的指令错误，请重新输入>");
                        switch(command)
                        {
                            case 1:*/
                                data = (int*)malloc(sizeof(int));
                                printf("输入入队数据>");
                                my_scanf_int(data,"输入的数据错误，请重新输入>");
                                /*res=1;
                                break;
                            case 2:
                                data = (double*)malloc(sizeof(double));
                                printf("输入入队数据>");
                                my_scanf_double(data,"输入的数据错误，请重新输入>");
                                res=1;
                                break;
                            case 3:
                                data = (char*)malloc(sizeof(char));
                                printf("输入入队数据>");
                                scanf("%c",data);
                                res=1;
                                break;
                            default:
                                printf("输入的数据错误，请重新输入>");
                                break;
                        }
                    }*/
                    EnLQueue(Q,data);
                    showcmdlist();
                    printf("入队成功\n");
                    printf("输入指令编号>");
                }
                else
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                break;
            case 7:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    DeLQueue(Q);
                    length = LengthLQueue(Q);
                    printf("出队完成，队列长度为%d\n",length);
                    printf("输入指令编号>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("队列为空\n");
                    printf("输入指令编号>");
                }
                break;
            case 8:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    ClearLQueue(Q);
                    printf("操作完成\n");
                    printf("输入指令编号>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("队列为空\n");
                    printf("输入指令编号>");
                }
                break;
            case 9:
                if(Q!=NULL&&Q->length!=0)
                {
                    showcmdlist();
                    TraverseLQueue(Q, LPrint);
                    printf("输入指令编号>");
                }
                else if(Q==NULL)
                {
                    showcmdlist();
                    printf("队列不存在\n");
                    printf("输入指令编号>");
                }
                else if(Q->length==0)
                {
                    showcmdlist();
                    printf("队列为空\n");
                    printf("输入指令编号>");
                }
                break;
            default:
                showcmdlist();
                printf("输入的指令错误，请重新输入>");
                break;
        }
    }
}