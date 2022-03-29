#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//初始化链栈
void Init_LinkStack(LinkStack &s)
{
    //printf("init执行开始\n");
    s=(Stacknode *)malloc(sizeof(Stacknode));
    s->next=NULL;
    //printf("init执行结束\n");
}

//入栈
void Push(LinkStack &s,ElemType e)
{
    //printf("push执行开始\n");
    Stacknode *p;
    p=(Stacknode *)malloc(sizeof(Stacknode));
    p->data=e;//头插法
    p->next=s;
    s=p;
    //printf("push执行结束\n");
}

//出栈
int Pop(LinkStack &s)
{
    Stacknode *p;
    if(s==NULL)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        p=s;
        s=p->next;//往后挪一位
        free(p);
        return 1;
    }
}

//查看栈顶元素
int GetTop(LinkStack &s)
{
    if(s==NULL)
    {
        printf("栈空\n");
        return 0;
    }
    else
    {
        printf("%d",s->data);
        return 1;
    }
}


//链表的显示
void Display_LinkStack(LinkStack &s)
{
    //printf("display执行开始\n");
    Stacknode *p;
    p=s;

    //printf("%d",p->data);
    while(p->next!=NULL)
    {
        printf("             %6d\n",p->data);
        //printf("12");
        p=p->next;
    }
    //printf("display执行结束\n");
}

int InputNumber()  //交互函数
{
	int num = 0; // Store converted numbers.
	int status = 1; // 记录输入状态
	char str[50]={'\0'}; // 接收字符串
	do
	{
		scanf("%s", str);
		status = 0;int InputNumber()
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

