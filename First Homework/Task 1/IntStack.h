#pragma once
//my stack consists of a dynamic array and its size which is used to both track the array's element count and
//holding the index of the top element

class IntStack
{
private:

	int* arr = nullptr;
	int size = 0;

	//increments size
	void incrementSize();

	//decreases size
	void decreaseSize();

	//resizing the array. For an example from an array with 2 elements after the function the array will be with 3 
	//elements
	void resize();

	//checks whether the array has no elements
	bool isEmpty() const;

public:

	//returns the top element of the array
	int peek() const;

	//adds an element to the top of the array
	void push(int);

	//removes the top element of the array
	void pop();

	//prints all the elements in the array starting from the top one
	void print() const;

	//gets the size of the array
	int getSize() const;

	//constructors
	IntStack();
	IntStack(const IntStack&);

	//destructor
	~IntStack();

	//the sort function which sets the elements in the array in descending order(it is not a member of the class)
	friend void sortStack(IntStack&);
};