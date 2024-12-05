#ifndef STUDENT_H
#define STUDENT_H
#include"user.h"

class student : public user
{
public:
	student() {};
	student(user* _user);
	void save_info_student();
	void allocate_book();
private:
	string book_3;
};

#endif // !STUDENT_H