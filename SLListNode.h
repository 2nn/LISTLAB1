#pragma once
#include <stdlib.h>

template <class T>
class SLListNode
{
	T data;
public:
	SLListNode *next;
	void inputData(T dataval)
	{
		data = dataval;
	}

	T outputData()
	{
		return data;
	}

};


