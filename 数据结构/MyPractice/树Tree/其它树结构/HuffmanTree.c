/*
��������
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char E;

typedef struct TreeNode {
        E element;
        struct TreeNode* left;
        struct TreeNode* right;
        int value;    //���Ȩֵ
} *Node;

typedef Node T;
typedef struct LNode
{
		T element;
		struct LNode* next;
}* LNode;

struct Queue
{
		LNode front, rear;
};
typedef struct Queue* LinkedQueue;

_Bool initQueue(LinkedQueue queue) {
        LNode node = malloc(sizeof(struct LNode));
        if (node == NULL) return 0;
        queue->front = queue->rear = node;
        node->next = NULL;   //��Ϊ�����õ����жϽ�����һ��ΪNULL������˵�ǵ�Ĭ���趨ΪNULL
        return 1;
}
_Bool offerQueue(LinkedQueue queue, T element) {
        LNode node = malloc(sizeof(struct LNode));
        if (node == NULL) return 0;
        node->element = element;
        node->next = NULL;   //��Ϊ�����õ����жϽ�����һ��ΪNULL������˵�ǵ�Ĭ���趨ΪNULL
        LNode pre = queue->front;   //���Ǵ�ͷ��㿪ʼ���󰤸�����ֱ���ҵ���һ��С�ڵ�ǰֵ�Ľ�㣬���ߵ�ͷΪֹ
        while (pre->next && pre->next->element->value <= element->value)
                pre = pre->next;
        if (pre == queue->rear) {   //���˵�ҵ���λ���Ѿ�������ˣ���ôֱ�Ӳ�����У������֮ǰ��һ����
                queue->rear->next = node;
                queue->rear = node;
        }
        else {    //������VIPģʽ��ֱ�Ӳ��
                node->next = pre->next;
                pre->next = node;
        }
        return 1;
}
T pollQueue(LinkedQueue queue) {
        T e = queue->front->next->element;
        LNode node = queue->front->next;
        queue->front->next = queue->front->next->next;  //ֱ����ͷ���ָ�����¸����
        if (queue->rear == node) queue->rear = queue->front;   //�����β���Ǵ����ӵĽ�㣬��ô��β�ص�����λ����
        free(node);   //�ͷ��ڴ�
        return e;
}
void printQueue(LinkedQueue queue) {
        printf("<<< ");
        LNode node = queue->front->next;
        while (1) {    //ע�ⲻ��ֱ���пգ���Ϊǰ������û���ǣ�Ҳ��û���½��next�趨ΪNULL
                printf("%c ", node->element->element);
                if (node == queue->rear) break;    //���Ѿ���ӡ���һ��Ԫ�غ��ٽ���
                else node = node->next;
        }
        printf("<<<\n");
}

Node createNode(E element, int value) {   //����һ�����
        Node node = malloc(sizeof(struct TreeNode));
        node->element = element;
        node->left = node->right = NULL;
        node->value = value;
        return node;
}

char* encode(Node root, E e) {
        if (root == NULL) return NULL;   //ΪNULL�϶�����û�ҵ�
        if (root->element == e) return "";   //����ҵ��˾ͷ���һ���մ�
        char* str = encode(root->left, e);  //��ȥ�����
        char* s = malloc(sizeof(char) * 10);
        if (str != NULL) {
                s[0] = '0';
                str = strcat(s, str);   //�������ҵ��ˣ���ô�Ͱ���ߵ��Ѿ�ƴ�õ��ַ���ƴ�ӵ���ǰ�ĺ���
        }
        else {    //��߲������ٿ����ұ�
                str = encode(root->right, e);
                if (str != NULL) {
                        s[0] = '1';
                        str = strcat(s, str);   //����ұ��ҵ��ˣ���ô�Ͱ��ұߵ��Ѿ�ƴ�õ��ַ���ƴ�ӵ���ǰ�ĺ���
                }
        }
        return str;   //��󷵻ز����õ��ַ�������һ��
}

void printEncode(Node root, E e) {
        printf("%c �ı���Ϊ��%s", e, encode(root, e));   //����Ľ��������
        putchar('\n');
}

int main() {
        struct Queue queue;
        initQueue(&queue);

        offerQueue(&queue, createNode('A', 5));
        offerQueue(&queue, createNode('B', 16));
        offerQueue(&queue, createNode('C', 8));
        offerQueue(&queue, createNode('D', 13));

        while (queue.front->next != queue.rear) {   //���front����һ������rear��ô˵��������ֻ��һ��Ԫ����
                Node left = pollQueue(&queue);
                Node right = pollQueue(&queue);
                Node node = createNode(' ', left->value + right->value);   //�����µĸ����
                node->left = left;
                node->right = right;
                offerQueue(&queue, node);   //��󽫹����õ���������
        }
        Node root = pollQueue(&queue);
        printEncode(root, 'A');
        printEncode(root, 'B');
        printEncode(root, 'C');
        printEncode(root, 'D');

        return 0;
}