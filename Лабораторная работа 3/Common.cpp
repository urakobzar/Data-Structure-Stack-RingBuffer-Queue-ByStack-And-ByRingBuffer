#include "Common.h"
#include <iostream>

using namespace std;

int ReadingCorrectValue()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            break;
        }
        cout << "К сожалению, Вы ошиблись\n";
        cout << "(Вводимое значение должно быть целым числом)\n";
        cout << "Введите снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int ReadingCorrectSize()
{
    int size;
    while (true)
    {
        cout << "Введите пожалуйста начальное количество элементов: ";
        cin >> size;
        if (size <= 0)
        {
            cout << "К сожалению, Вы ошиблись\n";
            cout << "(Начальное количество должно быть целым";
            cout << " числом больше 0)\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return size;
}

bool CheckDataStructureMaking(bool checkMaking)
{
    if (!checkMaking)
    {
        cout << "Структура данных ещё не создана!\n";
        cout << "Возвращение в меню выбора\n";
        system("pause");
        return false;
    }
}
