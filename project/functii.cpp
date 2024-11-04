#include "functii.h"

student::student()
{
    name = " ";
    password = " ";
}

void student::getname()
{
    cin >> name;
}

void student::getage()
{
    scanf("%d", &age);
}

void student::getpassword()
{
    cin >> password;
}

void student::show()
{
    cout << name << endl << password << endl << book_3 << endl;
}

void student::login_student(string name, string password)
{
    this->name = name;
    this->password = password;
}

int student::exist()
{
    if(!name.compare(" ") && !password.compare(" "))
        return 0;
    else
        return 1;
}

void student::safe_in_file()
{
    fstream file(name + ".txt");
    if(file.is_open())
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
    int i = 0, valid_name, size_of_option;
    char current_line[20], wanted_book[10];
    string copy_info_file;
    fstream file;

    file.open("carti.txt");

    //ask wanted book
    getchar();//clear buffer
    printf("Ce carte doriti sa imprumutati: ");
    gets(wanted_book);
    size_of_option = strlen(wanted_book);

    //search in file
    while(file.get(current_line[i]))
    {
        if(current_line[i] == '\n')//end of a line
        {
            //test if the current line is the wanted book
            for(i = 0, valid_name = 1; valid_name && i != size_of_option; i++)
                if(wanted_book[i] != current_line[i])
                    valid_name = 0;

            if(valid_name)
            {
                current_line[strlen(current_line)-2]--;//decrease the number of the books

                book_3 = wanted_book;//copy the name of the book
            }

            copy_info_file += current_line;//put all the lines in one string that will rewrite the book file
            i = 0;
        }
        else
            i++;
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
    if(file.is_open())
    {
        printf("Parola: ");
        cin >> password_try;
        getline(file, password_real);

        if(!password_real.compare(password_try))
        {
            cout << "Buna " << user;
            s.login_student(user,password_real);
        }
        else
            printf("Parola gresita");
        file.close();
    }
    else
    {
        cout << "Nu exista cont cu numele " << user;
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

    if(!file.is_open())
    {
        printf("Eroare la deschiderea fisierului carti");
        return;
    }
    while(getline(file, s))
        cout << s << endl;

    file.close();
}

void see_course_list()
{
    string s;
    ifstream file("cursuri.txt");

    if(!file.is_open())
    {
        printf("Eroare la deschiderea fisierului cursuri");
        return;
    }
    while(getline(file, s))
        cout << s << endl;

    file.close();
}
