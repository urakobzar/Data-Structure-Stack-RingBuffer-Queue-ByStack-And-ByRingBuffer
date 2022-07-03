#pragma once

struct RingBuffer
{
	const int BufferSize = 8;
	int* Buffer;
	int First = 0;
	int Last = 0;
	int FilledPlaceCounter = 0;
	bool* IsPlaceFilled;
};

/// @brief ������� �������� ���������� ������
/// @param ringBuffer ���������� ��������� ���������� ������
void MakingRingBuffer(RingBuffer& ringBuffer);

/// @brief ������� ���������� � ��������� �����
/// @param ringBuffer ���������� ��������� ���������� ������
/// @param newElement ����������� �������
void AddRingBuffer(RingBuffer& ringBuffer, int newElement);

/// @brief ������� �������� �� ���������� ������
/// @param ringBuffer ���������� ��������� ���������� ������
/// @return ��������� ������� ��� ������ �� �����
void DeleteRingBuffer(RingBuffer& ringBuffer);

/// @brief ������� �������� ��������� ���� � ��������� ������
/// @param ringBuffer ���������� ��������� ���������� ������
/// @return ����� ��������� ����
int FreePlaceCount(RingBuffer& ringBuffer);

/// @brief ������� �������� ������� ���� � ��������� ������
/// @param ringBuffer ���������� ��������� ���������� ������
/// @return ����� ������� ����
int FilledPlaceCount(RingBuffer& ringBuffer);

/// @brief 
/// @param ringBuffer ���������� ��������� ���������� ������
void DeleteBuffer(RingBuffer& ringBuffer);

/// @brief ������� ������ ���������� ������ �� �����
/// @param ringBuffer ���������� ��������� ���������� ������
void PrintRingBuffer(RingBuffer& ringBuffer);