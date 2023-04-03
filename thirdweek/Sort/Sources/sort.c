#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)                       //ȡ��temp��ǰһ���Ƚϣ������ǰһ��С��������ǰ�Աȣ�ֱ��վ�����ʵ�λ�ã������йص����Ȼ����ƶ�һ�����ư��߶��Ŷ�
{
    int i,j,temp;                                   
    for(i=1;i<n;i++)                                
    {
        temp=a[i];                                  //����ǰԪ�ش�����ʱ����
        for(j=i-1;j>=0&&a[j]>temp;j--)              //�ӵ�ǰԪ�ص�ǰһ��Ԫ�ؿ�ʼ��ǰ������ֱ���ҵ��ȵ�ǰԪ��С��Ԫ��
        {
            a[j+1]=a[j];                            //���ȵ�ǰԪ�ش��Ԫ�غ���
        }
        a[j+1]=temp;                                //����ǰԪ�ز��뵽���ʵ�λ��
    }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i=begin,j=mid+1,k=0;                        //i,j�ֱ�ָ�������������㣬kָ�������������
    while(i<=mid&&j<=end)                           //���������鶼û�б�����ʱ
    {
        if(a[i]<=a[j])                              //�����������Ԫ��С���ұ������Ԫ��
        {
            temp[k++]=a[i++];                       //����������Ԫ�ش���������飬������������ָ�����
        }
        else                                        //����ұ������Ԫ��С����������Ԫ��
        {
            temp[k++]=a[j++];                       //���ұ������Ԫ�ش���������飬�����ұ������ָ�����
        }
    }
    while(i<=mid)                                   //���������黹��ʣ��Ԫ��
    {
        temp[k++]=a[i++];                           //����������Ԫ�ش���������飬������������ָ�����
    }
    while(j<=end)                                   //����ұ����黹��ʣ��Ԫ��
    {
        temp[k++]=a[j++];                           //���ұ������Ԫ�ش���������飬�����ұ������ָ�����
    }
    for(i=0;i<k;i++)                                //�����������Ԫ�ظ��Ƶ�ԭ����
    {
        a[begin+i]=temp[i];
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)              //�ݹ�
{
    if(begin<end)                                   //���������ֻ��һ��Ԫ�أ�����Ҫ����
    {
        int mid=(begin+end)/2;                      //�������Ϊ������
        MergeSort(a,begin,mid,temp);                //����������������
        MergeSort(a,mid+1,end,temp);                //���ұ������������
        MergeArray(a,begin,mid,end,temp);           //����������ϲ�
    }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)//�����±����м��ߣ�ֱ�������±��������ڼ���ߴ���temp���ұ�С��temp������temp������Ȼ��ݹ飬������ϸ��
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)
{

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{

}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
    int i,j;
    int *count=(int *)malloc(sizeof(int)*(max+1));//��������
    int *temp=(int *)malloc(sizeof(int)*size);      //��ʱ����
    for(i=0;i<=max;i++)
    {
        count[i]=0;                                 //��ʼ����������
    }
    for(i=0;i<size;i++)
    {
        count[a[i]]++;                                  //����
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];               //�����ۼӣ���ǰ����
    }
    for(i=size-1;i>=0;i--)
    {
        temp[count[a[i]]-1]=a[i];               //��Ԫ�ط�����ʱ����
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
    
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
    
}
