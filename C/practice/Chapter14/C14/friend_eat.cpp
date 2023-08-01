/*嵌套结构的应用*/
#include<stdio.h>
#define MAX 20
const char* msg[4] =
{
	"很高兴认识你，",
	"你让我见识到了2022年了还能有这么蠢蛋的",
	"为感谢你拓宽我的视野，我决定请你吃你最喜欢吃的",
	"，顺便让我再康康你能不能更蠢"
};

/*第一个结构*/
struct Name
{
	char first[MAX];
	char last[MAX];
};

/*第二个结构*/
struct Guy
{
	struct Name handle;
	char favfood[MAX];
	char job[MAX];
	float income;
};

int main(void)
{
	struct Guy fellow =
	{
		{"祎","韦"},
		"牛排",
		"研究生",
		500
	};
	printf("致%s%s：\n%4s", fellow.handle.last, fellow.handle.first,"");
	printf("%s%s%s。\n", msg[0], fellow.handle.last, fellow.handle.last);
	printf("%s%s。\n", msg[1], fellow.job);
	printf("%s%s%s", msg[2], fellow.favfood, msg[3]);
	
	/*开始拜金*/
	if (fellow.income > 10000)
	{
		puts("。");
	}
	else if (fellow.income > 5000)
	{
		puts("！");
	}
	else
	{
		puts("！！");
	}

	printf("\n%60s%s\n", "", "somebody");
	printf("%60s%s\n", "", "2022.06.17");
	return 0;
}