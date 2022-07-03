#include "QueueStack.h"

void MakingStack(QueueBasedStack& stack)
{
    stack.Head = 0;
    stack.Tail = 0;
    stack.BufferSize = stack.BasicBuffer;
    stack.Buffer = new int[stack.BufferSize];
}

void EnqueueStack(QueueBasedStack& stack, int addElement)
{
    Resize(stack);     
    stack.Buffer[stack.Tail] = addElement;
    stack.Tail++;
}

void DequeueStack(QueueBasedStack& stack)
{    
    stack.Tail--;
    Resize(stack);
}

void Resize(QueueBasedStack& stack)
{
    const int growthFactor = 2;
    if ((stack.Tail >= stack.BufferSize) || 
        ((stack.Tail < stack.BufferSize / growthFactor) && 
            (stack.BufferSize > stack.BasicBuffer)))
    {
        while (stack.Tail >= stack.BufferSize)
        {
            stack.BufferSize = stack.BufferSize * growthFactor;
        }
        if (stack.Tail < (stack.BufferSize / growthFactor))
        {
            if (stack.BufferSize > stack.BasicBuffer)
            {
                stack.BufferSize = stack.BufferSize / growthFactor;
            }
        }
        int* newBuffer = new int[stack.BufferSize];
        for (int i = 0; i < stack.Tail; ++i)
        {
            newBuffer[i] = stack.Buffer[i];
        }
        delete[] stack.Buffer;
        stack.Buffer = newBuffer;
    }
}

void ExchangeElements(QueueBasedStack& pushStack, QueueBasedStack& popStack)
{
    int indexTail = pushStack.Tail;
    for (int i = indexTail-1; i >=0; i--)
    {
        EnqueueStack(popStack, pushStack.Buffer[i]);
        pushStack.Tail--;
    }
}

void DeleteQueueStack(QueueBasedStack& stack)
{
    delete[] stack.Buffer;
    stack.Buffer = nullptr;
}

bool IsStackEmpty(QueueBasedStack& stack)
{
    if (stack.Tail == 0)
    {
        return (true);
    }
    return (false);
}
