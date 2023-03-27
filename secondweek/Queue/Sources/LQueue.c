#include "LQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q 队列指针Q
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
 *  @description : 销毁队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	ClearLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front==Q->rear&&Q->length==0)return TRUE;
    else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q e 队列指针Q,返回数据指针e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    int temp = *(int*)(Q->front->data);
    *(int*)e=temp;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
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
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
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
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *temp;
    temp=Q->front;
    printf("当前队列为：");
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
 *  @description : 操作函数
 *  @param       : q 指针q
 *  @notice      : None
 */
void LPrint(void *q)
{
    printf("%d-",*(int *)q);
}


