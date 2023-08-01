const int LEN = 40;

struct Golf
{
        char fullname[LEN];
        int handicap;
};

//将golf结构体初始化为提供的name和hc值
void setgolf(Golf & g, const char * name, int hc);
//提示用户输入名字和handicap值，然后将其存储在结构中
int setgolf(Golf & g);
//重置handicap值
void handicap(Golf & g, int hc);
//显示golf结构的内容
void showgolf(const Golf & g);