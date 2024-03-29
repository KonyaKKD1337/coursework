#include "list.h"

char *full_name(Node *MyNode)
{
    return MyNode->full_name;
}
char *model(Node *MyNode)
{
    return MyNode->model;
}
char *year(Node *MyNode)
{
    char *s=NULL;
    if ((s=(char*)malloc(30*sizeof(char)))!=NULL)
    {
        sprintf(s,"%d",MyNode->year);
    }
    else s=NULL;

    return s;
}
char *season(Node *MyNode)
{
    char *s=NULL;
    if ((s=(char*)malloc(30*sizeof(char)))!=NULL)
    {
        sprintf(s,"%d",MyNode->season);
    }
    else s=NULL;

    return s;
}
char *retail_price(Node *MyNode)
{
    char *s=NULL;
    if ((s=(char*)malloc(30*sizeof(char)))!=NULL)
    {
        sprintf(s,"%.2f",MyNode->retail_price);
    }
    else s=NULL;

    return s;
}
char *resell_price(Node *MyNode)
{
    char *s=NULL;
    if ((s=(char*)malloc(30*sizeof(char)))!=NULL)
    {
        sprintf(s,"%.2f",MyNode->resell_price);
    }
    else s=NULL;

    return s;
}

Node *FindNodeById(Head *MyHead, int d)
{
    Node *B=NULL;

    B=MyHead->first;
    while (B->id!=d) B=B->next;

    return B;
}

int FindNodesByField(Head *MyHead, char *(*Fname)(Node *MyNode), int d, char *s, int *A)
{
    Node *B;
    char *C=NULL;
    int i,key,m,len1,len2,k;

    m=0;
    key=1;
    B=MyHead->first;
    do
    {
        if ((C=Fname(B))!=NULL)
        {
            if ((d==4)||(d==5))
            {
                len2=-1;
                len1=strlen(C);
                for (i=0;i<len1;i++)
                    if (C[i]==',')
                    {
                        len2=i;
                        i=len1;
                    }
                k=0;
                if (len2!=-1)
                {
                    for (i=len1-1;i>len2;i--)
                    {
                        if (C[i]=='0') k++;
                        else i=len2;
                    }
                }
                if (len2!=-1)
                    if (len1-k-1==len2) k=k+1;
                k=len1-k;
            }
            else k=strlen(C);

            if ((strncmp(C,s,k)==0)&&(k==strlen(s)))
            {
                NodePrint(B);
                puts("");
                m++;
            }
            B=B->next;
            if ((d!=0)&&(d!=1)) free(C);
        }
        else
        {
            key=-1;
            m=-1;
        }
    }
    while ((B!=NULL)&&(key!=-1));

    return m;
}

int Sort1_6(Head *MyHead, Node *B, char *(*Fname)(Node *MyNode), int d, int k, int *A)
{
    Node *H;
    char *C=NULL;
    char *D=NULL;
    int i,j,key,c,m;

    key=1;
    for (i=0;i<MyHead->cnt-1;i++)
    {
        B=MyHead->first;
        for (j=0;j<MyHead->cnt-1;j++)
        {
            if ((C=Fname(B))!=NULL)
            {
                if ((D=Fname(B->next))!=NULL)
                {
                    if (k==0)
                    {
                        if ((((d==0)||(d==1))&&(strcmp(C,D)>0))||((d!=0)&&(d!=1)&&(strlen(C)>strlen(D)))||((d!=0)&&(d!=1)&&(strlen(C)==strlen(D))&&(strcmp(C,D)>0)))
                        {
                            H=B->next;
                            B->next=B->next->next;
                            H->next=B;
                            H->id=j+1;
                            if (j==0) MyHead->first=H;
                            if (j!=0)
                            {
                                B=FindNodeById(MyHead,j);
                                B->next=H;
                            }

                            c=A[j]; // ��������� ������� size ����� ������������
                            A[j]=A[j+1];
                            A[j+1]=c;

                            H=FindNodeById(MyHead,j+1);
                            m=H->id; // ��������� ������� ����� ������������
                            while (H->next)
                            {
                                H->next->id=m+1;
                                H=H->next;
                                m++;
                            }

                            B=FindNodeById(MyHead,j+1);
                        }
                        B=B->next;
                    }
                    else if (k==1)
                    {
                        if ((((d==0)||(d==1))&&(strcmp(C,D)<0))||((d!=0)&&(d!=1)&&(strlen(C)<strlen(D)))||((d!=0)&&(d!=1)&&(strlen(C)==strlen(D))&&(strcmp(C,D)<0)))
                        {
                            H=B->next;
                            B->next=B->next->next;
                            H->next=B;
                            H->id=j+1;
                            if (j==0) MyHead->first=H;
                            if (j!=0)
                            {
                                B=FindNodeById(MyHead,j);
                                B->next=H;
                            }

                            c=A[j]; // ��������� ������� size ����� ������������
                            A[j]=A[j+1];
                            A[j+1]=c;

                            H=FindNodeById(MyHead,j+1);
                            m=H->id; // ��������� ������� ����� ������������
                            while (H->next)
                            {
                                H->next->id=m+1;
                                H=H->next;
                                m++;
                            }

                            B=FindNodeById(MyHead,j+1);
                        }
                        B=B->next;
                    }
                    if ((d!=0)&&(d!=1))
                    {
                        free(C);
                        free(D);
                    }
                }
                else
                {
                    free(C);
                    j=MyHead->cnt;
                    i=MyHead->cnt-1;
                    key=0;
                }
            }
            else
            {
                j=MyHead->cnt;
                i=MyHead->cnt-1;
                key=0;
            }
        }
    }
    KartPrint(MyHead,B);

    return key;
}
