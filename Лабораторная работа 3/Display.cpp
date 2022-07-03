#include <iostream>
#include "Common.h"
#include "IOStack.h"
#include "IORingBuffer.h"
#include "IOQueueStack.h"
#include "IOQueueBuffer.h"

using namespace std;

enum MenuItems
{
    StackItems = 1,
    RingBufferItems = 2,
    QueueStackItems = 3,
    QueueBufferItems = 4,
    ExitMenuItem = 5
};

int main()
{
    setlocale(LC_ALL, "rus");
    while (true)
    {
        cout << "\nЧто вы хотите сделать?\n";
        cout << "1: Работать со Стеком\n";
        cout << "2: Работать с Кольцевым Буфером\n";
        cout << "3: Работать с Очередью на базе двух Стеков\n";
        cout << "4: Работать с Очередью на базе Кольцевого Буфера\n";
        cout << "5: Выйти из программы\n";
        cout << "\nВведите ваш вариант действий: ";
        int menuNumber = ReadingCorrectValue();
        cout << endl;
        switch (menuNumber)
        {
            case StackItems:
            {
                StackActions();
                break;
            }
            case RingBufferItems:
            {
                BufferActions();
                break;
            }
            case QueueStackItems:
            {
                QueueStackActions();
                break;
            }
            case QueueBufferItems:
            {
                QueueBufferActions();
                break;
            }
            case ExitMenuItem:
            {
                cout << "\n*Вы решили выйти из программы*\n";
                return 0;
            }
            default:
            {
                cout << "Вы ошиблись!\n";
                cout << "Введите правильно!\n\n";
                system("pause");
                break;
            }
        }
    }
    return 0;
}
