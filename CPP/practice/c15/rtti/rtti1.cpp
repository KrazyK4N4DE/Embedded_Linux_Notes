#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using namespace std;

class Grand
{
private:
        int hold;
public:
        Grand(int h = 0) : hold(h) {}
        virtual void Speak() const { cout << "I am a grand class!" << endl; }
        virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
        Superb(int h = 0) : Grand(h) {}
        void Speak() const { cout << "I am a superb class!!" << endl; }
        virtual void Say() const { cout << "I hold the superb value of " << Value() << "!" << endl; }
};

class Magnificient : public Superb
{
private:
        char ch;
public:
        Magnificient(int h = 0, char c = 'A') : Superb(h), ch(c) {}
        void Speak() const { cout << "I am a magnificient class!!!" << endl; }
        void Say() const { cout << "I hold the character " << ch << " and the integer " << Value() << "!" << endl; }
};

Grand *GetOne();

int main()
{
        Grand *pg;
        Superb *ps;

        srand(time(0));
        
        for(int i = 0; i < 5; i++)
        {
                pg = GetOne();
                cout << "Now processing type " << typeid(*pg).name() << "." << endl;
                pg -> Speak();  // 三个类中都有的虚函数

                //运行时会出现段错误：基类指针指向派生类对象，但是强制转换为派生类指针，这样会导致指针指向的内存空间不连续，从而出现段错误
                //ps = (Superb *)pg;  
                //ps -> Say();  // 只有Superb和Magnificient类中有的虚函数
                if(ps = dynamic_cast<Superb *>(pg))
                        ps -> Say();
                if(typeid(Magnificient) == typeid(*pg))
                        cout << "Yes, you're really magnificient!" << endl;
        }
        return 0;
}

Grand *GetOne()
{
        Grand *p;

        switch(rand() % 3)
        {
                case 0:
                        p = new Grand(rand() % 100);
                        break;
                case 1:
                        p = new Superb(rand() % 100);
                        break;
                case 2:
                        p = new Magnificient(rand() % 100, 'A' + rand() % 26);
                        break;
        }

        return p;
}