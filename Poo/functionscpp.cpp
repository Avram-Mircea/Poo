#include"functions.h"

user log_in()
{
	string user_name, password_try, password_real, _position;
	user _user;
	char result;
	do
	{
		system("cls");
		cout << "Numele contului: ";
		cin >> user_name;

		ifstream file(user_name + ".txt");
		if (file.is_open())
		{
			//account exists
			getline(file, password_real);

			do
			{
				//test the password
				cout << "Parola: ";
				cin >> password_try;
				result = password_real.compare(password_try);
				if (result)
				{
					//wrong password
					cout << "\033[91mParola gresita\033[0m";
					wait_a_key();
					cout << "\x1b[2K";
					cout << "\x1b[1A" << "\x1b[2K";
					cout << "\x1b[1A" << "\x1b[2K";
				}
			} while (result);

			//see what position the user have
			getline(file, _position);
			if (_position.compare("admin"))
				_user.set_user(user_name, password_real, "student");
			else
				_user.set_user(user_name, password_real, "admin");

			file.close();
			system("cls");
			cout << "Buna " << user_name << '!';
			wait_a_key();
		}
		else
		{
			//account does not exist
			cout << "\033[91mNu exista cont!\033[0m" << endl << endl << "Creati cont?[D/N]" << endl;
			cin >> result;

			if (result == 68)
				_user = create_account();//create a new account
			else
			{
				cout << endl << "\033[91mNu puteti imprumuta carti sau sa va inscrieti la cursuri fara cont!\033[0m";
				wait_a_key();
			}
		}
	} while (!_user.exist());

	return _user;
}

user create_account()
{
	string name, password, position;

	system("cls");
	cout << endl << "Numele dumneavoastra: ";
	cin >> name;
	cout << "Parola contului: ";
	cin >> password;
	cout << "Functia: ";
	cin >> position;

	//create a new file with username and enter the password and position in it
	ofstream file(name + ".txt");
	file << password << endl << position << endl;
	file.close();

	user _user;
	_user.set_user(name, password, position);
	return _user;
}

void wait_a_key()
{
	getchar();
	getchar();
}