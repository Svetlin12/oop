#include "IntStack.h"
#include <iostream>

using namespace std;

void IntStack::incrementSize()
{
	this->size++;
}

void IntStack::decreaseSize()
{
	this->size--;
}

void IntStack::resize()
{
	int* newArray = new int[getSize() + 1];
	for (int i = 0; i < getSize(); i++)
	{
		newArray[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArray;
	incrementSize();
}

bool IntStack::isEmpty() const
{
	return this->arr == nullptr;
}

int IntStack::peek() const
{
	if (isEmpty())
	{
		cout << "Stack is empty!" << endl;
	}
	else
	{
		return arr[getSize() - 1];
	}
}

void IntStack::push(int value)
{
	resize();
	this->arr[getSize() - 1] = value;
}

void IntStack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is already empty!" << endl;
		return;
	}
	else decreaseSize();
}

void IntStack::print() const
{
	for (int i = getSize() - 1; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
}

int IntStack::getSize() const
{
	return this->size;
}

IntStack::IntStack()
{
	this->arr = new int[getSize()];
}

IntStack::~IntStack()
{
	delete[] this->arr;
}

IntStack::IntStack(const IntStack& s)
{
	this->size = s.getSize();
	this->arr = new int[getSize() + 1];
	for (int i = 0; i < getSize(); i++)
	{
		arr[i] = s.arr[i];
	}
}

void sortStack(IntStack& s)
{
	for (int i = 0; i < s.getSize(); i++)
	{
		for (int j = 0; j < s.getSize() - 1; j++)
		{
			if (s.arr[i] < s.arr[j])
			{
				int temp = s.arr[i];
				s.arr[i] = s.arr[j];
				s.arr[j] = temp;
			}
		}
	}
}
