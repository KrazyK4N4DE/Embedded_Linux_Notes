#ifndef __3_GOLF_H__
#define __3_GOLF_H__

const int LEN = 40;

class Golf
{
private:
        char fullname[LEN];
        int handicap;
public:
        //构造函数
        Golf(const char * name, int hc);
        //默认构造函数
        Golf();
        //重置handicap值
        void Reset(int hc);
        //显示
        void Show() const;
};

#endif