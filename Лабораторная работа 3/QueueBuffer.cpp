#include "QueueBuffer.h"

void MakingQueueBuffer(QueueBuffer& queueBuffer)
{
	queueBuffer.Buffer = new int[queueBuffer.BufferSize];
	queueBuffer.IsPlaceFilled = new bool[queueBuffer.BufferSize];
	for (int i = 0; i < queueBuffer.BufferSize; ++i)
	{
		queueBuffer.IsPlaceFilled[i] = false;
	}
}

void EnqueueQueueBuffer(QueueBuffer& queueBuffer, int newElement)
{
	if ((queueBuffer.First == queueBuffer.Last) &&
		(queueBuffer.FilledPlaceCounter > 0))
	{
		if (queueBuffer.First == queueBuffer.BufferSize - 1)
		{
			queueBuffer.First = 0;
		}
		else
		{
			queueBuffer.First++;
		}
	}
	queueBuffer.Buffer[queueBuffer.Last] = newElement;
	queueBuffer.IsPlaceFilled[queueBuffer.Last] = true;
	if (queueBuffer.Last == queueBuffer.BufferSize - 1)
	{
		queueBuffer.Last = 0;
	}
	else
	{
		queueBuffer.Last++;
	}
	if (queueBuffer.FilledPlaceCounter < queueBuffer.BufferSize)
	{
		queueBuffer.FilledPlaceCounter++;
	}
}

void DequeueQueueBuffer(QueueBuffer& queueBuffer)
{
	queueBuffer.IsPlaceFilled[queueBuffer.First] = false;
	if (queueBuffer.First == queueBuffer.BufferSize - 1)
	{
		queueBuffer.First = 0;
	}
	else
	{
		queueBuffer.First++;
	}
	queueBuffer.FilledPlaceCounter--;
}

void DeleteQueue(QueueBuffer& queueBuffer)
{
	delete[] queueBuffer.Buffer;
	queueBuffer.Buffer = nullptr;
	delete[] queueBuffer.IsPlaceFilled;
	queueBuffer.IsPlaceFilled = nullptr;
}
