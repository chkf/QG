#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

int data[100001];
int dummy[100001];
int temp[100001];

void read_data(void)
{
    int i;
    FILE *fp;
    fp = fopen("data.txt","r");
    if (fp == NULL)
    {
        printf("Error: can't open file data.txt");
    }
    while(fscanf(fp, "%d\n", &data[i++]) != EOF);
    fclose(fp);
}

//在data.txt中用时间伪随机生成10000个数，用于测试排序算法的效率
void create_data(void)
{
    int i;
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL)
    {
        printf("Error: can't open file data.txt");
    }
    for(i=0;i<10000;i++)
    {
        fprintf(fp,"%d\n",rand());
    }
    fclose(fp);
}

void showcmdlist(void)
{
    system("cls");
    printf("input command>");
    printf("1:insertSort\n");
    printf("3:MergeSort\n");
    printf("4:QuickSort_Recursion\n");
    printf("5:QuickSort\n");
    printf("6:Partition\n");
    printf("7:CountSort\n");
    printf("8:RadixCountSort\n");
    printf("9:ColorSort\n");
    printf("8:exit\n");
    printf("input command>");
}


//把数组data的数据和answer.txt中的数据进行对比，全对返回1
int check(void)
{
    int i=0;
    FILE *fp;
    fp = fopen("answer.txt","r");
    while(fscanf(fp, "%d\n", &temp[i++]) != EOF)
    {
        if(temp[i-1]!=data[i-1])
        {
            fclose(fp);
            printf("%d",i);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}



int main ()
{   
    FILE *fp;
    int i = 0,command;
    while(1)
    {
        printf("press enter to continue");
        getch();
        showcmdlist();
        scanf("%d",&command);
        switch(command)
        {
            case 1:
                read_data();
                insertSort(data,10000);                               //调用插入排序算法
                printf("InsertSort: ");
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                break;
            case 2:
                read_data();
                MergeArray(data,0,5000,10000,dummy);                         //调用归并排序算法
                printf("MergeSort: ");
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                break;
            case 3:
                read_data();
                MergeSort(data,0,9999,dummy);                               //调用归并排序算法
                printf("MergeSort: ");
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                break;
            case 4:
                read_data();
                QuickSort_Recursion(data,0,9999);                               //调用快速排序算法
                printf("QuickSort_Recursion: ");
                for(i=0;i<10000;i++)
                {

                }
                break;
            case 5:
                read_data();
                QuickSort(data,10000);                               //调用快速排序算法
                printf("QuickSort: ");
                for(i=0;i<10000;i++)
                {

                }
                break;
            case 6:
                read_data();
                Partition(data,0,99);                               //调用快速排序算法
                printf("Partition: ");
                for(i=0;i<10000;i++)
                {

                }
                break;
            case 7:
                read_data();
                CountSort(data,100,90000);                               //调用计数排序算法
                printf("CountSort: ");
                for(i=0;i<10000;i++)
                {

                }
                break;
            case 8:
                read_data();
                RadixCountSort(data,100);                               //调用基数排序算法
                printf("RadixCountSort: ");
                for(i=0;i<10000;i++)
                {

                }
                break;
            case 9:
                read_data();
                ColorSort(data,100);                               //调用颜色排序算法
                printf("ColorSort: ");
                for(i=0;i<10000;i++)
                {

                }
                break;          
            case 10:
                return 0;
                break;
            default:
                printf("Error: command not found");
                break;
        }
    }
}