#include<stdio.h>
#include<Windows.h>//��ֹ����һ������
#include<malloc.h>
#include "LinkStack.h"

int main()
{
    LinkStack s;
    int i=1;
    ElemType x;
    Init_LinkStack(s);
    //Push(s,2);
    for(x=1;x<5;x++)
    {
        Push(s,x);
    }
    //Display_LinkStack(s);
    while(i)//��֤һֱ����
    {
        printf("��ǰ��˳��ջ���£���Ϊ�ף���Ϊ������\n");
        Display_LinkStack(s);
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   ��ջ    \n");
        printf("    2   ��ջ   \n");
        printf("    3   ��ȡջ��Ԫ��   \n");
        printf("    4   ����   \n");
        printf("    0   ��������      \n");
        printf("------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1, 2, 3, 4, 0>:\n");
       switch(InputNumber())
        {
        case 1:
            printf("�������ջԪ�أ�");
            scanf("%d",&x);
            Push(s,x);
            //Display_SeqStack(&s);
            printf("\n\n");
            break;
        case 2:
            Pop(s);
            //Display_SeqStack(&s);
            printf("\n\n");
            break;
        case 3:
            printf("ջ��Ԫ��Ϊ��");
            GetTop(s);
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


