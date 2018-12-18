/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// Given a linked list, return a reversed fixed size group linked list
// Example: given 1-2-3-4-5-6, 3 
//          return 4-5-6-1-2-3
//          given 1-2-3-4-5-6-7-8   3 
//          return 7-8-4-5-6-1-2-3
#include <iostream>

using namespace std;
struct Node {
    int value;
    Node * next;
    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

void printNode(Node * root) {
    if (!root) {
        cout << endl;
        return;
    }
    cout << root->value << " ";
    printNode(root->next);
}

Node * getReversedPairHelper(Node * retval, Node * root, int groupSize) {
    if(!root) return retval;
    Node * cur = root;
    for(int i = 0; i < groupSize - 1; i++) {
        if(!cur->next) {
            cur->next = retval;
            retval = root;
            return retval;
        } else {
            cur = cur->next;
        }
    }
    Node * temp = root;
    root = cur->next;
    cur->next = retval;
    retval = temp;
    return getReversedPairHelper(retval, root, groupSize);
}

Node * getReversedPiar(Node * root, int groupSize) {
    Node *retval = nullptr;
    return getReversedPairHelper(retval, root, groupSize);
}

int main()
{
    Node * root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = new Node(7);
    root->next->next->next->next->next->next->next = new Node(8);
    Node * hehe = getReversedPiar(root, 3);
    printNode(hehe);

    return 0;
}
