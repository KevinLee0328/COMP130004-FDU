#include<iostream>
#include<cassert>

template<typename T>
class DoubleQueue {
public:
	DoubleQueue(int size = 100);
	~DoubleQueue() { delete[] queue; }
	bool Enqueue(const T& x, int end);
	bool Dlqueue(T& x, int end);
	bool getfront(T& x, int end);
	void makeEmpty() { end1 = end2 = 0; }
	bool IsEmpty() const { return end1 == end2; }
	bool IsFull() const { return (end2 + 1) % maxsize == end1; }
private:
	int end1, end2;
	T* queue;
	int maxsize;
};

template<typename T>
DoubleQueue<T>::DoubleQueue(int size)
{
	maxsize = size;
	queue = new T[maxsize];
	assert(queue != NULL);
	end1 = end2 = 0;
}

template<typename T>
bool DoubleQueue<T>::Enqueue(const T& x, int end)
{
	if (IsFull()) return false;
	if (end == 1) {
		end1 = (end1 - 1 + maxsize) % maxsize;
		queue[end1] = x;
	}
	else {
		queue[end2] = 2;
		end2 = (end2 + 1) % maxsize;
	}
	return true;
}

template<typename T>
bool DoubleQueue<T>::Dlqueue(T& x, int end)
{
	if (IsEmpty()) return false;
	if (end == 1) {
		x = queue[end1];
		end1 = (end1 + 1) % maxsize;
	}
	else {
		end2 = (end2 - 1 + maxsize) % maxsize;
		x = queue[end2];
	}
	return true;
}

template<typename T>
bool DoubleQueue<T>::getfront(T& x, int end)
{
	if (IsEmpty()) return false;
	if (end == 1) x = queue[end1];
	else x = queue[(end2 - 1 + maxsize) % maxsize];
	return true;
}