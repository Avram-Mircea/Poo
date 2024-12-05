#ifndef MENU_H
#define MENU_H

#include"student.h"

class menu
{
public:
	menu();

	void menu_log();
	void menu_student(student* _student);
	void menu_admin();

	user log_in();
	void wait_a_key();
	user create_account();
};

#endif // !

