#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6

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

/*
* ������������㷨
* @param graph ͼ
* @param startVertex ��㶥���±�
* @param targetVertex Ŀ�궥���±�
* @param visited �Ѿ��������ǵĶ����±�����
*/
void dfs(Graph graph, int startVertex, int targetVertex, int* visited)
{
        printf("%c -> ", graph->vertex[startVertex].element);  // ��ӡ��һ�������ֵ
        visited[startVertex] = 1;  // ���ϱ��
        Node node = graph->vertex[startVertex].next;  // ��һ��node��鶥����ڽӹ�ϵ
        while (node)  // ���ھӵĻ�
        {
                if (!visited[node->nextVertex])  // ������±�����Ӧ�Ķ���û����ǵĻ�����������
                        dfs(graph, node->nextVertex, targetVertex, visited);
                node = node->next;  // ��һ����
        }
}
/*
* ������������㷨(�������������)
* @param graph ͼ
* @param startVertex ��㶥���±�
* @param targetVertex Ŀ�궥���±�
* @param visited �Ѿ��������ǵĶ����±�����
* @return �������������ҵ�����1��û�ҵ�����0
*/
_Bool dfs_r(Graph graph, int startVertex, int targetVertex, int* visited)
{
        printf("%c -> ", graph->vertex[startVertex].element);  // ��ӡ��һ�������ֵ
        visited[startVertex] = 1;  // ���ϱ��
        if (startVertex == targetVertex) return 1;  // �ҵ��˾�
        Node node = graph->vertex[startVertex].next;  // ��һ��node��鶥����ڽӹ�ϵ
        while (node)  // ���ھӵĻ�
        {
                if (!visited[node->nextVertex])  // ������±�����Ӧ�Ķ���û����ǵĻ�����������
                        if (dfs_r(graph, node->nextVertex, targetVertex, visited)) return 1;
                node = node->next;  // ��һ����
        }
        return 0;
}

int main()
{
        Graph graph = create();
        for (int c = 'A'; c <= 'F'; ++c)
                addVertex(graph, (char)c);
        addEdge(graph, 0, 1);   //A -> B
        addEdge(graph, 1, 2);   //B -> C
        addEdge(graph, 1, 3);   //B -> D
        addEdge(graph, 1, 4);   //B -> E
        addEdge(graph, 4, 5);   //E -> F
        
        int arr[6] = { 0 };
        printf("\n%d", dfs_r(graph, 0, 5, arr));

        return 0;
}