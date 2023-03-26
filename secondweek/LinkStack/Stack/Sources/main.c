#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkStack.h" 

LinkStack *top=NULL;

void showcmdlist(void)
{
    system("cls");
    printf("��ջ����ָ�\n");
    printf("    1.������ջ\n");
    printf("    2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("    3.�鿴ջ��ֵ\n");
    printf("    4.�����ջ\n");
    printf("    5.������ջ\n");
    printf("    6.�����ջ����\n");
    printf("    7.��ջX1\n");
    printf("    8.��ջX1\n");
    printf("\n");
}

/*����Ƿ�Ϊ����*/
Status topcheck(void)
{
    if(top==NULL)
    {
        printf("��ջ������\n");
        return ERROR;
    }
    else return SUCCESS;
}

/*Ӧ�Բ�ͬ�������ز�ͬ��statusֵ*/
void res_react(bool res,char * str)                     //����ɹ����Ҫ˵�Ļ�
{
    if(res)
    {
        showcmdlist();
        printf("�����ɹ�\n");
        if(str)printf(str);
    }
    else
    {
        showcmdlist();
        printf("�����ˣ���\n");
        if(str)printf(str);
    }
}

/*��ʾ�������*/
Status error_reshow(char * str,bool showtop)                          //�������ݴ���ʱ����������ʾ
{
    int topdata;
    bool res;
    showcmdlist();
    if(showtop)
    {
        res = getTopLStack(top,&topdata);
        if(res)printf("��ǰջ��ֵΪ%d\n",topdata);
        else printf("��ǰջΪ��\n");
    }
    printf("�������ݴ���\n");
    printf(str);
}

/*��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�*/
void my_scanf(ElemType * i,char * error_warn,bool showtop)                 //�������
{
    bool res=0;
    while(!res)
    {
        if(!res)res=scanf("%d",i);
        while(getchar()!='\n');                             //û�յ�'\n'�Ϳ���
        if(!res)error_reshow(error_warn,showtop);
    }
}
int main()
{
    int command,newdata,topdata,length,outdata;
    bool res;
    showcmdlist();
    printf("����ָ����>");
    while (1)
    {
        my_scanf(&command,"����Ĳ���ָ�����������>",false);
        switch(command)
        {
            case 1:
                top = initLStack(top);
                showcmdlist();
                printf("��ջ�����ɹ�\n");
                printf("�����ʼ������ջ,��'-1'����>");
                my_scanf(&newdata,"���������ʼ���ݣ���'-1'����>",true);
                while(newdata!=-1)
                {
                    res = pushLStack(top,newdata);
                    getTopLStack(top,&topdata);
                    if(res&&getTopLStack(top,&topdata))printf("��ǰջ��%d��Ԫ�أ���ǰջ��ֵΪ%d\n",top->count,topdata);
                    printf("�����ʼ����,��'-1'����>");
                    my_scanf(&newdata,"���������ʼ���ݣ���'-1'����>",true);
                }
                showcmdlist();
                printf("��ջ��ʼ���ɹ�\n");
                res = getTopLStack(top,&topdata);
                if(res)printf("��ǰջ��%d��Ԫ�أ�ջ��ֵΪ%d\n",top->count,topdata);
                else printf("��ǰջΪ��\n");
                printf("����ָ����>");
                break;
            case 2:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    if(isEmptyLStack(top))
                    {
                        printf("��ջΪ��\n");
                    }
                    else
                    {
                        printf("��ջ�ǿ�\n");
                    }
                    printf("����ָ����>");
                }
                break;
            case 3:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    res = getTopLStack(top,&topdata);
                    if(res)printf("��ǰջ��ֵΪ%d\n",topdata);
                    else printf("��ǰջΪ��\n");
                    printf("����ָ����>");
                }
                break;
            case 4:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    clearLStack(top);
                    res = getTopLStack(top,&topdata);
                    if(res)printf("�����ˣ���ǰջ��ֵΪ%d\n",topdata);
                    else printf("ջ�����\n");
                    printf("����ָ����>");
                }
                break;
            case 5:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("l.fshd");
                    res = destroyLStack(top);
                    top=NULL;
                    res_react(res,"����ָ����>");
                }
                break;
            case 6:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    LStackLength(top,&length);
                    printf("��ǰ��ջ�ĳ���Ϊ%d\n",length);
                    printf("����ָ����>");
                }
                break;
            case 7:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else
                {
                    showcmdlist();
                    printf("������ջ��ֵ>");
                    my_scanf(&newdata,"������������>",true);
                    res = pushLStack(top,newdata);
                    getTopLStack(top,&topdata);
                    if(res&&getTopLStack(top,&topdata))printf("��ǰջ��%d��Ԫ�أ���ǰջ��ֵΪ%d\n",top->count,topdata);
                    printf("����ָ����>");
                }
                break;
            case 8:
                if(!topcheck())
                {
                    printf("����ָ����>");
                }
                else if (!top->count)
                {
                    showcmdlist();
                    printf("��ջΪ��\n����ָ����>");
                }
                else
                {
                    showcmdlist();
                    res = popLStack(top,&outdata);
                    getTopLStack(top,&topdata);
                    if(top->count==0)
                    {
                        if(res)printf("��ջ��ֵΪ%d����ǰջ��%d��Ԫ��\n",outdata,top->count);
                    }
                    else
                    if(res)printf("��ջ��ֵΪ%d����ǰջ��%d��Ԫ�أ���ǰջ��ֵΪ%d\n",outdata,top->count,topdata);
                    printf("����ָ����>");
                }
                break;
            default:
                showcmdlist();
                printf("����Ĳ���ָ�����������>");
            break;
        }
    }
    return 0;
}