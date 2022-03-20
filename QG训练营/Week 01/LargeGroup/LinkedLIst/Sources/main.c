#include "linkedListDemo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void *InitList(LinkedList L)                 //初始化链表
{
    if(!L)                                  // 判断链表头结点是否存在
    {
        return ERROR;                       //若不存在，则初始化失败，返回error
    }
    L = (LinkedList)malloc(sizeof(LNode)); // 为头结点动态分配内存
    if(L == NULL)                          // 判断是否申请成功
    {
        return OVERFLOW;                    //若申请失败，说明栈溢出，返回overflow
    }
    printf("链表初始化成功!\n");
    L->next = NULL;                          //生成一个只有头结点的链表
    return L;
}


Status DestroyList(LinkedList L)             //销毁链表
{
    LinkedList p;                            //定义结构体指针p遍历每一个结点
    p = L;                                   //指针p指向链表起始位置
    while(p)
    {
        p = p->next;                         //指针p指向下一个结点
        free(L);                            // 释放L所指向结点的内存空间
        L = p;                               //指针L指向指针p
    }
    printf("链表删除成功!\n");
    return SUCCESS;
}


void *InsertList(LinkedList L, int i, ElemType x)//插入元素
{
    if(L == NULL)
    {
        printf("链表不存在!");
        return ERROR;
    }
    LinkedList pre;
    pre = L;
    for(int temp=1; temp < i; temp++)      //让指针pre指向插入位置的前驱结点
    {
        pre = pre->next;
    }
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));  //为插入的结点申请空间
    q->data = x;
    q->next = pre->next;                    //先让插入结点连接后置结点
    pre->next = q;                          //再让前驱结点连接插入结点

    printf("元素插入成功!\n");
    return L;
}


void *DeleteList(LinkedList L, ElemType x)       //删除链表中的指定元素
{
    if(L == NULL || L->next == NULL)
    {
        printf("链表为空!");
        return ERROR;
    }
    LinkedList q, pre;
    q = L->next;
    while(q->data != x)                         //pre找到要删除元素值的前驱结点，此时q指向被删除的结点
    {
        pre = q;
        q = q->next;
    }
    pre->next = q->next;
    free(q);                                     //释放被删除结点的内存空间
    printf("元素值删除成功!");
    return L;
}


void TraverseList(LinkedList L, void (*visit)(ElemType e))//遍历链表并打印
{
    LinkedList p = L->next;        //指针p找到第一个结点
    while(p)
    {
        visit(p->data);            //从第一个结点开始逐个打印元素值
        p = p->next;
    }
    printf("\n");
}
void visit(ElemType e)
{
    printf("%d->", e);
}


void *SearchList(LinkedList L, int i) // 查找指定位置的结点
{
    if(L == NULL || L->next == NULL)
    {
        printf("链表为空!");
        return NULL;
    }
    int j = 1;                   //j为计数器
    LinkedList p = L->next;
    if(i == 1)                   //若只有一个结点，直接返回头指针
    {
        return L;
    }
    if(i < 1)                    //位置小于1，返回null链表
    {
        return NULL;
    }
    while(p && i>j)               //当j=i时结束循环，返回指针
    {
        p = p->next;
        j++;
    }
    return p;
}


void *ReverseList(LinkedList L)//逆转链表
{
	if(L == NULL)
    {
        printf("链表为空!");
        return ERROR;
    }
	LNode *s,*p;
	p = L->next;           //准备阶段：先记录第一个结点的位置，并断开L和第一个结点的连接
	L->next = NULL;
	while(p)
	{
		s = p;              //s记录p的位置
		p = p->next;        //p指向下一个结点
		s->next = L->next;  //先让s所指结点连接L的后置结点
		L->next = s;        //再让L连接s所指结点
	}

	return L;
}


void IsLoopList(LinkedList L)//判断成环
{
    if(L == NULL || L->next == NULL)
    {
        printf("链表为空或链表只有一个结点");
        return ERROR;
    }
    LinkedList fast, slow;
    slow = L;
    fast = L->next;
    while(1)
    {
        if(!fast || !fast->next)                     //快指针遍历到null，说明链表不成环
        {
            printf("不是成环链表\n");
            return SUCCESS;
        }
        else if(fast == slow || fast->next == slow) // 快指针与满指针相遇，说明链表成环
        {
            printf("是成环链表\n");
            return SUCCESS;
        }
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}


LNode* ReverseEvenList(LinkedList L)
{
    LinkedList cur = L->next;
    LinkedList pre;
    LinkedList phead = (LinkedList)malloc(sizeof(LNode));
    phead->next = NULL;
    LinkedList ph = phead;

    while( cur && cur->next )
    {
        pre = cur;
        ph->next = pre->next; // First point to the second node in two groups.
        ph = ph->next; // Move ph pointer.
        cur = cur->next->next; // Move the cur pointer for the next round of swaps.
        ph->next = pre; // Point to the first node in two sets.
        ph = ph->next; // Move ph pointer.
    }
    ph->next = cur; // Finally point to the remaining element if cur is NULL or odd.
    return phead;
}


LNode* FindMidNode(LinkedList L)//查找中间结点
{
    if(L == NULL || L->next == NULL)
    {
        return L;
    }
    LinkedList fast, slow;
    fast = slow = L;
    while(fast!=NULL)
    {
        if(fast->next == NULL) //如果fast指针指向最后一个结点，则再走一个结点指向NULL
        {
            fast = fast->next;
        }
        else
        {
            fast = fast->next->next;//fast指针跨过两个结点
        }
        slow = slow->next;//slow指针跨过一个结点
    }
    return slow;  //fast到达最后一个结点时，slow指针指向中间结点
}


void *Create()
{
    LinkedList head;
    LinkedList p, s;                                               //定义两个结构体指针s、p，s用来申请内存和储存数据，p用来记录前置结点位置和结点连接
    ElemType x, cycle = 1;
    int i=1;
    head = (LinkedList)malloc(sizeof(LNode));
    p = head;
    while(cycle)
    {
        printf("请输入第%d个数据(input non-integer to exit):",i++);//输入0~9以外的其他字符结束链表的创建
        if(scanf("%d", &x) == 1)                                   //如果数据输入符合规范，则scanf正确接收到变量的值为1
        {
            s = (LinkedList)malloc(sizeof(LNode));
            s->data = x;
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
        }
    }
    printf("链表创建成功!\n");
    p->next = NULL;
    return head;
}


int LinkedList_length(LinkedList L)//测量链表结点个数
{
    int k = 0;
    while(L != NULL)
    {
        k++;
        L = L->next;
    }
    return k;
}


int InputNumber()  //交互函数
{
	int num = 0; // Store converted numbers.
	int status = 0; // 记录输入状态
	char str[100]; // 接收字符串
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			//检查有无不合规范的字符
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')  //存储的元素可以为负数
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR)
        {
			printf("你的输入有误,请重新输入:");
		}
		else
		{
			int i = 0;
			// Convert string to number.
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
                {
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
            {
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    LinkedList head; // 定义链表的头指针
    int flag = 0; // flag判断链表是否存在
    while(SUCCESS)
    {
        system("cls");
        printf("\n\n\n----------------------------------\n");
        printf(">>> 1.创建链表                   \n");
        printf(">>> 2.打印链表                   \n");
        printf(">>> 3.初始化链表                 \n");
        printf(">>> 4.整表删除                   \n");
        printf(">>> 5.插入元素                   \n");
        printf(">>> 6.删除元素                   \n");
        printf(">>> 7.查找元素                   \n");
        printf(">>> 8.逆置链表                   \n");
        printf(">>> 9.逆置链表奇/偶数结点.       \n");
        printf(">>> 10.查找中间结点              \n");
        printf(">>> 11.判断成环                  \n");
        printf(">>> 12.Exit.                     \n");
        printf("---------------------------------\n");
        if(flag)
        {
            TraverseList(head, visit); // 打印链表
        }
        else
        {
            printf("No LinkedList.\n");
        }
        printf("---------------------------------\n");
        printf("----->>> 请选择:");
        switch(InputNumber())
        {
        case 1:
            head = Create();
            flag = 1;
            break;
        case 2:
            if(flag)
            {
                TraverseList(head, visit);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 3:
            head = InitList(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList(head);
                flag = 0;
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 5:
            if(flag)
            {
                int i;
                ElemType x;
                printf("请输入插入的位置 ");
                scanf("%d", &i);
                printf("请输入插入元素的值:");
                scanf("%d", &x);
                head = InsertList(head, i, x);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 6:
            if(flag)
            {
                ElemType x;
                printf("请输入删除的元素值 ");
                scanf("%d", &x);
                DeleteList(head, x);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 7:
            if(flag)
            {
                int i;
                LinkedList temp;
                printf("请输入查找的位置");
                scanf("%d", &i);
                temp = SearchList(head, i);
                printf("第%d个结点的元素是%d\n",i,temp->data);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 8:
            if(flag)
            {
                head = ReverseList(head);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 9:
            if(flag)
            {
                head = ReverseEvenList(head);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 10:
            if(flag)
            {
                LinkedList mid, temp = head;
                mid = FindMidNode(head);           //用mid来接收函数的返回值
                if(LinkedList_length(head)%2 == 0)
                {
                    printf("中间结点的元素值是%d\n", mid->data);
                }
                else                             // 如果结点个数为偶数，则打印中间两个结点.
                {
                    while(temp->next != mid)     // 另外一个中间结点在mid结点的前面
                    {
                        temp = temp->next;
                    }
                    printf("中间结点的元素值是%d和%d\n", temp->data, temp->next->data);
                }
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 11:
            if(flag)
            {
                IsLoopList(head);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 12:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
