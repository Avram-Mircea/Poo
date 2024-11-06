#include "functii.h"

student::student()
{
    name = " ";
    password = " ";
    age = -1;
}

void student::getname()
{
    cin >> name;
}

void student::getage()
{
    scanf_s("%d", &age);
}

void student::getpassword()
{
    cin >> password;
}

void student::show()
{
    std::cout << name << endl << password << endl << book_3 << endl;
}

void student::login_student(string name, string password)
{
    this->name = name;
    this->password = password;
}

int student::exist()
{
    if (!name.compare(" ") && !password.compare(" "))
        return 0;
    else
        return 1;
}

void student::safe_in_file()
{
    fstream file(name + ".txt");
    if (file.is_open())
    {
        file.close();
        ofstream file_w(name + ".txt");

        file_w << password << endl << book_3 << endl;
        file_w.close();
    }
    else
    {
        file << password << endl << book_3 << endl;
        file.close();
    }
}

void student::allocate_book()
{
    int i, valid_name, size_of_option;
    char current_line_char[20] = {'\0'};
    char wanted_book[10] = {'\0'};
    char predecessor_line[20] = {'\0'};
    string copy_info_file, current_line_string;
    fstream file;

    file.open("carti.txt");

    //ask wanted book
    getchar();//clear buffer
    printf("Ce carte doriti sa imprumutati: ");
    gets_s(wanted_book);
    size_of_option = strlen(wanted_book);

    //search in file
    getline(file, current_line_string);
    strcpy_s(current_line_char, current_line_string.c_str());

    //search in file for wanted book
    while (strcmp(predecessor_line,current_line_char))//test if it reads all the file by comparing the former line and current line
    {                                                 //if they are the same it means we read all the file
        //test if the current line is the wanted book
        for (i = 0, valid_name = 1; valid_name && i != size_of_option; i++)
        {
            if (wanted_book[i] != current_line_char[i])
                valid_name = 0;
        }
        if (valid_name)
        {
            current_line_char[strlen(current_line_char) - 1]--;//decrease the number of the books
            
            copy_info_file += current_line_char;
            copy_info_file += '\n';
            
            current_line_char[strlen(current_line_char) - 1]++;

            strcpy_s(predecessor_line, current_line_char);
            getline(file, current_line_string);//get line from file
            strcpy_s(current_line_char, current_line_string.c_str());

            book_3 = wanted_book;//copy the name of the book
        }
        else
        {
            strcpy_s(predecessor_line, current_line_char);
            getline(file, current_line_string);
            strcpy_s(current_line_char, current_line_string.c_str());
            if (strcmp(predecessor_line, ""))//to do not put extra enters('\n')
            {
                copy_info_file += predecessor_line;
                copy_info_file += '\n';
            }
        }
    }

    file.close();

    ofstream file_w("carti.txt");
    file_w << copy_info_file;
    file_w.close();
}
void student::allocate_course()
{

}

student log_in()
{
    string user, password_try, password_real;
    student s;

    printf("Care este numele contului: ");
    cin >> user;

    ifstream file(user + ".txt");
    if (file.is_open())
    {
        printf("Parola: ");
        cin >> password_try;
        getline(file, password_real);

        if (!password_real.compare(password_try))
        {
            std::cout << "Buna " << user;
            s.login_student(user, password_real);
        }
        else
            printf("Parola gresita");
        file.close();
    }
    else
    {
        std::cout << "Nu exista cont cu numele " << user;
    }
    return s;
}

void wait_a_key()
{
    getchar();
    getchar();
}

void see_book_list()
{
    string s;
    ifstream file("carti.txt");

    if (!file.is_open())
    {
        printf("Eroare la deschiderea fisierului carti");
        return;
    }
    while (getline(file, s))
        std::cout << s << endl;

    file.close();
}

void see_course_list()
{
    string s;
    ifstream file("cursuri.txt");

    if (!file.is_open())
    {
        printf("Eroare la deschiderea fisierului cursuri");
        return;
    }
    while (getline(file, s))
        std::cout << s << endl;

    file.close();
}
