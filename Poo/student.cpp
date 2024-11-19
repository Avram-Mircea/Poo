#include "student.h"
#define MAX_LENGTH_CHAR 20

student::student(user _user)
{
	name = _user.get_name();
	password = _user.get_password();
	position = "student";
}

void student::safe_info_student()
{
	ofstream file(this->name + ".txt");
	file << this->password << '\n' << this->position << '\n' << this->book_3;
	file.close();
}

void student::allocate_book()
{
	string current_line, file_content;
	char wanted_book[MAX_LENGTH_CHAR], line_char[MAX_LENGTH_CHAR];
	ifstream file;
	bool end_file = false, same_word;
	int i, length_wanted_book, length_current_line;

	file.open("carti.txt");

	cout << "Ce carte doriti sa imprumutati: ";
	cin.getline(wanted_book, MAX_LENGTH_CHAR);
	length_wanted_book = strlen(wanted_book);

	while (!end_file)
	{
		getline(file, current_line);
		strcpy_s(line_char, current_line.c_str());

		same_word = true;
		for (i = 0; same_word && i != length_wanted_book; i++)
			if (line_char[i] != wanted_book[i])
				same_word = false;

		if (same_word)
		{
			length_current_line = strlen(line_char);
			if (line_char[length_current_line - 1] == '0' && line_char[length_current_line - 2] == ' ')
			{
				cout << "\033[91mNu se poate aloca cartea.\nNumarul cartilor este 0.\033[0m";
				getchar();
			}
			else if (line_char[length_current_line - 1] != '0')
			{
				line_char[length_current_line - 1]--;
				book_3 = wanted_book;
				safe_info_student();
			}
			else
			{
				for (i = 1; line_char[length_current_line - i] == '0'; i++)
					;
				
				if (line_char[length_current_line - i] != '1')
				{
					line_char[length_current_line - i]--;
					for (i = length_current_line - i + 1; i != length_current_line; i++)
						line_char[i] = '9';
				}
				else if (line_char[length_current_line - i - 1] != ' ')
				{
					line_char[length_current_line - i] = '0';
					for (i = length_current_line - i + 1; i != length_current_line; i++)
						line_char[i] = '9';
				}
				else
				{
					length_current_line--;
					for (i = length_current_line - i + 1; i != length_current_line; i++)
						line_char[i] = '9';
					line_char[length_current_line] = '\0';
				}
				book_3 = wanted_book;
				safe_info_student();
			}
			file_content += line_char;
			if (!file.eof())
				file_content += '\n';
		}
		else if(current_line.compare("\n"))
		{
			file_content += current_line;
			if (!file.eof())
				file_content += '\n';
		}
		end_file = file.eof();
	}
	file.close();

	ofstream file_w("carti.txt");
	file_w << file_content;
	file_w.close();
}
