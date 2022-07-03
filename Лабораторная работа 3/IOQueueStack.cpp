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

/// @brief ������� ������ �����
/// @param stack ���������� ��������� �����
void PrintStack(QueueBasedStack& stack)
{
    for (int i = 0; i < stack.Tail; i++)
    {
        cout << " | ";
        cout << stack.Buffer[i] << " | ";
    }
}


/// @brief �������� ������ ������� �� �����
/// @param popStack ���������� ��������� �������
/// @param pushStack ���������� ��������� �������
void PrintQueueStack(QueueBasedStack& popStack, QueueBasedStack& pushStack)
{  
    cout << "�������: ";
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
        cout << "������� �����!\n";
        cout << "����������� � ���� ������\n";
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
        cout << "\n��� �� ������ �������?\n";
        if (!checkQueueMaking)
        {
            cout << "0: ������� �������\n";
        }
        cout << "1: �������� ������� � �������\n";
        cout << "2: ������� ������� �� �������\n";
        cout << "3: ������� �������\n";
        cout << "4: ����� � ������� ����\n";
        cout << "\n������� ��� ������� ��������: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case QueueStackMakingItem:
            {
                if (checkQueueMaking)
                {
                    cout << "������� ��� �������!\n";
                    system("pause");
                    break;
                }
                cout << "*�� ������ ������� �������*\n";
                int sizeQueue = ReadingCorrectSize();
                for (int index = 0; index < sizeQueue; index++)
                {
                    cout << "������� ������� ������� " << index + 1 << ": ";
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
                cout << "*�� ������ ��������";
                cout << " ������� � �������*\n";
                cout << "\n������� ����������� �������: ";
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
                cout << "*�� ������ �������";
                cout << " ������� �� �������*\n";
                if (!IsStackEmpty(popStack))
                {
                    DequeueStack(popStack);
                    cout << "��������� �������: ";
                    cout << popStack.Buffer[popStack.Tail];
                    cout << endl;
                }
                else if (!IsStackEmpty(pushStack))
                {
                    ExchangeElements(pushStack, popStack);
                    DequeueStack(popStack);
                    cout << "��������� �������: ";
                    cout << popStack.Buffer[popStack.Tail];
                    cout << endl;
                }
                else
                {
                    cout << "������� �����!\n";
                    cout << "����������� � ���� ������\n";
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
                    cout << "*(������� ������������� �������)*\n";
                }
                cout << "*�� ������ ��������� ";
                cout << "� ������� ����*\n";
                queueExit = false;
                system("pause");
                break;
            }
            default:
            {
                cout << "�� ��������!\n";
                cout << "������� ���������!\n\n";
                system("pause");
                break;
            }
        }
    }
}