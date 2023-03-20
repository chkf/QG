#include "main.h"

LinkedList head;

int main()
{
    int command,j,i,newdata,deleteddata;
    bool res,mark;
    LinkedList p,q,end,MidNode,newnode;
    showcomlist();
    printf("����ָ����>");
    while (1)
    {   
        my_scanf(&command,"����Ĳ���ָ�����������>",false);
        switch (command)
        {
            case 1:
                res = InitList(&head);
                if(res)
                {
                    end=head;                                           //��ָ��ͷ���
                    showcomlist();
                    printf("����ͷ��㴴���ɹ�\n");
                    printf("�����ʼ����,��'-1'����>");
                    my_scanf(&newdata,"���������ʼ����,��'-1'����>",true);
                    while(newdata!=-1)
                    {   
                        newnode = (LNode*)malloc(sizeof(LNode));
                        newnode->data = newdata;                              //��������
                        res = InsertList(end, newnode);                                      
                        end=newnode;                                          //βָ��ָ���½��              
                        res_react(res,"�����ʼ����,��'-1'����>");
                        my_scanf(&newdata,"���������ʼ����,��'-1'����>",true);
                    }
                    showcomlist();
                    printf("�����ʼ���ɹ�\n");
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("����ָ����>");
                }
                else
                {
                    showcomlist();
                    printf("������ʧ�ܣ�����ָ��>");
                }
                break;
            case 2:
                if(!headcheck(false));
                else
                {
                    DestroyList(&head);
                    showcomlist();
                    printf("����ɾ���ɹ�������ָ��>");
                }
                break;
            case 3:
                if(!headcheck(false));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("\n�������λ��>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"�����������λ��>",true);
                        p=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("����λ�ô���\n");
                            printf("�����������λ��>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            p=p->next;
                            if(p==NULL||p->next==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("����λ�ô���\n�����������λ��>");
                                break;
                            }
                        }
                    }
                    printf("\n�����������>");
                    my_scanf(&newdata,"���������������>",true);
                    newnode = (LNode*)malloc(sizeof(LNode));
                    newnode->data=newdata;
                    res = InsertList(p, newnode);
                    res_react(res,"����ָ����>");
                }
                break;
            case 4:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("\n����ɾ�����>");
                    mark=false;
                    while(!mark)
                    {
                        my_scanf(&j,"��������ɾ�����>",true);
                        j--;
                        p=head;
                        if(j<0)
                        {
                            showcomlist();
                            printf("ɾ��������\n��������ɾ�����>");
                        }
                        else mark=true;                                 
                        for(i=0;i<j&&mark==true;i++)
                        {
                            p=p->next;
                            if(p->next==NULL||p==NULL)
                            {
                                showcomlist();
                                mark=false;
                                printf("ɾ��������\n��������ɾ�����>");
                                break;
                            }
                        }
                    }
                    res = DeleteList(p,&deleteddata);
                    res_react(res,NULL);
                    if(res)
                        printf("��ɾ����������Ϊ%d\n",deleteddata);
                    printf("����ָ����>");    
                }
                break;
            case 5:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("����ָ����>");
                }
                break;
            case 6:
                if(!headcheck(true));
                else
                {
                    system("cls");
                    showcomlist();
                    printf("Ҫ���ҵ�����Ϊ>");
                    my_scanf(&j,"����Ҫ���ҵ�����>",false);
                    res = SearchList(head, j);
                    res_react(res,"����ָ����>");
                }
                break;
            case 7:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    #if ReverseList_use_algo 
                        res = ReverseList_algo(&head,head);
                    #else
                        res = ReverseList(&head);
                    #endif
                    if(res)
                    {
                        printf("��ת��,��ǰ����Ϊ��");
                        TraverseList(head, printvalue);
                        printf("����ָ����>");
                    }
                    else
                    {
                        res_react(res,"����ָ����>");
                    }
                }
                break;
            case 8:
                if(!headcheck(true));
                else
                {
                    res = IsLoopList(head);
                    if(res)
                    {
                        showcomlist();
                        printf("����ɻ�\n");
                    }
                    else
                    {
                        showcomlist();
                        printf("�����ɻ�\n");
                    }
                    printf("����ָ����>");
                }
                break;
            case 9:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("��ż������,");
                    head = ReverseEvenList(&head);
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("����ָ��>");
                }
                break;
            case 10:
                if(!headcheck(true));
                else
                {
                    showcomlist();
                    printf("��ǰ����Ϊ��");
                    TraverseList(head, printvalue);
                    printf("�м�ڵ�Ϊ:");
                    MidNode = FindMidNode(&head);
                    printvalue(MidNode->data);
                    printf("����ָ��>");
                }
                break;
            default:
                showcomlist();
                printf("����Ĳ���ָ�����������>");
                break;
        }
    }
    return 0;
}


