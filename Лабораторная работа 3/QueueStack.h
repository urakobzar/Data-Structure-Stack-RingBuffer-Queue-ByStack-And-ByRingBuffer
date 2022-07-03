#pragma once

struct QueueBasedStack
{
	int* Buffer;
	int BufferSize;
	int Head;
	int Tail;
	const int BasicBuffer = 4;
};

/// @brief Функция инициализации очереди
/// @param queueStack Переменная структуры Очереди
void MakingStack(QueueBasedStack& queueStack);

/// @brief Функция проверки стэка Очереди на элементы
/// @param queueStack Переменная структуры Очереди
/// @return Пуст стэк или нет
bool IsStackEmpty(QueueBasedStack& queueStack);

/// @brief Функция перемещения элемента из Push-стэка в Pop-стэк
/// @param pushStack Переменная структуры Очереди
/// @param popStack Переменная структуры Очереди
void ExchangeElements(QueueBasedStack& pushStack, QueueBasedStack& popStack);

/// @brief Функция изменения размера Стэка
/// @param queueStack Переменная структуры Очереди
void Resize(QueueBasedStack& queueStack);

/// @brief Функция удаления элемента из Очереди 
/// @param queueStack Переменная структуры Очереди
void DequeueStack(QueueBasedStack& queueStack);

/// @brief Функция добавления элемента в Очередь
/// @param queueStack Переменная структуры Очереди
/// @param addElement Добавляемый элемент
void EnqueueStack(QueueBasedStack& queueStack, int addElement);

/// @brief Функкция удаления Очереди
/// @param queueStack Переменная структуры Очереди
void DeleteQueueStack(QueueBasedStack& queueStack);
