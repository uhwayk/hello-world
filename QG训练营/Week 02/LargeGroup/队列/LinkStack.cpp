#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��ʼ����ջ
void Init_LinkStack(LinkStack &s)
{
    //printf("initִ�п�ʼ\n");
    s=(Stacknode *)malloc(sizeof(Stacknode));
    s->next=NULL;
    //printf("initִ�н���\n");
}

//��ջ
void Push(LinkStack &s,ElemType e)
{
    //printf("pushִ�п�ʼ\n");
    Stacknode *p;
    p=(Stacknode *)malloc(sizeof(Stacknode));
    p->data=e;//ͷ�巨
    p->next=s;
    s=p;
    //printf("pushִ�н���\n");
}

//��ջ
int Pop(LinkStack &s)
{
    Stacknode *p;
    if(s==NULL)
    {
        printf("ջ��\n");
        return 1;
    }
    else
    {
        p=s;
        s=p->next;//����Ųһλ
        free(p);
        return 1;
    }
}

//�鿴ջ��Ԫ��
int GetTop(LinkStack &s)
{
    if(s==NULL)
    {
        printf("ջ��\n");
        return 0;
    }
    else
    {
        printf("%d",s->data);
        return 1;
    }
}


//�������ʾ
void Display_LinkStack(LinkStack &s)
{
    //printf("displayִ�п�ʼ\n");
    Stacknode *p;
    p=s;

    //printf("%d",p->data);
    while(p->next!=NULL)
    {
        printf("             %6d\n",p->data);
        //printf("12");
        p=p->next;
    }
    //printf("displayִ�н���\n");
}

int InputNumber()  //��������
{
	int num = 0; // Store converted numbers.
	int status = 1; // ��¼����״̬
	char str[50]={'\0'}; // �����ַ���
	do
	{
		scanf("%s", str);
		status = 0;int InputNumber()
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

