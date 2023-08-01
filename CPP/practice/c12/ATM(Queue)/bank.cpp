/*
* @brief  模拟银行排队FIFO
*/
#include <iostream>
#include "queue.h"

int main()
{
        int qs;
        Item cus;
        int i =0; //计数器
        int cus_num = 0;

        cout << "Enter maximum size of queue: ";
        cin >> qs;

        Queue line(qs);

        while(!line.isfull())
        {
                cus.Set(i++);
                line.enqueue(cus);
                cus_num++;
        }
        cout << "Customers: " << cus_num << endl;

        while(!line.isempty())
        {
                line.dequeue(cus);
                cus_num--;
        }
        cout << "Now, customers: " << cus_num << endl;
        
        return 0;
}