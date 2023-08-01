/*
线性表的顺序存储结构的C语言实现
*/
#include <stdio.h>
#include <stdlib.h>

//函数结果状态代码
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1 // 不可行
#define OVERFLOW -2   // 溢出

// Status定义为函数的返回类型，返回值为上述函数结果状态代码
typedef int Status;

// 创建结构
typedef int ElemType; // 设定类型
#define MAX 20   // 线性表的最大长度
typedef struct
{
        ElemType *data;
        int len; // 线性表的当前长度
} SqList;

// 初始化线性表
Status Init(SqList *L)
{
        L -> data = (ElemType *)malloc(MAX * sizeof(ElemType));
        if(!L -> data)  // 存储分配失败
                return OVERFLOW;
        L -> len = 0;
        return OK;
}

// 释放线性表
void Destroy(SqList *L)
{
        if(L -> data)
                free(L -> data);
}

// 清空线性表
Status Clear(SqList *L)
{
        L -> len = 0;
        return OK;
}

// 取得线性表长度
int GetLen(const SqList *L)
{
        return L -> len;        
}

// 判断线性表是否为空
Status IsEmpty(const SqList *L)
{
        if(L -> len == 0)
                return TRUE;
        return FALSE;
}

/*
取得线性表中第i个元素的值，用e返回
随机存取，算法复杂度为 O(1)
*/
Status GetElem(const SqList *L, int i, ElemType *e)
{
        if(L -> len == 0 || i < 1 || i > L -> len)
                return ERROR;
        *e = L -> data[i - 1];
        return OK;
}

/*
顺序表的按值查找：返回L中第一个与e满足特定关系的数据元素的位序
若不存在这样的数据元素，则返回值为0
算法复杂度为 O(n)
*/
int LocateElem(const SqList *L, ElemType e)
{
        for(int i = 0; i < L -> len; i++)
        {
                if(L -> data[i] == e)
                        return i + 1;
        }
        return 0;
}

/*
线性表的插入：在L中第i个位置之前插入新的数据元素e，L的长度加1
算法复杂度为 O(n)
*/
Status ListInsert(SqList *L, int i, ElemType e)
{
        if (L -> len == MAX)  // 线性表已满
                return ERROR;
        if(i < 1 || i > L -> len + 1)  // i值不合法
                return ERROR;
        if(i < L -> len + 1)  // 若插入数据位置不在表尾
        {
                for(int j = L -> len - 1; j >= i - 1; j--)
                        L -> data[j + 1] = L -> data[j];  //元素向后移
        }
        L -> data[i - 1] = e;
        L -> len++;
        return OK;
}

/*
线性表的删除：删除L的第i个数据元素，并用e返回其值，L的长度减1
算法复杂度为 O(n)
*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
        if(L -> len == 0)  // 线性表为空
                return ERROR;
        if(i < 1 || i > L -> len)  // i值不合法
                return ERROR;
        *e = L -> data[i - 1];
        if(i < L -> len)  //若删除数据位置不在表尾
        {
                for(int j = i; j < L -> len; j++)
                        L -> data[j - 1] = L -> data[j];  // 元素向前移
        }
        L -> len--;
        return OK;
}

void PrintList(SqList L)
{
        for(int i = 0; i < L.len; i++)
                printf("%d ", L.data[i]);
        printf("\n");
}

int main()
{
        SqList list;
        if(Init(&list))
        {
                ListInsert(&list, 1, 666);
                PrintList(list);
                ListInsert(&list, 1, 777);
                PrintList(list);
                ListInsert(&list, 2, 888);
                PrintList(list);
                for(int i = 0; i < 15; i++)
                {
                        ListInsert(&list, i + 1, i * 10);
                }
                PrintList(list);
                ElemType e;
                ListDelete(&list, 10, &e);
                printf("删除的元素为：%d\n", e);
                ListDelete(&list, 10, &e);
                printf("删除的元素为：%d\n", e);
                PrintList(list);
        }
        else
                printf("初始化失败，无法启动程序！\n");

        return 0;
}