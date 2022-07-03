#pragma once

struct QueueBasedStack
{
	int* Buffer;
	int BufferSize;
	int Head;
	int Tail;
	const int BasicBuffer = 4;
};

/// @brief ������� ������������� �������
/// @param queueStack ���������� ��������� �������
void MakingStack(QueueBasedStack& queueStack);

/// @brief ������� �������� ����� ������� �� ��������
/// @param queueStack ���������� ��������� �������
/// @return ���� ���� ��� ���
bool IsStackEmpty(QueueBasedStack& queueStack);

/// @brief ������� ����������� �������� �� Push-����� � Pop-����
/// @param pushStack ���������� ��������� �������
/// @param popStack ���������� ��������� �������
void ExchangeElements(QueueBasedStack& pushStack, QueueBasedStack& popStack);

/// @brief ������� ��������� ������� �����
/// @param queueStack ���������� ��������� �������
void Resize(QueueBasedStack& queueStack);

/// @brief ������� �������� �������� �� ������� 
/// @param queueStack ���������� ��������� �������
void DequeueStack(QueueBasedStack& queueStack);

/// @brief ������� ���������� �������� � �������
/// @param queueStack ���������� ��������� �������
/// @param addElement ����������� �������
void EnqueueStack(QueueBasedStack& queueStack, int addElement);

/// @brief �������� �������� �������
/// @param queueStack ���������� ��������� �������
void DeleteQueueStack(QueueBasedStack& queueStack);
