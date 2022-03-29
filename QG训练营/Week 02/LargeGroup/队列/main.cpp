#include<stdio.h>
#include<Windows.h>//防止程序一闪而过
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
    while(i)//保证一直进行
    {
        printf("当前的顺序栈如下（下为底，上为顶）：\n");
        Display_LinkStack(s);
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   进栈    \n");
        printf("    2   出栈   \n");
        printf("    3   读取栈顶元素   \n");
        printf("    4   清屏   \n");
        printf("    0   结束程序      \n");
        printf("------------------------------------\n");
        printf("请输入你选择的菜单号<1, 2, 3, 4, 0>:\n");
       switch(InputNumber())
        {
        case 1:
            printf("请输入进栈元素：");
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
            printf("栈顶元素为：");
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
            printf("输入有误~\n");
            break;
        }
    }
    return 0;
}


