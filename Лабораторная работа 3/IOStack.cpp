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
        cout << "\n��� �� ������ �������?\n";
        if (!checkStackMaking)
        {
            cout << "0: �������� �����\n";
        }
        cout << "1: ������� ��������� � ����\n";
        cout << "2: ������� ���������� �� �����\n";
        cout << "3: ����� �����\n";
        cout << "4: ��������� ������ �� ������\n";
        cout << "\n������� ��� ������� ��������: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case StackMakingItem:
            {
                if (!checkStackMaking)
                {
                    cout << "*�� ������ ������� ����*\n";
                    int size = ReadingCorrectSize();
                    for (int index = 0; index < size; index++)
                    {
                        cout << "������� ������� ������� " << index + 1 << ": ";
                        int newElement = ReadingCorrectValue();
                        Push(stack, newElement);
                    }
                    checkStackMaking = true;
                }
                else
                {
                    cout << "���� ��� ������!\n";
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
                cout << "*�� ������ �������� ������� � ����*";
                cout << endl << endl;
                cout << "������� ����������� � ���� �������: ";
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
                    cout << "*�� ������ ������� �������";
                    cout << " �� �����*\n";
                    cout << "����������� �������: ";
                    cout << stack.Buffer[stack.Top - 1];
                    cout << endl;
                    Pop(stack);
                }
                else
                {
                    cout << "���� ����!\n";
                    cout << "����������� � ���� ������\n";
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
                cout << "*�� ������ ������� ����*\n";
                cout << "����: ";
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
                    cout << "*(���� ������������� ������)*\n";
                }
                cout << "\n*�� ������ ��������� ";
                cout << "� ������� ����*\n";
                stackExit = false;
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