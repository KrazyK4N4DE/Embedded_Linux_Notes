/*rand1()Ϊα��������ɺ���������ÿ����������һ������λ�������ɵ�������ʼ����ͬ�����ӡ�
�迿srand1()���������ӣ���ʵ�֡������������*/
static unsigned long int next = 1;		//����
int rand1() 
{
	/*����α�������ħ����ʽ*/
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;		//����һ��0~32767֮���ֵ
}
void srand1(unsigned int seed) 
{
	next = seed;
}