#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//������ʽ����
LinkQueue * CreatLinkQueue(void)
{
	pLinkQueue pHeadQueue = NULL;//��ʽ����ָ��
	pNode pHeadNode = NULL;//ͷ���ָ��


	//Ϊ��ʽ���������ڴ�
	pHeadQueue = (LinkQueue *)malloc(sizeof(LinkQueue));
	if (pHeadQueue == NULL)
	{
		printf("��ʽ�����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}

	//Ϊ��ʽ����ͷ��������ڴ�
	pHeadNode = (Node *)malloc(sizeof(Node));
	if (pHeadNode == NULL)
	{
		printf("��ʽ����ͷ����ڴ�����ʧ�ܣ�������ֹ......\r\n");
		while (1);
	}

	pHeadQueue->qFront = pHeadNode;//����ָ��ͷ���
	pHeadQueue->qRear  = pHeadNode;//��βָ��ͷ���
	pHeadNode->pNext   = NULL;//ͷ������¸����
	pHeadNode->dat     = 0;//ͷ�������Ϊ��

	printf("��ʽ���д����ɹ�......\r\n");
	printf("ͷ���:0x%08X    ͷ���ָ��:0x%08X    ����ָ��:0x%08X    ��βָ��:0x%08X\r\n", pHeadNode, pHeadNode->pNext, pHeadQueue->qFront, pHeadQueue->qRear);

	return pHeadQueue;
}

//��ʽ�����������
void EnterLinkQueue(pLinkQueue queue, int value)
{
	pNode newNode = NULL;//��ʽ������ӽ��ָ��


	//Ϊ��ʽ������ӽ�������ڴ�
	newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("��ʽ������ӽ���ڴ�����ʧ��......\r\n");
		return;
	}

	queue->qRear->pNext = newNode;//����½��Ϊ�������
	queue->qRear   = newNode;//��βָ������½��
	newNode->pNext = NULL;//����½�����¸����
	newNode->dat   = value;//���ֵ

	printf("��ӳɹ������ֵ:%d  ---->  ", value);
	printf("���׽��ָ��:0x%08X    ��βָ��:0x%08X\r\n", queue->qFront, queue->qRear);
}

//�ж���ʽ�����Ƿ�Ϊ��
bool IsEmptyLinkQueue(pLinkQueue queue)
{
	//�������βָ��ͬһ��(�׽ڵ�)�������Ϊ��
	if (queue->qFront == queue->qRear)
		return true;
	else
		return false;
}

//������ʽ��������
void TraverseLinkQueue(pLinkQueue queue)
{
	pNode queNode = NULL;//���ָ��

	if (IsEmptyLinkQueue(queue))
	{
		printf("��ʽ����Ϊ�գ�����ʧ��......\r\n");
		return;
	}

	printf("��ʽ��������: ");
	queNode = queue->qFront->pNext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		printf("%d ", queNode->dat);//�������
		queNode = queNode->pNext;//��һ�����
	}
	printf("\r\n");
}

//��ʽ�������ݳ���
void OutLinkQueue(pLinkQueue queue)
{
	pNode queNode = 0;//���н��ָ��
    int e;

	if (IsEmptyLinkQueue(queue))
	{
		printf("��ʽ����Ϊ�գ�����ʧ��......\r\n");
		return;
	}

	if (queue->qFront->pNext == queue->qRear)//ֻ��һ����Ч���
		queue->qRear = queue->qFront;//��βָ����ڶ���ָ��

	queNode = queue->qFront->pNext;//���ָ��ָ�������Ч���
	queue->qFront->pNext = queNode->pNext;//���׽��ָ��ָ���¸����
	e = queNode->dat;//���ӽ��ֵ
	free(queNode);//�ͷ��ڴ�

	printf("���ӳɹ�������ֵ:%d  ---->  ", e);
	printf("���׽��ָ��:0x%08X    ��βָ��:0x%08X\r\n", queue->qFront->pNext, queue->qRear);
}

//��ȡ��ʽ���г���
int CountLinkQueue(pLinkQueue queue)
{
	pNode queNode = NULL;//���ָ��
	int len = 0;

	if (IsEmptyLinkQueue(queue))
	{
		printf("��ʽ����Ϊ��......\r\n");
		return len;
	}

	queNode = queue->qFront->pNext;//��һ����Ч���
	while (queNode != NULL)//���һ��������
	{
		len++;
		queNode = queNode->pNext;//��һ�����
	}

	printf("��ʽ���г���: %d\r\n", len);
	return len;
}

//��ն��� 
int InitLinkQueue(pLinkQueue Q)
{
	Q->qFront = Q->qRear = (Node*)malloc(sizeof(Node));			 //����ͷ���
	if (!Q->qRear || !Q->qFront)
	{
		return 0;
		printf("��̬�����ڴ�ʧ��\n");
	}
	Q->qFront->pNext = NULL;										//��ʼ��Ϊ��
	return 1;

}

int InputNumber()
{
	int num = 0; //�洢��ת������
	int status = 0; // ��־״̬
	char str[100]; // �����ַ���
	do
	{
		scanf("%s", str);
		status = 1;
		// ����������������Խ��
        if(str[1]!='\0'){
        	printf("Overflow, please input again:");
        	status=0;
		}
		else if(str[0]>'4'||str[0]<'0')
		{
			printf("��������,����������:");
			status=0;
		}
		
	} while (status == 0);
	return (str[0]-48);
}

