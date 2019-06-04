#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#define M 124
#define N 10

int main()
{


    Head *p0=NULL;
    Node *p=NULL;
    char *(*kindF[6])(Node *);
    char s[M];
    int A[100];
    int key1,key2;
    int n,m,c,v,d,k;

    kindF[0]=full_name;
    kindF[1]=model;
    kindF[2]=year;
    kindF[3]=season;
    kindF[4]=retail_price;
    kindF[5]=resell_price;

    p0=MakeHead();
    if (p0)
    {
        key1=0;
        key1=ReadFile(p0,p,A,&n);
        if (key1==1)
        {
            puts("\tHere is virtual database program");
            do
            {
                c=menu_main(); // основное меню
                if (c!=-1)
                {
                    key2=1;
                    switch (c)
                    {
                        case 1:
                        {
                            do
                            {
                                v=menu_1(); // редактирование
                                if (v!=-1)
                                {
                                    switch (v)
                                    {
                                        case 1: // добавление
                                        {
                                            printf("Specify number of row for adding - ");
                                            n++;
                                            d=scanID(&n);
                                            n--;
                                            if (d!=-1)
                                            {
                                                puts("Input of an element. Input through \';\'\n");
                                                p=ReadNode(s,&(A[n]));
                                                if (p!=NULL)
                                                {
                                                    InsertAfter(p0,p,d);
                                                    puts("Element adding completed successfully");
                                                    ChangeAfterInsert(p0,d,A);
                                                    n++;
                                                }
                                                else
                                                {
                                                    key2=0;
                                                    key1=0;
                                                    free(p);
                                                    clearNode(p0,p);
                                                }
                                            }
                                            else
                                            {
                                                key2=0;
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                        case 2: // удаление
                                        {
                                            if (n==0) puts("Deleting can\'t be done, not enough elements");
                                            else
                                            {
                                                printf("Specify element number, which you want to delete - ");
                                                d=scanID(&n);
                                                if (d!=-1)
                                                {
                                                    DeleteNode(p0,d);
                                                    n--;
                                                    ChangeAfterDelete(p0,d,A);
                                                }
                                            }
                                        }
                                            break;
                                        case 3: // изменение
                                        {
                                            if (n==0) puts("Editing can\'t be done, there are no elements to delete");
                                            else
                                            {
                                                printf("Specify element number, which you want to edit - ");
                                                d=scanID(&n);
                                                if (d!=-1)
                                                {
                                                    k=Read_Field(s);
                                                    printf("Enter new value of the field: ");
                                                    Read_Value(s);
                                                    p=p0->first;
                                                    m=ChangeValue(p,s,d,k);
                                                    if (m!=-1)
                                                    {
                                                        if (k==6) A[d-1]=m;
                                                    }
                                                    else
                                                    {
                                                        key2=0;
                                                        key1=0;
                                                        clearNode(p0,p);
                                                    }
                                                }
                                                else
                                                {
                                                    key2=0;
                                                    key1=0;
                                                    clearNode(p0,p);
                                                }
                                            }
                                        }
                                            break;

                                        default:
                                            break;
                                    }

                                    if (key2==1)
                                    {
                                        printf("\nWould you want to stay? 1 - Yes , 0 - No\n");
                                        key2=menu_intput();
                                        if (key2==-1)
                                        {
                                            key2=0;
                                            key1=0;
                                            clearNode(p0,p);
                                        }
                                        else
                                        {
                                            puts("");
                                        }; // завершение или продолжение работы в разделе
                                    }
                                    else
                                    {
                                        key2=0;
                                        key1=0;
                                        clearNode(p0,p);
                                    }
                                }
                                else
                                {
                                    key2=0;
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                            while (key2==1);
                        }
                            break;
                        case 2: // поиск
                        {
                            if (n!=0)
                            {
                                v=menu_2();
                                if (v!=-1)
                                {
                                    switch (v)
                                    {
                                        case 1:
                                        {
                                            printf("Specify number of the element which is needed to be shown - ");
                                            d=scanID(&n);
                                            if (d!=-1)
                                            {
                                                p=FindNodeById(p0,d);
                                                NodePrint(p);
                                                printf(" |\n\n");
                                            }
                                            else
                                            {
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                        case 2:
                                        {
                                            d=Read_Field(s);
                                            printf("Enter field value: ");
                                            Read_Value(s);
                                            m=FindNodesByField(p0,kindF[d],d,s,A);
                                            if (m==0) puts("Elements not found\n");
                                            else if (m!=-1) printf("Found %d elements\n\n",m);
                                            else
                                            {
                                                puts("Error occurred while allocating memory");
                                                key1=0;
                                                clearNode(p0,p);
                                            }
                                        }
                                            break;
                                    }
                                }
                                else
                                {
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                            else puts("Search can\'t be done, file is empty\n");
                        }
                            break;
                        case 3:
                        {
                            if (n==0) puts("Sorting can\'t be done, there are no elements\n");
                            else
                            {
                                printf("Sorting: 0) Ascending; 1) Descending\n");
                                v=menu_intput();
                                if (v!=-1)
                                {
                                    d=Read_Field(s);
                                    key1=Sort1_6(p0,p,kindF[d],d,v,A);
                                    if (key1==0) clearNode(p0,p);
                                }
                                else
                                {
                                    key1=0;
                                    clearNode(p0,p);
                                }
                            }
                        }
                            break;
                        case 4:
                        {
                            KartPrint(p0,p);
                        }
                            break;

                        default:
                            break;
                    }
                    if (key1==1)
                    {
                        printf("Do you want to continue? 1-Yes , 0-No\n");
                        key1=menu_intput();
                        if (key1!=1)
                        {
                            key1=0;
                            clearNode(p0,p);
                        } // завершение или продолжение работы
                    }
                    else
                    {
                        key1=0;
                        clearNode(p0,p);
                    }
                }
                else
                {
                    key1=0;
                    clearNode(p0,p);
                }
            }
            while (key1==1);

        }
        else {}; // в функции выводятся сообщения об ошибках
    }
    else puts("Error occurred while allocating memory");
    printf("\nThanks for using this program!\n");
    return 0;
}
