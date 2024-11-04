#include "functii.h"

int main()
{
    student s1;
    int quit = 1, option;

    /*s1.getname();
    s1.getage();
    s1.getpassword();

    s1.safe_in_file();

    s1.getname();
    s1.getpassword();
    s1.allocate_book();
    s1.safe_in_file();*/

    /*s1.getname();
    s1.getpassword();
    s1.safe_in_file();*/

    while(quit)
    {
        system("cls");
        printf("        Meniu\n---------------------\n");
        printf("1. Vezi lista carti\n2. Vezi lista cursuri\n3. Logare in cont\n4. Imprumutare carte\n5. Iesire\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            see_book_list();
            wait_a_key();
            break;
        case 2:
            see_course_list();
            wait_a_key();
            break;
        case 3:
            s1 = log_in();
            wait_a_key();
            break;
        case 4:
            if(s1.exist())
            {
                s1.allocate_book();
                s1.safe_in_file();
            }
            else
            {
                printf("Nu sunteti logat");
                wait_a_key();
            }
            break;
        case 5:
            quit = 0;
            break;
        default:
            printf("Obtiune invalida");
            wait_a_key();
        }
    }
    return 0;
}
