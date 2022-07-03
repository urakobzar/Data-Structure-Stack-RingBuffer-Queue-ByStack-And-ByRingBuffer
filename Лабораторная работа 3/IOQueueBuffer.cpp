#include "IOQueueBuffer.h"
#include <iostream>
#include "Common.h"

using namespace std;

enum MenuQueueBuffer
{
    QueueBufferMakingItem = 0,
    AddQueueBufferItem = 1,
    DeleteQueueBufferItem = 2,
    PrintQueueBufferItem = 3,
    QueueBufferExitItem = 4
};

/// @brief Функция вывода Очереди на экран
/// @param queueBuffer Переменная структуры Очереди
void PrintQueueBuffer(QueueBuffer& queueBuffer)
{
    if (queueBuffer.FilledPlaceCounter != 0)
    {
        cout << "\nКольцевой буфер:\n";
        for (int i = 0; i < queueBuffer.BufferSize; i++)
        {
            if (queueBuffer.IsPlaceFilled[i] == true)
            {
                cout << " | ";
                cout << queueBuffer.Buffer[i] << " | ";
            }
            if (queueBuffer.IsPlaceFilled[i] == false)
            {
                cout << " | ";
                cout << "  | ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Очередь пуста!\n";
        cout << "Возвращение в меню выбора\n";
    }
}

void QueueBufferActions()
{
    QueueBuffer queueBuffer;
    bool checkQueueMaking = false;
    bool queueExit = true;
    while (queueExit)
    {
        cout << "\nЧто вы хотите сделать?\n";
        if (!checkQueueMaking)
        {
            cout << "0: Создать очередь\n";
        }
        cout << "1: Добавить элемент в очередь\n";
        cout << "2: Удалить элемент из очереди\n";
        cout << "3: Вывести очередь\n";
        cout << "4: Выйти в главное меню\n";
        cout << "\nВведите ваш вариант действий: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case QueueBufferMakingItem:
            {
                if (checkQueueMaking)
                {
                    cout << "Очередь уже создана!\n";
                    system("pause");
                    break;
                }
                MakingQueueBuffer(queueBuffer);
                int sizeQueue = ReadingCorrectSize();
                for (int index = 0; index < sizeQueue; index++)
                {
                    cout << "Введите элемент очереди " << index + 1 << ": ";
                    int newElement = ReadingCorrectValue();
                    EnqueueQueueBuffer(queueBuffer, newElement);
                }
                checkQueueMaking = true;
                system("pause");
                break;
            }
            case AddQueueBufferItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                cout << "*Вы решили добавить";
                cout << " элемент в очередь*\n";
                cout << "\nВведите добавляемый элемент: ";
                int newElement = ReadingCorrectValue();
                EnqueueQueueBuffer(queueBuffer, newElement);
                PrintQueueBuffer(queueBuffer);
                system("pause");
                break;
            }
            case DeleteQueueBufferItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                if (queueBuffer.FilledPlaceCounter != 0)
                {
                    DequeueQueueBuffer(queueBuffer);
                    cout << "*Вы решили достать элемент";
                    cout << " из кольцевого буфера*\n";
                    cout << "Удаляемый элемент: ";
                    cout << queueBuffer.First << endl;
                    if (queueBuffer.FilledPlaceCounter != 0)
                    {
                        PrintQueueBuffer(queueBuffer);
                    }
                }
                else
                {
                    cout << "Очередь пуста!\n";
                    cout << "Возвращение в меню выбора\n";
                }
                system("pause");
                break;
            }
            case PrintQueueBufferItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                PrintQueueBuffer(queueBuffer);
                break;
            }
            case QueueBufferExitItem:
            {
                if (checkQueueMaking)
                {
                    DeleteQueue(queueBuffer);
                    cout << "*(Очередь автоматически удалена)*\n";
                }
                cout << "*Вы решили вернуться ";
                cout << "в главное меню*\n";
                queueExit = false;
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