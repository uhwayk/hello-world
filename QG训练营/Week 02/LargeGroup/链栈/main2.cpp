#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"


int main()
{
	pLinkQueue Queue;
	int delVal = 0;
	int i=1;

	Queue =  CreatLinkQueue();//创建链式队列
	printf("\r\n");
    int x;
    for(x=1;x<=5;x++){
    	EnterLinkQueue(Queue,x);
	}
	
	while(i)//保证一直进行
    {
        printf("当前的队列如下:\n");
        TraverseLinkQueue(Queue); 
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   数据入队    \n");
        printf("    2   数据出队   \n");
        printf("    3   清空队列   \n");
        printf("    4   清屏   \n");
        printf("    0   结束程序      \n");
        printf("------------------------------------\n");
        printf("请输入你选择的菜单号<1, 2, 3, 4, 5，0>:\n");
        switch(InputNumber())
        {
        case 1:
            printf("请输入入队元素：");
            scanf("%d",&x);
            EnterLinkQueue(Queue,x);
            printf("\n\n");
            break;
        case 2:
            OutLinkQueue(Queue); 
            //Display_SeqStack(&s);
            printf("\n\n");
            break;
        case 3:
        	int InitLinkQueue(pLinkQueue Q);
            printf("队列已清空!");
            printf("\n\n");
            break;
        case 4:
            system("cls");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误~\n");
            break;
        }
    }
    return 0;

}

