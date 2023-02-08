#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Stack {
    public:
        vector<int> data;

        int peek() {
            // See top element of Stack
            return this->data[this->data.size()-1];
        }

        void push(int value) {
            // Push new element onto top of Stack
            data.push_back(value);
        }

        void pop() {
            // Remove top element from stack
            data.pop_back();
        }
};

int main() {
    Stack my_stack;
    my_stack.push(1);
    cout << my_stack.peek() << "\n";
    my_stack.push(2);
    cout << my_stack.peek() << "\n";
    my_stack.pop();
    cout << my_stack.peek() << "\n";  
}