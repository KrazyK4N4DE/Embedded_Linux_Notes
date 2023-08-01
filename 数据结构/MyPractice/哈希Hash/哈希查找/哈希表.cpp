#include <iostream>
using namespace std;

const int SIZE = 9;  // 哈希表长度

// 封装一下数据类型
typedef struct Element
{
		int key;
}* Elem;
Elem CreateElem(int key)
{
		Elem element = new struct Element;
		element->key = key;
		return element;
}

// 哈希表
typedef struct HashTable
{
		Elem* table;
}* HT;
// 初始化哈希表
void initTable(HT hashtable)
{
		hashtable->table = new Elem[SIZE];
		for (int i = 0; i < SIZE; i++)
				hashtable->table[i] = NULL;
}
// 哈希函数
int hashop(int key)
{
		return key % SIZE;
}
// 插入操作
void insertTable(HT hashtable, Elem val)
{
		int index = hashop(val->key);
		hashtable->table[index] = val;
}
// 查找操作
bool findTable(HT hashtable, int key)
{
		int index = hashop(key);
		if (hashtable->table[index] == NULL) return 0;
		return hashtable->table[index]->key == key;
}

int main()
{
		struct HashTable hashTable;
		initTable(&hashTable);

		insertTable(&hashTable, CreateElem(10));
		insertTable(&hashTable, CreateElem(7));
		insertTable(&hashTable, CreateElem(13));
		insertTable(&hashTable, CreateElem(29));

		for (int i = 0; i < SIZE; i++)
		{
				if (hashTable.table[i])
						cout << hashTable.table[i]->key << " ";
				else
						cout << "NULL ";
		}

		printf("\n%d\n", findTable(&hashTable, 1));
		printf("%d\n", findTable(&hashTable, 13));

		return 0;
}