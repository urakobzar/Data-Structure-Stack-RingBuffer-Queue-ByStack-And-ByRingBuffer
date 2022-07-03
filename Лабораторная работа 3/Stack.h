#pragma once

struct Stack
{
    int* Buffer;
    int BufferSize;
    int Top;
    const int BasicBuffer = 4;
};

/// @brief ������� ������������� �����
/// @param stack ���������� ��������� �����
void MakingStack(Stack& stack);

/// @brief ������� ��������� � ���� 
/// @param stack ���������� ��������� �����
/// @param newElement ����������� � ���� �������
void Push(Stack& stack, int newElement);

/// @brief ������� ���������� �� �����
/// @param stack ���������� ��������� �����
void Pop(Stack& stack);

/// @brief ������� ��������� ������� �����
/// @param stack ���������� ��������� �����
void Resize(Stack& stack);