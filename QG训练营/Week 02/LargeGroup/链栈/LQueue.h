/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LQUEUE_H_INCLUDE
#define LQUEUE_H_INCLUDE

/**************************************************************
*	Struct Define Section
**************************************************************/

//���нڵ�
typedef struct Node
{
	int dat;//���ֵ
	struct Node *pNext;//��һ�����
}Node, *pNode;
//Node   ��Ч�� struct Node
//*pNode ��Ч�� struct Node *


//��ʽ����
typedef struct LinkQueue
{
	struct Node * qFront;//����ָ��
	struct Node * qRear;//��βָ��
}LinkQueue, *pLinkQueue;
//LinkQueue  ��Ч�� struct LinkQueue
//pLinkQueue ��Ч�� struct LinkQueue *

/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *	@description : initialize an empty LQueue
 *	@return		 : LNode(the new head node) or Status
 *  @notice      : None
 */
LinkQueue * CreatLinkQueue(void);
/**
 *  @name        : void Display_LinkStack(LinkStack &s)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head pointer)
 *	@return		 : Status
 *  @notice      : None
 */
void EnterLinkQueue(pLinkQueue queue, int value);

/**
 *  @name        : void Push(LinkStack &s,ElemType e)
 *	@description : insert node q after node p
 *	@param		 : LinkedList L, int i, ElemType x
 *	@return		 : L(the head pointer) or Status
 *  @notice      : None
 */
bool IsEmptyLinkQueue(pLinkQueue queue);

/**
 *  @name        : int Pop(LinkStack &s)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : LinkedList L, ElemType x
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void TraverseLinkQueue(pLinkQueue queue);

/**
 *  @name        : int GetTop(LinkStack *S,int &ptr)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void OutLinkQueue(pLinkQueue queue);

/**
 *  @name        : int GetTop(LinkStack *S,int &ptr)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
int CountLinkQueue(pLinkQueue queue);

/**
 *  @name        : int GetTop(LinkStack *S,int &ptr)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
int InitLinkQueue(pLinkQueue Q);

int InputNumber(); // Check input number.

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/


#endif // LQUEUE_H_INCLUDE

