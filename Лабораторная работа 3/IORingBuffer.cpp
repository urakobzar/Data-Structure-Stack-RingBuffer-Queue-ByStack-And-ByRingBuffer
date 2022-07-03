#include "IORingBuffer.h"
#include <iostream>
#include "Common.h"

using namespace std;

enum MenuRingBuffer
{
    FreePlace = 1,
    EmployedPlace = 2,
    AddRingBufferItem = 3,
    DeleteRingBufferItem = 4,
    PrintRingBufferItem = 5,
    RingBufferExitItem = 6
};

/// @brief Функция вывода Кольцевого Буфера на экран
/// @param ringBuffer Переменная структуры Кольцевого Буфера
void PrintRingBuffer(RingBuffer& ringBuffer)
{
    cout << "\nКольцевой буфер:\n";
    for (int i = 0; i < ringBuffer.BufferSize; i++)
    {
        if (ringBuffer.IsPlaceFilled[i] == true)
        {
            cout << " | ";
            cout << ringBuffer.Buffer[i] << " | ";
        }
        if (ringBuffer.IsPlaceFilled[i] == false)
        {
            cout << " | ";
            cout << "  | ";
        }
    }
    cout << endl;
}

void BufferActions()
{
    RingBuffer ringBuffer;
    MakingRingBuffer(ringBuffer);
    bool ringExit = true;
    while (ringExit)
    {
        cout << "\nЧто вы хотите сделать?\n";
        cout << "1: Количество свободных ячеек\n";
        cout << "2: Количество занятых ячеек\n";
        cout << "3: Добавление элемента\n";
        cout << "4: Удаление элемента\n";
        cout << "5: Вывод кольцевого буфера\n";
        cout << "6: Закончить работу с кольцевым буфером\n";
        cout << "\nВведите ваш вариант действий: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case FreePlace:
            {
                cout << "Число свободных ячеек: ";
                cout << FreePlaceCount(ringBuffer);
                cout << endl;
                system("pause");
                break;
            }
            case EmployedPlace:
            {
                cout << "Число занятых ячеек: ";
                cout << FilledPlaceCount(ringBuffer);
                cout << endl;
                system("pause");
                break;
            }
            case AddRingBufferItem:
            {
                cout << "*Вы решили добавить";
                cout << " элемент в кольцевой буфер*\n";
                cout << "\nВведите добавляемый элемент: ";
                int newElement = ReadingCorrectValue();
                AddRingBuffer(ringBuffer, newElement);
                PrintRingBuffer(ringBuffer);
                system("pause");
                break;
            }
            case DeleteRingBufferItem:
            {
                if (FilledPlaceCount(ringBuffer) != 0)
                {
                    DeleteRingBuffer(ringBuffer);
                    cout << "*Вы решили достать элемент";
                    cout << " из кольцевого буфера*\n";
                    cout << "Удаляемый элемент: ";
                    cout << ringBuffer.First << endl;
                    if (FilledPlaceCount(ringBuffer) != 0)
                    {
                        PrintRingBuffer(ringBuffer);
                    }
                }
                else
                {
                    cout << "Кольцевой буфер пуст!\n";
                    cout << "Возвращение в меню выбора\n";
                }
                system("pause");
                break;
            }
            case PrintRingBufferItem:
            {
                PrintRingBuffer(ringBuffer);
                break;
            }
            case RingBufferExitItem:
            {
                cout << "*Вы решили вернуться ";
                cout << "в главное меню*\n";
                ringExit = false;
                DeleteBuffer(ringBuffer);
                system("pause");
                break;
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
}
