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

int menu_main();                            /// основное меню для работы с программой
int menu_intput();                          /// меню для выбора между двух чисел
int menu_1();                               /// меню редактирования
int menu_2();                               /// меню для поиска элементов
int Read_Field(char *);                     /// считывание признака
void Read_Value(char *);                    /// считывание значения выбранного признака
int scanID(int *);                          /// ввод id элемента пользователем
Head *MakeHead();                           /// создание головы
Node *MakeNode();                           /// создание элемента списка
int ReadFile(Head *, Node *, int *, int *); /// считывание данных из файла
Node *ReadNode(char *, int *);              /// считывание элемента списка с клавиатуры
void NodePrint(Node *);                     /// вывод элемента списка на экран
void KartPrint(Head *, Node *);             /// вывод картотеки на экран
void AdressPrint(Head *);                   /// вывод адресов
void InsertAfter(Head *, Node *, int);      /// вставка элемента
void ChangeAfterInsert(Head *, int, int *); /// изменение номеров элементов и счётчиков size после вставки элемента
void clearNode(Head *, Node *);             /// отчистка памяти
void DeleteNode(Head *, int);               /// удаление элемента
void ChangeAfterDelete(Head *, int, int *); /// изменение номеров элементов и счётчиков size после удаления элемента
Node *FindNodeById(Head *, int);            /// поиск элемента по номеру
int FindNodesByField(Head *, char *(*Fname)(Node *), int, char *, int *); /// поиск элементов по значению поля
int ChangeValue(Node *, char *, int, int);  /// поиск элементов по значению поля
char *full_name(Node *);                    /// возвращает значение поля full_name текущего элемента списка
char *model(Node *);                        /// возвращает значение поля model текущего элемента списка
char *year(Node *);                         /// возвращает значение поля year текущего элемента списка
char *season(Node *);                        /// возвращает значение поля season текущего элемента списка
char *retail_price(Node *);                     /// возвращает значение поля retail_price текущего элемента списка
char *resell_price(Node *);                     /// возвращает значение поля resell_price текущего элемента списка
int Sort1_6(Head *, Node *, char *(*Fname)(Node *), int, int, int *); /// сортировка данных

#endif // LIST_H_INCLUDED