void showcomlist(void)
{
    system("cls");
    printf("���������ָ��:\n");
    printf("\n");
    printf("    1:�½�������\n");
    printf("    2:ɾ������\n");
    printf("    3:����һ�����\n");
    printf("    4:ɾ��һ�����\n");
    printf("    5:������ȡ����\n");
    printf("    6:���ҽ��\n");
    printf("    7:��ת����\n");
    printf("    8:�ж��Ƿ�Ϊѭ������\n");
    printf("    9:������ż����\n");
    printf("    10:���м���\n");
    printf("\n");
}

/*visit ����*/
void printvalue(ElemType e)                               
{
    printf("%d->",e);
}

/*��ת����ݹ鷨*/
Status ReverseList_algo(LinkedList *L,LinkedList q)      //��ͷ��㴫�ݵ����
{
/***************************�ݹ�*******************************/
    if(!q)                                               //ֻ��ͷ���
    {                   
        return ERROR;
    }
    if(q->next==NULL)
    {
        (*L)->next=q;                                    //�ҵ����һ������ͷ���ָ����
        return SUCCESS;
    }
    ReverseList_algo(L,(q->next));
    if(q!=(*L))
    {
        q->next->next=q;                                 //��һ���ڵ�ָ��ǰһ����ǰһ�����ָ��NULL
        q->next=NULL;
    }
}

/*��ʾ�������*/
Status error_reshow(char * str,bool showlist)                          //�������ݴ���ʱ����������ʾ
{
    showcomlist();
    if(showlist)TraverseList(head, printvalue);
    printf("�������ݴ���\n");
    printf(str);
}

/*��ֹ�������룬�����ܼ������������������λ���Ƿ�Ϸ�*/
void my_scanf(ElemType * i,char * error_warn,bool showlist)                 //�������
{
    bool res=0;
    while(!res)
    {
        res=scanf("%d",i);
        while(getchar()!='\n'||!res)                     //�̵��ַ�����ֹ�ܷ�
        {
            error_reshow(error_warn,showlist);
        }
    }
}

/*Ӧ�Բ�ͬ�������ز�ͬ��statusֵ*/
void res_react(bool res,char * str)                     //����ɹ����Ҫ˵�Ļ�
{
    if(res)
    {
        showcomlist();
        printf("�����ɹ�");
        printf("��ǰ����Ϊ��");
        TraverseList(head, printvalue);
        if(str)printf(str);
    }
    else
    {
        showcomlist();
        printf("�����ˣ���\n");
        printf("��ǰ����Ϊ��");
        TraverseList(head, printvalue);
        if(str)printf(str);
    }
}

/*���ͷ����Ƿ���ڣ�Ҳ�ɼ���һ������Ƿ����*/
Status headcheck(bool checkfirst)
{
    if(head==NULL)
    {
        showcomlist();
        printf("�������ڣ�����ָ��>");
        return ERROR;
    }
    if(checkfirst)
    {
        if(head->next==NULL)
        {
            showcomlist();
            printf("����Ϊ�գ�����ָ��>");
            return ERROR;
        }
    }
    return SUCCESS;
}
