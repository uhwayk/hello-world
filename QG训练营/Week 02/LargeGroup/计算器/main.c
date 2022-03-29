#include <stdlib.h>
#include <stdio.h>
#include "Calculator.h"
#include <math.h>

int main()
{
	Stack num, opt;
	char str[100]={0};
	int i = 0, tmp = 0, j;
	int n;//n��Ϊ������������ļ�����

	if(InitStack(&num) != OK || InitStack(&opt) != OK)
	{
		printf("Init Failure!\n");
		exit(1);
	}

	printf("��������ֵ���ʽ:\n");
	scanf("%s",str);
	for(n=0;str[n]!='\0';n++){
        if(str[n]<'0'||str[n]>'9'&&str[n]!='+'&&str[n]!='-'&&str[n]!='*'&&str[n]!='/'&&str[n]!='('&&str[n]!=')'){
            printf("���벻�����������淶������������:");
            scanf("%s",str);
         }
        else
        {
            while(str[i] != '\0' || EmptyStack(&opt) != OK)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			tmp = tmp * 10 + str[i] - '0';
			i++;
			if(str[i] < '0' || str[i] > '9')
			{
				Push(&num,tmp);
				tmp = 0;
			}
		}
		else
		{
			if((EmptyStack(&opt) == OK) || (GetTop(&opt) == '(' && str[i] != ')') || Priority(str[i]) > Priority(GetTop(&opt)))//��ջ����������
			{
				Push(&opt,str[i]);
				i++;
				continue;
			}
			if(GetTop(&opt) == '(' && str[i] == ')')//��ջ����������
			{
				Pop(&opt);
				i++;
				continue;
			}
			if((str[i] == '\0' && EmptyStack(&opt) != OK) || (str[i] == ')' && GetTop(&opt) != '(') || Priority(str[i]) <= Priority(GetTop(&opt)))//��ջ����������
			{
				switch(Pop(&opt))
				{
					case '+':
						Push(&num, Pop(&num) + Pop(&num));
						break;
					case '-':
						j = Pop(&num);
						Push(&num, Pop(&num) - j);
						break;
					case '*':
						Push(&num, Pop(&num) * Pop(&num));
						break;
					case '/':
						j = Pop(&num);
						Push(&num, Pop(&num) / j);
				}
				continue;
			}
		}
	}

	printf("%d",Pop(&num));
        printf("\n");

        return 0;
}


        }
	}

