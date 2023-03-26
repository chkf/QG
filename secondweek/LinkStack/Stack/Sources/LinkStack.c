#include "LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
//��ջ

//��ʼ��ջ
LinkStack * initLStack(LinkStack *s)
{
    s=(LinkStack*)malloc(sizeof(LinkStack));
    s->top=NULL;
    s->count=0;
    return s;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if(s->top==NULL)return SUCCESS;
    else return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(isEmptyLStack(s))return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
    LinkStackPtr temp;
    while(!isEmptyLStack(s))
    {                
        temp=s->top;
        s->top=s->top->next;
        s->count--;
        free(temp);
    }
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
    if(!isEmptyLStack(s))clearLStack(s);
    free(s);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
    if(!s)
    {
        return ERROR;
    }
    LinkStackPtr temp;
    temp=(LinkStackPtr)malloc(sizeof(StackNode));
    if(!temp)
    {
        printf("error!");
        return ERROR;
    }
    temp->data=data;
    temp->next=s->top;
    s->top=temp;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{
    LinkStackPtr temp;
    temp=s->top;
    if(s->top==NULL)
    {
        return ERROR;
    }
    *data=temp->data;
    s->top=temp->next;
    free(temp);
    s->count--;
    return SUCCESS;
}

