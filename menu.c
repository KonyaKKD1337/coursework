#include "list.h"

int menu_main()
{
    int c,len,key;
    char *s=NULL;

    puts("Menu:\n1) Editing\n2) Search for elements \n3) Sorting\n4) Show the table");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose action - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) c=1;
            else if (strcmp(s,"2")==0) c=2;
            else if (strcmp(s,"3")==0) c=3;
            else if (strcmp(s,"4")==0) c=4;
            else c=0;
            if ((c!=1)&&(c!=2)&&(c!=3)&&(c!=4))
            {
                puts("Incorrect value, try again");
                printf("Choose action - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error occurred while allocating memory");
        c=-1;
    }

    return c;
}

int menu_1()
{
    int v,len,key;
    char *s=NULL;

    printf("  Editing: 1) add new element 2) delete element 3) change element\n");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose action - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) v=1;
            else if (strcmp(s,"2")==0) v=2;
            else if (strcmp(s,"3")==0) v=3;
            else v=0;
            if ((v!=1)&&(v!=2)&&(v!=3))
            {
                puts("Incorrect value, try again");
                printf("Choose action - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error occurred while allocating memory");
        v=-1;
    }

    return v;
}

int menu_2()
{
    int v,len,key;
    char *s=NULL;

    printf("  Search: 1) Number of the element 2) Field value\n");

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose action - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"1")==0) v=1;
            else if (strcmp(s,"2")==0) v=2;
            else v=0;
            if ((v!=1)&&(v!=2))
            {
                puts("Incorrect value, try again");
                printf("Choose action - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error occurred while allocating memory");
        v=-1;
    }

    return v;
}

int menu_intput()
{
    int v,len,key;
    char *s=NULL;

    if ((s=(char*)malloc(N*sizeof(char)))!=NULL)
    {
        printf("Choose action - ");
        key=0;
        do
        {
            fgets(s,M,stdin);
            len=strlen(s);
            s[len-1]='\0';
            if (strcmp(s,"0")==0) v=0;
            else if (strcmp(s,"1")==0) v=1;
            else v=3;
            if ((v!=0)&&(v!=1))
            {
                puts("Incorrect value, try again");
                printf("Choose action - ");
            }
            else key=1;
        }
        while (key==0);

        free(s);
    }
    else
    {
        puts("Error occurred while allocating memory");
        v=-1;
    }

    return v;
}
