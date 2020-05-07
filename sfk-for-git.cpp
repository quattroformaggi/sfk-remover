#include <iostream>
#include <windows.h> //for based code
#include <lmcons.h>
#include <conio.h> //_getch()
using namespace std;

void exec(string strong)
{
    const char* comchar = strong.c_str();
    system(comchar);
}

int main()
{
    unsigned short choice;
    string uname;
    string comstr;
    system("title .sfk Remover @quattroformaggi");
    cout << "Part 1: Choose one of the basic directories:" << endl << "[1] Desktop" << endl << "[2] Downloads" << endl << "[3] Videos" << ":";
    cin >> choice;

    if ((choice != 1) && (choice != 2) && (choice != 3)) //
    {
        system("cls");
        cout << "Error with the choice input: a digit between 1-3 needs to be chosen, otherwise this error appears. Shutting down..." << endl;
        _getch();
        return -1;
    }

    ///////////////////////////////////////////based code <>
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;

    if (GetUserName((TCHAR*)username, &size))
        wcout << L"Your username is: {" << username << L"}" << endl;
    else
    {
        system("cls");
        cout << "Error with the username unput, probably you don't have one? Shutting down..." << endl;
        _getch();
        return -2;
    }
    ///////////////////////////////////////////

    cout << "Part 2: To confirm the start of the removing process, enter the username above: ";
    cin >> uname;

    switch (choice)
    {
    case 1: {comstr += "cd /d \"C:\\users\\" + uname + "\\desktop\" & dir & del /p *.sfk & echo. & echo [Enter] to clear the screen and exit"; exec(comstr); break; } //<>
    case 2: {comstr += "cd /d \"C:\\users\\" + uname + "\\downloads\" & dir & del /p *.sfk & echo. & echo [Enter] to clear the screen and exit"; exec(comstr); break; } //<>
    case 3: {comstr += "cd /d \"C:\\users\\" + uname + "\\videos\" & dir & del /p *.sfk & echo. & echo [Enter] to clear the screen and exit"; exec(comstr); break; } //<>
    }
    cout << "The End" << endl << "-- @quattroformaggi, 2020" << endl;
    _getch();
    system("cls");
    return 1;
}