#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct LNode
{
    int id;
    char *full_name;
    char *model;
    int year;
    int season;
    float retail_price;
    float resell_price;
    int *size;
    struct LNode *next;
};

struct LHead
{
    int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LNode Node;
typedef struct LHead Head;

int menu_main();                            /// �������� ���� ��� ������ � ����������
int menu_intput();                          /// ���� ��� ������ ����� ���� �����
int menu_1();                               /// ���� ��������������
int menu_2();                               /// ���� ��� ������ ���������
int Read_Field(char *);                     /// ���������� ��������
void Read_Value(char *);                    /// ���������� �������� ���������� ��������
int scanID(int *);                          /// ���� id �������� �������������
Head *MakeHead();                           /// �������� ������
Node *MakeNode();                           /// �������� �������� ������
int ReadFile(Head *, Node *, int *, int *); /// ���������� ������ �� �����
Node *ReadNode(char *, int *);              /// ���������� �������� ������ � ����������
void NodePrint(Node *);                     /// ����� �������� ������ �� �����
void KartPrint(Head *, Node *);             /// ����� ��������� �� �����
void AdressPrint(Head *);                   /// ����� �������
void InsertAfter(Head *, Node *, int);      /// ������� ��������
void ChangeAfterInsert(Head *, int, int *); /// ��������� ������� ��������� � ��������� size ����� ������� ��������
void clearNode(Head *, Node *);             /// �������� ������
void DeleteNode(Head *, int);               /// �������� ��������
void ChangeAfterDelete(Head *, int, int *); /// ��������� ������� ��������� � ��������� size ����� �������� ��������
Node *FindNodeById(Head *, int);            /// ����� �������� �� ������
int FindNodesByField(Head *, char *(*Fname)(Node *), int, char *, int *); /// ����� ��������� �� �������� ����
int ChangeValue(Node *, char *, int, int);  /// ����� ��������� �� �������� ����
char *full_name(Node *);                    /// ���������� �������� ���� full_name �������� �������� ������
char *model(Node *);                        /// ���������� �������� ���� model �������� �������� ������
char *year(Node *);                         /// ���������� �������� ���� year �������� �������� ������
char *season(Node *);                        /// ���������� �������� ���� season �������� �������� ������
char *retail_price(Node *);                     /// ���������� �������� ���� retail_price �������� �������� ������
char *resell_price(Node *);                     /// ���������� �������� ���� resell_price �������� �������� ������
int Sort1_6(Head *, Node *, char *(*Fname)(Node *), int, int, int *); /// ���������� ������

#endif // LIST_H_INCLUDED
