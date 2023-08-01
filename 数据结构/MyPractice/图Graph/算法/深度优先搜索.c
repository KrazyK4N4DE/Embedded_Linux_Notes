#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6

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

/*
* 深度优先搜索算法
* @param graph 图
* @param startVertex 起点顶点下标
* @param targetVertex 目标顶点下标
* @param visited 已经到达、并标记的顶点下标数组
*/
void dfs(Graph graph, int startVertex, int targetVertex, int* visited)
{
        printf("%c -> ", graph->vertex[startVertex].element);  // 打印第一个顶点的值
        visited[startVertex] = 1;  // 马上标记
        Node node = graph->vertex[startVertex].next;  // 用一个node检查顶点的邻接关系
        while (node)  // 有邻居的话
        {
                if (!visited[node->nextVertex])  // 如果该下标所对应的顶点没被标记的话，接着深搜
                        dfs(graph, node->nextVertex, targetVertex, visited);
                node = node->next;  // 下一条边
        }
}
/*
* 深度优先搜索算法(带返回搜索结果)
* @param graph 图
* @param startVertex 起点顶点下标
* @param targetVertex 目标顶点下标
* @param visited 已经到达、并标记的顶点下标数组
* @return 搜索结果，如果找到返回1，没找到返回0
*/
_Bool dfs_r(Graph graph, int startVertex, int targetVertex, int* visited)
{
        printf("%c -> ", graph->vertex[startVertex].element);  // 打印第一个顶点的值
        visited[startVertex] = 1;  // 马上标记
        if (startVertex == targetVertex) return 1;  // 找到了就
        Node node = graph->vertex[startVertex].next;  // 用一个node检查顶点的邻接关系
        while (node)  // 有邻居的话
        {
                if (!visited[node->nextVertex])  // 如果该下标所对应的顶点没被标记的话，接着深搜
                        if (dfs_r(graph, node->nextVertex, targetVertex, visited)) return 1;
                node = node->next;  // 下一条边
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