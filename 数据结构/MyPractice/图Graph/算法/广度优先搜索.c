#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 7
typedef char E;
typedef struct Node {   //结点和头结点分开定义，头结点记录顶点信息，普通结点记录邻接信息
        int nextVertex;
        struct Node* next;
} *Node;
struct HeadNode {
        E element;
        struct Node* next;
};
// 邻接表
typedef struct AdjacencyGraph {
        int vertexCount;   //顶点数
        int edgeCount;     //边数
        struct HeadNode vertex[MaxVertex];
} *Graph;

Graph create() {   //创建时，我们可以指定图中初始有多少个结点
        Graph graph = (Graph)malloc(sizeof(struct AdjacencyGraph));
        graph->vertexCount = graph->edgeCount = 0;
        return graph;   //头结点数组一开始可以不用管
}
void addVertex(Graph graph, E element) {
        if (graph->vertexCount >= MaxVertex) return;   //跟之前一样
        graph->vertex[graph->vertexCount].element = element;   //添加新结点时，再来修改也行
        graph->vertex[graph->vertexCount++].next = NULL;
}
/*
* @param a 起点的下标
* @param b 终点的下标
*/
void addEdge(Graph graph, int a, int b) {
        Node node = graph->vertex[a].next;
        Node newNode = (Node)malloc(sizeof(struct Node));
        newNode->next = NULL;
        newNode->nextVertex = b;
        if (!node) {    //如果头结点下一个边都没有，那么直接连上去
                graph->vertex[a].next = newNode;
        }
        else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
                do {
                        if (node->nextVertex == b)   //如果已经连接了对应的顶点，那么直接返回
                        {
                                free(newNode);
                                return;
                        }
                        if (node->next) node = node->next;   //否则继续向后遍历
                        else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
                } while (1);
                node->next = newNode;
        }
        graph->edgeCount++;   //边数计数+1
}
void printGraph(Graph graph) {
        for (int i = 0; i < graph->vertexCount; ++i) {
                printf("%d | %c", i, graph->vertex[i].element);
                // 生成一个node用于检查头结点是否有边
                Node node = graph->vertex[i].next;
                while (node) {
                        printf(" -> %d", node->nextVertex);
                        node = node->next;
                }
                putchar('\n');
        }
}

// 队列
typedef int T;  // 这里将下标作为元素
typedef struct QueueNode  // 队列结点
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
        if (node == NULL) return 0;  // 分配空间失败
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
* 广度优先搜索算法
* @param graph 图
* @param startVertex 起点顶点下标
* @param targetVertex 目标顶点下标
* @param visited 已经到达、并标记的顶点下标数组
* @param queue 辅助队列
*/
void bfs(Graph graph, int startVertex, int targetVertex, int* visited, Queue queue)
{
        EnQueue(queue, startVertex);  // 首先让第一个顶点的下标就入队，后面有对应操作
        visited[startVertex] = 1;  // 标记
        while(!isEmpty(queue))
        {
                int next = DeQueue(queue);  // 让一个排前的顶点的下标出队
                printf("%c -> ", graph->vertex[next].element);  // 打印出队的顶点
                Node node = graph->vertex[next].next;  // 用于检查这个出队顶点的邻接关系
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
* 广度优先搜索算法(带返回搜索结果)
* @param graph 图
* @param startVertex 起点顶点下标
* @param targetVertex 目标顶点下标
* @param visited 已经到达、并标记的顶点下标数组
* @param queue 辅助队列
* @return 搜索结果，搜到返回1，没有则返回0
*/
_Bool bfs_r(Graph graph, int startVertex, int targetVertex, int* visited, Queue queue)
{
        if (startVertex == targetVertex) return 1;
        EnQueue(queue, startVertex);  // 首先让第一个顶点的下标就入队，后面有对应操作
        visited[startVertex] = 1;  // 标记
        while (!isEmpty(queue))
        {
                int next = DeQueue(queue);  // 让一个排前的顶点的下标出队
                printf("%c -> ", graph->vertex[next].element);  // 打印出队的顶点
                Node node = graph->vertex[next].next;  // 用于检查这个出队顶点的邻接关系
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