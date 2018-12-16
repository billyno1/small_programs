#include <iostream>
#include <string>
#include <stack>
#include <assert.h>
using namespace std;

// Build a queue using two stacks

class Queue {
	stack<char> stack1;
	stack<char> stack2;
	string lastOperation;
	
public:
	void switchStack() {
	    if(stack1.size() == 0) {
        	while(stack2.size() != 0) {
        		stack1.push(stack2.top());
        		stack2.pop();
        	}	 
        } else {
        	while(stack1.size() != 0) {
        		stack2.push(stack1.top());
        		stack1.pop();
        	}	 
        }  
	}		

	void push(char ch) {
		if(lastOperation == "pop") {
			switchStack();
		}
		if(stack1.size() == 0) {
			stack2.push(ch);
		} else {
			stack1.push(ch);
		}
		lastOperation = "push";
	}

	char pop() {
	    char retval;
		if(lastOperation == "push") {
			switchStack();
		}
	    if(stack2.size() == 0) {
        	retval = stack1.top();
        	stack1.pop();
        } else {
        	retval = stack2.top();
        	stack2.pop();
        }  
        lastOperation = "pop";
        	return retval;
	}
};


int main() {
	string a = "abc";
	string b;
	Queue queue;
	for(int i = 0; i < a.size(); i++) {
		queue.push(a[i]);
	}
	for(int i = 0; i < a.size(); i++) {
		b += queue.pop();
	}
	assert  (!a.compare(b));
	
	b = "";
	queue.push('1');
	b += queue.pop();
	queue.push('2');
	b += queue.pop();
	queue.push('3');
	queue.push('4');
	b += queue.pop();
	b += queue.pop();
	cout << a << endl;
	cout << b << endl;
	assert  (b == "1234");
}
