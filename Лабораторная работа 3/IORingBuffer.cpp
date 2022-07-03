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

/// @brief ������� ������ ���������� ������ �� �����
/// @param ringBuffer ���������� ��������� ���������� ������
void PrintRingBuffer(RingBuffer& ringBuffer)
{
    cout << "\n��������� �����:\n";
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
        cout << "\n��� �� ������ �������?\n";
        cout << "1: ���������� ��������� �����\n";
        cout << "2: ���������� ������� �����\n";
        cout << "3: ���������� ��������\n";
        cout << "4: �������� ��������\n";
        cout << "5: ����� ���������� ������\n";
        cout << "6: ��������� ������ � ��������� �������\n";
        cout << "\n������� ��� ������� ��������: ";
        int localNumber = ReadingCorrectValue();
        cout << endl;
        switch (localNumber)
        {
            case FreePlace:
            {
                cout << "����� ��������� �����: ";
                cout << FreePlaceCount(ringBuffer);
                cout << endl;
                system("pause");
                break;
            }
            case EmployedPlace:
            {
                cout << "����� ������� �����: ";
                cout << FilledPlaceCount(ringBuffer);
                cout << endl;
                system("pause");
                break;
            }
            case AddRingBufferItem:
            {
                cout << "*�� ������ ��������";
                cout << " ������� � ��������� �����*\n";
                cout << "\n������� ����������� �������: ";
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
                    cout << "*�� ������ ������� �������";
                    cout << " �� ���������� ������*\n";
                    cout << "��������� �������: ";
                    cout << ringBuffer.First << endl;
                    if (FilledPlaceCount(ringBuffer) != 0)
                    {
                        PrintRingBuffer(ringBuffer);
                    }
                }
                else
                {
                    cout << "��������� ����� ����!\n";
                    cout << "����������� � ���� ������\n";
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
                cout << "*�� ������ ��������� ";
                cout << "� ������� ����*\n";
                ringExit = false;
                DeleteBuffer(ringBuffer);
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