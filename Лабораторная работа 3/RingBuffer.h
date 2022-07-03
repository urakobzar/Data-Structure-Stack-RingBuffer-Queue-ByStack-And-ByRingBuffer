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

/// @brief Функция создания Кольцевого Буфера
/// @param ringBuffer Переменная структуры Кольцевого Буфера
void MakingRingBuffer(RingBuffer& ringBuffer);

/// @brief Функция добавления в Кольцевой Буфер
/// @param ringBuffer Переменная структуры Кольцевого Буфера
/// @param newElement Добавляемый элемент
void AddRingBuffer(RingBuffer& ringBuffer, int newElement);

/// @brief Функция удаления из Кольцевого Буфера
/// @param ringBuffer Переменная структуры Кольцевого Буфера
/// @return Удаляемый элемент для вывода на экран
void DeleteRingBuffer(RingBuffer& ringBuffer);

/// @brief Функция подсчета свободных мест в Кольцевом Буфере
/// @param ringBuffer Переменная структуры Кольцевого Буфера
/// @return Число свободных мест
int FreePlaceCount(RingBuffer& ringBuffer);

/// @brief Функция подсчета занятых мест в Кольцевом Буфере
/// @param ringBuffer Переменная структуры Кольцевого Буфера
/// @return Число занятых мест
int FilledPlaceCount(RingBuffer& ringBuffer);

/// @brief 
/// @param ringBuffer Переменная структуры Кольцевого Буфера
void DeleteBuffer(RingBuffer& ringBuffer);

/// @brief Функция вывода Кольцевого Буфера на экран
/// @param ringBuffer Переменная структуры Кольцевого Буфера
void PrintRingBuffer(RingBuffer& ringBuffer);