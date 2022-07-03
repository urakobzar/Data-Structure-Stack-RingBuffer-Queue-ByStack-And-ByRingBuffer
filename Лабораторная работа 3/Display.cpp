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
        cout << "\n��� �� ������ �������?\n";
        cout << "1: �������� �� ������\n";
        cout << "2: �������� � ��������� �������\n";
        cout << "3: �������� � �������� �� ���� ���� ������\n";
        cout << "4: �������� � �������� �� ���� ���������� ������\n";
        cout << "5: ����� �� ���������\n";
        cout << "\n������� ��� ������� ��������: ";
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
                cout << "\n*�� ������ ����� �� ���������*\n";
                return 0;
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
    return 0;
}