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

/// @brief Функция создания Очереди
/// @param queueBuffer Переменная структуры Очереди
void MakingQueueBuffer(QueueBuffer& queueBuffer);

/// @brief Функция добавления элемента в Очередь
/// @param queueBuffer Переменная структуры Очереди
/// @param newElement Добавляемый элемент
void EnqueueQueueBuffer(QueueBuffer& queueBuffer, int newElement);

/// @brief Функция удаления элемента из Очереди
/// @param queueBuffer Переменная структуры Очереди
void DequeueQueueBuffer(QueueBuffer& queueBuffer);

/// @brief Функция удаления Очереди
/// @param queueBuffer Переменная структуры Очереди
void DeleteQueue(QueueBuffer& queueBuffer);
