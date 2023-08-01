/*数据被储存在何处？*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int static_store = 30;		//静态
const char * pcg = "static String";		//静态
int main()
{
	int auto_store = 40;		//自动
	char auto_string[] = "auto String";		//自动
	int* pi;		//待会被calloc了，动态
	char* pcl;		//待会被malloc了，动态
	pi = (int*)calloc(1, sizeof(int));		//calloc()接受两个参数，把malloc()中*的左右拆开
	*pi = 35;
	pcl = (char*)malloc(strlen("dynamic String") + 1);
	strcpy(pcl, "dynamic String");
	printf("static_store: %d at %p\n", static_store, &static_store);
	printf("auto_store: %d at %p\n", auto_store, &auto_store);
	printf("*pi: %d at %p\n", *pi, pi);
	printf("pcg: %s at %p\n", pcg, pcg);
	printf("%s at %p\n", auto_string, auto_string);
	printf("%s at %p\n", pcl, pcl);
	printf("%s at %p\n", "quoted string", "quoted string");		//字符常量静态了属于是
	free(pi);
	free(pcl);
	return 0;
}