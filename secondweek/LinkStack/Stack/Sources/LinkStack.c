#include "LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
//Á´Õ»

//³õÊ¼»¯Õ»
LinkStack * initLStack(LinkStack *s)
{
    s=(LinkStack*)malloc(sizeof(LinkStack));
    s->top=NULL;
    s->count=0;
    return s;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s)
{
	if(s->top==NULL)return SUCCESS;
    else return ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(isEmptyLStack(s))return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s)
{
    if(!isEmptyLStack(s))clearLStack(s);
    free(s);
    return SUCCESS;
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length)
{
	*length=s->count;
}

//ÈëÕ»
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

//³öÕ»
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

