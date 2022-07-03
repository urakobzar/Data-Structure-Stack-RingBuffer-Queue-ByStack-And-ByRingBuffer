#include <iostream>
#include "Common.h"
#include "IOQueueStack.h"

using namespace std;

enum MenuQueueStack
{
    QueueStackMakingItem = 0,
    AddQueueStackItem = 1,
    DeleteQueueStackItem = 2,
    PrintQueueStackItem = 3,
    QueueStackExitItem = 4
};

/// @brief Функция вывода Стека
/// @param stack Переменная структуры Стека
void PrintStack(QueueBasedStack& stack)
{
    for (int i = 0; i < stack.Tail; i++)
    {
        cout << " | ";
        cout << stack.Buffer[i] << " | ";
    }
}


/// @brief Функкция вывода Очереди на экран
/// @param popStack Переменная структуры Очереди
/// @param pushStack Переменная структуры Очереди
void PrintQueueStack(QueueBasedStack& popStack, QueueBasedStack& pushStack)
{  
    cout << "Очередь: ";
    if ((pushStack.Tail != 0) || (popStack.Tail != 0))
    {
        if (popStack.Tail != 0)
        {
            for (int i = popStack.Tail - 1; i >= 0; i--)
            {
                cout << " | ";
                cout << popStack.Buffer[i] << " | ";
            }
        }
        PrintStack(pushStack);
        cout << endl;
        cout << "PushStack: ";
        PrintStack(pushStack);
        cout << endl;
        cout << "PopStack: ";
        PrintStack(popStack);
        cout << endl;
    }
    else
    {
        cout << "Очередь пуста!\n";
        cout << "Возвращение в меню выбора\n";
    }       
}

void QueueStackActions()
{
    QueueBasedStack pushStack;
    QueueBasedStack popStack;
    MakingStack(pushStack);
    MakingStack(popStack);
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
            case QueueStackMakingItem:
            {
                if (checkQueueMaking)
                {
                    cout << "Очередь уже создана!\n";
                    system("pause");
                    break;
                }
                cout << "*Вы решили создать очередь*\n";
                int sizeQueue = ReadingCorrectSize();
                for (int index = 0; index < sizeQueue; index++)
                {
                    cout << "Введите элемент очереди " << index + 1 << ": ";
                    int addElement = ReadingCorrectValue();
                    EnqueueStack(pushStack, addElement);
                }
                checkQueueMaking = true;
                system("pause");
                break;
            }
            case AddQueueStackItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                cout << "*Вы решили добавить";
                cout << " элемент в очередь*\n";
                cout << "\nВведите добавляемый элемент: ";
                int addElement = ReadingCorrectValue();
                EnqueueStack(pushStack, addElement);
                system("pause");
                break;
            }
            case DeleteQueueStackItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                cout << "*Вы решили удалить";
                cout << " элемент из очереди*\n";
                if (!IsStackEmpty(popStack))
                {
                    DequeueStack(popStack);
                    cout << "Удаляемый элемент: ";
                    cout << popStack.Buffer[popStack.Tail];
                    cout << endl;
                }
                else if (!IsStackEmpty(pushStack))
                {
                    ExchangeElements(pushStack, popStack);
                    DequeueStack(popStack);
                    cout << "Удаляемый элемент: ";
                    cout << popStack.Buffer[popStack.Tail];
                    cout << endl;
                }
                else
                {
                    cout << "Очередь пуста!\n";
                    cout << "Возвращение в меню выбора\n";
                }
                system("pause");
                break;
            }
            case PrintQueueStackItem:
            {
                if (!CheckDataStructureMaking(checkQueueMaking))
                {
                    break;
                }
                PrintQueueStack(popStack, pushStack);
                system("pause");
                break;
            }
            case QueueStackExitItem:
            {
                if (checkQueueMaking)
                {
                    DeleteQueueStack(pushStack);
                    DeleteQueueStack(popStack);
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