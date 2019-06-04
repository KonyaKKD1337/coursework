#include "list.h"

void InsertAfter(Head *MyHead, Node *NewNode, int n)
{
    Node *MyNode=NULL;

    MyNode=MyHead->first;
    if (n!=1)
    {
        while (MyNode->id!=n-1) MyNode=MyNode->next;
    }

    if (MyNode!=NULL)
    {
        if (MyNode->next==NULL)
        {
            MyNode->next=NewNode;
            MyHead->last=NewNode;
        }
        else if (n!=1)
        {
            NewNode->next=MyNode->next;
            MyNode->next=NewNode;
        }
        else if (n==1)
        {
            NewNode->next=MyNode;
            MyHead->first=NewNode;
        }
    }
    else
    {
        NewNode->next=MyNode;
        MyHead->first=NewNode;
    }

    MyHead->cnt++;
    if (n!=1) MyNode->next->id=n;
}

void ChangeAfterInsert(Head *MyHead, int d, int *A)
{
    Node *B;
    int i,m;

    B=FindNodeById(MyHead,d);
    m=B->id; // изменение номеров после вставки
    while (B->next)
    {
        B->next->id=m+1;
        B=B->next;
        m++;
    }

    m=A[MyHead->cnt-1]; // перестановка счетчиков массива size после вставки элемента списка
    for (i=MyHead->cnt-2; i>d-2; i--) A[i+1]=A[i];
    A[d-1]=m;
}

void DeleteNode(Head *MyHead, int d)
{
    Node *B, *q, *MyNode=NULL;

    B=MyHead->first;
    q=MyHead->last;

    MyNode=FindNodeById(MyHead,d);

    if (MyNode==B)
    {
        MyHead->first=MyNode->next;
        MyNode->next=NULL;
        free(MyNode);
    }
    else
    {
        do
        {
            if(B->next==MyNode)
            {
                if(MyNode==q) MyHead->last=B;
                B->next=MyNode->next;
                MyNode->next=NULL;
                free(MyNode);
                B=NULL;
            }
            else B=B->next;
        }
        while (B!=NULL);
    }
    MyHead->cnt--;
    puts("Element deleted successfully");
}

void ChangeAfterDelete(Head *MyHead, int d, int *A)
{
    Node *B;
    int i;

    if (d!=MyHead->cnt+1)
    {
        for (i=d-1;i<MyHead->cnt+1;i++) A[i]=A[i+1]; // перестановка счетчика массива size после удаления элемента списка

        B=FindNodeById(MyHead,d+1);
        for (i=d;i<=MyHead->cnt;i++)
        {
            B->id=i;
            B=B->next;
        } // изменение номеров элементов после удаления
    }
}
