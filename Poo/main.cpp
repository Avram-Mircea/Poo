#include<iostream>
#include"functions.h"
#include"student.h"
using namespace std;

int main()
{
	/*user _user;
	int option = 1;
	while (option)
	{
		system("cls");
		cout << "        Meniu\n---------------------\n1. Creare cont\n2. Logare\n3. Vezi lista carti\n4. Vezi lista cursuri\n5. Iesire alpicatie\n\nObtiune: ";
		cin >> option;
		switch (option)
		{
		case 1:
			_user = create_account();
			option = 0;
			break;
		case 2:
			_user = log_in();
			option = 0;
			break;
		case 3:
			//see_books_list();
			break;
		case 4:
			//see_courses_list();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "\033[91mObtiune invalida!\033[0m";
			wait_a_key();
			break;
		}
	}

	if (_user.is_student())
	{
		student _student(_user);
		_student.show();
	}
	else
	{
		_user.show();
	}*/
	
	/*string current_line, file_content;
	ifstream file;
	bool a;

	file.open("carti.txt");
	if (!file.is_open())
		return -1;
	a = file.eof();
	while (!a)
	{
		getline(file, current_line);
		cout << current_line << endl;
		a = file.eof();
	}*/
	student s;
	s.allocate_book();
	return 0;
}