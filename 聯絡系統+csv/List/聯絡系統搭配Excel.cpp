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
        cout << "請輸入好友姓名：" << endl;
        cin >> name;
        cout << "請輸入好友生日：" << endl;
        cin >> birthday;
        cout << "請輸入好友電話：" << endl;
        cin >> phone;
        /*建立並輸入好友細節類別*/

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
                    cout << "姓名：" << name << endl;
                    temps = "";
                    count++;
                    continue;
                }
                if (count == 1)
                {
                    birthday = temps;
                    cout << "生日：" << birthday << endl;
                    temps = "";
                    count++;
                    continue;
                }
                if (count == 2)
                {
                    phone = temps;
                    cout << "電話：" << phone << endl;
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
        cout << "請輸入要修改的好友姓名：";
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
                        cout << "找到好友 " << aim;
                        cout << "請輸入要更改的部分 1>姓名 2>生日> 3>電話：";
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
                        cout << "請輸入更改後的姓名：";
                        cin >> name;
                        birthday += ch;
                        first_time = false;
                    }
                    else
                    {
                        static string *goal = &birthday; //讀取birthday->2001/12/26會少一個字
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
    cout << "＊＊＊＊好友系統＊＊＊＊" << endl;
    cout << "＊                  ＊" << endl;
    cout << "＊   1 > 新增好友    ＊" << endl;
    cout << "＊   2 > 列印名單    ＊" << endl;
    cout << "＊   3 > 修改名單    ＊" << endl;
    cout << "＊   0 >   退出      ＊" << endl;
    cout << "＊                  ＊" << endl;
    cout << "＊＊＊＊＊＊＊＊＊＊＊＊\n"
         << endl;
    cout << "輸入選項：";
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