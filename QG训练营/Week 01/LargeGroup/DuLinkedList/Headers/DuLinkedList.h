 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// 定义元素类型
typedef int ElemType;

// 定义链表结点的结构体
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior, *next;
} DuLNode, *DuLinkedList;

// 定义状态
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void *Create(int n)
 *	@description : Create a linked list
 *	@param		 : int n
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create(int n);

/**
 *  @data        : void *InitList_DuL(DuLinkedList L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *InitList_DuL(DuLinkedList L);

/**
 *  @data        : void DestroyList_DuL(DuLinkedList L)
 *	@description : destroy a linked list
 *	@param		 : L(the head pointer)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList L);

/**
 *  @data        : void *Insert_Node(DuLinkedList head)
 *	@description : insert node q before node p
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Insert_Node(DuLinkedList head);

/**
 *  @data        : void *DeleteList_DuL(DuLinkedList L, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : L(the head pointer), ElemType e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *DeleteList_DuL(DuLinkedList L, ElemType e);

/**
 *  @name        : DuLNode* FindMidNode(DuLinkedList L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : LNode*
 *  @notice      : choose to finish
 */
DuLNode* FindMidNode(DuLinkedList L);

/**
 *  @name        : void IsLoopList_DuL(DuLinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void IsLoopList_DuL(DuLinkedList L);

/**
 *  @name        : void *ReverseList_DuL(DuLinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *ReverseList_DuL(DuLinkedList L);


/**
 *  @data        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
void visit(ElemType e);

/**
 *  @name        : void *SearchList(LinkedList L, int i)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *SearchList(DuLinkedList L, int i);



int InputNumber(); // Check input number.

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif

