
/***************************************************************************************
 *	File Name				:	main.h
 *	CopyRight				:	
 *	SYSTEM					:   win11
 *	Create Data				:	2023.3.20
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef main_H
#define main_H

/**************************************************************
*	Macro Define Section
**************************************************************/

#define ReverseList_use_algo  1

/**************************************************************
*	Include Section
**************************************************************/
#include "linkedList.h"
#include <stdbool.h>


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void showcomlist(void)
 *	@description : show command list
 *	@param		 : None
 *	@return		 : None
 *  @notice      : include system("cls")
 */
void showcomlist(void);

/**
 *  @name        : void printvalue(ElemType e);
 *	@description : �Զ� visit ����
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void printvalue(ElemType e);

/**
 *  @name        : Status ReverseList_algo(LinkedList *L,LinkedList q);
 *	@description : reverse the linked list
 *	@param		 : L(the head node),q
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList_algo(LinkedList *L,LinkedList q);

/**
 *  @name        : Status error_reshow(char * str,bool showlist);
 *	@description : ��ʾ�������
 *	@param		 : a str to print,bool showlist
 *	@return		 : Status
 *  @notice      : None
 */
Status error_reshow(char * str,bool showlist);

/**
 *  @name        : void my_scanf(int * i,char * error_warn,bool showlist);
 *	@description : ��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�
 *	@param		 : i�����󾯸��bool showlist
 *	@return		 : None
 *  @notice      : None
 */
void my_scanf(ElemType * i,char * error_warn,bool showlist);

/**
 *  @name        : void res_react(bool res,char * str);
 *	@description : Ӧ�Բ�ͬ�������ز�ͬ��statusֵ
 *	@param		 : bool res��a str to print
 *	@return		 : None
 *  @notice      : None
 */
void res_react(bool res,char * str);

/**
 *  @name        : Status headcheck(bool checkfirst);
 *	@description : ���ͷ����Ƿ���ڣ�Ҳ�ɼ���һ������Ƿ����
 *	@param		 : bool checkfirst
 *	@return		 : Status
 *  @notice      : None
 */
Status headcheck(bool checkfirst);

#endif