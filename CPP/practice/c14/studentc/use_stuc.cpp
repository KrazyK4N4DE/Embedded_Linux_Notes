#include <iostream>
#include "studentc.h"

using namespace std;

const int pupils = 3;  // 学生3名
const int quizzes = 5; // 5个科目

void set(Student &sa, int n);

int main()
{
        Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
        int i;

        for(i = 0; i < pupils; i++)
                set(ada[i], quizzes);
        
        cout << "Student List:\n";
        for(i = 0; i < pupils; i++)
        {
                cout << ada[i];
                cout << "Average: " << ada[i].Average() << endl;
        }
        return 0;
}

void set(Student &sa, int n)
{
        cout << "Please enter the student's name: ";
        getline(cin, sa);
        cout << "Please enter " << n << " quiz scores: \n";
        for(int i = 0; i < n; i++)
                cin >> sa[i];  // 重载下标，而不是重载>>
        while(cin.get() != '\n');
}