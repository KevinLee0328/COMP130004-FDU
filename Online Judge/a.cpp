#include <iostream>
using namespace std;

class MaxHeap {
private:
	int* arr;
	int size;
	int capacity;
public:
	MaxHeap(int c)
	{
		size = 0;
		capacity = c;
		arr = new int[c];
	}
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	int extractMax()
	{
		if (size == 0)
			return 0;
		if (size == 1)
		{
			size--;
			return arr[0];
		}
		int root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify(0);
		return root;
	}
	void insertKey(int k)
	{
		if (size == capacity) return;
		size++;
		int i = size - 1;
		arr[i] = k;
		while (i != 0 && arr[parent(i)] < arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	void heapify(int i)
	{
		int l = left(i), r = right(i);
		int largest_ilr = i;
		if (l < size && arr[l] > arr[i])
			largest_ilr = l;
		if (r < size && arr[r] > arr[largest_ilr])
			largest_ilr = r;
		if (largest_ilr != i)
		{
			swap(arr[i], arr[largest_ilr]);
			heapify(largest_ilr);
		}
	}
};

int main() {
	int n;
	cin >> n;
	MaxHeap h(n);
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		int token;
		cin >> token;
		h.insertKey(token);
		sum += token;
	}
	bool flag = true;
	if (sum % 2) flag = false;
	long total1 = 0, total2 = 0;
	for (int i = 0; i < n; i++) {
		if (flag)
			total1 += h.extractMax();
		else
			total2 += h.extractMax();
		flag = !flag;
	}
	cout << total1 << " " << total2;
}