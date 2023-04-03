#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)                       
{
    int i,j,temp;                                   
    for(i=1;i<n;i++)                                //从第二个元素开始遍历
    {
        temp=a[i];                                  //将当前元素存入临时变量
        for(j=i-1;j>=0&&a[j]>temp;j--)              //从当前元素的前一个元素开始向前遍历，直到找到比当前元素小的元素
        {
            a[j+1]=a[j];                            //将比当前元素大的元素后移
        }
        a[j+1]=temp;                                //将当前元素插入到合适的位置
    }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{

}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin<end)                                   //如果数组中只有一个元素，则不需要排序
    {
        int mid=(begin+end)/2;                      //将数组分为两部分
        MergeSort(a,begin,mid,temp);                //对左边数组进行排序
        MergeSort(a,mid+1,end,temp);                //对右边数组进行排序
        MergeArray(a,begin,mid,end,temp);           //将两个数组合并
    }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
    if(begin<end)
    {
        int i=begin,j=end,temp=a[begin];
        while(i<j)
        {
            while(i<j&&a[j]>=temp)
            {
                j--;
            }
            if(i<j)
            {
                a[i++]=a[j];
            }
            while(i<j&&a[i]<=temp)
            {
                i++;
            }
            if(i<j)
            {
                a[j--]=a[i];
            }
        }
        a[i]=temp;
        QuickSort_Recursion(a,begin,i-1);
        QuickSort_Recursion(a,i+1,end);
    }
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)
{

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{

}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
    int i,j;
    int *count=(int *)malloc(sizeof(int)*(max+1));
    int *temp=(int *)malloc(sizeof(int)*size);
    for(i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for(i=0;i<size;i++)
    {
        count[a[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        temp[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    for(i=0;i<size;i++)
    {
        a[i]=temp[i];
    }
    free(count);
    free(temp);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
    int i,j;
    int *count=(int *)malloc(sizeof(int)*10);
    int *temp=(int *)malloc(sizeof(int)*size);
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(i=0;i<size;i++)
    {
        count[a[i]%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        temp[count[a[i]%10]-1]=a[i];
        count[a[i]%10]--;
    }
    for(i=0;i<size;i++)
    {
        a[i]=temp[i];
    }
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(i=0;i<size;i++)
    {
        count[a[i]/10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        temp[count[a[i]/10]-1]=a[i];
        count[a[i]/10]--;
    }
    for(i=0;i<size;i++)
    {
        a[i]=temp[i];
    }
    free(count);
    free(temp);
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
    
}
