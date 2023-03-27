#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : ��ʼ������
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
LQueue* InitLQueue(LQueue *Q)
{
    Q=(LQueue*)malloc(sizeof(LQueue));
    Q->front=NULL;
    Q->rear=NULL;
    Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *  @description : ���ٶ���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	ClearLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front==Q->rear&&Q->length==0)return TRUE;
    else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q e ����ָ��Q,��������ָ��e
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    int temp = *(int*)(Q->front->data);
    *(int*)e=temp;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : ȷ�����г���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if(data==NULL)return FALSE;
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
	Q->length++;
    if(Q->length==1)
    {

        Q->front=Q->rear=temp;
    }
    else
    {
        Q->rear->next=temp;
        Q->rear=temp;
    }
    temp->next=NULL;
    temp->data=data;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp=Q->front;
	Q->length--;
    Q->front=temp->next;
    //free(temp);
    return TRUE;

}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    while(Q->length!=0)
    {
        temp=Q->front;
        Q->length--;
        Q->front=temp->next;
    }
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : ������������
 *  @param       : Q ����ָ��Q����������ָ��foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *temp;
    temp=Q->front;
    printf("��ǰ����Ϊ��");
    while(temp!=Q->rear)
    {
        foo(temp->data);
        temp=temp->next;
    }
    foo(temp->data);
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *  @description : ��������
 *  @param       : q ָ��q
 *  @notice      : None
 */
void LPrint(void *q)
{
    printf("%d-",*(int *)q);
}


