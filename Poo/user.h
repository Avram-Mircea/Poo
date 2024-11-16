#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class user
{
public:
	user();
	void set_user(string _name, string _password, string _position);
	int exist();
	void show();
	string get_name();
	string get_password();
	bool is_student();
protected:
	string name;
	string password;
	string position;
};


#endif // !USER_H