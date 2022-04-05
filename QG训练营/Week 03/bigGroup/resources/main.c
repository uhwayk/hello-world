#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include <unistd.h>
#define LENGTH1 10000//定义数组长度
#define LENGTH2 50000//定义数组长度
#define LENGTH3 200000//定义数组长度
#define LEN 100//定义数组长度③
#define MAX 1000

int main()
{
    int arr[LEN];//arr用来存储100个数据
    int j;
    double total_t;
    srand((unsigned)time(NULL));
    for(int i =0;i < LEN;++i ){
        arr[i] =  rand()% MAX;
    }

    int arr1[LENGTH1];//arr1用来存储10000个数据（层次一）
    srand((unsigned)time(NULL));
    for(int i =0;i < LENGTH1;++i ){
        arr1[i] =  rand()% MAX;
    }

     int arr2[LENGTH2];//arr2用来存储50000个数据（层次二）
    srand((unsigned)time(NULL));
    for(int i =0;i < LENGTH2;++i ){
        arr2[i] =  rand()% MAX;
    }

     int arr3[LENGTH3];//arr3用来存储200000个数据（层次三）
    srand((unsigned)time(NULL));
    for(int i =0;i < LENGTH3;++i ){
        arr3[i] =  rand()% MAX;
    }

    printf("用时测试：100个数据*100k次排序\n\n");
    clock_t start_time1=clock();
    //printf("%dms",start_time1);

    {
        for(j=0;j<100000;j++)//测试100000组数据
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
        InsertSort(arr,LEN);
    }

    clock_t end_time1=clock();
    //printf("%dms",end_time1);

    total_t = (double)(end_time1 - start_time1) / CLOCKS_PER_SEC;
    printf("插入排序算法用时: %fs\n",total_t);
    printf("\n");

   clock_t start_time2=clock();
   // printf("%dms",start_time2);
    {
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100000;j++)
          MergeSort(arr,0,LEN);
     }

    clock_t end_time2=clock();
   // printf("%dms",end_time2);

    total_t = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC;
    printf("归并排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time3=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100000;j++)
        QuickSort(arr,0,LEN);


    }

    clock_t end_time3=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time3 - start_time3) / CLOCKS_PER_SEC;
    printf("快速排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time4=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100000;j++)
          RadixSort(arr,LEN);

    }

    clock_t end_time4=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time4 - start_time4) / CLOCKS_PER_SEC;
    printf("基数排序算法用时: %fs\n",total_t);
    printf("\n");

    clock_t start_time5=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100000;j++)
          CountSort(arr,LEN);

    }

    clock_t end_time5=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time5 - start_time5) / CLOCKS_PER_SEC;
    printf("计数排序算法用时: %fs\n",total_t);
    printf("\n");

