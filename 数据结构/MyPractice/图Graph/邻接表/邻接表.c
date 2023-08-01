#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5

typedef char E;

typedef struct Node {   //����ͷ���ֿ����壬ͷ����¼������Ϣ����ͨ����¼�ڽ���Ϣ
        int nextVertex;
        struct Node* next;
} *Node;
struct HeadNode {
        E element;
        struct Node* next;
};
// �ڽӱ�
typedef struct AdjacencyGraph {
        int vertexCount;   //������
        int edgeCount;     //����
        struct HeadNode vertex[MaxVertex];
} *Graph;

Graph create() {   //����ʱ�����ǿ���ָ��ͼ�г�ʼ�ж��ٸ����
        Graph graph = (Graph)malloc(sizeof(struct AdjacencyGraph));
        graph->vertexCount = graph->edgeCount = 0;
        return graph;   //ͷ�������һ��ʼ���Բ��ù�
}
void addVertex(Graph graph, E element) {
        if (graph->vertexCount >= MaxVertex) return;   //��֮ǰһ��
        graph->vertex[graph->vertexCount].element = element;   //����½��ʱ�������޸�Ҳ��
        graph->vertex[graph->vertexCount++].next = NULL;
}
/*
* @param a �����±�
* @param b �յ���±�
*/
void addEdge(Graph graph, int a, int b) {
        Node node = graph->vertex[a].next;
        Node newNode = (Node)malloc(sizeof(struct Node));
        newNode->next = NULL;
        newNode->nextVertex = b;
        if (!node) {    //���ͷ�����һ���߶�û�У���ôֱ������ȥ
                graph->vertex[a].next = newNode;
        }
        else {   //����˵����ǰ�����Ѿ�����������һ�����������ˣ��п��ܻ�����Ѿ����ӹ������������˵Ҫ�ر���һ��
                do {
                        if (node->nextVertex == b)   //����Ѿ������˶�Ӧ�Ķ��㣬��ôֱ�ӷ���
                        {
                                free(newNode);
                                return;
                        }
                        if (node->next) node = node->next;   //�������������
                        else break;   //���û����һ���ˣ��Ǿ��ҵ����һ������ˣ�ֱ�ӽ���
                } while (1);
                node->next = newNode;
        }
        graph->edgeCount++;   //��������+1
}
void printGraph(Graph graph) {
        for (int i = 0; i < graph->vertexCount; ++i) {
                printf("%d | %c", i, graph->vertex[i].element);
                // ����һ��node���ڼ��ͷ����Ƿ��б�
                Node node = graph->vertex[i].next;
                while (node) {
                        printf(" -> %d", node->nextVertex);
                        node = node->next;
                }
                putchar('\n');
        }
}

int main() {
        Graph graph = create();
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