#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//创建链式队列
LinkQueue * CreatLinkQueue(void)
{
	pLinkQueue pHeadQueue = NULL;//链式队列指针
	pNode pHeadNode = NULL;//头结点指针


	//为链式队列申请内存
	pHeadQueue = (LinkQueue *)malloc(sizeof(LinkQueue));
	if (pHeadQueue == NULL)
	{
		printf("链式队列内存申请失败，程序终止......\r\n");
		while (1);
	}

	//为链式队列头结点申请内存
	pHeadNode = (Node *)malloc(sizeof(Node));
	if (pHeadNode == NULL)
	{
		printf("链式队列头结点内存申请失败，程序终止......\r\n");
		while (1);
	}

	pHeadQueue->qFront = pHeadNode;//队首指向头结点
	pHeadQueue->qRear  = pHeadNode;//队尾指向头结点
	pHeadNode->pNext   = NULL;//头结点无下个结点
	pHeadNode->dat     = 0;//头结点数据为零

	printf("链式队列创建成功......\r\n");
	printf("头结点:0x%08X    头结点指针:0x%08X    队首指针:0x%08X    队尾指针:0x%08X\r\n", pHeadNode, pHeadNode->pNext, pHeadQueue->qFront, pHeadQueue->qRear);

	return pHeadQueue;
}

//链式队列数据入队
void EnterLinkQueue(pLinkQueue queue, int value)
{
	pNode newNode = NULL;//链式队列入队结点指针


	//为链式队列入队结点申请内存
	newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("链式队列入队结点内存申请失败......\r\n");
		return;
	}

	queue->qRear->pNext = newNode;//入队新结点为最后个结点
	queue->qRear   = newNode;//队尾指向入队新结点
	newNode->pNext = NULL;//入队新结点无下个结点
	newNode->dat   = value;//入队值

	printf("入队成功！入队值:%d  ---->  ", value);
	printf("队首结点指针:0x%08X    队尾指针:0x%08X\r\n", queue->qFront, queue->qRear);
}

//判断链式队列是否为空
bool IsEmptyLinkQueue(pLinkQueue queue)
{
	//队首与队尾指向同一节(首节点)点则队列为空
	if (queue->qFront == queue->qRear)
		return true;
	else
		return false;
}

//遍历链式队列数据
void TraverseLinkQueue(pLinkQueue queue)
{
	pNode queNode = NULL;//结点指针

	if (IsEmptyLinkQueue(queue))
	{
		printf("链式队列为空，遍历失败......\r\n");
		return;
	}

	printf("链式队列数据: ");
	queNode = queue->qFront->pNext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		printf("%d ", queNode->dat);//结点数据
		queNode = queNode->pNext;//下一个结点
	}
	printf("\r\n");
}

//链式队列数据出队
void OutLinkQueue(pLinkQueue queue)
{
	pNode queNode = 0;//队列结点指针
    int e;

	if (IsEmptyLinkQueue(queue))
	{
		printf("链式队列为空，出队失败......\r\n");
		return;
	}

	if (queue->qFront->pNext == queue->qRear)//只有一个有效结点
		queue->qRear = queue->qFront;//队尾指针等于队首指针

	queNode = queue->qFront->pNext;//结点指针指向队首有效结点
	queue->qFront->pNext = queNode->pNext;//队首结点指针指向下个结点
	e = queNode->dat;//出队结点值
	free(queNode);//释放内存

	printf("出队成功！出队值:%d  ---->  ", e);
	printf("队首结点指针:0x%08X    队尾指针:0x%08X\r\n", queue->qFront->pNext, queue->qRear);
}

//获取链式队列长度
int CountLinkQueue(pLinkQueue queue)
{
	pNode queNode = NULL;//结点指针
	int len = 0;

	if (IsEmptyLinkQueue(queue))
	{
		printf("链式队列为空......\r\n");
		return len;
	}

	queNode = queue->qFront->pNext;//第一个有效结点
	while (queNode != NULL)//最后一个结点结束
	{
		len++;
		queNode = queNode->pNext;//下一个结点
	}

	printf("链式队列长度: %d\r\n", len);
	return len;
}

//清空队列 
int InitLinkQueue(pLinkQueue Q)
{
	Q->qFront = Q->qRear = (Node*)malloc(sizeof(Node));			 //建立头结点
	if (!Q->qRear || !Q->qFront)
	{
		return 0;
		printf("动态分配内存失败\n");
	}
	Q->qFront->pNext = NULL;										//初始化为空
	return 1;

}

int InputNumber()
{
	int num = 0; //存储已转换的数
	int status = 0; // 标志状态
	char str[100]; // 接收字符串
	do
	{
		scanf("%s", str);
		status = 1;
		// 检查输入的数据有无越界
        if(str[1]!='\0'){
        	printf("Overflow, please input again:");
        	status=0;
		}
		else if(str[0]>'4'||str[0]<'0')
		{
			printf("输入有误,请重新输入:");
			status=0;
		}
		
	} while (status == 0);
	return (str[0]-48);
}

