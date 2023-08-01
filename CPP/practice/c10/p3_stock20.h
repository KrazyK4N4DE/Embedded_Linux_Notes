#ifndef Whatever
#define Whatever

#include<string>

class Stock
{
private: //私有成员，只能在类内部访问，可以通过public的方法间接访问
        std::string company; //公司名称
        long shares; //股票数量
        double share_val; //股票单价
        double total_val; //股票总价
        void set_tot() //转换成内联函数
        {
                total_val = shares * share_val;
        }
public:
        //获取股票信息
        Stock(); //默认构造函数
        //Stock(const std::string &co = "No name", long num = 101, double price = 1.3); //默认构造函数
        Stock(const std::string &co, long num, double price); //构造函数
        ~Stock(); //析构函数
        //购买股票
        void buy(long num, double price); 
        //卖出股票
        void sell(long num, double price); 
        //更新股票价格
        void update(double price); 
        //显示股票信息
        void show() const; 
        const Stock &topval(const Stock &s) const;
};

#endif