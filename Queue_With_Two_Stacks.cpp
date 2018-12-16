#include <iostream>
#include <string>
#include <stack>
#include <assert.h>
using namespace std;

// Build a queue using two stacks

class Queue {
	stack<char> stack1;
	stack<char> stack2;
	
public:
	void push(char ch) {
		if(stack1.size() == 0) {
			stack2.push(ch);
		} else {
			stack1.push(ch);
		}
	}

	char pop() {
	    if(stack1.size() == 0) {
        	while(stack2.size() != 0) {
        		stack1.push(stack2.top());
        		stack2.pop();
        	}	    
        	char retval = stack1.top();
        	stack1.pop();
        	return retval;
        } else {
        	while(stack1.size() != 0) {
        		stack2.push(stack1.top());
        		stack1.pop();
        	}	 
        	char retval = stack2.top();
        	stack2.pop();
        	return retval;
        }  

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
	cout << a << endl;
	cout << b << endl;
	assert  (!a.compare(b));
}



