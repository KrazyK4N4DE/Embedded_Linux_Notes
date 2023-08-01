/*rand1()为伪随机数生成函数，程序每次输出结果都一样，因位函数生成的数都开始于相同的种子。
需靠srand1()来重置种子，以实现“真正”的随机*/
static unsigned long int next = 1;		//种子
int rand1() 
{
	/*生成伪随机数的魔术公式*/
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;		//返回一个0~32767之间的值
}
void srand1(unsigned int seed) 
{
	next = seed;
}