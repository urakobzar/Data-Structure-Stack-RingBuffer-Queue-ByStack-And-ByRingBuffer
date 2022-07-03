#pragma once

struct QueueBuffer
{
	const int BufferSize = 8;
	int* Buffer;
	int First = 0;
	int Last = 0;
	int FilledPlaceCounter = 0;
	bool* IsPlaceFilled;
};

/// @brief ������� �������� �������
/// @param queueBuffer ���������� ��������� �������
void MakingQueueBuffer(QueueBuffer& queueBuffer);

/// @brief ������� ���������� �������� � �������
/// @param queueBuffer ���������� ��������� �������
/// @param newElement ����������� �������
void EnqueueQueueBuffer(QueueBuffer& queueBuffer, int newElement);

/// @brief ������� �������� �������� �� �������
/// @param queueBuffer ���������� ��������� �������
void DequeueQueueBuffer(QueueBuffer& queueBuffer);

/// @brief ������� �������� �������
/// @param queueBuffer ���������� ��������� �������
void DeleteQueue(QueueBuffer& queueBuffer);
