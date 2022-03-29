/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LQUEUE_H_INCLUDE
#define LQUEUE_H_INCLUDE

/**************************************************************
*	Struct Define Section
**************************************************************/

//队列节点
typedef struct Node
{
	int dat;//结点值
	struct Node *pNext;//下一个结点
}Node, *pNode;
//Node   等效于 struct Node
//*pNode 等效于 struct Node *


//链式队列
typedef struct LinkQueue
{
	struct Node * qFront;//队首指针
	struct Node * qRear;//队尾指针
}LinkQueue, *pLinkQueue;
//LinkQueue  等效于 struct LinkQueue
//pLinkQueue 等效于 struct LinkQueue *

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

