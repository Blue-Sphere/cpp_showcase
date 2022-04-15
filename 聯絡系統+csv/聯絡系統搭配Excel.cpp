#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Friend_detal
{
private:
    string name;
    string birthday;
    string phone;

public:
    void append()
    {
        cout << "�п�J�n�ͩm�W�G" << endl;
        cin >> name;
        cout << "�п�J�n�ͥͤ�G" << endl;
        cin >> birthday;
        cout << "�п�J�n�͹q�ܡG" << endl;
        cin >> phone;
        /*�إߨÿ�J�n�ͲӸ`���O*/

        fstream file;
        file.open("List/list.csv", ios::app);
        file << name << ',' << birthday << ',' << phone << endl;
        file.close();
    }
    void print_list()
    {
        fstream file;
        char ch;
        string temps;
        file.open("List/list.csv", ios::in);
        cout << "=========================\n";
        while ((ch = file.get()) != EOF)
        {
            if (ch != ',' && ch != '\n')
                temps += ch;
            else if (ch == ',' || ch == '\n')
            {
                static unsigned short int count = 0;
                if (count == 0)
                {
                    name = temps;
                    cout << "�m�W�G" << name << endl;
                    temps = "";
                    count++;
                    continue;
                }
                if (count == 1)
                {
                    birthday = temps;
                    cout << "�ͤ�G" << birthday << endl;
                    temps = "";
                    count++;
                    continue;
                }
                if (count == 2)
                {
                    phone = temps;
                    cout << "�q�ܡG" << phone << endl;
                    temps = "";
                    count = 0;
                }
                cout << "=========================\n";
            }
        }
        file.close();
    }
    void edit()
    {
        fstream file;
        file.open("List/list.csv", ios::out | ios::in);
        bool found_it = false;
        char ch;
        unsigned short int choice;
        string serch_name, aim, update;
        cout << "�п�J�n�ק諸�n�ͩm�W�G";
        cin >> aim;
        while ((ch = file.get()) != EOF)
        {
            if (found_it == false)
            {
                update += ch;
                if (ch != ',' && ch != '\n')
                    serch_name += ch;
                else
                {
                    if (serch_name.compare(aim) == 0)
                    {
                        found_it = true;
                        cout << "���n�� " << aim;
                        cout << "�п�J�n��諸���� 1>�m�W 2>�ͤ�> 3>�q�ܡG";
                        cin >> choice;
                    }
                    serch_name = "";
                    continue;
                }
            }
            else if (found_it == true)
            {
                static bool first_time = true;
                if (choice == 1)
                {
                    if (first_time == true)
                    {
                        cout << "�п�J���᪺�m�W�G";
                        cin >> name;
                        birthday += ch;
                        first_time = false;
                    }
                    else
                    {
                        static string *goal = &birthday; //Ū��birthday->2001/12/26�|�֤@�Ӧr
                        if (ch == ',')
                        {
                            goal = &phone;
                        }
                        else if (ch != ',')
                        {
                            *goal += ch;
                        }
                    }
                }

                if (ch == '\n')
                {
                    found_it = false;
                    for (int i = 0; i < aim.size() + 1; i++)
                        update.pop_back();
                    update += name + ',' + birthday + ',' + phone;
                    continue;
                } // Fixing_2
            }
        }
        file.close();
        //update
        file.open("List/list.csv", ios::out | ios::trunc);
        file << update;
        file.close();
    }
};

void menu_todo(int ch)
{
    switch (ch)
    {
    case 1:
    {
        Friend_detal f, *fptr = &f;
        fptr->append();
        break;
    }

    case 2:
    {
        Friend_detal f, *fptr = &f;
        fptr->print_list();
        break;
    }

    case 3:
    {
        Friend_detal f, *fptr = &f;
        fptr->edit();
        break;
    }
    }
}
void print_menu()
{
    unsigned short int choice;
    cout << "���������n�ͨt�Ρ�������" << endl;
    cout << "��                  ��" << endl;
    cout << "��   1 > �s�W�n��    ��" << endl;
    cout << "��   2 > �C�L�W��    ��" << endl;
    cout << "��   3 > �ק�W��    ��" << endl;
    cout << "��   0 >   �h�X      ��" << endl;
    cout << "��                  ��" << endl;
    cout << "������������������������\n"
         << endl;
    cout << "��J�ﶵ�G";
}

int main()
{
    unsigned short int g_choice;
    while (true)
    {
        print_menu();
        scanf("%d", &g_choice);
        if (g_choice == 0)
            break;
        else
            menu_todo(g_choice);
        return 0;
    }
    return 0;
}