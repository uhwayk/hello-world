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
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < len; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
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
			t[bucket[a[i] / base % 10] - 1] = a[i];  //原始序列中最后一个数据，放在新序列下标为 bucket[a[i] / base % 10] - 1 的地方。
			bucket[a[i] / base % 10]--;
		}
		for (i = 0; i < length; i++)
		{
			a[i] = t[i];
		}

		base = base * 10;
	}
}