//---------------------------------------------------------------------------------------------------------------------------------------------
     printf("用时测试：数据量为10000\n\n");
    clock_t start_time6=clock();
    //printf("%dms",start_time1);

    {
        for(j=0;j<100;j++)//测试100组数据
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
        InsertSort(arr1,LENGTH1);
    }

    clock_t end_time6=clock();
    //printf("%dms",end_time1);

    total_t = (double)(end_time6 - start_time6) / CLOCKS_PER_SEC;
    printf("插入排序算法用时: %fs\n",total_t);
    printf("\n");

   clock_t start_time7=clock();
   // printf("%dms",start_time2);
    {
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          MergeSort(arr1,0,LENGTH1);
     }

    clock_t end_time7=clock();
   // printf("%dms",end_time2);

    total_t = (double)(end_time7 - start_time7) / CLOCKS_PER_SEC;
    printf("归并排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time8=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
        QuickSort(arr1,0,LENGTH1);


    }

    clock_t end_time8=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time8 - start_time8) / CLOCKS_PER_SEC;
    printf("快速排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time9=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          RadixSort(arr1,LENGTH1);

    }

    clock_t end_time9=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time9 - start_time9) / CLOCKS_PER_SEC;
    printf("基数排序算法用时: %fs\n",total_t);
    printf("\n");

    clock_t start_time10=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          CountSort(arr1,LENGTH1);

    }

    clock_t end_time10=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time10 - start_time10) / CLOCKS_PER_SEC;
    printf("计数排序算法用时: %fs\n",total_t);
    printf("\n");

    //----------------------------------------------------------------------------------------------------------------------------------------------
     printf("用时测试：数据量为50000\n\n");
    clock_t start_time11=clock();
    //printf("%dms",start_time1);

    {
        for(j=0;j<100;j++)//测试100组数据
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
        InsertSort(arr2,LENGTH2);
    }

    clock_t end_time11=clock();
    //printf("%dms",end_time1);

    total_t = (double)(end_time11 - start_time11) / CLOCKS_PER_SEC;
    printf("插入排序算法用时: %fs\n",total_t);
    printf("\n");

   clock_t start_time12=clock();
   // printf("%dms",start_time2);
    {
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          MergeSort(arr2,0,LENGTH2);
     }

    clock_t end_time12=clock();
   // printf("%dms",end_time2);

    total_t = (double)(end_time12 - start_time12) / CLOCKS_PER_SEC;
    printf("归并排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time13=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
        QuickSort(arr2,0,LENGTH2);


    }

    clock_t end_time13=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time13 - start_time13) / CLOCKS_PER_SEC;
    printf("快速排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time14=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          RadixSort(arr2,LENGTH2);

    }

    clock_t end_time14=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time14 - start_time14) / CLOCKS_PER_SEC;
    printf("基数排序算法用时: %fs\n",total_t);
    printf("\n");

    clock_t start_time15=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          CountSort(arr2,LENGTH2);

    }

    clock_t end_time15=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time15 - start_time15) / CLOCKS_PER_SEC;
    printf("计数排序算法用时: %fs\n",total_t);
    printf("\n");

        //----------------------------------------------------------------------------------------------------------------------------------------------

           printf("用时测试：数据量为200000\n\n");
    clock_t start_time16=clock();
    //printf("%dms",start_time1);

    {
        for(j=0;j<100;j++)//测试100组数据
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
        InsertSort(arr3,LENGTH3);
    }

    clock_t end_time16=clock();
    //printf("%dms",end_time1);

    total_t = (double)(end_time16 - start_time16) / CLOCKS_PER_SEC;
    printf("插入排序算法用时: %fs\n",total_t);
    printf("\n");

   clock_t start_time17=clock();
   // printf("%dms",start_time2);
    {
      //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          MergeSort(arr3,0,LENGTH3);
     }

    clock_t end_time17=clock();
   // printf("%dms",end_time2);

    total_t = (double)(end_time17 - start_time17) / CLOCKS_PER_SEC;
    printf("归并排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time18=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
        QuickSort(arr3,0,LENGTH3);


    }

    clock_t end_time18=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time18 - start_time18) / CLOCKS_PER_SEC;
    printf("快速排序算法用时: %fs\n",total_t);
    printf("\n");

     clock_t start_time19=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          RadixSort(arr3,LENGTH3);

    }

    clock_t end_time19=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time19 - start_time19) / CLOCKS_PER_SEC;
    printf("基数排序算法用时: %fs\n",total_t);
    printf("\n");

    clock_t start_time20=clock();
    //printf("%dms",start_time3);
    {
        //  bubbleSort(arr,N);
       // chioseSort(arr,N);
          for(j=0;j<100;j++)//测试100组数据
          CountSort(arr3,LENGTH3);

    }

    clock_t end_time20=clock();
   // printf("%dms",end_time3);

    total_t = (double)(end_time20 - start_time20) / CLOCKS_PER_SEC;
    printf("计数排序算法用时: %fs\n",total_t);
    printf("\n");

    return 0;



}
