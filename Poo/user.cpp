#include "user.h"

user::user()
{ }

void user::set_user(string _name, string _password, string _position)
{
	name = _name;
	password = _password;
	position = _position;
}

int user::exist()
{
	return name.compare("");
}

void user::show()
{
	cout << name << endl << password << endl << position;
}

string user::get_name()
{
	return name;
}

string user::get_password()
{
	return password;
}

bool user::is_student()
{
	if (!position.compare("student"))
		return true;
	else
		return false;
}