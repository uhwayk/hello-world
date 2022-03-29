/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED


/**************************************************************
*	Struct Define Section
**************************************************************/

// ��������Ԫ��ֵ������
typedef int ElemType;

// �����������ͷָ���������Ľṹ��
typedef struct node {//�����ڵ�
	ElemType data;//������
	struct node *next;//ָ����
}Stacknode,*LinkStack;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void Init_LinkStack(LinkStack &s)
 *	@description : initialize an empty linkstak with no node
 *	@param		 : LinkStack &s
 *	@return		 : None 
 *  @notice      : None
 */
void Init_LinkStack(LinkStack &s);

/**
 *  @name        : void Display_LinkStack(LinkStack &s)
 *	@description : desplay the linkstack 
 *	@param		 : LinkStack &s
 *	@return		 : None
 *  @notice      : None
 */
void Display_LinkStack(LinkStack &s);

/**
 *  @name        : void Push(LinkStack &s,ElemType e)
 *	@description : let the value get into the stack
 *	@param		 : LinkStack &s,ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void Push(LinkStack &s,ElemType e);

/**
 *  @name        : int Pop(LinkStack &s)
 *	@description : let the value get out of the stack
 *	@param		 : LinkStack &s
 *	@return		 : None
 *  @notice      : None
 */
int Pop(LinkStack &s);

/**
 *  @name        : int GetTop(LinkStack *S,int &ptr)
 *	@description : find out the value at the top of stack
 *	@param		 : LinkStack &s
 *	@return		 : the value
 *  @notice      : None
 */
int GetTop(LinkStack &s);//���ջ������ڲ��ı�ջ

int InputNumber(); // Check input number.

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif

