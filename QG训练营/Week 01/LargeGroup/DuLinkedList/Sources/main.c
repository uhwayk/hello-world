#include <stdio.h>
#include <stdlib.h>
#include "DuLinkedList.h"

void *Create(int n)                                   //创建双向链表
{
    DuLinkedList h, p, s;
    h = (DuLinkedList)malloc(sizeof(DuLNode));        //首先为首元结点p申请分配内存空间

    if(h == NULL)                                      //如果申请失败，说明存在栈溢出
    {
        return OVERFLOW;                               //返回overflow
    }

    h->data = 0;                                        //首元结点中存储的元素值为0
    h->prior = NULL;
    h->next = NULL;
    p = h;

    for(int i=0; i<n; i++)
    {
        s = (DuLinkedList)malloc(sizeof(DuLNode));
        if(s == NULL)
        {
            return OVERFLOW;
        }
        p->next = s;
        printf("请输入第%d个结点的元素值:", i+1);
        scanf("%d", &s->data);
        s->prior = p;                                   //使新开辟的结点连接前驱结点
        s->next = NULL;
        p = s;
    }
    printf("链表创建成功!\n");
    return h;
}


void *InitList_DuL(DuLinkedList L)                   //初始化链表
{
    L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!L)
    {
        return OVERFLOW;
    }
	L->prior = L->next = NULL;                        //将链表的首元结点剥离出来
	printf("Successfully initialize a DuLinkedList!\n");
	return L;                                         //返回首元结点的指针
}


void DestroyList_DuL(DuLinkedList L) //销毁链表
{
    DuLinkedList p;
    p = L;                           //从表头依次遍历表中元素
	while(p)
    {
		p = p->next;
		free(L);                     //释放内存空间
		L = p;
	}
}


void *Insert_Node(DuLinkedList head)            //插入元素
{
   DuLinkedList q;
   DuLinkedList pnext = head;
   int i = 1;
   int n;

   printf("请输入插入的位置:");
   scanf("%d", &n);

   while((i<n) && (pnext != NULL))
   {
      i++;
      pnext = pnext->next;

   }                                            //循环结束，pnext指向插入位置的直接前驱结点

   if(pnext == NULL)
   {
     return ERROR;
   }
   else
   {
        q = (DuLinkedList)malloc(sizeof(DuLNode));//p申请动态分配内存空间
        printf("请输入插入的元素值:");
        scanf("%d", &q->data);                    //存入元素值

        q->next = pnext->next;                    //新节点先与其直接后继节点建立双层逻辑关系
        if(n = 0)
        {
          pnext->next = q;
          q->next = NULL;
        }
        else
        {
          pnext->next = q;
          pnext->next->prior = q;                  //新节点的直接前驱节点与之建立双层逻辑关系
          q->prior = pnext;
        }
   }
   return head;
}


void *DeleteList_DuL(DuLinkedList L, ElemType e)//删除元素
{
    if(L == NULL || L->next == NULL)
    {
        return ERROR;
    }
    DuLinkedList q, pre;
    q = L->next;
    while(q->data != e)
    {
        pre = q;
        q = q->next;
    }                                          //循环结束，q指向被删除元素，pre指向其前驱结点
    pre->next = q->next;                       //跨过被删除元素重新连接，达到删除元素的效果
    free(q);
    printf("删除成功!\n");
    return L;
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))   //打印链表
{
    DuLinkedList p = L->next;
	while(p)
    {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf("%d->",e);
}





void *SearchList(DuLinkedList L, int i) // 查找某位置的元素
{
    if(L == NULL || L->next == NULL)
    {
        printf("链表不存在!");
        return NULL;
    }
    int j = 1;
    DuLinkedList p = L->next;
    if(i == 1)
    {
        return L;
    }
    if(i < 1)
    {
        return NULL;
    }
    while(p && i>j)
    {
        p = p->next;
        j++;
    }
    return p;
}

DuLNode* FindMidNode(DuLinkedList L)//查找中间结点
{
    if(L == NULL || L->next == NULL)
    {
        return L;
    }
    DuLinkedList fast, slow;
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

void IsLoopList_DuL(DuLinkedList L)//判断成环
{
    if(L == NULL || L->next == NULL)
    {
        printf("链表为空或链表只有一个结点");
        return ERROR;
    }
    DuLinkedList fast, slow;
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

void *ReverseList_DuL(DuLinkedList L)//逆转链表
{
	if(L == NULL)
    {
        printf("链表为空!");
        return ERROR;
    }
	DuLNode *s,*p;
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

int DuLinkedList_length(DuLinkedList L)//测量链表结点个数
{
    int k = 0;
    while(L != NULL)
    {
        k++;
        L = L->next;
    }
    return k;
}

int InputNumber()
{
	int num = 0; //存储已转换的数
	int status = 0; // 标志状态
	char str[100]; // 接收字符串
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			// 检查输入是否符合规范
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')
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
			printf("输入有误,请重新输入:");
		}
		else
		{
			int i = 0;
			// 将字符串转换成整型数据
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
			// 检查输入的数据有无越界
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
    DuLinkedList head; // Head of DuLinkedList.
    int flag = 0; // Whether exist DuLinkedList.
    while(SUCCESS)
    {
        system("cls");
        printf("\n---------------------------\n");
        printf(">>> 1.创建新链表                 \n");
        printf(">>> 2.输出链表                   \n");
        printf(">>> 3.初始化链表                 \n");
        printf(">>> 4.删除链表                   \n");
        printf(">>> 5.插入新结点                 \n");
        printf(">>> 6.删除结点                   \n");
        printf(">>> 7.查找某位置的结点           \n");
        printf(">>> 8.查找中间结点               \n");
        printf(">>> 9.判断成环                   \n");
        printf(">>> 10.逆转链表                  \n");
        printf(">>> 11.Exit.                     \n");
        printf("---------------------------\n");
        if(flag)
        {
            TraverseList_DuL(head, visit); // 打印链表
        }
        else
        {
            printf("No LinkedList.\n");
        }
        printf("---------------------------\n");
        printf("----->>> 请选择:");
        switch(InputNumber())
        {
        case 1:
            {
                int n;
                printf("请输入链表的结点个数:");
                scanf("%d", &n);
                head = Create(n);
                flag = 1;
                break;
            }
        case 2:
            if(flag)
            {
                TraverseList_DuL(head, visit);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 3:
            head = InitList_DuL(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList_DuL(head);
                flag = 0;
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 5:
            if(flag)
            {
                head = Insert_Node(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 6:
            if(flag)
            {
                int x;
                printf("请输入删除的元素值:");
                scanf("%d", &x);
                head = DeleteList_DuL(head, x);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 7:
            if(flag)
            {
                int i;
                DuLinkedList temp;
                printf("请输入查找的位置:");
                scanf("%d", &i);
                temp = SearchList(head, i);
                printf("在位置%d的元素值是%d\n",i,temp->data);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 8:
             if(flag)
            {
                DuLinkedList mid, temp = head;
                mid = FindMidNode(head);           //用mid来接收函数的返回值
                if(DuLinkedList_length(head)%2 == 0)
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
        case 9:
            if(flag)
            {
                IsLoopList_DuL(head);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 10:
            if(flag)
            {
                head = ReverseList_DuL(head);
            }
            else
            {
                printf("链表不存在\n");
            }
            break;
        case 11:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}

