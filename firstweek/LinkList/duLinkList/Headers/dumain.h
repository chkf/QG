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
#ifndef du_main_H
#define du_main_H

/**************************************************************
*	Macro Define Section
**************************************************************/

/**************************************************************
*	Include Section
**************************************************************/
#include "duLinkedList.h"
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
 *  @name        : void showcomlist1(void)
 *	@description : 链表插入结点选择前插或者后插
 *	@param		 : None
 *	@return		 : None
 *  @notice      : include system("cls")
 */
void showcomlist1(void);

/**
 *  @name        : void printvalue(ElemType e);
 *	@description : 自定 visit 函数
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void printvalue(ElemType e);

/**
 *  @name        : Status error_reshow(char * str,bool showlist,int menu);
 *	@description : 显示输入错误
 *	@param		 : a str to print,bool showlist,int menu(两个菜单可选)
 *	@return		 : Status
 *  @notice      : None
 */
Status error_reshow(char * str,bool showlist,int menu);

/**
 *  @name        : void my_scanf(int * i,char * error_warn,bool showlist,int menu);
 *	@description : 防止错误输入，但不能检测输入数字在链表中位置是否合法
 *	@param		 : i，错误警告语，bool showlist,int menu(两个菜单可选)
 *	@return		 : None
 *  @notice      : None
 */
void my_scanf(ElemType * i,char * error_warn,bool showlist,int menu); 

/**
 *  @name        : void res_react(bool res,char * str);
 *	@description : 应对不同函数返回不同的status值
 *	@param		 : bool res，a str to print
 *	@return		 : None
 *  @notice      : None
 */
void res_react(bool res,char * str);

/**
 *  @name        : Status headcheck(bool checkfirst);
 *	@description : 检查头结点是否存在，也可检查第一个结点是否存在
 *	@param		 : bool checkfirst
 *	@return		 : Status
 *  @notice      : None
 */
Status headcheck(bool checkfirst);

#endif