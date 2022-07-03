#include "IOStack.h"
#include <iostream>
#include "Common.h"

using namespace std;

enum MenuStack
{
    StackMakingItem = 0,
    PushItem = 1,
    PopItem = 2,
    PrintStackItem = 3,
    StackExitItem = 4
};

void StackActions()
{
    Stack stack;
    MakingStack(stack);
    bool checkStackMaking = false;
    bool stackExit = true;
    while (stackExit)
    {
        cout << "\nЧто вы хотите сделать?\n";
        if (!checkStackMaking)
        {
            cout << "0: Создания стека\n";
        }
        cout << "1: Функции помещения в стек\n";
        cout << "2: Функция извлечения из стека\n";
        cout << "3: Вывод стека\n";
        cout << "4: Закончить работу со стеком\n";
        cout << "\nВведите ваш вариант действий: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case StackMakingItem:
            {
                if (!checkStackMaking)
                {
                    cout << "*Вы решили создать стек*\n";
                    int size = ReadingCorrectSize();
                    for (int index = 0; index < size; index++)
                    {
                        cout << "Введите элемент очереди " << index + 1 << ": ";
                        int newElement = ReadingCorrectValue();
                        Push(stack, newElement);
                    }
                    checkStackMaking = true;
                }
                else
                {
                    cout << "Стек уже создан!\n";
                }
                system("pause");
                break;
            }
            case PushItem:
            {
                if (!CheckDataStructureMaking(checkStackMaking))
                {
                    break;
                }
                cout << "*Вы решили добавить элемент в стек*";
                cout << endl << endl;
                cout << "Введите добавляемый в стек элемент: ";
                int newElement = ReadingCorrectValue();
                Push(stack, newElement);
                system("pause");
                break;
            }
            case PopItem:
            {
                if (!CheckDataStructureMaking(checkStackMaking))
                {
                    break;
                }
                if (stack.Top > 0)
                {
                    cout << "*Вы решили извлечь элемент";
                    cout << " из стека*\n";
                    cout << "Извлекаемый элемент: ";
                    cout << stack.Buffer[stack.Top - 1];
                    cout << endl;
                    Pop(stack);
                }
                else
                {
                    cout << "Стек пуст!\n";
                    cout << "Возвращение в меню выбора\n";
                }
                system("pause");
                break;
            }
            case PrintStackItem:
            {
                if (!CheckDataStructureMaking(checkStackMaking))
                {
                    break;
                }
                cout << "*Вы решили вывести стек*\n";
                cout << "Стек: ";
                for (int i = 0; i < stack.Top; i++)
                {
                    cout << stack.Buffer[i] << "   ";
                }
                cout << "\n";
                system("pause");
                break;
            }
            case StackExitItem:
            {
                if (checkStackMaking)
                {
                    delete[] stack.Buffer;
                    cout << "*(Стек автоматически удален)*\n";
                }
                cout << "\n*Вы решили вернуться ";
                cout << "в главное меню*\n";
                stackExit = false;
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