#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 7
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

// ����
typedef int T;  // ���ｫ�±���ΪԪ��
typedef struct QueueNode  // ���н��
{
        T elem;
        struct QueueNode* next;
}* QNode;
typedef struct LinkQueue
{
        QNode front, rear;
}* Queue;

_Bool InitQueue(Queue queue)
{
        QNode node = (QNode)malloc(sizeof(struct QueueNode));
        if (node == NULL) return 0;  // ����ռ�ʧ��
        queue->front = queue->rear = node;
        return 1;
}
_Bool EnQueue(Queue queue, T element)
{
        QNode node = (QNode)malloc(sizeof(struct QueueNode));
        if (node == NULL) return 0;
        node->elem = element;
        queue->rear->next = node;
        queue->rear = node;
        return 1;
}
_Bool isEmpty(Queue queue)
{
        return queue->front == queue->rear;
}
T DeQueue(Queue queue)
{
        T e = queue->front->next->elem;
        QNode node = queue->front->next;
        queue->front->next = queue->front->next->next;
        if (queue->rear == node) queue->rear = queue->front;
        free(node);
        return e;
}

/*
* ������������㷨
* @param graph ͼ
* @param startVertex ��㶥���±�
* @param targetVertex Ŀ�궥���±�
* @param visited �Ѿ��������ǵĶ����±�����
* @param queue ��������
*/
void bfs(Graph graph, int startVertex, int targetVertex, int* visited, Queue queue)
{
        EnQueue(queue, startVertex);  // �����õ�һ��������±����ӣ������ж�Ӧ����
        visited[startVertex] = 1;  // ���
        while(!isEmpty(queue))
        {
                int next = DeQueue(queue);  // ��һ����ǰ�Ķ�����±����
                printf("%c -> ", graph->vertex[next].element);  // ��ӡ���ӵĶ���
                Node node = graph->vertex[next].next;  // ���ڼ��������Ӷ�����ڽӹ�ϵ
                while (node)
                {
                        if (!visited[node->nextVertex])
                        {
                                EnQueue(queue, node->nextVertex);
                                visited[node->nextVertex] = 1;
                        }
                        node = node->next;
                }
        }
}
/*
* ������������㷨(�������������)
* @param graph ͼ
* @param startVertex ��㶥���±�
* @param targetVertex Ŀ�궥���±�
* @param visited �Ѿ��������ǵĶ����±�����
* @param queue ��������
* @return ����������ѵ�����1��û���򷵻�0
*/
_Bool bfs_r(Graph graph, int startVertex, int targetVertex, int* visited, Queue queue)
{
        if (startVertex == targetVertex) return 1;
        EnQueue(queue, startVertex);  // �����õ�һ��������±����ӣ������ж�Ӧ����
        visited[startVertex] = 1;  // ���
        while (!isEmpty(queue))
        {
                int next = DeQueue(queue);  // ��һ����ǰ�Ķ�����±����
                printf("%c -> ", graph->vertex[next].element);  // ��ӡ���ӵĶ���
                Node node = graph->vertex[next].next;  // ���ڼ��������Ӷ�����ڽӹ�ϵ
                while (node)
                {
                        if (node->nextVertex == targetVertex) return 1;
                        if (!visited[node->nextVertex])
                        {
                                EnQueue(queue, node->nextVertex);
                                visited[node->nextVertex] = 1;
                        }
                        node = node->next;
                }
        }
        return 0;
}

int main()
{
        Graph graph = create();
        for (int c = 'A'; c <= 'G'; ++c)
                addVertex(graph, (char)c);
        addEdge(graph, 0, 1);   //A -> B
        addEdge(graph, 1, 2);   //B -> C
        addEdge(graph, 1, 3);   //B -> D
        addEdge(graph, 1, 4);   //B -> E
        addEdge(graph, 4, 5);   //E -> F
        addEdge(graph, 3, 6);

        int arr[7] = { 0 };
        struct LinkQueue queue;
        InitQueue(&queue);
        printf("\n%d", bfs_r(graph, 0, 4, arr, &queue));

        return 0;
}