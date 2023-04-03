#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)                       //取出temp和前一个比较，如果比前一个小，就再向前对比，直到站到合适的位置，所有有关的项先惠普移动一格，类似按高度排队
{
    int i,j,temp;                                   
    for(i=1;i<n;i++)                                
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
    int i=begin,j=mid+1,k=0;                        //i,j分别指向两个数组的起点，k指向承载数组的起点
    while(i<=mid&&j<=end)                           //当两个数组都没有遍历完时
    {
        if(a[i]<=a[j])                              //如果左边数组的元素小于右边数组的元素
        {
            temp[k++]=a[i++];                       //将左边数组的元素存入承载数组，并将左边数组的指针后移
        }
        else                                        //如果右边数组的元素小于左边数组的元素
        {
            temp[k++]=a[j++];                       //将右边数组的元素存入承载数组，并将右边数组的指针后移
        }
    }
    while(i<=mid)                                   //如果左边数组还有剩余元素
    {
        temp[k++]=a[i++];                           //将左边数组的元素存入承载数组，并将左边数组的指针后移
    }
    while(j<=end)                                   //如果右边数组还有剩余元素
    {
        temp[k++]=a[j++];                           //将右边数组的元素存入承载数组，并将右边数组的指针后移
    }
    for(i=0;i<k;i++)                                //将承载数组的元素复制到原数组
    {
        a[begin+i]=temp[i];
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)              //递归
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
void QuickSort_Recursion(int *a, int begin, int end)//两个下标往中间走，直到两个下标相遇，期间左边大于temp，右边小于temp，会与temp交换，然后递归，把数组细分
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
    int *count=(int *)malloc(sizeof(int)*(max+1));//计数数组
    int *temp=(int *)malloc(sizeof(int)*size);      //临时数组
    for(i=0;i<=max;i++)
    {
        count[i]=0;                                 //初始化计数数组
    }
    for(i=0;i<size;i++)
    {
        count[a[i]]++;                                  //计数
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];               //计数累加（从前往后）
    }
    for(i=size-1;i>=0;i--)
    {
        temp[count[a[i]]-1]=a[i];               //将元素放入临时数组
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
    
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
    
}
