#ifndef FUNCTII_H
#define FUNCTII_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class student
{
public:
    student();

    void getname();
    void getage();
    void getpassword();
    void login_student(string name, string password);
    int exist();
    void show();

    void safe_in_file();
    void allocate_book();
    void allocate_course();

private:
    string name;
    int age;
    string password;
    string book_1, book_2, book_3;
};

student log_in();
void wait_a_key();
void see_book_list();
void see_course_list();


#endif // FUNCTII
