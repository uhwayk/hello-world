#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"


int main()
{
	pLinkQueue Queue;
	int delVal = 0;
	int i=1;

	Queue =  CreatLinkQueue();//������ʽ����
	printf("\r\n");
    int x;
    for(x=1;x<=5;x++){
    	EnterLinkQueue(Queue,x);
	}
	
	while(i)//��֤һֱ����
    {
        printf("��ǰ�Ķ�������:\n");
        TraverseLinkQueue(Queue); 
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   �������    \n");
        printf("    2   ���ݳ���   \n");
        printf("    3   ��ն���   \n");
        printf("    4   ����   \n");
        printf("    0   ��������      \n");
        printf("------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1, 2, 3, 4, 5��0>:\n");
        switch(InputNumber())
        {
        case 1:
            printf("���������Ԫ�أ�");
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
            printf("���������!");
            printf("\n\n");
            break;
        case 4:
            system("cls");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("��������~\n");
            break;
        }
    }
    return 0;

}

