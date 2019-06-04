#include "list.h"

Head *MakeHead()
{
    Head *A=NULL;

    if ((A=(Head*)malloc(sizeof(Head)))!=NULL)
    {
        A->cnt=0;
        A->first=NULL;
        A->last=NULL;
    }

    return A;
}

Node *MakeNode()
{
    Node *B=NULL;

    if ((B=(Node*)malloc(sizeof(Node)))!=NULL)
    {
        if ((B->full_name=(char*)malloc(M*sizeof(char)))!=NULL)
        {
            if ((B->model=(char*)malloc(M*sizeof(char)))!=NULL)
            {
                if ((B->size=(int*)malloc(N*sizeof(int)))!=NULL)
                {
                    B->id=1;
                    B->next=NULL;
                }
                else
                {
                    free(B);
                    free(B->full_name);
                    free(B->model);
                    B=NULL;
                }
            }
            else
            {
                free(B);
                free(B->full_name);
                B=NULL;
            }
        }
        else
        {
            free(B);
            B=NULL;
        }
    }

    return B;
}

void NodePrint(Node *B)
{
    int i;
    printf("%20s | %9s | %5d |  %3d   | %12.2f | %12.2f |", B->full_name, B->model, B->year, B->season, B->retail_price, B->resell_price);

    for (i=0; i<4; i++)
        printf("  %2d |", B->size[i]);
}

void KartPrint(Head *MyHead, Node *B)
{
    int i;
    if (MyHead->first!=NULL)
    {
        printf("+--------------------+-----------+-------+--------+--------------+--------------+-----+-----+-----+-----+");
        printf("\n|%20s|%11s|%7s|%8s|%8s|%7s|%5s|%5s|%5s|%5s|\n"," Full name "," Model "," Year "," Season "," Retail price "," Resell price "," S "," M "," L "," XL ");
        printf("+--------------------+-----------+-------+--------+--------------+--------------+-----+-----+-----+-----+\n");
        B=MyHead->first;
        for (i=0;i<MyHead->cnt;i++)
        {
            NodePrint(B);
            printf("\n");
            B=B->next;
        }
        puts("");
    }
    else puts("     | File EMPTY |\n");
}

void clearNode(Head *MyHead, Node *B)
{
    B=MyHead->first;
    while (B!=NULL)
    {
        free(B->full_name);
        free(B->model);
        free(B->size);
        free(B);
        B=B->next;
    }
    free(MyHead);
}
