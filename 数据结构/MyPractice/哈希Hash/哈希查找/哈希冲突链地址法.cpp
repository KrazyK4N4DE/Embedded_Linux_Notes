#include <iostream>
using namespace std;

const int SIZE = 9;

typedef struct LNode
{
		int val;
		struct LNode* next;
}* Node;
Node CreateNode(int elem)
{
		Node node = new struct LNode;
		node->next = NULL;
		node->val = elem;
		return node;
}

typedef struct HashTable
{
		struct LNode* table;
}* HTable;

void initTable(HTable hashTable)
{
		hashTable->table = new struct LNode[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
				hashTable->table[i].val = -1;
				hashTable->table[i].next = NULL;
		}
}
// 哈希函数
int hashop(int key)
{
		return key % SIZE;
}
// 插入操作
void insertTable(HTable hashTable, int key)
{
		int index = hashop(key);
		Node head = hashTable->table + index;  // 在对应下标插入结点
		while (head->next)
				head = head->next;
		head->next = CreateNode(key);
}
// 查找操作
bool findTable(HTable hashTable, int key)
{
		int index = hashop(key);
		Node head = &(hashTable->table[index]);
		while (head->next && head->val != key)
				head = head->next;
		return head->val == key;
}

int main()
{
		struct HashTable table;
		initTable(&table);

		insertTable(&table, 10);
		insertTable(&table, 19);
		insertTable(&table, 20);

		printf("%d\n", findTable(&table, 20));
		printf("%d\n", findTable(&table, 17));
		printf("%d\n", findTable(&table, 19));

		return 0;
}