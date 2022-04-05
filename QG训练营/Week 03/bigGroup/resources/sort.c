#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#define MAX 100000


void InsertSort(int a[], int len)
{
    int i,j,temp;
        for (i=1;i<len;i++){
                temp = a[i];
                j=i-1;
                while((j>=0) && (a[j]>temp)) {
                        a[j+1] = a[j];
                        j--;
                }
                a[j+1] = temp;
        }
}


void merge(int a[],int l,int r,int mid)
{
  int aux[r-l+1],i,j,k;

  for(k=l;k<=r;k++)
  aux[k-l]=a[k];

  i=l;
  j=mid+1;
  for(k=l;k<=r;k++)
  {
  	if(i>mid)
  	{
  		a[k]=aux[j-l];
  		j++;
	  }
	else if(j>r)
	{
		a[k]=aux[i-l];
		i++;
	  }
	else if(aux[i-l]>aux[j-l])
	{
		a[k]=aux[j-l];
		j++;
		}
	else
	{
		a[k]=aux[i-l];
		i++;
			}


	  }

}

void merge_sort(int a[],int l,int r)
{
    if(l>=r)
	return ;

	int mid=(l+r)/2;

	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,l,r,mid);

}

void MergeSort(int a[],int l,int r)
{
	merge_sort(a,l,r-1);
}

void QuickSort(int *arr, int begin, int end)
{
    if(begin > end)
        return;
    int tmp = arr[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];
    arr[i] = tmp;
    QuickSort(arr, begin, i-1);
    QuickSort(arr, i+1, end);
}


void CountSort(int *a, int len)
{
	assert(a);
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (int i = 0; i < len; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;
}

void RadixSort(int *a, int length)
{
	int i, max = a[0], base = 1;;
	for (i = 1; i < length; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int *t = (int *)malloc(sizeof(int) * length);
	while (max / base > 0)
	{
		int bucket[10] = {0};

		for (i = 0; i < length; i++)
		{
			bucket[a[i] / base % 10]++;
		}
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (i = length - 1; i >= 0; i--)
		{
			t[bucket[a[i] / base % 10] - 1] = a[i];  //ԭʼ���������һ�����ݣ������������±�Ϊ bucket[a[i] / base % 10] - 1 �ĵط���
			bucket[a[i] / base % 10]--;
		}
		for (i = 0; i < length; i++)
		{
			a[i] = t[i];
		}

		base = base * 10;
	}
}
