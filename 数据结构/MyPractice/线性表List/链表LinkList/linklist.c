/*
线性表的链式存储结构的C语言实现
*/
#include <stdio.h>

//函数结果状态代码
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出

// Status定义为函数的返回类型，返回值为上述函数结果状态代码
typedef int Status;

// 定义结点
typedef int ElemType;
typedef struct node
{
        ElemType data;
        struct node *next;
}node;  // 必须要这样创建一个变量，否则在下面的函数中无法使用
typedef struct node *LinkList;

// 初始化单链表
Status InitList(LinkList *L)
{
        *L = (LinkList)malloc(sizeof(node));
        if(!(*L))
                return ERROR;
        (*L) -> next = NULL;

        return OK;
}

// 判断空表
Status IsEmpty(LinkList L)
{
        if(L -> next == NULL)
                return TRUE;
        else
                return FALSE;
}

// 销毁单链表
void Destroy(LinkList *L)
{
        LinkList p;
        while(*L)
        {
                p = (*L);
                (*L) = (*L) -> next;
                free(p);
        }
}

/*
清空单链表
与销毁单链表的区别在于，销毁单链表是将单链表的所有结点都释放掉，
而清空单链表，头指针和头结点仍在
*/
Status ClearList(LinkList *L)
{
        LinkList p, q;
        p = (*L) -> next;
        while(p != NULL)
        {
                q = p -> next;
                free(p);
                p = q;
        }
        (*L) -> next = NULL;

        return OK;
}

// 求单链表的表长
int ListLen(LinkList L)
{
        LinkList p = L -> next;
        int i = 0;
        while(p)
        {
                i++;
                p = p -> next;
        }

        return i;
}

/*
求单链表中第i个元素的值
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
        int j = 1;
        LinkList p = L -> next;

        while(p && j < i)
        {
                p = p -> next;
                ++j;
        }
        if(!p || j < i)  // 第i个元素不存在
                return ERROR;

        *e = p -> data;

        return OK;
}

/*
单链表的按值查找：根据指定数据获取该数据所在位置(地址)
时间复杂度为O(n)
*/
LinkList LocateElem(LinkList L, ElemType e)
{
        LinkList p = L -> next;
        while(p && p -> data != e)
                p = p -> next;
        return p;
}

/*
单链表的按值查找：根据指定数据获取该数据所在位置(序号)
时间复杂度为O(n)
*/
int LocateElem_L(LinkList L, ElemType e)
{
        int i = 0;
        LinkList p = L -> next;
        while(p)
        {
                ++i;
                if(p -> data == e)
                        return i;
                p = p -> next;
        }

        return 0;
}

/*
单链表的插入：在第i个结点前插入值为e的新结点
先遍历查找前驱结点，时间复杂度为O(n)，
然后插入新结点，时间复杂度为O(1)
*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
        int j = 0;
        LinkList p = *L;
        LinkList s = (LinkList)malloc(sizeof(node));
        s -> data = e;  // 创建新结点

        while(p && j < i - 1)  // 寻找第i个结点前驱
        {
                p = p -> next;
                ++j;
        }
        if(!p || j > i - 1)  // 第i - 1个结点不存在
                return ERROR;
        s -> next = p -> next;
        p -> next = s;

        free(s);

        return OK;
}

/*
单链表的删除：删除第i个结点，用e返回其值
先遍历查找前驱结点，时间复杂度为O(n)，
然后删除结点，时间复杂度为O(1)
*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
        int j = 0;
        LinkList p = *L;
        
        while(p && j < i - 1)
        {
                ++j;
                p = p -> next;
        }
        if(!p || j > i - 1)
                return ERROR;
        
        LinkList q = p -> next;
        p -> next = q -> next;
        *e = q -> data;

        free(q);

        return OK;
}

/*
单链表的建立：头插法(元素倒序插入)
时间复杂度为O(n)
*/
void CreateList_H(LinkList *L, int n)
{
        L = (LinkList)malloc(sizeof(node));
        (*L) -> next = NULL;
        LinkList p;

        for(int i = n; i > 0; --i)
        {
                p = (LinkList)malloc(sizeof(node));
                scanf("%d", &(p -> data));

                p -> next = (*L) -> next;
                (*L) -> next = p;
        }

        free(p);
}

/*
单链表的建立：尾插法(元素正序插入)
时间复杂度为O(n)
*/
void CreateList_T(LinkList *L, int n)
{
        L = (LinkList)malloc(sizeof(node));
        (*L) -> next = NULL;
        LinkList p, r;  //接下来操作不涉及头结点，所以要多一个临时变量
        r = *L;

        for(int i = 0; i < n; ++i)
        {
                p = (LinkList)malloc(sizeof(node));
                scanf("%d", &(p -> data));
                p -> next = NULL;
                r -> next = p;
                r = p;  // r指向新的尾结点
        }

        free(p);
}

/*
带尾指针循环链表的合并
时间复杂度为O(1)
*/
LinkList Connect(LinkList *La, LinkList *Lb)
{
        LinkList p  = (*La) -> next;
        (*La) -> next = (*Lb) -> next -> next;
        free((*Lb) -> next);
        (*Lb) -> next = p;
}