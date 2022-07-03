#include "RingBuffer.h"

void MakingRingBuffer(RingBuffer& ringBuffer)
{
	ringBuffer.Buffer = new int[ringBuffer.BufferSize];
	ringBuffer.IsPlaceFilled = new bool[ringBuffer.BufferSize];
	for (int i = 0; i < ringBuffer.BufferSize; ++i)
	{
		ringBuffer.IsPlaceFilled[i] = false;
	}
}


void ActionFirstElemnt(RingBuffer& ringBuffer)
{
	if (ringBuffer.First == ringBuffer.BufferSize - 1)
	{
		ringBuffer.First = 0;
	}
	else
	{
		ringBuffer.First++;
	}
}

void AddRingBuffer(RingBuffer& ringBuffer, int newElement)
{
	if ((ringBuffer.First == ringBuffer.Last) &&
			(ringBuffer.FilledPlaceCounter > 0))
	{
		ActionFirstElemnt(ringBuffer);
	}
	ringBuffer.Buffer[ringBuffer.Last] = newElement;
	ringBuffer.IsPlaceFilled[ringBuffer.Last] = true;
	if (ringBuffer.Last == ringBuffer.BufferSize - 1)
	{
		ringBuffer.Last = 0;
	}
	else
	{
		ringBuffer.Last++;
	}
	if (ringBuffer.FilledPlaceCounter < ringBuffer.BufferSize)
	{
		ringBuffer.FilledPlaceCounter++;
	}
}

void DeleteRingBuffer(RingBuffer& ringBuffer)
{
	ringBuffer.IsPlaceFilled[ringBuffer.First] = false;
	ActionFirstElemnt(ringBuffer);
	ringBuffer.FilledPlaceCounter--;
}

int FreePlaceCount(RingBuffer& ringBuffer)
{
	return (ringBuffer.BufferSize - ringBuffer.FilledPlaceCounter);
}

int FilledPlaceCount(RingBuffer& ringBuffer)
{
	return (ringBuffer.FilledPlaceCounter);
}

void DeleteBuffer(RingBuffer& ringBuffer)
{
	delete[] ringBuffer.Buffer;
	ringBuffer.Buffer = nullptr;
	delete[] ringBuffer.IsPlaceFilled;
	ringBuffer.IsPlaceFilled = nullptr;
}
