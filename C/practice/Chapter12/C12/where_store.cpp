/*���ݱ������ںδ���*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int static_store = 30;		//��̬
const char * pcg = "static String";		//��̬
int main()
{
	int auto_store = 40;		//�Զ�
	char auto_string[] = "auto String";		//�Զ�
	int* pi;		//���ᱻcalloc�ˣ���̬
	char* pcl;		//���ᱻmalloc�ˣ���̬
	pi = (int*)calloc(1, sizeof(int));		//calloc()����������������malloc()��*�����Ҳ�
	*pi = 35;
	pcl = (char*)malloc(strlen("dynamic String") + 1);
	strcpy(pcl, "dynamic String");
	printf("static_store: %d at %p\n", static_store, &static_store);
	printf("auto_store: %d at %p\n", auto_store, &auto_store);
	printf("*pi: %d at %p\n", *pi, pi);
	printf("pcg: %s at %p\n", pcg, pcg);
	printf("%s at %p\n", auto_string, auto_string);
	printf("%s at %p\n", pcl, pcl);
	printf("%s at %p\n", "quoted string", "quoted string");		//�ַ�������̬��������
	free(pi);
	free(pcl);
	return 0;
}