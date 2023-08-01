#include <iostream>
#include <string>
#include "p2_stock10.h"


//默认构造函数
Stock::Stock()
{
        std::cout << "Default constructor called" << std::endl;
        company = "no name";
        shares = 0;
        share_val = 0.0;
        total_val = 0.0;
}

Stock::Stock(const std::string &co, long num, double price) //获取股票信息
{
        company = co;
        if (num < 0)
        {
                std::cout << "Number of shares can't be negative; " << company
                          << " shares set to 0." << std::endl;
                shares = 0;
        }
        else
                shares = num;
        share_val = price;
        set_tot();
}

void Stock::buy(long num, double price) //购买股票
{
        if (num < 0)
        {
                std::cout << "Number of shares can't be negative; " << company
                          << " shares set to 0." << std::endl;
        }
        else
                shares += num;
        share_val = price;
        set_tot();  
}
void Stock::sell(long num, double price) //卖出股票
{
        if (num < 0)
        {
                std::cout << "Number of shares can't be negative; " << company
                          << " shares set to 0." << std::endl;
        }
        else if(num > shares)
                std::cout << "You can't sell more than you have! " << std::endl;
        else
        {
                shares -= num;
                share_val = price;
                set_tot();
        }
}
void Stock::update(double price) //更新股票价格
{
        share_val = price;
        set_tot();
}
void Stock::show() const//显示股票信息
{
        std::cout << "Company: " << company << std::endl;
        std::cout << "Shares: " << shares << std::endl;
        std::cout << "Share Price: $" << share_val << std::endl;
        std::cout << "Total Worth: $" << total_val << std::endl;
}

Stock::~Stock()
{
        std::cout << "Bye, " << company << "!\n";
}