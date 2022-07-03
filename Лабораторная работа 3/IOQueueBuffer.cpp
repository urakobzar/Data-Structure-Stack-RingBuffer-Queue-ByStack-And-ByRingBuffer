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

/// @brief ������� ������ ������� �� �����
/// @param queueBuffer ���������� ��������� �������
void PrintQueueBuffer(QueueBuffer& queueBuffer)
{
    if (queueBuffer.FilledPlaceCounter != 0)
    {
        cout << "\n��������� �����:\n";
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
        cout << "������� �����!\n";
        cout << "����������� � ���� ������\n";
    }
}

void QueueBufferActions()
{
    QueueBuffer queueBuffer;
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
            case QueueBufferMakingItem:
            {
                if (checkQueueMaking)
                {
                    cout << "������� ��� �������!\n";
                    system("pause");
                    break;
                }
                MakingQueueBuffer(queueBuffer);
                int sizeQueue = ReadingCorrectSize();
                for (int index = 0; index < sizeQueue; index++)
                {
                    cout << "������� ������� ������� " << index + 1 << ": ";
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
                cout << "*�� ������ ��������";
                cout << " ������� � �������*\n";
                cout << "\n������� ����������� �������: ";
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
                    cout << "*�� ������ ������� �������";
                    cout << " �� ���������� ������*\n";
                    cout << "��������� �������: ";
                    cout << queueBuffer.First << endl;
                    if (queueBuffer.FilledPlaceCounter != 0)
                    {
                        PrintQueueBuffer(queueBuffer);
                    }
                }
                else
                {
                    cout << "������� �����!\n";
                    cout << "����������� � ���� ������\n";
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