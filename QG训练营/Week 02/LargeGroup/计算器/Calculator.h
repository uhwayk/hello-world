/**************************************
*  Multi-Include-Prevent Section
**************************************/
#ifndef CALCULATOR_H_INCLUDE
#define CALCULATOR_H_INCLUDE

#define OK     10000001
#define ERROR  10000002

/**************************************
*  Struct-Define Section
**************************************/

//定义栈中的元素
typedef struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

//定义栈的结构
typedef struct stack
{
    Node *top;
    int count;
};
typedef struct stack Stack;

/***************************************
*	Prototype Declare Section
***************************************/

/**
 *  @name        : int InitStack(Stack *1)
 *	@description : create an empty stack
 *	@param		 : Stack *1
 *	@return		 : status
 *  @notice      : None
 */
int InitStack(Stack *
              );

 /**
 *  @name        : int EmptyStack(Stack *s)
 *	@description : judge if it is empty
 *	@param		 : Stack *s
 *	@return		 : status
 *  @notice      : None
 */
int EmptyStack(Stack *s);

/**
 *  @name        : int Push(Stack *s,int e)
 *	@description : push a node into the stack
 *	@param		 : Stack *s,int e
 *	@return		 : status
 *  @notice      : None
 */
int Push(Stack *s,int e);

/**
 *  @name        : int GetTop(Stack *s)
 *	@description : get the top value of the stack
 *	@param		 : Stack *s
 *	@return		 : the value(int)
 *  @notice      : None
 */
int GetTop(Stack *s);

/**
 *  @name        : int Priority(char c)
 *	@description : define the priority '('> '*''/' > '+''-'
 *	@param		 : char c
 *	@return		 : 3/2/1/0
 *  @notice      : None
 */
int Priority(char c);

/**
 *  @name        : int Push(Stack *s)
 *	@description : pop the value at the top of the stack out
 *	@param		 : Stack *s
 *	@return		 : the value at the top of the stack
 *  @notice      : None
 */
int Pop(Stack *s);



#endif // CALCULATOR_H_INCLUDE
