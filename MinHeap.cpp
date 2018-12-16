#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class MinIntHeap {
public:
	int capacity;
	int size;
	int * array;

	MinIntHeap(int c) {
		capacity = c;
		size = 0;
		array = new int [capacity];
		for(int i = 0; i < capacity; i++) {
			array[i] = INT_MAX;
		}
	}

	void swap(int child, int parent) {
		int temp = array[child];
		array[child] = array[parent];
		array[parent] = temp;
	}

	// bubble up the last inserted element, if it's value < parent, swap them.
	void bubbleUp() {
		int index = size - 1;
		while (index > 0) {
			int parentIndex;
			if(index % 2 == 0) {	//it's a right child
				parentIndex = (index - 2) / 2;
			} else {
				parentIndex = (index - 1) / 2;
			}
			//cout << "bubbleup: index: " << index << ". parent is " << parentIndex << endl;
			if (array[index] < array[parentIndex]) {
				swap(index, parentIndex);
				index = parentIndex;
			}  else {
				break; // insertion is at right place
			}
		}
	}

	bool insert(int value) {
		if (size < capacity) {
			array[size++] = value;
			bubbleUp();
			return true;
		}
		return false;
	}

	// given an index, return the index of its child whose value is smaller than the other child
	int getSmallerChildIndex (int index) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (array[left] < array[right]) {
			return left;
		} else {
			return right;
		}
	}

	// bubble down the first element to get the smallest element
	void bubbleDown() {
		int parentIndex = 0;
		while (parentIndex*2 +1 < size) {
			int childIndex = getSmallerChildIndex(parentIndex);
			//cout << "bubbledown: parentIndex: " << parentIndex << ". parent is " << array[parentIndex] << ". Child index " << childIndex << ", child is " << array[childIndex]<<endl;
			if (array[parentIndex] > array[childIndex]) {
				swap(parentIndex , childIndex);
				parentIndex = childIndex;
			}  else {
			    //printHeap();
				break; // we are done bubble down.
			}
			//printHeap();
		}		
	}
	
	int removeMin() {
		int retval = INT_MAX;
		if (size > 0) {
			retval = array[0];
			array[0] = array[size - 1]; // move the last element to the top
			//cout << "a[0] is now " << array[0] << endl;
			array[size - 1] = INT_MAX;  // set the last element to default value
			size --;                    // decrement the size since one is removed
			bubbleDown();	            // bubble down the first element
			//printHeap();
		}
		return retval;
	}
	
	void printHeap() {
	    for(int i = 0; i < size; i++) {
	        cout << array[i] << " ";
	    }
	    cout << endl;
	}
};

int main() {
	MinIntHeap minHeap(10);
	minHeap.insert(2);
	minHeap.insert(1);
	minHeap.insert(3);
	minHeap.insert(8);
	minHeap.insert(5);
	minHeap.insert(7);
	minHeap.insert(9);
	minHeap.insert(4);
	minHeap.insert(0);
	minHeap.insert(6);
	for(int i = 0; i < 10; i++) {
	    cout << minHeap.removeMin() << endl;
	    //minHeap.removeMin();
	}
}	




