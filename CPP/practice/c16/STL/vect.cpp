/*
vector容器的使用
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Review
{
        string title;
        int rating;
};

bool FillReview(Review &r);
void ShowReview(const Review &r);

int main()
{
        vector<Review> books;
        Review temp;

        while(FillReview(temp))
                books.push_back(temp);
        
        int num = books.size();

        if(num > 0)
        {
                cout << "You entered the following: " << endl;
                for(int i = 0; i < num; i++)
                        ShowReview(books[i]);
        
                cout << "Reprising: " << endl;
                vector<Review>::iterator pr;  //迭代器变量
                for(pr = books.begin(); pr != books.end(); pr++)
                        ShowReview(*pr);

                vector<Review> oldlist(books);

                if(num > 3)
                {
                        books.erase(books.begin() + 1, books.begin() + 3);  //删除第二个和第三个元素， begin() + 3处不删除
                        cout << "After erasing: " << endl;
                        for(pr = books.begin(); pr != books.end(); pr++)
                                ShowReview(*pr);

                        books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);  //在books第一个元素前插入oldlist第二个元素，begin() + 2处不插入
                        cout << "After inserting: " << endl;
                        for(pr = books.begin(); pr != books.end(); pr++)
                                ShowReview(*pr);
                }
                books.swap(oldlist);  //交换两个容器的内容                
                cout << "Swapping contents of oldlist and books: " << endl;
                for(pr = books.begin(); pr != books.end(); pr++)
                        ShowReview(*pr);
        }
        else
                cout << "\nDone." << endl;
        
        return 0;
}

bool FillReview(Review &r)
{
        cout << "Enter book title (\"quit\" to quit): ";
        getline(cin, r.title);
        if(r.title == "quit")
                return false;

        cout << "Enter book rating: ";
        cin >> r.rating;

        if(!cin)
                return false;

        while(cin.get() != '\n');

        return true;
}

void ShowReview(const Review &r)
{
        cout << r.rating << "\t" << r.title << endl;
}