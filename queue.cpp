#include <iostream>

using namespace std;

class Queue{
	class Node{
	public:
		int value;
		Node * next;
		Node(int value):value(value){}
	};
	
	Node * head = nullptr;
	Node * tail = nullptr;
	
	public:
	void enqueue(int value) {
		if(!head) {
			head = new Node (value);
			tail = head;
		} else {
			tail->next = new Node (value);
			tail = tail->next;
		}
	}
	
	int peak() {
		return head->value;
	}
	int dequeue() {
		if(head){
			int retval = peak();
			Node *node = head;
			head = head->next;
			delete node;
			return retval;
		}
		return -999;
	}
};

int main() {
	Queue queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
}
