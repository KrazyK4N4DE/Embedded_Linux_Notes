/*
����ͼ���ڽӾ���
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5

typedef char E;
typedef struct MatrixGraph
{
		int vertexCount, edgeCount;
		int matrix[MaxVertex][MaxVertex];
		E data[MaxVertex];  // �������Ӧ����
}* Graph;

Graph createGraph()
{
		Graph graph = malloc(sizeof(struct MatrixGraph));
		graph->vertexCount = graph->edgeCount = 0;
		for (int i = 0; i < MaxVertex; i++)
				for (int j = 0; j < MaxVertex; j++)
						graph->matrix[i][j] = 0;
		return graph;
}
// ���붥��
void addVertex(Graph graph, E elem)
{
		if (graph->vertexCount >= MaxVertex) return;
		graph->data[graph->vertexCount++] = elem;	
}
// ����ߣ�from��ʾ�������ĵ��±꣬to��ʾ�����ϵĵ���±�
void addEdge(Graph graph, int from, int to)
{
		if (graph->matrix[from][to] == 0)
		{
				graph->matrix[from][to] = 1;  // ���������ͼ�Ļ�����Ҫ[from][to]��[to][from]����Ϊ1
				graph->edgeCount++;
		}
}
void printGraph(Graph graph) {
		for (int i = -1; i < graph->vertexCount; ++i) {
				for (int j = -1; j < graph->vertexCount; ++j) {
						if (j == -1)
								printf("%c", 'A' + i);
						else if (i == -1)
								printf("%3c", 'A' + j);
						else
								printf("%3d", graph->matrix[i][j]);
				}
				putchar('\n');
		}
}

int main()
{
		Graph graph = createGraph();
		for (int c = 'A'; c <= 'D'; ++c)
				addVertex(graph, (char)c);
		addEdge(graph, 0, 1);   //A -> B
		addEdge(graph, 1, 2);   //B -> C
		addEdge(graph, 2, 3);   //C -> D
		addEdge(graph, 3, 0);   //D -> A
		addEdge(graph, 2, 0);   //C -> A

		printGraph(graph);

		return 0;
}