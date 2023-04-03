#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <windows.h>
#include <conio.h>
#include <time.h>

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

//��data.txt����ʱ��α�������10000���������ڲ��������㷨��Ч��
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
    printf("2:MergeSort\n");
    printf("3:QuickSort_Recursion\n");
    printf("4:CountSort\n");
    printf("5:exit\n");
    printf("input command>");
}


//������data�����ݺ�answer.txt�е����ݽ��жԱȣ�ȫ�Է���1
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
    clock_t start,end;
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
                start=clock();
                insertSort(data,10000);                               //���ò��������㷨
                end=clock();
                printf("time:%dms\n",end-start);
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                break;
            case 2:
                read_data();
                start=clock();
                MergeSort(data,0,9999,dummy);                               //���ù鲢�����㷨
                end=clock();
                printf("time:%dms\n",end-start);
                printf("MergeSort: ");
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                printf("MergeSort: ");
                for(i=0;i<100;i++)
                    printf("%d ",data[i]);
                break;
            case 3:
                read_data();
                start=clock();
                QuickSort_Recursion(data,0,9999);                               //���ÿ��������㷨
                end=clock();
                printf("time:%dms\n",end-start);
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                for(i=0;i<100;i++)
                    printf("%d ",data[i]);
                break;
            case 4:
                read_data();
                start=clock();
                CountSort(data,10000,999999);                               //���ü��������㷨
                end=clock();
                printf("time:%dms\n",end-start);
                if(check())
                    printf("Correct\n");
                else
                    printf("Wrong\n");
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Error: command not found");
                break;
        }
    }
}