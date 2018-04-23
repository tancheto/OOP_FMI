#pragma once
int const MAX = 100;

class Stack
{
private:
	double* arr;
	int length;
	int upperIndex;
	void doubling(); //doubling the size of the stack when it's full
	bool isFull();

public:
	Stack();
	Stack(Stack const& s);
	Stack &operator=(Stack const& s);
	~Stack();
	double peek();
	double pop();
	void push(double n);
	bool isEmpty();
	int size();
}
;