#pragma once
#include <iostream>

using namespace std;

template <typename T>
class MagicBox
{
private:

	T* subjects = nullptr;
	int size = 0;
	int cap = 0;

	void increaseSize();
	void decreaseSize();
	void resize();

	bool isFull() const;
	bool isEmpty() const;

	void increaseCap();

	void copy(const MagicBox& m);

public:

	MagicBox();
	MagicBox(const MagicBox& m);
	~MagicBox();
	MagicBox<T> operator=(const MagicBox& m);

	int getSize() const;

	int getCap() const;

	void insert(T value);
	void pop(int randomNumber);
	void list() const;

};

template<typename T>
void MagicBox<T>::increaseSize()
{
	this->size++;
}

template<typename T>
void MagicBox<T>::decreaseSize()
{
	this->size--;
}

template<typename T>
void MagicBox<T>::resize()
{
	T* newSubjects = new T[getSize() + 1];
	for (int i = 0; i < getSize(); i++)
	{
		newSubjects[i] = this->subjects[i];
	}
	delete[] this->subjects;
	this->subjects = newSubjects;
	increaseCap();
}

template<typename T>
bool MagicBox<T>::isFull() const
{
	return this->cap == this->size;
}

template<typename T>
bool MagicBox<T>::isEmpty() const
{
	return this->size == 0;
}

template<typename T>
void MagicBox<T>::increaseCap()
{
	this->cap++;
}

template<typename T>
void MagicBox<T>::copy(const MagicBox & m)
{
	this->size = m.getSize();
	this->cap = m.getCap();
	this->subjects = new T[getSize()];
	for (int i = 0; i < getSize(); i++)
	{
		this->subjects[i] = m.subjects[i];
	}
}

template<typename T>
MagicBox<T>::MagicBox()
{
	this->subjects = new T[getSize() + 1];
	increaseCap();
}

template<typename T>
MagicBox<T>::MagicBox(const MagicBox & m)
{
	copy(m);
}

template<typename T>
MagicBox<T>::~MagicBox()
{
	delete[] this->subjects;
}

template<typename T>
MagicBox<T> MagicBox<T>::operator=(const MagicBox & m)
{
	if (this == &m) return *this;

	delete[] this->subjects;
	copy(m);
	return *this;
}

template<typename T>
int MagicBox<T>::getSize() const
{
	return this->size;
}

template<typename T>
int MagicBox<T>::getCap() const
{
	return this->cap;
}

template<typename T>
void MagicBox<T>::insert(T value)
{
	if (isFull()) resize();

	this->subjects[getSize()] = value;
	increaseSize();
}

template<typename T>
void MagicBox<T>::pop(int randomNumber)
{
	if (isEmpty())
	{
		cout << "The magic box is empty! Can't remove anything!" << endl;
	}
	else
	{
		for (int i = randomNumber; i < getSize(); i++)
		{
			this->subjects[i] = this->subjects[i + 1];
		}
		decreaseSize();
	}
}

template<typename T>
void MagicBox<T>::list() const
{
	cout << "---------Magic Box---------" << endl << "subjects in the Magic Box: " << endl;
	for (int i = 0; i < getSize(); i++)
	{
		cout << this->subjects[i] << endl;
	}
	cout << "---------------------------" << endl;
}
