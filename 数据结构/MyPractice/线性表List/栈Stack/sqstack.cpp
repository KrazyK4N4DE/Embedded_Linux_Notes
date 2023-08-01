/*
顺序栈
*/
#include <iostream>
using namespace std;
const int MAXSIZE = 10;

typedef int E;
struct Stack
{
		E* array;  // 用数组表示栈
		int top;  // 表示栈顶位置，存的是栈顶元素的下标
		int capacity;  // 表示栈容量，所以top的最大值为capacity - 1
};
typedef  struct Stack* ArrayStack;

/*初始化栈*/
bool initStack(ArrayStack stack)
{
		stack->capacity = MAXSIZE;
		stack->array = new E[stack->capacity];
		stack->top = -1;  // 没有元素是-1，因为top代表的是下标
		if (stack->array == NULL) return 0;

		return 1;
}

void showStack(ArrayStack stack)
{
		for (int i = 0; i < stack->top + 1; ++i)
				cout << stack->array[i] << " ";
		cout << endl;
}

/*压栈操作*/
bool pushStack(ArrayStack stack, E elem)
{
		if (stack->top + 1 == stack->capacity)  return 0;  //如果栈容量满了，则不再压栈
		stack->array[++stack->top] = elem;
		return 1;
}

/*判断是否为空*/
bool isEmpty(ArrayStack stack)
{
		return (stack->top == -1);
}

/*出栈操作*/
E popStack(ArrayStack stack)
{
		return stack->array[stack->top--];
}

int main()
{
		struct Stack stack;
		initStack(&stack);
		
		for (int i = 0; i < 11; ++i)
				pushStack(&stack, i * 100);
		showStack(&stack);
		
		while (!isEmpty(&stack))  // 先进后出
				cout << popStack(&stack) << " ";
		cout << endl;

		return 0;
}