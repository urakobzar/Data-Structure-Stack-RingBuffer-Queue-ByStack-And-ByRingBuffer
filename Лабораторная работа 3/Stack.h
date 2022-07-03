#pragma once

struct Stack
{
    int* Buffer;
    int BufferSize;
    int Top;
    const int BasicBuffer = 4;
};

/// @brief Функция инициализации Стека
/// @param stack Переменная структура Стека
void MakingStack(Stack& stack);

/// @brief Функции помещения в Стек 
/// @param stack Переменная структуры Стека
/// @param newElement Добавляемый в Стек элемент
void Push(Stack& stack, int newElement);

/// @brief Функция извлечения из Стека
/// @param stack Переменная структуры Стека
void Pop(Stack& stack);

/// @brief Функция изменения размера Стека
/// @param stack Переменная структуры Стека
void Resize(Stack& stack);