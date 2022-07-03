#include "Stack.h"

void MakingStack(Stack& stack)
{
    stack.Top = 0;
    stack.BufferSize = stack.BasicBuffer;
    stack.Buffer = new int[stack.BufferSize];
}

void Push(Stack& stack, int newElement)
{
    Resize(stack);
    stack.Buffer[stack.Top] = newElement;
    stack.Top++;
}

void Pop(Stack& stack)
{
    stack.Top--;
    Resize(stack);
}
 
void Resize(Stack& stack)
{
    const int growthFactor = 2;
    if ((stack.Top >= stack.BufferSize) 
        || ((stack.Top < stack.BufferSize / growthFactor) 
            && (stack.BufferSize > stack.BasicBuffer)))
    {
        while (stack.Top >= stack.BufferSize)
        {
            stack.BufferSize = stack.BufferSize * growthFactor;
        }
        if (stack.Top < (stack.BufferSize / growthFactor))
        {
            if (stack.BufferSize > stack.BasicBuffer)
            {
                stack.BufferSize = stack.BufferSize / growthFactor;
            }
        }
        int* newBuffer = new int[stack.BufferSize];
        for (int i = 0; i < stack.Top; ++i)
        {
            newBuffer[i] = stack.Buffer[i];
        }
        delete[] stack.Buffer;
        stack.Buffer = newBuffer;
    }
}
