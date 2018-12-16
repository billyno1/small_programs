#include <iostream>

using namespace std;

class Stack{
	class Node{
	public:
		int value;
		Node * next;
		Node(int value):value(value){}
	};
	
	Node * head;
	public:
	void push(int value) {
		if(!head) {
			head = new Node (value);
		} else {
			Node *node = new Node (value);
			node->next = head;
			head = node;
		}
	}
	
	int peak() {
		return head->value;
	}
	int pop() {
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
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
}
